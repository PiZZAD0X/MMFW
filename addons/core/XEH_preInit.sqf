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

private _GlobalPreInit = GETMVALUE(GlobalPreInit,"");
LOG_1("_GlobalPreInit:%1",_GlobalPreInit);
if !(_GlobalPreInit isEqualTo "") then {
    call compile _GlobalPreInit;
};

if (!(hasInterface) || (isServer)) then {
    [QGVAR(EndmissionEvent), {
        params ["_scenario"];
        [QEGVAR(EndMission,LocalObjectsEvent), []] call CBA_fnc_localEvent;
    }] call CBA_fnc_addEventHandler;
};

GVAR(CachedDisplayNames) = [];

ADDON = true;
