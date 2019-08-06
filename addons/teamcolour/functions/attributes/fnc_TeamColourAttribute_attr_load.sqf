#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _control = (_ctrl controlsGroupCtrl 100);
private _name = gettext (_config >> "property");
private _teamcolourarray = [["None",[0, 0, 0, 0]],["White",[1, 1, 1, 1]],["Red",[1, 0, 0, 1]],["Green",[0, 1, 0, 1]],["Blue",[0, 0, 1, 1]],["Yellow",[1, 1, 0, 1]]];
{
    _x params ["_name","_colour"];
    private _index = _control lbadd _name;
    _control lbsetdata [_index,_name];
    _control lbsetValue [_index,_foreachIndex];
    _control lbsetpicture [_index,"#(argb,8,8,3)color(1,1,1,1)"];
    _control lbsetpicturecolor [_index,_colour];
    _control lbsetpicturecolorselected [_index,_colour];
    if (_value isEqualto (_control lbData _index)) then {
        _control lbSetCurSel _index;
    };
} foreach _teamcolourarray;
