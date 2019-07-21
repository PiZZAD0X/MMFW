#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if !(GETMVALUE(Enabled,false)) exitWith {
    INFO("Framework is disabled in Mission settings... exiting");
};

INFO("Initializing Framework");
LOG("Global Pre Init");
SETMVAR(Initialized,false);
[] call FUNC(setDefaults);

private _missionFrameworkVersionCreatedStr = (GETMVALUE(Version_Created,""));
if (_missionFrameworkVersionCreatedStr isEqualto "") then {
    SETMVAR(Version_CreatedNum,102);
    INFO("Mission Created with Framework Version: Legacy");
} else {
    private _missionFrameworkVersionCreated = parseNumber ((_missionFrameworkVersionCreatedStr splitString ".") joinString "");
    SETMVAR(Version_CreatedNum,_missionFrameworkVersionCreated);
    INFO_1("Mission Created with Framework Version:%1",_missionFrameworkVersionCreated);
};

private _missionFrameworkVersionStr = (GETMVALUE(Version_Updated,""));
if (_missionFrameworkVersionStr isEqualto "") then {
    SETMVAR(Version_UpdatedNumber,102);
    INFO("Mission Updated with Framework Version: Legacy");
} else {
    private _missionFrameworkVersion = parseNumber ((_missionFrameworkVersionStr splitString ".") joinString "");
    SETMVAR(Version_UpdatedNumber,_missionFrameworkVersion);
    INFO_1("Mission Updated with Framework Version:%1",_missionFrameworkVersion);
};

[QGVAR(EntityAttributeLoad), {
    params ["_object", "_propertyName", "_value", ["_isGlobal",false,[false]]];
    _object setvariable [_propertyName,_value,_isGlobal];
}] call CBA_fnc_addEventHandler;

//[QGVAR(SettingsLoaded), {
//    //_respawnTypeArray = [['1 Life','ONELIFE'],['Unlimited','UNLIMITED'],['Individual Tickets','INDTICKETS'],['Team Tickets','TEAMTICKETS']];
//}] call CBA_fnc_addEventHandler;

[QEGVAR(EndMission,LocalObjectsEvent), {
    {
        _x enableSimulation false;
        removeAllWeapons _x;
    } foreach vehicles select {local _x};
    {
        _x enableSimulation false;
        removeAllWeapons _x;
    } foreach allUnits select {local _x};
}] call CBA_fnc_addEventHandler;

[QEGVAR(Debug,DebugMessageEvent), {
    params ["_message"];
    [_message] call FUNC(debugMessageDisplay);
}] call CBA_fnc_addEventHandler;

if (!(hasInterface) || (isServer)) then {
    [QGVAR(EndmissionEvent), {
        params ["_scenario"];
        [QEGVAR(EndMission,LocalObjectsEvent), []] call CBA_fnc_localEvent;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
