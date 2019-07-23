#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _logic = ((get3denselected "logic") select 0);
private _cfgname = gettext (_config >> "property");
_logic setvariable [_cfgname,_value];
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable ["parentcontrolcfg",_config];
private _ctrlGroup = ctrlParentControlsGroup _ctrlCombo;
private _AOSystemTypes = [["Hard","HARD"],["Soft","SOFT"]];
{
    _x params ["_name","_string"];
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_string];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
        private _AOType = _value;
        private _configH = configHierarchy _config;
        private _configHParent = _configH select ((count _configH) - 2);
        private _cfgAttributes = [_configHParent,1] call BIS_fnc_returnChildren;
        private _n = 0;
        {
            if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {
                private _cfg = _cfgAttributes select _n;
                _n = _n + 1;
                private _state = true;
                if (isArray(_cfg >> "AOTypes")) then {
                    private _AOTypes = getarray (_cfg >> "AOTypes");
                    if !(_AOType in _AOTypes) then {
                        _state = _state && false;
                    };
                };
                private _fade = [0.75,0] select _state;
                _x ctrlenable _state;
                _x ctrlsetfade _fade;
                _x ctrlcommit 0;
                ctrlsetfocus _x;
                ctrlsetfocus _ctrlCombo;
            };
        } foreach (allcontrols (ctrlparent _ctrlCombo));
    };
} foreach _AOSystemTypes;
