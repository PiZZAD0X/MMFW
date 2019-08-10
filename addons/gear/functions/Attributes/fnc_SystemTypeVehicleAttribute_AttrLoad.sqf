#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_value"];

private _unit = ((get3denselected "object") select 0);
private _ctrlCombo = (_control controlsGroupCtrl 100);
private _n = 0;
private _gearSystem = _value;
SETVAR(_unit,UnitSystemType,_GearSystem);
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
private _gearSystemTypes = [["None","NONE"],["Olsen","OLSEN"]];
{
    _x params ["_name","_string"];
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_string];
    _ctrlCombo lbsetValue [_index,_forEachIndex];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _gearSystemTypes;
private _cfgAttributes = [configFile >> "Cfg3den" >> "Object" >> "AttributeCategories" >> QGVAR(UnitCategory) >> "Attributes",0] call BIS_fnc_returnChildren;
{
     if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {
        private _cfg = _cfgAttributes select _n;
        _n = _n + 1;
        private _state = true;
        if (isArray(_cfg >> "GearSystems")) then {
            private _GearSystems = getarray (_cfg >> "GearSystems");
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
