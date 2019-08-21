#include "script_component.hpp"
EXEC_CHECK(SERVER);

params ["_logic","_zoneName"];
LOG_2("Activating CaptureZone logic: %1 name: %2 PFH",_logic,_zoneName);
if (isNil QGVAR(ListArray)) then {GVAR(ListArray) = [];};
GVAR(ListArray) pushBack _logic;
private _varName = format ["%1_var",_logic];
private _teamControllingvarName = format ["%1_teamControlling",_logic];
LOG_2("Activating CaptureZone _varName: %1 _teamControllingvarName: %2 PFH",_varName,_teamControllingvarName);

GVAR(DOUBLES(PFHhandle,_logic)) = [{
    //var redeclares
    params ["_argNested", "_idPFH"];
    _argNested params ["_args","_lastCheckedTime",["_initialized",false,[false]],"_varName","_teamControllingvarName",["_oldOwner","UNCONTESTED",[""]],["_ownerControlCount",0,[0]],"_marker"];
    _args params ["_logic","_zoneName","_area","_mode","_capArray","_timeArray","_messagesArray","_colours","_hidden","_silent","_automessages","_ratioNeeded"];
    _area params ["_loc","_radiusX","_radiusY","_direction","_isRectangle"];
    _colours params ["_bluforcolour","_opforcolour","_indforcolour","_civcolour","_uncontestedcolour","_contestedcolour"];
    _messagesArray params ["_bluformessageArray","_opformessageArray","_indformessageArray","_CIVmessageArray","_contestedmessage","_uncontestedmessage"];
    _capArray params ["_bluforCapMode","_opforCapMode","_indforCapMode","_civCapMode"];
    private ["_owner","_markername"];

    if !(_initialized) then {
        _argNested set [2,true];
        _oldOwner = "UNCONTESTED";
        _owner = "UNCONTESTED";
        _argNested set [6,0];

        if !(_hidden) then {
            _markername = format ["%1_ZoneMarker",_logic];
            _marker = createmarker [_markername,_loc];
            _argNested set [7,_marker];
            if (_isRectangle) then {
                _marker setMarkerShape "RECTANGLE";
            } else {
                _marker setMarkerShape "ELLIPSE";
            };
            _marker setMarkerSize [_radiusX, _radiusY];
            _marker setMarkerAlpha 0.25;
            _marker setMarkerBrush "SolidBorder";
            _marker setMarkerDir _direction;
            _marker setMarkerColor _uncontestedcolour;
        };

        MissionNamespace setvariable [_varName,false];
        MissionNamespace setvariable [_teamControllingvarName,"UNCONTESTED"];
    };

    private _bluCount = 0;
    private _opCount = 0;
    private _indCount = 0;
    private _civCount = 0;

    private _playersInArea = (([] call EFUNC(Core,AlivePlayers)) select {(_x inArea _area) && {(!captive _x)}});

    if (_playersInArea isEqualTo []) exitwith {
        if ((missionNamespace getvariable [_varName,false]) && {(_mode isEqualto "REPEATABLE")}) then {
            _owner = "UNCONTESTED";
            if !(_owner isEqualto _oldOwner) then {
                _argNested set [5,_owner];
                _argNested set [6,0];
                if !(_hidden) then {
                    _marker setMarkerColor _uncontestedcolour;
                    _marker setMarkerAlpha 0.25;
                };
                if !(_silent) then {
                    if (_automessages) then {
                        private _msg = format ["%1 is uncontested!",_zoneName];
                        _msg remoteExec ["hintsilent"];
                    } else {
                        _uncontestedmessage remoteExec ["hintsilent"];
                    };
                };
                MissionNamespace setvariable [_varName,false];
                MissionNamespace setvariable [_teamControllingvarName,"UNCONTESTED"];
            };
        };
    };

    {
        switch (side _x) do {
            case west: {
                if !(_bluforCapMode isEqualto 2) then {
                    _bluCount = _bluCount + 1;
                };
            };
            case east: {
                if !(_opforCapMode isEqualto 2) then {
                    _opCount = _opCount + 1;
                };
            };
            case independent: {
                if !(_indforCapMode isEqualto 2) then {
                    _indCount = _indCount + 1;
                };
            };
            case civilian: {
                if !(_civCapMode isEqualto 2) then {
                    _civCount = _civCount + 1;
                };
            };
            default {};
        };
    } foreach _playersInArea;

    if (({(selectMax [_bluCount, _opCount, _indCount, _civCount] isEqualTo _x) && !(_x isEqualto 0)} count [_bluCount, _opCount, _indCount, _civCount]) > 1) then {
        //it's a tie between 2 or more teams
        _owner = "CONTESTED";
        _argNested set [6,0];
        if !(_owner isEqualto _oldOwner) then {
            _argNested set [5,_owner];
            if !(_hidden) then {
                _marker setMarkerColor _contestedcolour;
                _marker setMarkerAlpha 0.25;
            };
            if !(_silent) then {
                if (_automessages) then {
                    private _msg = format ["%1 is contested!",_zoneName];
                    _msg remoteExec ["hintsilent"];
                } else {
                    _contestedmessage remoteExec ["hintsilent"];
                };
            };
        };
    } else {
        //a team has a number advantage
        private _ratio = 10;
        private _liveCountArray = [_bluCount,_opCount,_indCount,_civCount];
        private _findMax = (_liveCountArray call CBA_fnc_findMax);
        private _max = _findMax select 0;
        private _maxindex = _findMax select 1;
        private _2ndplace = 0;
        if !(_ratioNeeded isEqualto 0) then {
            _liveCountArray deleteAt _maxindex;
            _2ndplace = selectMax _liveCountArray;
            if !(_2ndplace isEqualTo 0) then {
                _ratio = (_2ndplace / _max);
            } else {
                _ratio = 10;
            };
        } else {
            _ratio = 10;
            _2ndplace = 0;
        };
        if (_ratio > _ratioNeeded) then {
            //a team has enough ratio for control!
            _owner = ["BLUFOR","OPFOR","Indfor","CIVILIAN"] select _maxindex;

            switch (_owner) do {
                case "BLUFOR": {
                    if (_owner isEqualto _oldOwner) then {
                        if (_bluforCapMode isEqualTo 0) then {
                            _argNested set [6,(_ownerControlCount + 1)];
                            if ((_argNested select 6) > (_timeArray select 0)) then {
                                //message is blufor has captured
                                if !(_hidden) then {
                                    _marker setMarkerColor _bluforcolour;
                                    _marker setMarkerAlpha 0.5;
                                };
                                if !(_silent) then {
                                    if (_automessages) then {
                                        private _msg = format ["%1 has captured %2!",EGVAR(Core,TeamName_Blufor),_zoneName];
                                        _msg remoteExec ["hintsilent"];
                                    } else {
                                        (_bluformessageArray select 1) remoteExec ["hintsilent"];
                                    };
                                };
                                MissionNamespace setvariable [_varName,true];
                                MissionNamespace setvariable [_teamControllingvarName,"BLUFOR"];
                                if (_mode isEqualto "ONCE") exitWith {
                                    if !(_hidden) then {
                                        _marker setMarkerAlpha 0.5;
                                        _marker setMarkerBrush "Border";
                                    };
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                                };
                            };
                        };
                    } else {
                        _argNested set [5,_owner];
                        _argNested set [6,0];
                        //message if blufor is capturing
                        if !(_hidden) then {
                            _marker setMarkerColor _bluforcolour;
                            _marker setMarkerAlpha 0.25;
                        };
                        if !(_silent) then {
                            if (_automessages) then {
                                private _msg = format ["%1 is capturing %2!",EGVAR(Core,TeamName_Blufor),_zoneName];
                                _msg remoteExec ["hintsilent"];
                            } else {
                                (_bluformessageArray select 0) remoteExec ["hintsilent"];
                            };
                        };
                    };
                };
                case "OPFOR": {
                    if (_owner isEqualto _oldOwner) then {
                        if (_opforCapMode isEqualTo 0) then {
                            _argNested set [6,(_ownerControlCount + 1)];
                            if ((_argNested select 6) > (_timeArray select 1)) then {
                                //message is blufor has captured
                                if !(_hidden) then {
                                    _marker setMarkerColor _opforcolour;
                                    _marker setMarkerAlpha 0.5;
                                };
                                if !(_silent) then {
                                    if (_automessages) then {
                                        private _msg = format ["%1 has captured %2!",EGVAR(Core,TeamName_Opfor),_zoneName];
                                        _msg remoteExec ["hintsilent"];
                                    } else {
                                        (_opformessageArray select 1) remoteExec ["hintsilent"];
                                    };
                                };
                                MissionNamespace setvariable [_varName,true];
                                MissionNamespace setvariable [_teamControllingvarName,"OPFOR"];
                                if (_mode isEqualto "ONCE") exitWith {
                                    if !(_hidden) then {
                                        _marker setMarkerAlpha 0.5;
                                        _marker setMarkerBrush "Border";
                                    };
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                                };
                            };
                        };
                    } else {
                        //message if blufor is capturing
                        _argNested set [5,_owner];
                        _argNested set [6,0];
                        if !(_hidden) then {
                            _marker setMarkerColor _opforcolour;
                            _marker setMarkerAlpha 0.25;
                        };
                        if !(_silent) then {
                            if (_automessages) then {
                                private _msg = format ["%1 is capturing %2!",EGVAR(Core,TeamName_Opfor),_zoneName];
                                _msg remoteExec ["hintsilent"];
                            } else {
                                (_opformessageArray select 0) remoteExec ["hintsilent"];
                            };
                        };
                    };
                };
                case "Indfor": {
                    if (_owner isEqualto _oldOwner) then {
                        if (_indforCapMode isEqualTo 0) then {
                            _argNested set [6,(_ownerControlCount + 1)];
                            if ((_argNested select 6) > (_timeArray select 2)) then {
                                //message is blufor has captured
                                if !(_hidden) then {
                                    _marker setMarkerColor _indforcolour;
                                    _marker setMarkerAlpha 0.5;
                                };
                                if !(_silent) then {
                                    if (_automessages) then {
                                        private _msg = format ["%1 has captured %2!",EGVAR(Core,TeamName_Indfor),_zoneName];
                                        _msg remoteExec ["hintsilent"];
                                    } else {
                                        (_indformessageArray select 1) remoteExec ["hintsilent"];
                                    };
                                };
                                MissionNamespace setvariable [_varName,true];
                                MissionNamespace setvariable [_teamControllingvarName,"Indfor"];
                                if (_mode isEqualto "ONCE") exitWith {
                                    if !(_hidden) then {
                                        _marker setMarkerAlpha 0.5;
                                        _marker setMarkerBrush "Border";
                                    };
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                                };
                            };
                        };
                    } else {
                        //message if blufor is capturing
                        _argNested set [5,_owner];
                        _argNested set [6,0];
                        if !(_hidden) then {
                            _marker setMarkerColor _indforcolour;
                            _marker setMarkerAlpha 0.25;
                        };
                        if !(_silent) then {
                            if (_automessages) then {
                                private _msg = format ["%1 is capturing %2!",EGVAR(Core,TeamName_Indfor),_zoneName];
                                _msg remoteExec ["hintsilent"];
                            } else {
                                (_indformessageArray select 0) remoteExec ["hintsilent"];
                            };
                        };
                    };
                };
                case "CIVILIAN": {
                    if (_owner isEqualto _oldOwner) then {
                        if (_civCapMode isEqualTo 0) then {
                            _argNested set [6,(_ownerControlCount + 1)];
                            if ((_argNested select 6) > (_timeArray select 3)) then {
                                //message is blufor has captured
                                if !(_hidden) then {
                                    _marker setMarkerColor _CIVcolour;
                                    _marker setMarkerAlpha 0.5;
                                };
                                if !(_silent) then {
                                    if (_automessages) then {
                                        private _msg = format ["%1 has captured %2!",EGVAR(Core,TeamName_Civ),_zoneName];
                                        _msg remoteExec ["hintsilent"];
                                    } else {
                                        (_CIVmessageArray select 1) remoteExec ["hintsilent"];
                                    };
                                };
                                MissionNamespace setvariable [_varName,true];
                                MissionNamespace setvariable [_teamControllingvarName,"CIVILIAN"];
                                if (_mode isEqualto "ONCE") exitWith {
                                    if !(_hidden) then {
                                        _marker setMarkerAlpha 0.5;
                                        _marker setMarkerBrush "Border";
                                    };
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                                };
                            };
                        };
                    } else {
                        _argNested set [5,_owner];
                        _argNested set [6,0];
                        if !(_hidden) then {
                            _marker setMarkerColor _CIVcolour;
                            _marker setMarkerAlpha 0.25;
                        };
                        if !(_silent) then {
                            if (_automessages) then {
                                private _msg = format ["%1 is capturing %2!",EGVAR(Core,TeamName_Civ),_zoneName];
                                _msg remoteExec ["hintsilent"];
                            } else {
                                (_CIVmessageArray select 0) remoteExec ["hintsilent"];
                            };
                        };
                    };
                };
                default {
                    _owner = "UNCONTESTED";
                    if !(_owner isEqualto _oldOwner) then {
                        _argNested set [5,_owner];
                        _argNested set [6,0];
                        if !(_hidden) then {
                            _marker setMarkerColor _uncontestedcolour;
                            _marker setMarkerAlpha 0.25;
                        };
                        if !(_silent) then {
                            if (_automessages) then {
                                private _msg = format ["%1 is uncontested!",_zoneName];
                                _msg remoteExec ["hintsilent"];
                            } else {
                                _uncontestedmessage remoteExec ["hintsilent"];
                            };
                        };
                    };
                };
            };
        } else {
            //not enough of a ratio to gain control!
            _owner = "CONTESTED";
            if !(_owner isEqualto _oldOwner) then {
                _argNested set [6,0];
                _argNested set [5,_owner];
                if !(_hidden) then {
                    _marker setMarkerColor _contestedcolour;
                    _marker setMarkerAlpha 0.25;
                };
                if !(_silent) then {
                    if (_automessages) then {
                        private _msg = format ["%1 is contested!",_zoneName];
                        _msg remoteExec ["hintsilent"];
                    } else {
                        _contestedmessage remoteExec ["hintsilent"];
                    };
                };
                MissionNamespace setvariable [_varName,false];
                MissionNamespace setvariable [_teamControllingvarName,"CONTESTED"];
            };
        };
    };


}, 1, [_this,(-99),false,_varName,_teamControllingvarName]] call CBA_fnc_addPerFrameHandler;
