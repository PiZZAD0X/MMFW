#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _value = ctrlText (_ctrl controlsGroupCtrl 100);
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,UnitGearManualType,_value);
_value
