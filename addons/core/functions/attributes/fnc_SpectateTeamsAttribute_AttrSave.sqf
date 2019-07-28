#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_config"];

private _value = [];
private _ctrlListbox = _ctrl controlsGroupCtrl 100;
if (ctrlshown _ctrlListbox) then {
    for "_i" from 0 to (lbsize _ctrlListbox - 1) do {
        if (_ctrlListbox lbvalue _i > 0) then {
            _value pushback (_ctrlListbox lbdata _i);
        };
    };
};
_value
