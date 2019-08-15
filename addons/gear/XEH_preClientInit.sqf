#include "script_component.hpp"

[QGVAR(PlayerGearLoad), {
    if (!(GETMVALUE(ACEAR_System_Enabled,false)) && {!(GETMVALUE(Olsen_Enabled,false))}) exitwith {
        SETPLPVAR(GearReady,true);
    };
    [{(!isNull ace_player) && {!((GETPLVAR(UnitSystemType,"")) isEqualto "")} && {!((GETPLVAR(UnitGearType,"")) isEqualto "")}}, {
        private ["_loadoutName"];
        private _systemType = (GETPLVAR(UnitSystemType,"NONE"));
        LOG_1("_systemType: %1",_systemType);
        private _gearType = (GETPLVAR(UnitGearType,"NONE"));
        LOG_1("_gearType: %1",_gearType);
        SETPLPVAR(GearClass,_gearType);
        //player setvariable [QGVAR(GearClass),_gearType,true];
        if (_systemType isEqualto "NONE") exitwith {
            LOG_1("No gear system set for unit: %1",player);
            SETPLPVAR(GearReady,true);
        };
        if (_gearType isEqualto "NONE") exitwith {
            ERROR_1("No loadout found for unit: %1",player);
            SETPLPVAR(GearReady,true);
        };
        if (_gearType isEqualto "MANUAL") then {
            switch (_systemType) do {
                case "ACEAR": {
                    private _manualClass = (GETPLVAR(UnitGearManualType,""));
                    if (_manualClass isEqualto "") exitwith {
                        ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",player);
                        SETPLPVAR(GearReady,true);
                    };
                    private _found = false;
                    //private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    if (_defaultloadoutsArray isEqualto []) exitwith {
                        LOG("ACE Arsenal DefaultLoadouts Empty!");
                        SETPLPVAR(GearReady,true);
                    };
                    {
                        _x params ["_name","_loadoutData"];
                        if (_manualClass == _name) exitwith {
                            player setUnitLoadout _loadoutData;
                            LOG_2("Setting ace loadout: %1 for unit %2",_manualClass,player);
                            SETPLPVAR(GearReady,true);
                            _found = true;
                        };
                    } foreach _defaultloadoutsArray;
                    if !(_found) exitwith {
                        ERROR_1("Could not find %1 in Default Loadouts!",_manualClass);
                        SETPLPVAR(GearReady,true);
                    };
                };
                case "OLSEN": {
                    private _manualClass = (GETPLVAR(UnitGearManualTypeOlsen,""));
                    if (_manualClass isEqualto "") exitwith {
                        ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",player);
                        SETPLPVAR(GearReady,true);
                    };
                    LOG_2("Executing gear class: %1 for unit %2",_manualClass,player);
                    [player,_manualClass] call FUNC(OlsenGearScript);
                    SETPLPVAR(GearReady,true);
                };
            };
        } else {
            private ["_SystemTag","_loadoutvarname"];
            switch (_systemType) do {
                case "ACEAR": {_SystemTag = "ACE_Arsenal"};
                case "OLSEN": {_SystemTag = "Olsen"};
            };
            private ["_loadoutvarname"];
            switch (side player) do {
                case west: {
                    _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Blufor_%2",_SystemTag,_gearType];
                };
                case east: {
                    _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Opfor_%2",_SystemTag,_gearType];
                };
                case resistance: {
                    _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Indfor_%2",_SystemTag,_gearType];
                };
                case civilian: {
                    _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Civ_%2",_SystemTag,_gearType];
                };
            };
            //_loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
            _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
            if (_loadoutName isEqualto "NONE") exitwith {
                ERROR_2("No loadout found for unit: %1 and var %2",player,_loadoutvarname);
                SETPLPVAR(GearReady,true);
            };
            switch (_systemType) do {
                case "ACEAR": {
                    private _found = false;
                    //private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    if (_defaultloadoutsArray isEqualto []) exitwith {
                        LOG("ACE Arsenal DefaultLoadouts Empty!");
                        SETPLPVAR(GearReady,true);
                    };
                    {
                        _x params ["_name","_loadoutData"];
                        if (_loadoutName == _name) exitwith {
                            player setUnitLoadout _loadoutData;
                            LOG_2("Setting ace loadout: %1 for unit %2",_loadoutName,player);
                            SETPLPVAR(GearReady,true);
                            _found = true;
                        };
                    } foreach _defaultloadoutsArray;
                    if !(_found) exitwith {
                        ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                        SETPLPVAR(GearReady,true);
                    };
                };
                case "OLSEN": {
                    LOG_2("Executing gear class: %1 for unit %2",_loadoutName,player);
                    [player,_loadoutName] call FUNC(OlsenGearScript);
                    SETPLPVAR(GearReady,true);
                };
            };
        };
    }] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [{!isNull ace_player},{
        [QGVAR(PlayerGearLoad), []] call CBA_fnc_localEvent;
    }] call CBA_fnc_waitUntilandExecute;
    [{GETPLVAR(GearReady,false)}, {
        if (isClass(configFile >> "CfgPatches" >> "UO_BriefingKit")) then {
            [] call UO_loadoutIndex;
        };
    }] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;
