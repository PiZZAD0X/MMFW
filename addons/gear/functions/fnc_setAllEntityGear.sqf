#include "script_component.hpp"
EDEN_CHECK;

(all3DENEntities select 0) apply {
    private _object = _x;
    if !(GETVAR(_object,UnitSystemType,"NONE") isEqualto "NONE") then {
        if !(GETVAR(_object,UnitGearType,"NONE") isEqualto "NONE") then {
            [_object] call FUNC(GearTypeLoad3DEN);
        };
    };
};
