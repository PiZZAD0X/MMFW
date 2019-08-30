#include "script_component.hpp"
EDEN_CHECK;

params ["_args","_config","_valueVar","_configVar"];
_args params ["_ctrl"];

private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
private _value = (_ctrlCombo lbValue lbCurSel _ctrlCombo);
missionNamespace setvariable [_configVar,_value];
missionNamespace setvariable [_valueVar,_config];
_value
