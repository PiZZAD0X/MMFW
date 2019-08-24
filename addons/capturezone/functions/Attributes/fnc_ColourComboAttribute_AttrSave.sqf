#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _control = (_ctrl controlsGroupCtrl 100);
private _config = _control getvariable [QGVAR(parentcontrolcfg),""];
private _value = (_control lbData lbCurSel _control);
if !(_config isEqualTo "") then {
    private _attProperty = getText (_config >> "property");
    missionNamespace setvariable [_attProperty,_value];
};
_value
