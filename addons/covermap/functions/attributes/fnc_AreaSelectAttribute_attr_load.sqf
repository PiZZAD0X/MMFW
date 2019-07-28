#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config",["_playerMode",false,[false]]];

private _unit = ((get3denselected "object") select 0);
private _cfgname = gettext (_config >> "property");
_unit setvariable [_cfgname,_value];
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable ["parentcontrolcfg",_config];
private _CoverMapModules = (all3DENEntities select 3) select {_x isKindOf QGVAR(Module)};
if (_CoverMapModules isEqualTo []) exitwith {
    ERROR("No CoverMap Modules Found!");
    private _name = "No Modules Found";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    _ctrlCombo lbSetCurSel _index;
};

private _CoverMapModulesList = [];
{
    private _logic = _x;
    private _AreaName = (_logic get3DENAttribute QGVAR(AOName)) select 0;
    if (_AreaName in _CoverMapModulesList) then {
        ERROR_1("Duplicate AreaName for Covermap AO %1",_AreaName);
    } else {
        _CoverMapModulesList append [_AreaName];
    };
} foreach _CoverMapModules;

if (_playerMode) then {
    private _name = "Side Default AO";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} else {
    private _name = "No Area Selected";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
};

{
    private _name = _x;
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _CoverMapModulesList;
