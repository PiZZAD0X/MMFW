#include "script_component.hpp"
EDEN_CHECK;

params ["_args","_valueVar","_configVar"];
_args params ["_ctrlCombo","_cursel"];
private _respawnType = _ctrlCombo lbValue _cursel;
missionNamespace setvariable [_valueVar,_respawnType];

[_args,_configVar,_valueVar] spawn {
    params ["_args","_configVar","_valueVar"];
    disableserialization;
    _args params ["_ctrlCombo","_cursel"];
    private _respawnType = _ctrlCombo lbValue _cursel;
    private _configstr = missionNamespace getvariable [_configVar,""];
    private _configH = configHierarchy _configstr;
    private _configHParent = _configH select ((count _configH) - 2);
    private _cfgAttributes = [_configHParent,0] call BIS_fnc_returnChildren;
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
    private _allControls = (allcontrols (ctrlparent _ctrlCombo)) select {ctrlParentControlsGroup _x isEqualto _ctrlGroup};
    private _n = 0;
    {
        private _cfg = _cfgAttributes select _n;
        private _ctrl = _x;
        _n = _n + 1;
        private _respawnTypes = getarray (_cfg >> "respawnTypes");
        private _state = ((_respawnTypes isEqualTo []) || (_respawnType in _respawnTypes));
        private _fade = [0.75,0] select _state;
        _ctrl ctrlenable _state;
        _ctrl ctrlsetfade _fade;
        _ctrl ctrlcommit 0;
        ctrlsetfocus _ctrl;
        ctrlsetfocus _ctrlCombo;
    } foreach _allControls;
};
