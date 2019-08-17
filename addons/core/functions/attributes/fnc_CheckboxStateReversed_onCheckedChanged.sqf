#include "script_component.hpp"
EDEN_CHECK;

_this spawn {
    params ["_ctrlCheckbox"];
    disableSerialization;
    private _state = [true,false] select (cbChecked _ctrlCheckbox);
    private _fade = [0.75,0] select _state;
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCheckbox;
    {
        if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {
            _x ctrlenable _state;
            _x ctrlsetfade _fade;
            _x ctrlcommit 0;
        };
    } foreach ((allcontrols (ctrlparent _ctrlCheckbox))- [ctrlParentControlsGroup _ctrlCheckbox]);
};
