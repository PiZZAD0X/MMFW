
#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_config"];

private _value = ((_ctrl controlsGroupCtrl 100) lbData lbCurSel (_ctrl controlsGroupCtrl 100));
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,UnitGearType,_value);
_value
