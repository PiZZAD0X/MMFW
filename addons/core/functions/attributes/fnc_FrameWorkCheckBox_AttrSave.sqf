#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _checked = cbchecked (_ctrl controlsGroupCtrl 100);
if (_checked) then {
    [] call FUNC(3denEH);
};
_checked
