#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_ctrl","_config"];

private _value = ((_ctrl controlsGroupCtrl 100) lbData lbCurSel (_ctrl controlsGroupCtrl 100));
private _cfgname = gettext (_config >> "property");
private _logic = ((get3denselected "logic") select 0);
_logic setvariable [_cfgname,_value];
_value
