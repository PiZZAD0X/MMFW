#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_team"];

private _ctrlButton = _ctrl select 0;
private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlCombo = _ctrlGroup controlsgroupctrl 100;
private _value = (_ctrlCombo lbData lbCurSel _ctrlCombo);
[_value,_team,_ctrlButton] call FUNC(GearLoadPreset);
