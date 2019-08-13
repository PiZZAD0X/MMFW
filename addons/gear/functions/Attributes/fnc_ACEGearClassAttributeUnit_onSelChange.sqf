
#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_cursel"];

private _unit = ((get3denselected "object") select 0);
private _lbValue = _control lbData _cursel;
SETVAR(_unit,ManualUnitClass,_lbValue);
