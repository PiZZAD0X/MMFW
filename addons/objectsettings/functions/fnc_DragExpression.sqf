#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj","_value"];
if !(local _obj) exitWith {};
if (_value isEqualTo 1) exitwith {};

[{!isNull (_this select 0)},{
    switch (_value) do {
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
}, [_obj,_value]] call CBA_fnc_waitUntilandExecute;
