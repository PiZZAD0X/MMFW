
#include "script_component.hpp"
EDEN_CHECK;

LOG_1("_this: %1",_this);
params ["_args","_configVar","_valueVar"];
_args params ["_ctrlCombo","_cursel"];

private _respawnType = _ctrlCombo lbValue _cursel;
diag_log format ["combo new var onsel: %1",_respawnType];
private _configstr = missionNamespace getvariable [_configVar,""];
private _configH = configHierarchy _configstr;
private _configHParent = _configH select ((count _configH) - 2);
private _cfgAttributes = [_configHParent,0] call BIS_fnc_returnChildren;
missionNamespace setvariable [_valueVar,_respawnType];
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
private _n = 0;
{
    if (ctrlParentControlsGroup _x == _ctrlGroup) then {
        private _cfg = _cfgAttributes select _n;
        private _respawnTypes = getarray (_cfg >> "respawnTypes");
        private _state = ((count _respawnTypes == 0) || (_respawnType in _respawnTypes));
        private _fade = [0.75,0] select _state;
        _n = _n + 1;
        _x ctrlenable _state;
        _x ctrlsetfade _fade;
        _x ctrlcommit 0;
        ctrlsetfocus _x;
        ctrlsetfocus _ctrlCombo;
    };
} foreach (allcontrols (ctrlparent _ctrlCombo));
