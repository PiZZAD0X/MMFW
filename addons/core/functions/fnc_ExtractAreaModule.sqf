#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        if !(GETMVAR(Enabled,false)) exitWith {};
        _input params ["_logic",["_isActivated",true,[true]]];
        LOG_1("Starting Module function for Extract %1",_logic);
        if !(_isActivated) exitWith {};
        if (is3den) then {
            private _ExtractModules = (all3DENEntities select 3) select {(_x isKindOf QEGVAR(EndConditions,ExtractModule)) || (_x isKindOf QEGVAR(EndConditions,ExtractModule_R))};
            private _ExtractModulesList = [];
            private _compareList = (_ExtractModules - [_logic]);
            LOG_2("_logic: %1 _compareList: %2",_logic,_compareList);
            {
                private _AreaName = (_x get3DENAttribute QEGVAR(EndConditions,AreaName)) select 0;
                if !(_AreaName in _ExtractModulesList) then {
                    _ExtractModulesList append [_AreaName];
                };
            } foreach _compareList;
            LOG_2("_logic: %1 _ExtractModulesList: %2",_logic,_ExtractModulesList);
            private _AreaName = (_logic get3DENAttribute QEGVAR(EndConditions,AreaName)) select 0;
            if (_AreaName in _ExtractModulesList) exitwith {
                ERROR_1("Duplicate AreaName for Extract Area %1",_AreaName);
                [_AreaName,_logic,_ExtractModulesList] spawn {
                    params ["_AreaName","_logic","_ExtractModulesList"];
                    private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                    if (_result) then {
                        for "_i" from 1 to (count _ExtractModulesList) step 1 do {
                            private _newName = format ["ExtractArea_%1",_i];
                            LOG_3("logic %1 newName %2 currentList %3",_logic,_newName,_ExtractModulesList);
                            if !(_newName in _ExtractModulesList) exitwith {
                                _logic set3DENAttribute [QEGVAR(EndConditions,AreaName), _newName];
                                LOG_2("Renamed %1 to %2",_logic,_newName);
                            };
                        };
                    };
                };
            };
        } else {
            private _AreaName = EGETVAR(_logic,EndConditions,AreaName,"ExtractArea0");
            private _position = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
            _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
            private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];
            if (isNil QEGVAR(EndConditions,ExtractAreaArray)) then {
                EGVAR(EndConditions,ExtractAreaArray) = [[_AreaName,_area,_logic]];
            } else {
                EGVAR(EndConditions,ExtractAreaArray) pushback [_AreaName,_area,_logic];
            };
            publicvariable QEGVAR(EndConditions,ExtractAreaArray);
        };
    };
    case "attributesChanged3DEN": {
        _input params ["_logic",["_isActivated",true,[true]]];
        private _ExtractModules = (all3DENEntities select 3) select {(_x isKindOf QEGVAR(EndConditions,ExtractModule)) || (_x isKindOf QEGVAR(EndConditions,ExtractModule_R))};
        private _ExtractModulesList = [];
        private _compareList = (_ExtractModules - [_logic]);
        LOG_2("_logic: %1 _compareList: %2",_logic,_compareList);
        {
            private _AreaName = (_x get3DENAttribute QEGVAR(EndConditions,AreaName)) select 0;
            if !(_AreaName in _ExtractModulesList) then {
                _ExtractModulesList append [_AreaName];
            };
        } foreach _compareList;
        LOG_2("_logic: %1 _ExtractModulesList: %2",_logic,_ExtractModulesList);
        private _AreaName = (_logic get3DENAttribute QEGVAR(EndConditions,AreaName)) select 0;
        if (_AreaName in _ExtractModulesList) exitwith {
            ERROR_1("Duplicate AreaName for Extract Area %1",_AreaName);
            [_AreaName,_logic,_ExtractModulesList] spawn {
                params ["_AreaName","_logic","_ExtractModulesList"];
                private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                if (_result) then {
                    for "_i" from 1 to (count _ExtractModulesList) step 1 do {
                        private _newName = format ["ExtractArea_%1",_i];
                        LOG_3("logic %1 newName %2 currentList %3",_logic,_newName,_ExtractModulesList);
                        if !(_newName in _ExtractModulesList) exitwith {
                            _logic set3DENAttribute [QEGVAR(EndConditions,AreaName), _newName];
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
