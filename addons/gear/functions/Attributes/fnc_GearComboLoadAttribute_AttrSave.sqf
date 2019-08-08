
#include "script_component.hpp"
EDEN_CHECK;

LOG("GearComboLoadAttribute_AttrSave started");

private _value = ((_this controlsGroupCtrl 100) lbData lbCurSel (_this controlsGroupCtrl 100));
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,UnitGearType,_value);
_value
