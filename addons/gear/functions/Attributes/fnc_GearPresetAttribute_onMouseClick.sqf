
#include "script_component.hpp"
EDEN_CHECK;

LOG("GearPresetAttribute_onMouseClick started");
LOG_1("GearPresetAttribute_onMouseClick started, this: %1",_this);
params ["_originalThis","_args"];

private _ctrlButton = _originalThis select 0;
private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlCombo = _ctrlGroup controlsgroupctrl 100;
private _value = (_ctrlCombo lbData lbCurSel _ctrlCombo);
LOG_1("GearLoadPreset started, _value: %1",_value);
[_value,_args,_ctrlButton] call FUNC(GearLoadPreset);
