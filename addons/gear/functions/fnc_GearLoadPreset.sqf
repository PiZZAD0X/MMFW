
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

LOG("GearLoadPreset started");

params ["_preset",["_teamTag","BLUFOR",[""]],"_ctrlButton"];
LOG_2("_preset: %1 _teamTag: %2",_preset,_teamTag);

if (_preset isEqualto "NONE") exitwith {
    private _classArray = getArray(configFile >> QGVAR(Types) >> "typesArray");
    {
        private _gearType = _x;
        private _varName = format ["%3_Gear_ACE_Arsenal_LoadoutType_%1_%2",_teamTag,_gearType,PREFIXSTR];
        LOG_1("_varName: %1",_varName);
        private _attrSection = format ["%2_Gear_%1",_teamTag,PREFIXSTR];
        private _loadoutName = "NONE";
        missionNamespace setVariable [_varName, _loadoutName];
        LOG_1("_attrSection: %1",_attrSection);
        _attrSection set3DENMissionAttribute [_varName,_loadoutName];
    } foreach _classArray;
    LOG_1("_ctrlButton:",_ctrlButton);
    private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlButton;
    LOG_2("_ctrlGroup: %1 _ctrlButton: %2",_ctrlGroup,_ctrlButton);
    {
        private _newcontrol = _x;
        LOG_1("_newcontrol %1",_newcontrol);
        ctrlsetfocus _newcontrol;
        private _cursel = lbCurSel _newcontrol;
        LOG_1("_cursel %1",_cursel);
        private _lbValue = _newcontrol lbData _cursel;
        if !(_lbValue isEqualto "") then {
            LOG_1("_lbValue %1",_lbValue);
            private _config = _newcontrol getvariable [QGVAR(parentcontrolcfg),""];
            LOG_1("_config %1",_config);
            if !(_config isEqualto "") then {
                private _attProperty = getText (_config >> "property");
                LOG_1("_attProperty %1",_attProperty);
                private _missionVarValue = missionNamespace getvariable [_attProperty,"NONE"];
                LOG_1("_missionVarValue %1",_missionVarValue);
                [_newcontrol,_config,_missionVarValue] call FUNC(ACEGearClassAttribute_AttrReLoad);
                private _size = lbSize _newcontrol;
                private _found = false;
                LOG_1("_size %1",_size);
                for "_i" from 0 to _size step 1 do {
                    private _indexValue = _newcontrol lbData _i;
                    LOG_1("_i %1",_i);
                    LOG_1("_indexValue %1",_indexValue);
                    if (_indexValue == _missionVarValue) exitwith {
                        _newcontrol lbSetCurSel _i;
                        _found = true;
                        _newcontrol ctrlCommit 0;
                    };
                };
                LOG_1("_found %1",_found);
                ctrlsetfocus _ctrlButton;
            };
        };
    } foreach (allcontrols (ctrlparent _ctrlButton));
    LOG_1("Preset Reset for %1",_teamTag);
};

