#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        EXEC_CHECK(ALL);
        _input params ["_logic",["_isActivated",true,[true]]];
        private _AreaName = GETVAR(_logic,AreaName,"Area0");
        private _loc = getPosATL _logic;
        private _size = _logic getVariable ["objectArea", [100, 100]];
        _size params ["_radiusX","_radiusY"];
        private _direction = getdir _logic;
        private _area = [_loc,_radiusX,_radiusY,_direction,true];
        private _sendArray = [_AreaName,_area,_logic];
        if (isNil QGVAR(AreaArray)) then {
            GVAR(AreaArray) = [_sendArray];
        } else {
            private _index = [GVAR(AreaArray),_AreaName,0] call EFUNC(Core,searchNestedArray);
            private _inArray = if (_index isEqualTo -1) then {false} else {true};
            if (_inArray) then {
                GVAR(AreaArray) set [_index,_sendArray];
            } else {
                GVAR(AreaArray) pushback _sendArray;
            };
        };
        publicvariable QGVAR(AreaArray);
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
