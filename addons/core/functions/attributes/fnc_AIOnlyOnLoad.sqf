#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

private _unit = ((get3denselected 'object') select 0);
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrl;
private ['_isUnitPlayable'];
{
    if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {
        if !(isNull player) then {
             _isUnitPlayable = ((_unit in playableUnits) || (_unit isEqualto player));
        } else {
             _isUnitPlayable = (_unit in playableUnits);
        };
        private _state = [true,false] select (_isUnitPlayable);
        private _fade = [0.75,0] select _state;
        _x ctrlenable _state;
        _x ctrlsetfade _fade;
        _x ctrlshow _state;
        _x ctrlcommit 0;
        ctrlsetfocus _x;
        ctrlsetfocus _ctrl;
    };
} foreach (allcontrols (ctrlparent _ctrl));
