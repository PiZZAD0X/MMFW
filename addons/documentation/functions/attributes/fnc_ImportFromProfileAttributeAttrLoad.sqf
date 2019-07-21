
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

//IGNORE_PRIVATE_WARNING ["_x"];

params ["_ctrl"];

private _control = _ctrl controlsgroupctrl 100;
private _profileArray = profileNamespace getvariable [QGVAR(ProfileSettingsArray),[]];
if (_profileArray isEqualto []) then {
    lbClear _control;
    private _placeholderIndex = _control lbadd 'No Settings Profiles Saved';
    _control lbsetdata [_placeholderIndex,'No Settings Profiles Saved'];
    _control lbSetCurSel _placeholderIndex;
} else {
    lbClear _control;
    private _placeholderIndex = _control lbadd 'None';
    _control lbsetdata [_placeholderIndex,'None'];
    {
        _x params ['_name'];
        private _index = _control lbadd _name;
        _control lbsetdata [_index,_name];
    } foreach _profileArray;
    _control lbSetCurSel _placeholderIndex;
};
