#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _unit = ((get3denselected "object") select 0);
private _cfgname = gettext (_config >> "property");
_unit setvariable [_cfgname,_value];
private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable [QGVAR(parentcontrolcfg),_config];
private _HostageModules = (all3DENEntities select 3) select {(_x isKindOf QGVAR(Module) || _x isKindOf QGVAR(Module_R))};
if (_HostageModules isEqualTo []) exitwith {
    ERROR("No Hostage Modules Found!");
    private _name = "No Modules Found";
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,"No Area Selected"];
    _ctrlCombo lbSetCurSel _index;
};

{
    private _logic = _x;
    private _AreaName = (_logic get3DENAttribute QGVAR(AreaName)) select 0;
    private _position = getPosATL _logic;
    private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
    _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
    private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];
    private _sendArray = [_AreaName,_area,_logic];
    if (isNil QGVAR(AreaArray)) then {
        GVAR(AreaArray) = [_sendArray];
    } else {
        private _index = GVAR(AreaArray) findIf {_x select 0 isEqualTo _AreaName};
        private _inArray = !(_index isEqualTo -1);
        LOG_2("_AreaName %1 _inArray %2",_AreaName,_inArray);
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
if (_value isEqualto (_ctrlCombo lbData _index) || (_value isEqualto "No Area Selected")) then {
    _ctrlCombo lbSetCurSel _index;
};

GVAR(AreaArray) apply {
    _x params ["_AreaName","_area","_logic"];
    private _index = _ctrlCombo lbadd _AreaName;
    _ctrlCombo lbsetdata [_index,_AreaName];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
};
