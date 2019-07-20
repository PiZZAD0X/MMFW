
#include "script_component.hpp"
EDEN_CHECK;

LOG_1("_this: %1",_this);
params ["_args","_valuevar"];
_args params ["_ctrl"];

diag_log format ["onsetfocus _args: %1",_args];
private _selectedRespawnType = missionNamespace getvariable [_valueVar,0];
diag_log format ["onsetfocus _valueVar: %1",_valueVar];
private _ctrlGroup = ctrlparentcontrolsgroup _ctrl;
diag_log format ["onsetfocus _selectedRespawnType: %1",_selectedRespawnType];
{
    private _ctrlListbox = _ctrlGroup controlsGroupCtrl (100 + _x);
    private _state = (_x == _selectedRespawnType);
    _ctrlListbox ctrlshow _state;
    _ctrlListbox ctrlenable _state;
} foreach [0,1,2,3,4,5];
