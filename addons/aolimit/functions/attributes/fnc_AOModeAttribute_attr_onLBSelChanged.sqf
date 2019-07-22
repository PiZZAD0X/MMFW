#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_ctrlCombo","_cursel"];
LOG_2("_ctrlCombo: %1 _cursel: %2",_ctrlCombo,_cursel);

private _AOType = _ctrlCombo lbData _cursel;
private _logic = ((get3denselected "logic") select 0);
private _logicType = typeOf _logic;
private _cfgAttributes = [configFile >> "CfgVehicles" >> _logicType >> "Attributes",0] call BIS_fnc_returnChildren;
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
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
