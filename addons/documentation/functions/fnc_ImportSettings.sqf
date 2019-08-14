#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlCombo = _ctrlGroup controlsgroupctrl 100;
private _name = _ctrlCombo lbData (lbCurSel _ctrlCombo);

private _profileArray = profileNamespace getvariable [QGVAR(ProfileSettingsArray),[]];
if (_profileArray isEqualto []) exitwith {};
private _found = false;
{
    _x params ["_nameArray","_settingsArray"];
    if (_nameArray isEqualto _name) exitwith {
        _found = true;
        {
            _x params ["_section","_class","_value"];
            LOG_3("_section: %1 _class: %2 _value: %3",_section,_class,_value);
            _section set3DENMissionAttribute [_class,_value];
        } foreach _settingsArray;
        LOG_1("Loaded %1 Settings Preset from Profile!",_name);
    };
} foreach _profileArray;
if !(_found) exitwith {
    ERROR_1("%1 Settings Preset not found in Profile!",_name);
};

[] call FUNC(BasicSettings3DEN);
