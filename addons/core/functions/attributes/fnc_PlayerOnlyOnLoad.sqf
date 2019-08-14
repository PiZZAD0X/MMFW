#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

[_ctrl] spawn {
    disableSerialization;
    params ["_ctrl"];
    private _unit = ((get3denselected "object") select 0);
    private ["_isUnitPlayable"];
    if !(isNull player) then {
         _isUnitPlayable = ((_unit in playableUnits) || (_unit isEqualto player));
    } else {
         _isUnitPlayable = (_unit in playableUnits);
    };
    private _state = [false,true] select (_isUnitPlayable);
    private _fade = [0.75,0] select _state;
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrl;
    private _allControls = (allcontrols (ctrlparent _ctrl)) select {ctrlParentControlsGroup _x isEqualto _ctrlGroup};
    {
        private _name = ctrlClassName _x;
        private _isCategory = _name isEqualTo "Minimize";
        if (_isCategory && {!_state}) then {
            private _checked = cbChecked _x;
            if (_checked) then {
                ctrlActivate _x;
            };
        };
        _x ctrlenable _state;
        _x ctrlsetfade _fade;
        _x ctrlshow _state;
        _x ctrlcommit 0;
        ctrlsetfocus _x;
        ctrlsetfocus _ctrl;
    } foreach _allControls;
};
