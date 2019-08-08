
#include "script_component.hpp"
EDEN_CHECK;

LOG("SystemTypeAttribute_onSelChange started");

params ["_ctrl","_cursel"];
TRACE_2("SystemTypeAttribute_onSelChange",_ctrlCombo,_cursel);

private _ctrlCombo = _ctrl select 0;
private _GearSystem = _ctrlCombo lbData _cursel;
private _unit = ((get3denselected 'object') select 0);
SETVAR(_unit,UnitSystemType,_GearSystem);
private _n = 0;
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
private _cfgAttributes = [configFile >> 'Cfg3den' >> 'Object' >> 'AttributeCategories' >> QGVAR(UnitCategory) >> 'Attributes',0] call BIS_fnc_returnChildren;
{
    if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {
        private _cfg = _cfgAttributes select _n;
        _n = _n + 1;
        private _state = true;
        if (isArray(_cfg >> 'GearSystems')) then {
            private _GearSystems = getarray (_cfg >> 'GearSystems');
            if !(_gearSystem in _GearSystems) then {
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
