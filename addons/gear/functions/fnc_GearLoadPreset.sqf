
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

LOG("GearLoadPreset started");

params ["_preset",["_teamTag","BLUFOR",[""]],"_ctrlButton"];
TRACE_2("",_preset,_teamTag);

if (_preset isEqualto "NONE") exitwith {
    private _classArray = getArray(configFile >> QGVAR(Types) >> "typesArray");
    {
        private _gearType = _x;
        private _varName = format ["MMFW_Gear_ACE_Arsenal_LoadoutType_%1_%2",_teamTag,_gearType];
        private _attrSection = format ["MMFW_Gear_%1",_teamTag];
        private _loadoutName = "NONE";
        missionNamespace setVariable [_varName, _loadoutName];
        _attrSection set3DENMissionAttribute [_varName,_loadoutName];
    } foreach _classArray;

    {
        private _newcontrol = _x;
        ctrlsetfocus _newcontrol;
        private _cursel = lbCurSel _newcontrol;
        private _lbValue = _newcontrol lbData _cursel;
        if !(_lbValue isEqualto "") then {
            private _config = _newcontrol getvariable [QGVAR(parentcontrolcfg),""];
            if !(_config isEqualto "") then {
                private _attProperty = getText (_config >> "property");
                private _missionVarValue = missionNamespace getvariable [_attProperty,"NONE"];
                [_newcontrol,_config,_missionVarValue] call FUNC(ACEGearClassAttribute_AttrReLoad);
                private _size = lbSize _newcontrol;
                for "_i" from 0 to _size step 1 do {
                    private _indexValue = _newcontrol lbData _i;
                    if (_indexValue == _missionVarValue) exitwith {
                        _newcontrol lbSetCurSel _i;
                        _newcontrol ctrlCommit 0;
                    };
                };
                ctrlsetfocus _ctrlButton;
            };
        };
    } foreach (allcontrols (ctrlparent _ctrlButton));
};
private _cfgEntries = [configFile >> QGVAR(Presets),0] call BIS_fnc_returnChildren;
private _found = false;
private _foundCfg = "";
{
    private _cfg = _x;
    private _displayName = getText(_cfg >> "displayName");
    if (_displayName isEqualto _preset) exitwith {
        _found = true;
        _foundCfg = _cfg;
        TRACE_2("found match",_preset,_cfg);
    };
} foreach _cfgEntries;
if (!(_found) || (_foundCfg isEqualto "")) exitwith {
    LOG_1("Preset %1 not found!",_preset);
};
private _displayName = getText(_foundCfg >> "displayName");
private _configName = configName _foundCfg;
TRACE_3(""_foundCfg,_preset,_configName);
private _isArray = isArray (_foundCfg >> "addonsRequired");
if (_isArray) then {
    private _loaded = true;
    private _addon = "";
    private _requiredAddons = getArray (_foundCfg >> "addonsRequired");
    {
        _addon = _x;
        LOG_1("_addon: %1",_addon);
        if !(isClass (configFile >> 'CfgPatches' >> _addon)) exitwith {
            _loaded = false;
        };
    } foreach _requiredAddons;
    if !(_loaded) exitWith {
        [_displayName,_addon,_requiredAddons] spawn {
            params ["_displayName","_addon","_requiredAddons"];
            private _missingAddonsStr = format ["Missing Addon for %1: %2",_displayName,_addon];
            ERROR_2("Required Addons for %1: %2",_displayName,_requiredAddons);
            [_missingAddonsStr, "Missing Required Addon", true, false, (findDisplay 313)] call BIS_fnc_guiMessage;
        };
    };
};
private _namePrefix = getText(_foundCfg >> "namePrefix");
private _loadoutsArrayStr = getText(_foundCfg >> "loadoutsArray");
private _loadoutsArray = call compile _loadoutsArrayStr;
private _defaultloadoutsArray = missionNamespace getvariable ["ace_arsenal_defaultLoadoutsList",[]];
{
    _x params [["_gearType","",[""]],["_loadoutArray",[],[[]]]];
    if !(_loadoutArray isEqualto []) then {
        private _gearTypeString = localize (format ["STR_MMFW_Gear_DisplayName_%1",_gearType]);
        private _loadoutName = format ["%1 %2",_namePrefix,_gearTypeString];
        private _loadoutIndex = _defaultloadoutsArray findIf {(_x select 0) == _loadoutName};
        if (_loadoutIndex isEqualTo -1) then {
            _defaultloadoutsArray pushBack [_loadoutName, _loadoutArray];
            missionNamespace setvariable ["ace_arsenal_defaultLoadoutsList",_defaultloadoutsArray];
            "ace_arsenal_DummyCategory" set3DENMissionAttribute ["ace_arsenal_DefaultLoadoutsListAttribute",_defaultloadoutsArray];
        } else {
            _defaultloadoutsArray set [_loadoutIndex, [_loadoutName, _loadoutArray]];
            missionNamespace setvariable ["ace_arsenal_defaultLoadoutsList",_defaultloadoutsArray];
            "ace_arsenal_DummyCategory" set3DENMissionAttribute ["ace_arsenal_DefaultLoadoutsListAttribute",_defaultloadoutsArray];
        };
        private _varName = format ["MMFW_Gear_ACE_Arsenal_LoadoutType_%1_%2",_teamTag,_gearType];
        private _attrSection = format ["MMFW_Gear_%1",_teamTag];
        missionNamespace setVariable [_varName, _loadoutName];
        _attrSection set3DENMissionAttribute [_varName,_loadoutName];
    };
} foreach _loadoutsArray;

{
    private _newcontrol = _x;
    ctrlsetfocus _newcontrol;
    private _cursel = lbCurSel _newcontrol;
    private _lbValue = _newcontrol lbData _cursel;
    if !(_lbValue isEqualto "") then {
        private _config = _newcontrol getvariable [QGVAR(parentcontrolcfg),""];
        if !(_config isEqualto "") then {
            private _attProperty = getText (_config >> "property");
            private _missionVarValue = missionNamespace getvariable [_attProperty,"NONE"];
            [_newcontrol,_config,_missionVarValue] call FUNC(ACEGearClassAttribute_AttrReLoad);
            private _size = lbSize _newcontrol;
            for "_i" from 0 to _size step 1 do {
                private _indexValue = _newcontrol lbData _i;
                if (_indexValue == _missionVarValue) exitwith {
                    _newcontrol lbSetCurSel _i;
                    _newcontrol ctrlCommit 0;
                };
            };
            ctrlsetfocus _ctrlButton;
        };
    };
} foreach (allcontrols (ctrlparent _ctrlButton));

LOG_2("Loaded %1 Preset for %2",_displayName,_teamTag);
