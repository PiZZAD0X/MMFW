#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _pictureChecked = gettext (configfile >> "ctrlCheckbox" >> "textureChecked");
private _pictureUnchecked = gettext (configfile >> "ctrlCheckbox" >> "textureUnchecked");
private _ctrlListbox = _ctrl controlsGroupCtrl 100;
{
    private _name = _x;
    private _lbAdd = _ctrlListbox lbadd _name;
    _ctrlListbox lbsetdata [_lbAdd,_name];
    private _active = _name in _value;
    _ctrlListbox lbsetvalue [_lbAdd,([0,1] select _active)];
    _ctrlListbox lbsetpicture [_lbAdd,([_pictureUnchecked,_pictureChecked] select _active)];
} foreach ["BLUFOR","OPFOR","INDFOR","CIVILIAN"];