private _cfgEntries = [configFile >> QGVAR(Presets),0] call BIS_fnc_returnChildren;
private _found = false;
private _foundCfg = "";
{
    private _cfg = _x;
    private _displayName = getText(_cfg >> "displayName");
    if (_displayName isEqualto _preset) exitwith {
        _found = true;
        _foundCfg = _x;
        LOG_2("found match for %1 config: %2",_preset,_cfg);
    };
} foreach _cfgEntries;
if (!(_found) || (_foundCfg isEqualto "")) exitwith {
    LOG_1("Preset %1 not found!",_preset);
};
private _displayName = getText(_foundCfg >> "displayName");
LOG_1("_displayName: %1",_displayName);
private _namePrefix = getText(_foundCfg >> "namePrefix");
LOG_1("_namePrefix: %1",_namePrefix);
private _loadoutsArrayStr = getText(_foundCfg >> "loadoutsArray");
private _loadoutsArray = call compile _loadoutsArrayStr;
private _defaultloadoutsArray = missionNamespace getvariable ["ace_arsenal_defaultLoadoutsList",[]];
{
    _x params [["_gearType","",[""]],["_loadoutArray",[],[[]]]];
    if !(_loadoutArray isEqualto []) then {
        LOG_1("_gearType: %1",_gearType);
        private _gearTypeString = localize (format ["STR_%2_Gear_DisplayName_%1",_gearType,PREFIXSTR]);
        LOG_1("_gearTypeString: %1",_gearTypeString);
        private _loadoutName = format ["%1 %2",_namePrefix,_gearTypeString];
        LOG_1("_loadoutName: %1",_loadoutName);
        LOG_1("_loadoutArray: %1",_loadoutArray);
        LOG_1("_defaultloadoutsArray: %1",_defaultloadoutsArray);
        LOG_1("_defaultloadoutsArrayCount: %1", (count _defaultloadoutsArray));
        private _loadoutIndex = _defaultloadoutsArray findIf {(_x select 0) == _loadoutName};
        LOG_1("_loadoutIndex: %1",_loadoutIndex);
        if (_loadoutIndex == -1) then {
            _defaultloadoutsArray pushBack [_loadoutName, _loadoutArray];
            missionNamespace setvariable ["ace_arsenal_defaultLoadoutsList",_defaultloadoutsArray];
            "ace_arsenal_DummyCategory" set3DENMissionAttribute ["ace_arsenal_DefaultLoadoutsListAttribute",_defaultloadoutsArray];
        } else {
            _defaultloadoutsArray set [_loadoutIndex, [_loadoutName, _loadoutArray]];
            missionNamespace setvariable ["ace_arsenal_defaultLoadoutsList",_defaultloadoutsArray];
            "ace_arsenal_DummyCategory" set3DENMissionAttribute ["ace_arsenal_DefaultLoadoutsListAttribute",_defaultloadoutsArray];
        };
        private _varName = format ["%3_Gear_ACE_Arsenal_LoadoutType_%1_%2",_teamTag,_gearType,PREFIXSTR];
        LOG_1("_varName: %1",_varName);
        private _attrSection = format ["%2_Gear_%1",_teamTag,PREFIXSTR];
        missionNamespace setVariable [_varName, _loadoutName];
        LOG_1("_attrSection: %1",_attrSection);
        _attrSection set3DENMissionAttribute [_varName,_loadoutName];
    };
} foreach _loadoutsArray;

LOG_1("_ctrlButton:",_ctrlButton);
private _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlButton;
LOG_2("_ctrlGroup: %1 _ctrlButton: %2",_ctrlGroup,_ctrlButton);
{
    private _newcontrol = _x;
    LOG_1("_newcontrol %1",_newcontrol);
    ctrlsetfocus _newcontrol;
    private _cursel = lbCurSel _newcontrol;
    LOG_1("_cursel %1",_cursel);
    private _lbValue = _newcontrol lbData _cursel;
    if !(_lbValue isEqualto "") then {
        LOG_1("_lbValue %1",_lbValue);
        private _config = _newcontrol getvariable [QGVAR(parentcontrolcfg),""];
        LOG_1("_config %1",_config);
        if !(_config isEqualto "") then {
            private _attProperty = getText (_config >> "property");
            LOG_1("_attProperty %1",_attProperty);
            private _missionVarValue = missionNamespace getvariable [_attProperty,"NONE"];
            LOG_1("_missionVarValue %1",_missionVarValue);
            [_newcontrol,_config,_missionVarValue] call FUNC(ACEGearClassAttribute_AttrReLoad);
            private _size = lbSize _newcontrol;
            private _found = false;
            LOG_1("_size %1",_size);
            for "_i" from 0 to _size step 1 do {
                private _indexValue = _newcontrol lbData _i;
                LOG_1("_i %1",_i);
                LOG_1("_indexValue %1",_indexValue);
                if (_indexValue == _missionVarValue) exitwith {
                    _newcontrol lbSetCurSel _i;
                    _found = true;
                    _newcontrol ctrlCommit 0;
                };
            };
            LOG_1("_found %1",_found);
            ctrlsetfocus _ctrlButton;
        };
    };
} foreach (allcontrols (ctrlparent _ctrlButton));

LOG_2("Loaded %1 Preset for %2",_displayName,_teamTag);
