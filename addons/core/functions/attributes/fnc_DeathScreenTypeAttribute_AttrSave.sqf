#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_config"];

private _value = ((_ctrl controlsGroupCtrl 100) lbData lbCurSel (_ctrl controlsGroupCtrl 100));
_value
