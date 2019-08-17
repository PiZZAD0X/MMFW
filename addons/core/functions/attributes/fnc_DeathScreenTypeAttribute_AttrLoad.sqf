#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

private _ctrlCombo = (_ctrl controlsGroupCtrl 100);
_ctrlCombo setvariable [QGVAR(parentcontrolcfg),_config];
private _AOSystemTypes = [
    ["Fade on Damage","FADE"],
    ["Instant","INSTANT"],
    ["VR Exit","VR"]
];

{
    _x params ["_name","_string"];
    private _index = _ctrlCombo lbadd _name;
    _ctrlCombo lbsetdata [_index,_string];
    if (_value isEqualto (_ctrlCombo lbData _index)) then {
        _ctrlCombo lbSetCurSel _index;
    };
} foreach _AOSystemTypes;
