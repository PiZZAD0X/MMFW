#include "script_component.hpp"
EDEN_CHECK;

//IGNORE_PRIVATE_WARNING ["_x"];

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlEdit = _ctrlGroup controlsgroupctrl 100;
private _name = ctrlText _ctrlEdit;

private _loadoutsList = (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []]);
if (_name isEqualto "") exitwith {};
private _profileArray = profileNamespace getvariable [QGVAR(ProfileLoadoutSettingsArray),[]];
if (_profileArray isEqualto []) then {
    _profileArray pushback [_name,_loadoutsList];
    profileNamespace setvariable [QGVAR(ProfileLoadoutSettingsArray),_profileArray];
    saveProfileNamespace;
} else {
    private _findIfResult = _profileArray findif {((toLower (_x select 0)) isEqualto (toLower _name))};
    if (_findIfResult > -1) then {
        ERROR_1("preset _name: %1 already found in _profileArray!, setting option for overwrite",_name);
        [_profileArray,_name,_loadoutsList,_findIfResult] spawn {
            params ["_profileArray","_name","_loadoutsList","_findIfResult"];
            private _result = ["Loadout Preset Name is already in profile, do you want to overwrite this preset?", "Overwrite Loadout Preset", "Overwrite", true, (findDisplay 313)] call BIS_fnc_guiMessage;
            if (_result) then {
                _profileArray set [_findIfResult,[_name,_loadoutsList]];
                profileNamespace setvariable [QGVAR(ProfileLoadoutSettingsArray),_profileArray];
                saveProfileNamespace;
                LOG("Loadout settings saved to profile");
            };
        };
    } else {
        _profileArray pushback [_name,_loadoutsList];
        profileNamespace setvariable [QGVAR(ProfileLoadoutSettingsArray),_profileArray];
        saveProfileNamespace;
        LOG("Loadout settings saved to profile");
    };
};
