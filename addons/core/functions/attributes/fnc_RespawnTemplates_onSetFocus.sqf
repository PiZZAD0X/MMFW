#include "script_component.hpp"
EDEN_CHECK;

params ["_args","_valuevar"];
_args params ["_ctrl"];

private _selectedRespawnType = missionNamespace getvariable [_valueVar,0];
private _ctrlGroup = ctrlparentcontrolsgroup _ctrl;
{
    private _ctrlListbox = _ctrlGroup controlsGroupCtrl (100 + _x);
    private _state = (_x == _selectedRespawnType);
    _ctrlListbox ctrlshow _state;
    _ctrlListbox ctrlenable _state;
} foreach [0,1,2,3,4,5];
