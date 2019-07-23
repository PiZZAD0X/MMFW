#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _control = (_ctrl controlsGroupCtrl 100);
private _name = gettext (_config >> 'property');
private _unit = ((get3denselected 'object') select 0);
private _behaviorArray = ['Unchanged','Careless','Safe','Aware','Combat','Stealth'];
{
    private _index = _control lbadd _x;
    _control lbsetdata [_index,_x];
    _control lbsetValue [_index,_foreachIndex];
    if (_value isEqualto (_control lbData _index)) then {
        _control lbSetCurSel _index;
        _unit setvariable [_name,_value];
    };
} foreach _behaviorArray;
