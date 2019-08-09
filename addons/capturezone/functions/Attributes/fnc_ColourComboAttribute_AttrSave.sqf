#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _control = (_ctrl controlsGroupCtrl 100);
private _config = _control getvariable [QGVAR(parentcontrolcfg),""];
private _attProperty = getText (_config >> "property");
private _value = (_control lbData lbCurSel _control);
missionNamespace setvariable [_attProperty,_value];
_value
