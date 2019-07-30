/*
 * Author: TheMagnetar
 * Handles assigning the additional options to the group.
 *
 * Arguments:
 * 0: Settings <HASH>
 * 1: Additional options <ARRAY> (default: [])
 *
 * Return Value:
 * Settings expanded with the parsed options <HASH>
 *
 * Example:
 * [player, [["task", "patrol"]]] call mmfw_core_fnc_parseOptions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_settings", ["_options", []]];

{
    _x params ["_key", "_value"];

    if (_value isEqualType "" && {_value == "true" || _value == "false"}) then {
        if (_value == "true") then {
            _value = true;
        } else {
            _value = false;
        };
    };

    switch (toLower _key) do {
        case "allowland": { HASHSET(_settings,allowLand,_value); };
        case "allowvehicles": { [_settings, "allowVehicles", _value] call CBA_fnc_hashSet };
        case "allowwater": { HASHSET(_settings,allowWater,_value); };
        case "behaviour": { HASHSET(_settings,behaviour,_value); };
        case "blacklist": { HASHSET(_settings,blacklist,_value); };
        case "combatmode": { HASHSET(_settings,combatMode,_value); };
        case "createtemplate": { HASHSET(_settings,createTemplate,_value); };
        case "deletespawnmarkers": { HASHSET(_settings,deleteSpawnMarkers,_value); };
        case "execwaypoint": { HASHSET(_settings,execWaypoint,_value); };
        case "flyinheight": { HASHSET(_settings,flyInHeight,_value); };
        case "forceroads": { HASHSET(_settings,forceRoads,_value); };
        case "formation": { HASHSET(_settings,formation,_value); };
        case "fullcache": { HASHSET(_settings,fullCache,_value); };
        case "init": { HASHSET(_settings,init,_value); };
        case "patrolbuildings": { HASHSET(_settings,patrolBuildings,_value); };
        case "perimetersettings": { HASHSET(_settings,perimeterSettings,_value); };
        case "perimetercenter": { HASHSET(_settings,perimeterSettings,[_value, (HASHGET(_settings,perimeterSettings)) select 1]); };
        case "perimeterradius": { HASHSET(_settings,perimeterSettings,[(HASHGET(_settings,perimeterSettings)) select 0, _value]); };
        case "prespawn": { HASHSET(_settings,preSpawn,_value); };
        case "randombehaviour": { HASHSET(_settings,randomBehaviour,_value); };
        case "randomposition": {HASHSET(_settings,randomPosition,_value); };
        case "reinforcement": {HASHSET(_settings,reinforcement,_value); };
        case "release": {HASHSET(_settings,release,_value); };
        case "skill": { HASHSET(_settings,skill,_value); };
        case "skillleader": { HASHSET(_settings,skillLeader,_value); };
        case "spawninbuilding": { HASHSET(_settings,spawnInBuilding,_value); };
        case "speed": { HASHSET(_settings,speed,_value); };
        case "swimindepth": { HASHSET(_settings,swimInDepth,_value); };
        case "task": { HASHSET(_settings,task,format [QEGVAR(tasks,%1),_value]); };
        case "template": { HASHSET(_settings,template,_value); };
        case "waitatwaypoint": { HASHSET(_settings,waitAtWaypoint,_value); };
        case "waypointmarkers": { HASHSET(_settings,waypointMarkers,_value); };
    };
} forEach _options;

_settings
