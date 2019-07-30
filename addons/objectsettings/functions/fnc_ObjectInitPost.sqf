#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj"];
if !(local _obj) exitWith {};

private _carryValue = GETVAR(_obj,Carryable,1);
private _dragValue = GETVAR(_obj,Draggable,1);

if (_carryValue isEqualTo 1 && {_dragValue isEqualTo 1}) exitwith {};

switch (_carryValue) do {
    case 0: {
        [_this, false] call ace_dragging_fnc_setCarryable;
    };
    case 2: {
        private _carryPosition = _obj getvariable ["ace_dragging_carryPosition",[0,1,1]];
        private _carryDirection = _obj getvariable ["ace_dragging_carryDirection",0];
        [_this, true, _carryPosition, _carryDirection, true] call ace_dragging_fnc_setCarryable;
    };
    default {};
};

switch (_dragValue) do {
    case 0: {
        [_this, false] call ace_dragging_fnc_setDraggable;
    };
    case 2: {
        private _dragPosition = _obj getvariable ["ace_dragging_dragPosition",[0,1,1]];
        private _dragDirection = _obj getvariable ["ace_dragging_dragDirection",0];
        [_this, true, _dragPosition, _dragDirection, true] call ace_dragging_fnc_setDraggable;
    };
    default {};
};
