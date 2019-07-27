#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj","_value"];
if !(local _obj) exitWith {};
if (_value isEqualTo 1) exitwith {};

[{!isNull (_this select 0)},{
    switch (_value) do {
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
}, [_obj,_value]] call CBA_fnc_waitUntilandExecute;
