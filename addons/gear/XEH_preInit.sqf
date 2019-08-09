#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(LocalObjectsGearLoad), {
    if (!(GETMVAR(ACEAR_System_Enabled,false)) && {!(GETMVAR(Olsen_Enabled,false))}) exitwith {};
    {
        [{(!isNull _this)}, {
            params ["_unit"];
            private ["_loadoutName"];
            private _systemType = (GETVAR(_unit,UnitSystemType,"NONE"));
            private _gearType = (GETVAR(_unit,UnitGearType,"NONE"));
            SETVAR(_unit,gearType,_gearType);
            if (_systemType isEqualto "NONE") exitwith {};
            if (_gearType isEqualto "NONE") exitwith {
                ERROR_1("No loadout found for unit: %1",_unit);
            };
            if (_gearType isEqualto "MANUAL") then {
                _unit setvariable [QGVAR(ManualUnitClass),"MANUAL"];
                private _manualClass = GETVAR(_unit,ManualUnitClass,"");
                if (_manualClass isEqualto "") exitwith {
                    ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_unit);
                };
                switch (_systemType) do {
                    case "ACEAR": {
                        private _found = false;
                        private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                        {
                            _x params ["_name","_loadoutData"];
                            if (_manualClass == _name) exitwith {
                                _unit setUnitLoadout _loadoutData;
                                LOG_2("Setting ace loadout: %1 for unit %2",_manualClass,_unit);
                                _found = true;
                            };
                        } foreach _defaultloadoutsArray;
                        if !(_found) exitwith {
                            ERROR_1("Could not find %1 in Default Loadouts!",_manualClass);
                        };
                    };
                    case "OLSEN": {
                        private _manualClass = (GETVAR(_unit,UnitGearManualType,""));
                        if (_manualClass isEqualto "") exitwith {
                            ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_unit);
                        };
                        LOG_2("Executing gear of file: %1 for unit %2",_manualClass,_unit);
                        [_unit,_manualClass] call FUNC(OlsenGearScript);
                    };
                };
            } else {
                private ["_SystemTag","_loadoutvarname"];
                switch (_systemType) do {
                    case "ACEAR": {_SystemTag = "ACE_Arsenal"};
                    case "OLSEN": {_SystemTag = "Olsen"};
                };
                switch (side _unit) do {
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
                        _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Civ_%2",_SystemTag,_gearType];
                    };
                };
                _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
                if (_loadoutName isEqualto "NONE") exitwith {
                    ERROR_2("No loadout found for unit: %1 and var %2",_unit,_loadoutvarname);
                };
                switch (_systemType) do {
                    case "ACEAR": {
                        private _found = false;
                        private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                        {
                            _x params ["_name","_loadoutData"];
                            if (_loadoutName == _name) exitwith {
                                _unit setUnitLoadout _loadoutData;
                                LOG_2("Setting ace loadout: %1 for unit %2",_loadoutName,_unit);
                                _found = true;
                            };
                        } foreach _defaultloadoutsArray;
                        if !(_found) exitwith {
                            ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                        };
                    };
                    case "OLSEN": {
                        LOG_2("Executing gear of file: %1 for unit %2",_loadoutName,_unit);
                        [_unit,_loadoutName] call FUNC(OlsenGearScript);
                    };
                };
            };
        },_x] call CBA_fnc_waitUntilandExecute;
    } forEach (allUnits select {local _x && (!isPlayer _x)});
    {
        [{(!isNull _this)}, {
            params ["_vehicle"];
            private ["_loadoutName"];
            private _systemType = _vehicle getvariable [QGVAR(VehicleSystemType),"NONE"];
            private _loadoutName = _vehicle getvariable [QGVAR(VehicleGearManualType),""];
            if (_systemType isEqualto "NONE") exitwith {};
            switch (_systemType) do {
                case "ACEAR": {
                    if (_loadoutName isEqualto "") exitwith {
                        ERROR_1("Vehicle %1 is set to manual loadout but has none!, exiting gearscript.",_vehicle);
                    };
                    private _found = false;
                    private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    {
                        _x params ["_name","_loadoutData"];
                        if (_loadoutName == _name) exitwith {
                            _vehicle setUnitLoadout _loadoutData;
                            LOG_2("Setting ace loadout: %1 for vehicle %2",_loadoutName,_vehicle);
                            _found = true;
                        };
                    } foreach _defaultloadoutsArray;
                    if !(_found) exitwith {
                        ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                    };
                };
                case "OLSEN": {
                    if (_loadoutName isEqualto "") exitwith {
                        ERROR_1("Vehicle %1 is set to manual loadout but has none!, exiting gearscript.",_vehicle);
                    };
                    LOG_2("Executing gear of file: %1 for vehicle %2",_loadoutName,_vehicle);
                    [_vehicle,_loadoutName] call FUNC(OlsenGearScript);
                };
            };
        },_x] call CBA_fnc_waitUntilandExecute;
    } forEach (vehicles select {local _x && (!isPlayer _x)});
    missionNamespace setvariable [QGVAR(ServerInit),true,true];
}] call CBA_fnc_addEventHandler;

