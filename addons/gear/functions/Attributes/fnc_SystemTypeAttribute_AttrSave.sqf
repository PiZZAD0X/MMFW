#include "script_component.hpp"
EDEN_CHECK;

params ["_control"];

private _value = (_control controlsGroupCtrl 100) lbData lbCurSel (_control controlsGroupCtrl 100);
private _unit = ((get3denselected 'object') select 0);
SETVAR(_unit,UnitSystemType,_value);
_value
