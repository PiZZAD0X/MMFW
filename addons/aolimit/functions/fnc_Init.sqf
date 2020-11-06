#include "script_component.hpp"

[QEGVAR(Core,RegisterModuleEvent), ["AO Limit", "Allows the mission maker to set AO limits to specific sides.", "Olsen, Sacher and PiZZADOX"]] call CBA_fnc_localEvent;
//[_logic,_area,_selectedSides,_entryMode,_airsetting,_AOMode,_softAOtime,_softAOtimeAir] passed array

[{(!(isNull player)) && {(CBA_missionTime > 1)}}, {
    params ["_args", "_unit"];
    _args params ["_logic","_area","_selectedSides","_entryMode","","_AOMode","",""];
    private ["_startedInside","_run","_arrayname","_enteredZone","_outSide"];
    if !((side _unit) in _selectedSides) exitwith {};
    private _softAOMode = ((toUpper _AOMode) isEqualto "SOFT");

    scopename "AOLimitMainSpawn";

    _run = false;

    if (isNil QGVAR(Array_1)) then {
        GVAR(Array_1) = [_area];
        GVAR(Arrays) = [GVAR(Array_1)];
        _arrayname = QGVAR(Array_1);
        _run = true;
    } else {
        GVAR(Arrays) apply {
            private _AOLimitArray = _x;
            if (({_logic inArea _x} count _AOLimitArray) > 0) exitwith {
                _AOLimitArray pushBackUnique _area;
                _run = false;
                breakOut "AOLimitMainSpawn";
            };
        };
        private _count = (count GVAR(Arrays));
        _arrayname = format ["##PREFIX##_AOLimit_Array_%1",_count];
        missionNamespace setvariable [_arrayname,[_area]];
        _run = true;
    };

    if ((count (missionNamespace getvariable _arrayname)) == 1) then {
        if ((vehicle _unit) inArea _area) then {
            _startedInside = true;
            _outSide = false;
            _enteredZone = true;
        } else {
            if !(_entryMode) exitwith {
                _run = false;
                //diag_log "exiting AO limit fnc, already one running!";
                breakOut "AOLimitMainSpawn";
            };
            _startedInside = false;
            _outSide = true;
            _enteredZone = false;
        };
    } else {
        if (({(vehicle _unit) inArea _x} count (missionNamespace getvariable _arrayname)) > 0) then {
            _startedInside = true;
            _outSide = false;
            _enteredZone = true;
        } else {
            if !(_entryMode) exitwith {
                _run = false;
                //diag_log "exiting AO limit fnc, already one running!";
                breakOut "AOLimitMainSpawn";
            };
            _startedInside = false;
            _outSide = true;
            _enteredZone = false;
        };
    };

    TRACE_3("unit starting",_outSide,_startedInside,_enteredZone);
    LOG("Starting AO Limit");

    if (_run) then {
        GVAR(PFHhandle) = [{
            params ["_argNested", "_idPFH"];
            _argNested params ["_unit","_args","_startedInside","_outSide","_enteredZone","_arrayname","_softAOMode","_recheckDead","_pos"];
            _args params ["","_area","","_entryMode","_airsetting","","_softAOtime","_softAOtimeAir"];

            TRACE_3("",_argNested,_area,(vehicle _unit));
            private _air = ((vehicle _unit) isKindOf "Air");
            if ((_airsetting) && {_air}) exitwith {};

            if ((count ((missionNamespace getvariable _arrayname))) isEqualto 1) then {
                if ((vehicle _unit) inArea _area) then {
                    LOG("unit in area");
                    _outSide = false;
                    _argNested set [3,_outSide];
                    _enteredZone = true;
                    _argNested set [4,_enteredZone];
                    if !(_softAOMode) then {
                        _pos = getPosATL (vehicle _unit);
                        _argNested set [8,_pos];
                    } else {
                        SETMVAR(Display,_outSide);
                    };
                } else {
                    LOG("unit outside area");
                    if ((!(_startedInside) && {(_enteredZone)}) || {(_startedInside)}) then {
                        LOG("unit outside area 2");
                        _outSide = true;
                        _argNested set [3,_outSide];
                        if !(_softAOMode) then {
                            (vehicle _unit) setVelocity [0,0,0];
                            (vehicle _unit) setPos _pos;
                        } else {
                            if !(GETMVAR(DisplayOpen,false)) then {
                                private _timeLeft = if (_air) then {_softAOtimeAir} else {_softAOtime};
                                SETMVAR(Display,_outSide);
                                SETMVAR(TimeLeft,_timeLeft);
                                QGVAR(Layer) cutRsc [QGVAR(SoftWarning), "PLAIN", 0.5, false];
                            };
                        };
                    };
                };
            } else {
                if (({(vehicle _unit) inArea _x} count (missionNamespace getvariable _arrayname)) > 0) then {
                    LOG("unit in area b");
                    _enteredZone = true;
                    _argNested set [4,_enteredZone];
                    _outSide = false;
                    _argNested set [3,_outSide];
                    if !(_softAOMode) then {
                        _pos = getPosATL (vehicle _unit);
                        _argNested set [8,_pos];
                    } else {
                        SETMVAR(Display,_outSide);
                    };
                } else {
                    LOG("unit outside area b");
                    if ((!(_startedInside) && {(_enteredZone)}) || {(_startedInside)}) then {
                        LOG("unit outside area b 2");
                        _outSide = true;
                        _argNested set [3,_outSide];
                        if !(_softAOMode) then {
                            (vehicle _unit) setVelocity [0,0,0];
                            (vehicle _unit) setPos _pos;
                        } else {
                            if !(GETMVAR(DisplayOpen,false)) then {
                                private _timeLeft = if (_air) then {_softAOtimeAir} else {_softAOtime};
                                SETMVAR(Display,_outSide);
                                SETMVAR(TimeLeft,_timeLeft);
                                QGVAR(Layer) cutRsc ["RscAOLimit", "PLAIN", 0.5, false];
                            };
                        };
                    };
                };
            };

            SETMVAR(Display,_outSide);

            if ((count (missionNamespace getvariable _arrayname)) == 1) then {
                if ((!(_startedInside) && {!_softAOMode} && {(_entryMode)} && {!((vehicle _unit) inArea _area)}) || {(_recheckDead && !_softAOMode)}) then {
                    _recheckDead = false;
                    _argNested set [7,_recheckDead];
                    _enteredZone = true;
                    _argNested set [4,_enteredZone];
                };
            } else {
                if ((({(vehicle _unit) inArea _x} count ((missionNamespace getvariable _arrayname)) < 1) && {!(_startedInside)} && {!_softAOMode} && {(_entryMode)}) || {(_recheckDead && !_softAOMode)}) then {
                    _recheckDead = false;
                    _argNested set [7,_recheckDead];
                    _enteredZone = true;
                    _argNested set [4,_enteredZone];
                };
            };

            if (!((vehicle _unit) call EFUNC(Core,isAlive)) && {!(_recheckDead)}) then {
                _recheckDead = true;
                _argNested set [7,_recheckDead];
                _enteredZone = false;
                _argNested set [4,_enteredZone];
            };

        }, 0, [_unit,_args,_startedInside,_outSide,_enteredZone,_arrayname,_softAOMode,false]] call CBA_fnc_addPerFrameHandler;
    };
}, [_this,player]] call CBA_fnc_waitUntilAndExecute;
