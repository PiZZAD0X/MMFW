#include "script_component.hpp"
EDEN_CHECK;

params ["_args","_value","_config","_valueVar","_configVar"];
_args params ["_ctrl"];

private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
missionNamespace setvariable [_valueVar,_value];
missionNamespace setvariable [_configVar,_config];
private _respawnSystemTypeArray = [['None',0],['Unlimited',1],['Individual Tickets',2],['Team Tickets',3]];
{
    _x params ['_name','_number'];
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_name];
    _ctrlCombo lbsetValue [_index,_number];
    if (_value isEqualto (_ctrlCombo lbValue _index)) then {\
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _respawnSystemTypeArray;
