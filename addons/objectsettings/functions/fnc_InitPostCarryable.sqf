#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj","_value"];
if !(local _obj) exitWith {};
TRACE_2("initPostDraggable",_obj,_value);

switch (_value) do {
    case 0: {
        [_obj, false] call ace_dragging_fnc_setCarryable;
    };
    case 1: {
        [_obj, true] call ace_dragging_fnc_setCarryable;
    };
    case 2: {
        private _config = configFile >> "CfgVehicles" >> typeOf _obj;
        private _position = [0,1,1];
        private _direction = 0;
        if (getNumber (_config >> "ace_dragging_canCarry") isEqualTo 1) then {
            _position = getArray (_config >> "ace_dragging_carryPosition");
            _direction = getNumber (_config >> "ace_dragging_carryDirection");
        };
        private _carryPosition = _obj getvariable ["ace_dragging_carryPosition",_position];
        private _carryDirection = _obj getvariable ["ace_dragging_carryDirection",_direction];
        [_obj, true, _carryPosition, _carryDirection, true] call ace_dragging_fnc_setCarryable;
    };
    default {};
};
