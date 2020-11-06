#include "script_component.hpp"
EDEN_CHECK;

//IGNORE_PRIVATE_WARNING ["_x"];

params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlEdit = _ctrlGroup controlsgroupctrl 100;
private _name = ctrlText _ctrlEdit;

private _attributeValues = [];
private _sections = QUOTE(!(((str(configname _x)) find QN(PREFIX)) isEqualto -1)) configClasses (Configfile >> "Cfg3DEN" >> "Mission");
{
    private _section = configName _x;
    private _children = [configfile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories",2,false] call BIS_fnc_returnChildren;
    {
        private _attributeName = "";
        _attributeName = getText (_x >> "data");
        private _attributeValue = _section get3DENMissionAttribute _attributeName;
        if (isNil "_attributeValue") then {
            _attributeName = configName _x;
            _attributeValue = _section get3DENMissionAttribute _attributeName;
            if (isNil "_attributeValue") then {
                _attributeName = getText (_x >> "property");
                _attributeValue = _section get3DENMissionAttribute _attributeName;
                _attributeValues pushBack [_section,_attributeName,_attributeValue];
            } else {
                _attributeValues pushBack [_section,_attributeName,_attributeValue];
            };
        } else {
            _attributeValues pushBack [_section,_attributeName,_attributeValue];
        };
    } foreach _children;
} foreach _sections;

if (_name isEqualto "") exitwith {};
private _profileArray = profileNamespace getvariable [QGVAR(ProfileSettingsArray),[]];
if (_profileArray isEqualto []) then {
    _profileArray pushback [_name,_attributeValues];
    profileNamespace setvariable [QGVAR(ProfileSettingsArray),_profileArray];
    saveProfileNamespace;
} else {
    private _findIfResult = _profileArray findif {((toLower (_x select 0)) isEqualto (toLower _name))};
    if (_findIfResult > -1) then {
        ERROR_1("preset _name: %1 already found in _profileArray!, setting option for overwrite",_name);
        [_profileArray,_name,_attributeValues,_findIfResult] spawn {
            params ["_profileArray","_name","_attributeValues","_findIfResult"];
            private _result = ["Setting Preset Name is already in profile, do you want to overwrite this preset?", "Overwrite Settings Preset", "Overwrite", true, (findDisplay 313)] call BIS_fnc_guiMessage;
            if (_result) then {
                _profileArray set [_findIfResult,[_name,_attributeValues]];
                profileNamespace setvariable [QGVAR(ProfileSettingsArray),_profileArray];
                saveProfileNamespace;
            };
        };
    } else {
        _profileArray pushback [_name,_attributeValues];
        profileNamespace setvariable [QGVAR(ProfileSettingsArray),_profileArray];
        saveProfileNamespace;
    };
};

LOG_1("saving %1",[_name,_attributeValues]);
LOG_1("_profileArray %1",_profileArray);
