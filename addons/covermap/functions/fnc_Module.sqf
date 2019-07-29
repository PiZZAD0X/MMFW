#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        if !(GETMVAR(Enabled,false)) exitWith {};
        _input params ["_logic"];
        LOG_1("Starting Module function for CoverMap %1",_logic);
        if (is3den) then {
            private _CoverMapModules = (all3DENEntities select 3) select {_x isKindOf QGVAR(Module)};
            private _CoverMapModulesList = [];
            private _compareList = (_CoverMapModules - [_logic]);
            LOG_2("_logic: %1 _compareList: %2",_logic,_compareList);
            {
                private _AreaName = (_x get3DENAttribute QGVAR(AOName)) select 0;
                if !(_AreaName in _CoverMapModulesList) then {
                    _CoverMapModulesList append [_AreaName];
                };
            } foreach _compareList;
            LOG_2("_logic: %1 _CoverMapModulesList: %2",_logic,_CoverMapModulesList);
            private _AreaName = (_logic get3DENAttribute QGVAR(AOName)) select 0;
            if (_AreaName in _CoverMapModulesList) exitwith {
                ERROR_1("Duplicate AOName for CoverMap Area %1",_AreaName);
                [_AreaName,_logic,_CoverMapModulesList] spawn {
                    params ["_AreaName","_logic","_CoverMapModulesList"];
                    private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                    if (_result) then {
                        for "_i" from 1 to (count _CoverMapModulesList) step 1 do {
                            private _newName = format ["Area_%1",_i];
                            LOG_3("logic %1 newName %2 currentList %3",_logic,_newName,_CoverMapModulesList);
                            if !(_newName in _CoverMapModulesList) exitwith {
                                _logic set3DENAttribute [QGVAR(AOName), _newName];
                                LOG_2("Renamed %1 to %2",_logic,_newName);
                            };
                        };
                    };
                };
            };
        } else {
            private _AOName = GETVAR(_logic,AOName,"Area0");
            private _AOZoom = GETVAR(_logic,ZoomLevel,0.4);
            private _loc = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100]];
            _size params ["_radiusX","_radiusY"];
            private _direction = getdir _logic;
            private _area = [_loc,_radiusX,_radiusY,_direction,true];
            if (isNil QGVAR(AOArray)) then {
                GVAR(AOArray) = [[_AOName,_area,_AOZoom,_logic]];
            } else {
                GVAR(AOArray) pushback [_AOName,_area,_AOZoom,_logic];
            };
            publicvariable QGVAR(AOArray);
        };
    };
    case "attributesChanged3DEN": {
        _input params ["_logic"];
        private _CoverMapModules = (all3DENEntities select 3) select {_x isKindOf QGVAR(Module)};
        private _CoverMapModulesList = [];
        private _compareList = (_CoverMapModules - [_logic]);
        LOG_2("_logic: %1 _compareList: %2",_logic,_compareList);
        {
            private _AreaName = (_x get3DENAttribute QGVAR(AOName)) select 0;
            if !(_AreaName in _CoverMapModulesList) then {
                _CoverMapModulesList append [_AreaName];
            };
        } foreach _compareList;
        LOG_2("_logic: %1 _CoverMapModulesList: %2",_logic,_CoverMapModulesList);
        private _AreaName = (_logic get3DENAttribute QGVAR(AOName)) select 0;
        if (_AreaName in _CoverMapModulesList) exitwith {
            ERROR_1("Duplicate AOName for CoverMap Area %1",_AreaName);
            [_AreaName,_logic,_CoverMapModulesList] spawn {
                params ["_AreaName","_logic","_CoverMapModulesList"];
                private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                if (_result) then {
                    for "_i" from 1 to (count _CoverMapModulesList) step 1 do {
                        private _newName = format ["Area_%1",_i];
                        LOG_3("logic %1 newName %2 currentList %3",_logic,_newName,_CoverMapModulesList);
                        if !(_newName in _CoverMapModulesList) exitwith {
                            _logic set3DENAttribute [QGVAR(AOName), _newName];
                            LOG_2("Renamed %1 to %2",_logic,_newName);
                        };
                    };
                };
            };
        };
    };
    default {};
};
true
