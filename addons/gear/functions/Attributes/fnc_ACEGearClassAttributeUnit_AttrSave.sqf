
#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _control = (_ctrl controlsGroupCtrl 100);
private _value = (_control lbData lbCurSel _control);
SETVAR(_unit,ManualUnitClass,_value);
_value
