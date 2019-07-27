#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _unit = ((get3denselected "object") select 0);
private _cfgname = gettext (_config >> "property");
_unit setvariable [_cfgname,_value];
LOG_2("hostageAreaAttribute Load started with %1, %2",_unit,_cfgname);
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable ["parentcontrolcfg",_config];
private _HostageModules = (all3DENEntities select 3) select {(_x isKindOf QGVAR(Module) || _x isKindOf QGVAR(Module_R))};
LOG_1("all3den select 3 %1",(all3DENEntities select 3));
LOG_1("_HostageModules %1",_HostageModules);
if (_HostageModules isEqualTo []) exitwith {
    ERROR("No Hostage Modules Found!");
    private _name = "No Modules Found";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    _ctrlCombo lbSetCurSel _index;
};

LOG_1("GVAR(AreaArray) %1",GVAR(AreaArray));
{
    private _logic = _x;
    private _AreaName = GETVAR(_logic,AreaName,"Area0");
    private _loc = getPosATL _logic;
    private _size = _logic getVariable ["objectArea", [100, 100]];
    _size params ["_radiusX","_radiusY"];
    private _direction = getdir _logic;
    private _area = [_loc,_radiusX,_radiusY,_direction,true];
    private _sendArray = [_AreaName,_area,_logic];
    if (isNil QGVAR(AreaArray)) then {
        GVAR(AreaArray) = [_sendArray];
    } else {
        private _index = [GVAR(AreaArray),_AreaName,0] call FUNC(searchNestedArray);
        private _inArray = if (_index isEqualTo -1) then {false} else {true};
        if (_inArray) then {
            GVAR(AreaArray) set [_index,_sendArray];
        } else {
            GVAR(AreaArray) pushback _sendArray;
        };
    };
} foreach _HostageModules;

private _name = "No Area Selected";
private _index = _ctrlCombo lbadd _name;
_ctrlCombo lbsetdata [_index,_name];
_ctrlCombo lbSetCurSel _index;

{
    _x params ["_AreaName","_area","_logic"];
    private _index = _ctrlCombo lbadd _AreaName;
    _ctrlCombo lbsetdata [_index,_AreaName];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach GVAR(AreaArray);
