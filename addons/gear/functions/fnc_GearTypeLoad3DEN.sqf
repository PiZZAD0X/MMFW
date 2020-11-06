
#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

params ["_object","",""];
TRACE_1("",_object);

if (_object isKindOf "CAManBase") then {
    //private _systemType = GETVAR(_object,UnitSystemType,"NONE");
    private _systemType = (_object get3DENAttribute QGVAR(UnitSystemType)) select 0;
    //private _gearType = GETVAR(_object,UnitGearType,"NONE");
    private _gearType = (_object get3DENAttribute QGVAR(UnitGearType)) select 0;
    TRACE_2("",_systemType,_gearType);
    if (_systemType isEqualto "NONE") exitwith {};
    if (_gearType isEqualto "NONE") exitwith {
        ERROR_1("No loadout found for unit: %1",_object);
    };
    if (_gearType isEqualto "MANUAL") then {
        switch (_systemType) do {
            case "ACEAR": {
                //private _manualClass = GETVAR(_object,UnitGearManualType,"");
                private _manualClass = (_object get3DENAttribute QGVAR(UnitGearManualType)) select 0;
                if (_manualClass isEqualto "") exitwith {
                    ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_object);
                };
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
                private _manualClass = GETVAR(_object,UnitGearManualTypeOlsen,"");
                if (_manualClass isEqualto "") exitwith {
                    ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_object);
                };
                TRACE_2("Executing gear class",_manualClass,_object);
                [_object,_manualClass] call FUNC(OlsenGearScript);
            };
        };
    } else {
        private _SystemTag = switch (_systemType) do {
            case "ACEAR": {"ACE_Arsenal"};
            case "OLSEN": {"Olsen"};
            default {""};
        };
        private _loadoutvarname = "";
        switch (side _object) do {
            case west: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Blufor_%2",_SystemTag,_gearType];
            };
            case east: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Opfor_%2",_SystemTag,_gearType];
            };
            case independent: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Indfor_%2",_SystemTag,_gearType];
            };
            case civilian: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Civilian_%2",_SystemTag,_gearType];
            };
        };
        private _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
        if (_loadoutName isEqualto "NONE") exitwith {
            TRACE_2("No loadout found",_object,_loadoutvarname);
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
            LOG_2("Executing gear of file class: %1 for vehicle %2",_loadoutName,_object);
            [_object,_loadoutName] call FUNC(OlsenGearScript);
        };
    };
    save3DENInventory [_object];
};
