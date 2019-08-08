
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

params ["_object"];
LOG_1("_object: %1",_object);

if (_object isKindOf "CAManBase") then {
    private _systemType = GETVAR(_object,UnitSystemType,"NONE");
    LOG_1("_systemType: %1",_systemType);
    private _gearType = GETVAR(_object,UnitGearType,"NONE");
    LOG_1("_gearType: %1",_gearType);
    if (_systemType isEqualto "NONE") exitwith {};
    if (_gearType isEqualto "NONE") exitwith {
        ERROR_1("No loadout found for unit: %1",_object);
    };
    if (_gearType isEqualto "MANUAL") then {
        private _manualClass = GETVAR(_object,ManualUnitClass,"");
        if (_manualClass isEqualto "") exitwith {
            ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_object);
        };
        switch (_systemType) do {
            case "ACEAR": {
                private _found = false;
                private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                {
                    _x params ["_name","_loadoutData"];
                    if (_manualClass == _name) exitwith {
                        _object setUnitLoadout _loadoutData;
                        LOG_2("Setting ace loadout: %1 for unit %2",_manualClass,_object);
                        _found = true;
                    };
                } foreach _defaultloadoutsArray;
                if !(_found) exitwith {
                    ERROR_1("Could not find %1 in Default Loadouts!",_manualClass);
                };
            };
            case "OLSEN": {
                LOG_2("Executing gear class: %1 for unit %2",_manualClass,_object);
                [_object,_manualClass] call FUNC(OlsenGearScript);
            };
        };
    } else {
        private ["_SystemTag","_loadoutvarname"];
        switch (_systemType) do {
            case "ACEAR": {_SystemTag = "ACE_Arsenal"};
            case "OLSEN": {_SystemTag = "Olsen"};
        };
        switch (side _object) do {
            case west: {
                _loadoutvarname = format ["%3_Gear_%1_LoadoutType_Blufor_%2",_SystemTag,_gearType,PREFIXSTR];
            };
            case east: {
                _loadoutvarname = format ["%3_Gear_%1_LoadoutType_Opfor_%2",_SystemTag,_gearType,PREFIXSTR];
            };
            case independent: {
                _loadoutvarname = format ["%3_Gear_%1_LoadoutType_Indfor_%2",_SystemTag,_gearType,PREFIXSTR];
            };
            case civilian: {
                _loadoutvarname = format ["%3_Gear_%1_LoadoutType_Civ_%2",_SystemTag,_gearType,PREFIXSTR];
            };
        };
        private _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
        if (_loadoutName isEqualto "NONE") exitwith {
            ERROR_2("No loadout found for unit: %1 and var %2",_object,_loadoutvarname);
        };
        switch (_systemType) do {
            case "ACEAR": {
                private _found = false;
                private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                {
                    _x params ["_name","_loadoutData"];
                    if (_loadoutName == _name) exitwith {
                        _object setUnitLoadout _loadoutData;
                        LOG_2("Setting ace loadout: %1 for unit %2",_loadoutName,_object);
                        _found = true;
                    };
                } foreach _defaultloadoutsArray;
                if !(_found) exitwith {
                    ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                };
            };
            case "OLSEN": {
                LOG_2("Executing gear class: %1 for unit %2",_loadoutName,_object);
                [_object,_loadoutName] call FUNC(OlsenGearScript);
            };
        };
    };
    save3DENInventory [_object];
} else {
    private _systemType = GETVAR(_object,VehicleSystemType,"NONE");
    private _loadoutName = GETVAR(_object,VehicleGearManualType,"NONE");
    if (_systemType isEqualto "NONE") exitwith {};
    switch (_systemType) do {
        case "OLSEN": {
            if (_loadoutName isEqualto "") exitwith {
                ERROR_1("Vehicle %1 is set to manual loadout but has none!, exiting gearscript.",_object);
            };
            LOG_2("Executing gear of file: %1 for vehicle %2",_loadoutName,_object);
            [_object,_loadoutName] call FUNC(OlsenGearScript);
        };
    };
    save3DENInventory [_object];
};