[QGVAR(UnitLoad), {
    params ["_unit"];
    if (!(GETMVAR(ACEAR_System_Enabled,false)) && {!(GETMVAR(Olsen_Enabled,false))}) exitwith {
        SETPVAR(_unit,GearReady,true);
    };
    [{(!isNull _this)}, {
        params ["_unit"];
        private ["_loadoutName"];
        private _systemType = (GETVAR(_unit,UnitSystemType,"NONE"));
        private _gearType = (GETVAR(_unit,UnitGearType,"NONE"));
        (SETVAR(_unit,gearType,_gearType));
        if (_systemType isEqualto "NONE") exitwith {};
        if (_gearType isEqualto "NONE") exitwith {
            ERROR_1("No loadout found for unit: %1",_unit);
            SETPVAR(_unit,GearReady,true);
        };
        if (_gearType isEqualto "MANUAL") then {
            _unit setvariable [QGVAR(ManualUnitClass),"MANUAL"];
            private _manualClass = (GETVAR(_unit,UnitGearManualType,""));
            if (_manualClass isEqualto "") exitwith {
                ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_unit);
                SETPVAR(_unit,GearReady,true);
            };
            switch (_systemType) do {
                case "ACEAR": {
                    private _found = false;
                    private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    {
                        _x params ["_name","_loadoutData"];
                        if (_manualClass isEqualto _name) exitwith {
                            _unit setUnitLoadout _loadoutData;
                            LOG_2("Setting ace loadout: %1 for unit %2",_manualClass,_unit);
                            SETPVAR(_unit,GearReady,true);
                            _found = true;
                        };
                    } foreach _defaultloadoutsArray;
                    if !(_found) exitwith {
                        ERROR_1("Could not find %1 in Default Loadouts!",_manualClass);
                        SETPVAR(_unit,GearReady,true);
                    };
                };
                case "OLSEN": {
                    private _manualClass = (GETVAR(_unit,UnitGearManualType,""));
                    if (_manualClass isEqualto "") exitwith {
                        ERROR_1("Unit %1 is set to manual loadout but has none!, exiting gearscript.",_unit);
                        SETPVAR(_unit,GearReady,true);
                    };
                    LOG_2("Executing gear class: %1 for unit %2",_manualClass,_unit);
                    [_unit,_manualClass] call FUNC(OlsenGearScript);
                    SETPVAR(_unit,GearReady,true);
                };
            };
        } else {
            private ["_SystemTag","_loadoutvarname"];
            switch (_systemType) do {
                case "ACEAR": {_SystemTag = "ACE_Arsenal"};
                case "OLSEN": {_SystemTag = "Olsen"};
            };
            switch (side _unit) do {
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
                    _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Civ_%2",_SystemTag,_gearType];
                };
            };
            _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
            if (_loadoutName isEqualto "NONE") exitwith {
                ERROR_2("No loadout found for unit: %1 and var %2",_unit,_loadoutvarname);
                SETPVAR(_unit,GearReady,true);
            };
            switch (_systemType) do {
                case "ACEAR": {
                    private _found = false;
                    private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                    {
                        _x params ["_name","_loadoutData"];
                        if (_loadoutName == _name) exitwith {
                            _unit setUnitLoadout _loadoutData;
                            LOG_2("Setting ace loadout: %1 for unit %2",_loadoutName,_unit);
                            SETPVAR(_unit,GearReady,true);
                            _found = true;
                        };
                    } foreach _defaultloadoutsArray;
                    if !(_found) exitwith {
                        ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                        SETPVAR(_unit,GearReady,true);
                    };
                };
                case "OLSEN": {
                    LOG_2("Executing gear class: %1 for unit %2",_loadoutName,_unit);
                    [_unit,_loadoutName] call FUNC(OlsenGearScript);
                    SETPVAR(_unit,GearReady,true);
                };
            };
        };
    },_unit] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(ForceUnitLoad), {
    params ["_unit",["_systemType","ACEAR",[""]],["_forcedClass","NONE",[""]],["_forcedSide",(side (_this select 0))]];
    if (!(GETMVAR(ACEAR_System_Enabled,false)) && {!(GETMVAR(Olsen_Enabled,false))}) exitwith {
        SETPVAR(_unit,GearReady,true);
    };
    if (_forcedClass isEqualto "NONE") exitwith {ERROR_1("Invalid forcedclass for unit:%1",_unit)};
    [{(!isNull (_this select 0))}, {
        params ["_unit","_systemType","_forcedClass","_forcedSide"];
        private ["_loadoutName","_SystemTag","_loadoutvarname"];
        (SETVAR(_unit,gearType,_forcedClass));
        switch (_systemType) do {
            case "ACEAR": {_SystemTag = "ACE_Arsenal"};
            case "OLSEN": {_SystemTag = "Olsen"};
        };
        switch (_forcedSide) do {
            case west: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Blufor_%2",_SystemTag,_forcedClass];
            };
            case east: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Opfor_%2",_SystemTag,_forcedClass];
            };
            case independent: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Indfor_%2",_SystemTag,_forcedClass];
            };
            case civilian: {
                _loadoutvarname = format ["MMFW_Gear_%1_LoadoutType_Civ_%2",_SystemTag,_forcedClass];
            };
        };
        _loadoutName = missionNamespace getvariable [_loadoutvarname,"NONE"];
        if (_loadoutName isEqualto "NONE") exitwith {
            ERROR_2("No loadout found for unit: %1 and var %2",_unit,_loadoutvarname);
                SETPVAR(_unit,GearReady,true);
        };
        switch (_systemType) do {
            case "ACEAR": {
                private _found = false;
                private _defaultloadoutsArray = missionNamespace getvariable ['ace_arsenal_defaultLoadoutsList',[]];
                {
                    _x params ["_name","_loadoutData"];
                    if (_loadoutName == _name) exitwith {
                        _unit setUnitLoadout _loadoutData;
                        LOG_2("Setting ace loadout: %1 for unit %2",_loadoutName,_unit);
                        SETPVAR(_unit,GearReady,true);
                        _found = true;
                    };
                } foreach _defaultloadoutsArray;
                if !(_found) exitwith {
                    ERROR_1("Could not find %1 in Default Loadouts!",_loadoutName);
                    SETPVAR(_unit,GearReady,true);
                };
            };
            case "OLSEN": {
                LOG_2("Executing gear class: %1 for unit %2",_loadoutName,_unit);
                [_unit,_loadoutName] call FUNC(OlsenGearScript);
                SETPVAR(_unit,GearReady,true);
            };
        };
    },[_unit,_systemType,_forcedClass,_forcedSide]] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(VehicleLoad), {
    if !(GETMVAR(Olsen_Enabled,false)) exitwith {};
    params ["_vehicle"];
    [{(!isNull _this)}, {
        params ["_vehicle"];
        private _systemType = GETVAR(_vehicle,VehicleSystemType,"NONE");
        private _loadoutName = GETVAR(_vehicle,VehicleGearManualType,"NONE");
        if (_systemType isEqualto "NONE") exitwith {};
        switch (_systemType) do {
            case "OLSEN": {
                if (_loadoutName isEqualto "") exitwith {
                    ERROR_1("Vehicle %1 is set to manual loadout but has none!, exiting gearscript.",_vehicle);
                };
                LOG_2("Executing gear of file: %1 for vehicle %2",_loadoutName,_vehicle);
                [_vehicle,_loadoutName] call FUNC(OlsenGearScript);
            };
        };
    },_vehicle] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(ForceVehicleLoad), {
    if !(GETMVAR(Olsen_Enabled,false)) exitwith {};
    params ["_vehicle",["_systemType","NONE",[""]],["_forcedClass","NONE",[""]]];
    if (_forcedClass isEqualto "NONE") exitwith {ERROR_1("Invalid forcedclass for vehicle:%1",_vehicle)};
    [{(!isNull (_this select 0))}, {
        params ["_vehicle",["_systemType","OLSEN",[""]],["_forcedClass","NONE",[""]]];
        if (_systemType isEqualto "NONE") exitwith {};
        switch (_systemType) do {
            case "OLSEN": {
                if (_forcedClass isEqualto "") exitwith {
                    ERROR_1("Vehicle %1 is set to manual loadout but has none!, exiting gearscript.",_vehicle);
                };
                LOG_2("Executing gear of file: %1 for vehicle %2",_forcedClass,_vehicle);
                [_vehicle,_forcedClass] call FUNC(OlsenGearScript);
            };
        };
    },[_vehicle,_systemType,_forcedClass]] call CBA_fnc_waitUntilandExecute;
}] call CBA_fnc_addEventHandler;


ADDON = true;
