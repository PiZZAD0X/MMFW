
#include "script_component.hpp"
EDEN_CHECK;

LOG("ACEGearClassAttributeonSel started");

private _control = _this select 0;
private _cursel = _this select 1;
private _lbValue = _control lbData _cursel;
private _config = _control getvariable [QGVAR(parentcontrolcfg),""];
private _attProperty = getText (_config >> "property");
missionNamespace setvariable [_attProperty,_lbValue];
