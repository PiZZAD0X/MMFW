#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        EXEC_CHECK(ALL);
        _input params ["_logic",["_isActivated",true,[true]]];
        if (is3den) then {
            private _HostageModules = (all3DENEntities select 3) select {_x isKindOf QGVAR(Module)};
            private _HostageModulesList = [];
            private _compareList = (_HostageModules - [_logic]);
            TRACE_2("",_logic,_compareList);
            {
                private _AreaName = (_x get3DENAttribute QGVAR(AreaName)) select 0;
                if !(_AreaName in _HostageModulesList) then {
                    _HostageModulesList append [_AreaName];
                };
            } foreach _compareList;
            TRACE_2("",_logic,_HostageModulesList);
            private _AreaName = (_logic get3DENAttribute QGVAR(AreaName)) select 0;
            if (_AreaName in _HostageModulesList) exitwith {
                ERROR_1("Duplicate AreaName for Hostage Area %1",_AreaName);
                [_AreaName,_logic,_HostageModulesList] spawn {
                    params ["_AreaName","_logic","_HostageModulesList"];
                    private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                    if (_result) then {
                        for "_i" from 1 to (count _HostageModulesList) step 1 do {
                            private _newName = format ["Area_%1",_i];
                            TRACE_3("",_logic,_newName,_HostageModulesList);
                            if !(_newName in _HostageModulesList) exitwith {
                                _logic set3DENAttribute [QGVAR(AreaName), _newName];
                                TRACE_2("",_logic,_newName);
                            };
                        };
                    };
                };
            };
        } else {
            private _AreaName = GETVAR(_logic,AreaName,"Area0");
            private _position = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
            _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
            private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];
            private _sendArray = [_AreaName,_area,_logic];
            if (isNil QGVAR(AreaArray)) then {
                GVAR(AreaArray) = [_sendArray];
            } else {
                private _index = GVAR(AreaArray) findIf {_x select 0 isEqualTo _AreaName};
                private _inArray = !(_index isEqualTo -1);
                if (_inArray) then {
                    GVAR(AreaArray) set [_index,_sendArray];
                } else {
                    GVAR(AreaArray) pushback _sendArray;
                };
            };
            publicvariable QGVAR(AreaArray);
        };
    };
    case "attributesChanged3DEN": {
        _input params ["_logic",["_isActivated",true,[true]]];
        private _HostageModules = (all3DENEntities select 3) select {_x isKindOf QGVAR(Module)};
        private _HostageModulesList = [];
        private _compareList = (_HostageModules - [_logic]);
        TRACE_2("",_logic,_compareList);
        {
            private _AreaName = (_x get3DENAttribute QGVAR(AreaName)) select 0;
            if !(_AreaName in _HostageModulesList) then {
                _HostageModulesList append [_AreaName];
            };
        } foreach _compareList;
        TRACE_2("",_logic,_HostageModulesList);
        private _AreaName = (_logic get3DENAttribute QGVAR(AreaName)) select 0;
        if (_AreaName in _HostageModulesList) exitwith {
            ERROR_1("Duplicate AreaName for Hostage Area %1",_AreaName);
            [_AreaName,_logic,_HostageModulesList] spawn {
                params ["_AreaName","_logic","_HostageModulesList"];
                private _result = ["Area Name duplicate found, please rename one of the Areas", "Duplicate Area Name", "Rename?", true, (findDisplay 313)] call BIS_fnc_guiMessage;
                if (_result) then {
                    for "_i" from 1 to (count _HostageModulesList) step 1 do {
                        private _newName = format ["Area_%1",_i];
                        TRACE_3("",_logic,_newName,_HostageModulesList);
                        if !(_newName in _HostageModulesList) exitwith {
                            _logic set3DENAttribute [QGVAR(AreaName), _newName];
                            TRACE_2("",_logic,_newName);
                        };
                    };
                };
            };
        };
    };
    default {};
};
true
