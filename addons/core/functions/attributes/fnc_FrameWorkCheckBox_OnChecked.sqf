#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlCheckbox"];

private _state = cbChecked _ctrlCheckbox;
if (_state) then {
    [] call FUNC(3denEH);
};
