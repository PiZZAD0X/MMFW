
#include "script_component.hpp"
EDEN_CHECK;

params ["_control"];

private _ctrlGroup = ctrlParentControlsGroup _control;
private _ctrlCombo = _ctrlGroup controlsgroupctrl 100;
private _unit = ((get3denselected "object") select 0);
[_unit] call FUNC(GearTypeLoad3DEN);
