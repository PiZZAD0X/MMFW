#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(InitEvent), {
    if !(GETMVAR(Enabled,false)) exitWith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Cover Map", "Covers map except specified area, allows switching between multiple AOs", "Blackhawk and PIZZADOX"]] call CBA_fnc_localEvent;
    [{(!isNull player)}, {
        private ["_DefaultAO"];
        if !((GETPLVAR(UnitDefaultAO,"")) isEqualto "") then {
            _DefaultAO = GETPLVAR(UnitDefaultAO,"");
            _DefaultAO = toLower(_DefaultAO);
            //IGNORE_PRIVATE_WARNING ["_x"];
            if ((GVAR(AOArray) findif {_DefaultAO isEqualto (_x select 0)}) isEqualto -1) exitwith {
                ERROR_2("Default CoverMap for unit: %1 area: %2 does not exist!",player,_DefaultAO);
            };
        } else {
            switch (side player) do {
                case west: {
                    _DefaultAO = (GETMVAR(DefaultAO_BLUFOR,""));
                    _DefaultAO = toLower(_DefaultAO);
                    if (_DefaultAO isEqualto "") exitwith {
                        ERROR("No Default BLUFOR Area defined for CoverMap!");
                    };
                    if (((GVAR(AOArray)) findif {_DefaultAO isEqualto (_x select 0)}) isEqualto -1) exitwith {
                        ERROR_1("Default CoverMap BLUFOR area: %1 does not exist!",_DefaultAO);
                    };
                };
                case east: {
                    _DefaultAO = (GETMVAR(DefaultAO_OPFOR,""));
                    _DefaultAO = toLower(_DefaultAO);
                    if (_DefaultAO isEqualto "") exitwith {
                        ERROR("No Default OPFOR Area defined for CoverMap!");
                    };
                    if ((GVAR(AOArray) findif {_DefaultAO isEqualto (_x select 0)}) isEqualto -1) exitwith {
                        ERROR_1("Default CoverMap OPFOR area: %1 does not exist!",_DefaultAO);
                    };
                };
                case independent: {
                    _DefaultAO = (GETMVAR(DefaultAO_Indfor,""));
                    _DefaultAO = toLower(_DefaultAO);
                    if (_DefaultAO isEqualto "") exitwith {
                        ERROR("No Default Indfor Area defined for CoverMap!");
                    };
                    if ((GVAR(AOArray) findif {_DefaultAO isEqualto (_x select 0)}) isEqualto -1) exitwith {
                        ERROR_1("Default CoverMap Indfor area: %1 does not exist!",_DefaultAO);
                    };
                };
                case civilian: {
                    _DefaultAO = (GETMVAR(DefaultAO_Civ,""));
                    _DefaultAO = toLower(_DefaultAO);
                    if (_DefaultAO isEqualto "") exitwith {
                        ERROR("No Default Civilian Area defined for CoverMap!");
                    };
                    if ((GVAR(AOArray) findif {_DefaultAO isEqualto (_x select 0)}) isEqualto -1) exitwith {
                        ERROR_1("Default CoverMap Civilian area: %1 does not exist!",_DefaultAO);
                    };
                };
                default {};
            };
        };

        GVAR(currentAO) = _DefaultAO;
        [_DefaultAO] call FUNC(Briefing);

        [{(visibleMap)},{
            _this call FUNC(Live);
        },_DefaultAO] call CBA_fnc_waitUntilAndExecute;
    }] call CBA_fnc_waitUntilAndExecute;

    [{((!isNull player) && {CBA_missionTime > 1})}, {
        if (GETMVAR(AllowSwitching,false)) then {
            if !((GETPLVAR(UnitAONameArray,[])) isEqualto []) then {
                private _MapChangeMenu = ["MapChangeMenu", "Switch Map", "", {}, {true}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions","ACE_Equipment"], _MapChangeMenu] call ace_interact_menu_fnc_addActionToObject;
                private ["_ActionArray"];
                if (isNil "_ActionArray") then {
                    _ActionArray = [];
                };
                {
                    private _AONameAllowed = toLower(_x);
                    {
                        _x params ["_AOName"];
                        if ((_AONameAllowed isEqualto _AOName) && {!(_AONameAllowed in _ActionArray)}) then {
                            private _condition = {
                                params ["", "", "_params"];
                                (visibleMap) && {!(GVAR(currentAO) isEqualto (_params select 0))} && {(GETMVAR(AllowSwitching,false))}
                            };
                            private _statement = {
                                params ["", "", "_params"];
                                [(_params select 0)] call FUNC(Live);
                            };
                            private _tempAction = ["switch_MapAO", ("Switch Map to " + _AONameAllowed), "", _statement, _condition, {}, [_AONameAllowed]] call ace_interact_menu_fnc_createAction;
                            [player, 1, ["ACE_SelfActions","ACE_Equipment","MapChangeMenu"], _tempAction] call ace_interact_menu_fnc_addActionToObject;
                            _ActionArray pushback _AONameAllowed;
                            LOG_1("CoverMap action added for area: %1",_AONameAllowed);
                        };
                    } foreach GVAR(AOArray);
                } foreach (GETPLVAR(UnitAONameArray,[]));
            };
        };
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    if !(GETMVAR(Enable,false)) exitWith {};
    [QGVAR(InitEvent), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
