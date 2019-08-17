#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];
TRACE_1("",_value);

private _unit = ((get3denselected "object") select 0);
private _cfgname = gettext (_config >> "property");
_unit setvariable [_cfgname,_value];
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable [QGVAR(parentcontrolcfg),_config];
private _ExtractModules = (all3DENEntities select 3) select {(_x isKindOf QEGVAR(EndConditions,ExtractModule)) || (_x isKindOf QEGVAR(EndConditions,ExtractModule_R))};
if (_ExtractModules isEqualTo []) exitwith {
    ERROR("No Extraction Areas Found!");
    private _name = "No Extract Areas Found";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,"No Area Selected"];
    _ctrlCombo lbSetCurSel _index;
};

private _ExtractModulesList = [];
{
    private _logic = _x;
    private _AreaName = (_logic get3DENAttribute QEGVAR(EndConditions,AreaName)) select 0;
    if (_AreaName in _ExtractModulesList) then {
        ERROR_1("Duplicate AreaName for Extract Area %1",_AreaName);
    } else {
        _ExtractModulesList append [_AreaName];
    };
} foreach _ExtractModules;

private _name = "No Area Selected";
private _index = _ctrlCombo lbadd _name;
_ctrlCombo lbsetdata [_index,_name];
if (_value isEqualto (_ctrlCombo lbData _index) || (_value isEqualto "No Area Selected")) then {
    _ctrlCombo lbSetCurSel _index;
};

{
    private _name = _x;
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _ExtractModulesList;
