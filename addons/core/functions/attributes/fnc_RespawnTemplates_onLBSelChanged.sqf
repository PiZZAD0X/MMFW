
#include "script_component.hpp"
EDEN_CHECK;

LOG_1("_this: %1",_this);
params ["_ctrlListbox","_cursel"];

private _active = _ctrlListbox lbvalue _cursel;
LOG_1("_active: %1",_active);
_active = (_active + 1) % 2;
LOG_1("_active: %1",_active);
private _pictureChecked = gettext (configfile >> "ctrlCheckbox" >> "textureChecked");
private _pictureUnchecked = gettext (configfile >> "ctrlCheckbox" >> "textureUnchecked");
_ctrlListbox lbsetvalue [_cursel,_active];
_ctrlListbox lbsetpicture [_cursel,[_pictureUnchecked,_pictureChecked] select _active];
