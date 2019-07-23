#include "script_component.hpp"
EDEN_CHECK;

params ["_args","_configVar","_valueVar"];
_args params ["_ctrlCombo"];

[{!((missionNamespace getvariable [(_this select 1),""]) isEqualto "")}, {
    params ["_ctrlCombo","_varName","_cfgVarName"];
    private _configstr = missionNamespace getvariable [_cfgVarName,""];
    private _configH = configHierarchy _configstr;
    private _configHParent = _configH select ((count _configH) - 2);
    private _cfgAttributes = [_configHParent,0] call BIS_fnc_returnChildren;
    private _respawnType = missionNamespace getvariable [_varName,0];
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
    private _n = 0;
    {
        if (ctrlParentControlsGroup _x == _ctrlGroup) then {\
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
}, [_ctrlCombo,_valueVar,_configVar]] call CBA_fnc_waitUntilAndExecute;
