/*
 * Author: TheMagnetar
 * Sets the basic setting parameters.
 *
 * Arguments:
 * 0: Settings <HASH>
 * 1: Marker <STRING>
 * 2: Group type <STRING>
 *
 * Return Value:
 * Hash with basic settings <HASH>
 *
 * Example:
 * [[], "marker", "infantry"] call mmfw_core_fnc_init
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_settings", "_marker", "_type"];

if !([_settings] call CBA_fnc_isHash) exitWith {
    WARNING_1("Passed argument is not a valid CBA Hash: %1",_settings);
    _settings
};

HASHSET(_settings,blacklist,[]);
HASHSET(_settings,deleteSpawnMarkers,false);
HASHSET(_settings,fullCache,false);
HASHSET(_settings,marker,_marker);
HASHSET(_settings,type,_type);
HASHSET(_settings,waypointMarkers,[]);

HASHSET(_settings,skillLeader,[]);
HASHSET(_settings,skill,[]);

HASHSET(_settings,task,QEGVAR(tasks,patrolRandom));

HASHSET(_settings,allowWater,false);
HASHSET(_settings,allowLand,true);
HASHSET(_settings,forceRoads,false);

HASHSET(_settings,randomBehaviour,true);
HASHSET(_settings,waitAtWaypoint,true);
HASHSET(_settings,allowVehicles,true);
HASHSET(_settings,patrolBuildings,true);
HASHSET(_settings,spawnInBuilding,false);
HASHSET(_settings,randomPosition,false);
HASHSET(_settings,reinforcement,true);
HASHSET(_settings,execWaypoint,"");
private _perimeter = [[_marker] call CBA_fnc_getPos, 100];
HASHSET(_settings,perimeterSettings,_perimeter);

HASHSET(_settings,init,"");
HASHSET(_settings,preSpawn,"");

HASHSET(_settings,template,"");
HASHSET(_settings,createTemplate,"");

HASHSET(_settings,release,false);


_settings
