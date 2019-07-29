#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_config"];

private _value = ((_ctrl controlsGroupCtrl 100) lbData lbCurSel (_ctrl controlsGroupCtrl 100));
private _unit = ((get3denselected "object") select 0);
private _name = gettext (_config >> 'property');
_unit setvariable [_name,_value];
_value
