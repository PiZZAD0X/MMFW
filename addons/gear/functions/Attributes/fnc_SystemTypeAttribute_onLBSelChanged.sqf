#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlCombo","_cursel"];
private _GearSystem = _ctrlCombo lbData _cursel;
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,UnitSystemType,_GearSystem);

_this spawn {
    disableserialization;
    params ["_ctrlCombo","_cursel"];
    private _GearSystem = _ctrlCombo lbData _cursel;
    private _cfgAttributes = (configfile >> "Cfg3DEN" >> "Object" >> "AttributeCategories" >> QGVAR(UnitCategory) >> "Attributes");
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCombo;
    private _allControls = (allcontrols (ctrlparent _ctrlCombo)) select {ctrlParentControlsGroup _x isEqualto _ctrlGroup};
    private _n = 0;
    {
        private _cfg = _cfgAttributes select _n;
        private _ctrl = _x;
        _n = _n + 1;
        private _GearSystems = getarray (_cfg >> "GearSystems");
        private _state = ((_GearSystems isEqualTo []) || (_gearSystem in _GearSystems));
        private _fade = [0.75,0] select _state;
        _ctrl ctrlenable _state;
        _ctrl ctrlsetfade _fade;
        _ctrl ctrlcommit 0;
        ctrlsetfocus _ctrl;
        ctrlsetfocus _ctrlCombo;
    } foreach _allControls;
};
