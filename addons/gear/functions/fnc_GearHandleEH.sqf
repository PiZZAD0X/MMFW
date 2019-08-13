#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

if !(GETMVAR(GearHandle,false)) exitwith {};

params ["_object"];

if (GETVAR(_object,UnitSystemType,"NONE") isEqualto "NONE") exitwith {};
if (GETVAR(_object,UnitGearType,"NONE") isEqualto "NONE") exitwith {};

[_object] call FUNC(GearTypeLoad3DEN);
