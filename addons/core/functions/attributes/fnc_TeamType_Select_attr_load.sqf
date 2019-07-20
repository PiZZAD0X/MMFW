#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _name = gettext (_config >> "property");
missionNamespace setvariable [_name,_value];
private _control = (_ctrl controlsGroupCtrl 100);
_control setvariable [QGVAR(ParentCfg),_config];
_control lbsetcursel _value;
