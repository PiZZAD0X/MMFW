#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

params ["_object"];
LOG_1("GearHandle called for unit: %1",_object);

if !(GETMVAR(GearHandle,false)) exitwith {
    LOG_1("GearHandle disabled for unit: %1",_object);
};

if (GETVAR(_object,UnitSystemType,"NONE") isEqualto "NONE") exitwith {
    ERROR_1("No UnitSystemType found for unit: %1",_object);
};
if (GETVAR(_object,UnitGearType,"NONE") isEqualto "NONE") exitwith {
    ERROR_1("No UnitGearType found for unit: %1",_object);
};

[_object] call FUNC(GearTypeLoad3DEN);
