#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_cursel"];

private _lbValue = _control lbData _cursel;
private _config = _control getvariable [QMGVAR(parentcontrolcfg),""];
private _attProperty = getText (_config >> "property");
missionNamespace setvariable [_attProperty,_lbValue];
