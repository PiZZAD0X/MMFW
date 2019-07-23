#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_value"];

private _unit = ((get3denselected "object") select 0);
private _config = _control getvariable ["ParentCfg",""];
private _name = gettext (_config >> "property");
_unit setvariable [_name,_value];
