#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _logic = ((get3denselected "logic") select 0);
private _cfgname = gettext (_config >> "property");
_logic setvariable [_cfgname,_value];
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable [QGVAR(parentcontrolcfg),_config];
private _AOSystemTypes = [["Hard","HARD"],["Soft","SOFT"]];
{
    _x params ["_name","_string"];
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_string];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _AOSystemTypes;
