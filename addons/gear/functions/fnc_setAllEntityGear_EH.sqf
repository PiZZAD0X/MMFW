#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

if !(GETMVAR(GearHandle,false)) exitwith {};

{
    private _object = _x;
    if !(GETVAR(_object,UnitSystemType,"NONE") isEqualto "NONE") then {
        if !(GETVAR(_object,UnitGearType,"NONE") isEqualto "NONE") then {
            [_object] call FUNC(GearTypeLoad3DEN);
        };
    };
} foreach (all3DENEntities select 0);
