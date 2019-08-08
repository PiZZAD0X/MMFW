
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

params ["_object"];
LOG_1("_object: %1",_object);
LOG_1("_object UnitSystemType: %1",GETVAR(_object,UnitSystemType,"NONE"));
LOG_1("_object UnitGearType: %1",GETVAR(_object,UnitGearType,"NONE"));

if (GETVAR(_object,UnitSystemType,"NONE") isEqualto "NONE") exitwith {};
if (GETVAR(_object,UnitGearType,"NONE") isEqualto "NONE") exitwith {};

[_object] call FUNC(GearTypeLoad3DEN);
