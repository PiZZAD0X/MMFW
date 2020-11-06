#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        if !(GETMVAR(Enabled,false)) exitWith {};
        _input params ["_logic",["_isActivated",true,[true]]];
        LOG_1("Starting Module function for Extract %1",_logic);
        if !(_isActivated) exitWith {};
        private _handleHeight = GETVAR(_logic,HandleHeight,false);
        private _side = ["BLUFOR","OPFOR","INDFOR","CIVILIAN"] select (GETVAR(_logic,Side,0));
        SETPVAR(_logic,Side,_side);
        private _cond = compile GETVAR(_logic,Cond,"true");
        SETPVAR(_logic,Cond,_cond);
        private _position = getPosATL _logic;
        private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
        _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
        private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];
        SETPVAR(_logic,Area,_area);
        if ((GETMVAR(RespawnList,[])) isEqualTo []) then {
            GVAR(RespawnList) = [_logic];
        } else {
            GVAR(RespawnList) pushBackUnique _logic;
        };
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
