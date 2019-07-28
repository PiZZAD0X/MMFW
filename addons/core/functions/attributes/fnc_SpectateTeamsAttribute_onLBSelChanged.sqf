#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlListbox","_cursel"];

private _active = _ctrlListbox lbvalue _cursel;
_active = (_active + 1) % 2;
private _pictureChecked = gettext (configfile >> "ctrlCheckbox" >> "textureChecked");
private _pictureUnchecked = gettext (configfile >> "ctrlCheckbox" >> "textureUnchecked");
_ctrlListbox lbsetvalue [_cursel,_active];
_ctrlListbox lbsetpicture [_cursel,([_pictureUnchecked,_pictureChecked] select _active)];
