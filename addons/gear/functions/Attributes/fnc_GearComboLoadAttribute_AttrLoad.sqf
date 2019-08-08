
#include "script_component.hpp"
EDEN_CHECK;

LOG("GearComboLoadAttribute_AttrLoad started");

private _control = (_this controlsGroupCtrl 100);
_control setvariable [QGVAR(parentcontrolcfg),_config];
private _classArray = getArray(configFile >> QGVAR(Types) >> "typesArray");
private _name = "None";
private _className = "NONE";
private _index = (_control lbadd _name);
_control lbsetdata [_index,_className];
_control lbsetValue [_index,0];
if (_value isEqualto _className) then {
    _control lbSetCurSel _index;
    private _unit = ((get3denselected "object") select 0);
    SETVAR(_unit,UnitGearType,_value);
};
{
    private _className = _x;
    private _name = localize ("STR_" + QGVAR(DisplayName) + "_" + _className);
    private _index = (_control lbadd _name);
    _control lbsetdata [_index,_className];
    _control lbsetValue [_index,(_foreachIndex + 1)];
    if (_value isEqualto _className) then {
        _control lbSetCurSel _index;
        private _unit = ((get3denselected "object") select 0);
        SETVAR(_unit,UnitGearType,_value);
    };
} foreach _classArray;
private _name = "Manual";
private _className = "MANUAL";
private _index = (_control lbadd _name);
_control lbsetdata [_index,_className];
_control lbsetValue [_index,((count _classArray) + 1)];
if (_value isEqualto _className) then {
    _control lbSetCurSel _index;
    private _unit = ((get3denselected "object") select 0);
    SETVAR(_unit,UnitGearType,_value);
};
