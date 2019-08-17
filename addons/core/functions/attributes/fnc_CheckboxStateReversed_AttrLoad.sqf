#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _ctrlCheckbox = (_ctrl controlsGroupCtrl 100);
_ctrlCheckbox cbSetChecked _value;
