#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlEdit = _ctrlGroup controlsgroupctrl 100;
private _name = ctrlText _ctrlEdit;

private _loadoutList = (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []]);
private _profileArray = profileNamespace getvariable [QGVAR(ProfileLoadoutSettingsArray),[]];
if (_profileArray isEqualto []) exitwith {};
private _found = false;
{
    _x params ["_nameArray","_loadoutListArray"];
    if (_nameArray isEqualto _name) exitwith {
        _found = true;
        if (_loadoutList isEqualTo []) then {
            missionNamespace setVariable ["ace_arsenal_defaultLoadoutsList", _loadoutListArray];
        } else {
            ace_arsenal_defaultLoadoutsList append _loadoutListArray;
        };
        LOG_1("Loaded %1 Loadout Preset from Profile!",_name);
    };
} foreach _profileArray;
if !(_found) exitwith {
    ERROR_1("%1 Loadout Preset not found in Profile!",_name);
};
