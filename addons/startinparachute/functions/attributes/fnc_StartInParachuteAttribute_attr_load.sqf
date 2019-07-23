#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _unit = ((get3denselected "object") select 0);
private _name = gettext (_config >> "property");
_unit setvariable [_name,_value];
private _control = (_ctrl controlsGroupCtrl 100);
_control setvariable ["ParentCfg",_config];
_control lbsetcursel _value
