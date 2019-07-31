#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj","_value"];
if !(local _obj) exitWith {};
TRACE_2("initPostDraggable",_obj,_value);

switch (_value) do {
    case 0: {
        [_obj, false] call ace_dragging_fnc_setDraggable;
    };
    case 1: {
        [_obj, true] call ace_dragging_fnc_setDraggable;
    };
    case 2: {
        private _config = configFile >> "CfgVehicles" >> typeOf _obj;
        private _position = [0,0,0];
        private _direction = 0;
        if (getNumber (_config >> "ace_dragging_canDrag") isEqualTo 1) then {
            _position = getArray (_config >> "ace_dragging_dragPosition");
            _direction = getNumber (_config >> "ace_dragging_dragDirection");
        };
        private _dragPosition = _obj getvariable ["ace_dragging_dragPosition",_position];
        private _dragDirection = _obj getvariable ["ace_dragging_dragDirection",_direction];
        [_obj, true, _dragPosition, _dragDirection, true] call ace_dragging_fnc_setDraggable;
    };
    default {};
};
