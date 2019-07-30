/*
 * Author: TheMagnetar
 * Task patrol.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_handlePatrolRandomState
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

if !(CBA_missionTime >= (_group getVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime])) exitWith {};

if ((units _group) findIf {alive _x} isEqualTo -1) exitWith {deleteGroup _group;};

private _leader = leader _group;
private _targetPos = waypointPosition [_group, 0];

if (!local _leader) exitWith {
    _group setVariable [QEGVAR(tasks,waitUntil), _group getVariable [QEGVAR(tasks,waitUntil), CBA_missionTime], true];
    _group setVariable [QEGVAR(tasks,distance), _group getVariable [QEGVAR(tasks,distance), (getPos _leader) distance2D _targetPos], true];
    _group setVariable [QEGVAR(tasks,buildingCheckTime), _group getVariable [QEGVAR(tasks,buildingCheckTime), CBA_missionTime], true];
    _group setVariable [QEGVAR(tasks,inBuilding), _group getVariable [QEGVAR(tasks,inBuilding), false], true];
};

// Do not do advanced actions if unit is cached
if (_group getVariable [QEGVAR(tasks,cached), false]) exitWith {};

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _checkingDistance = HASHGET(_settings,checkingDistance);
private _reachedDistance = HASHGET(_settings,reachedDistance);

// Search for a vehicle
private _distance = _leader distance _targetPos;

if (_distance > _reachedDistance && {vehicle _leader == _leader} && {HASHGET(_settings,allowVehicles)}) then {
    // TODO: Check for vehicles
};

// Start patrolling buildings if units are near the waypoint
private _unitType = HASHGET(_settings,type);
private _inBuilding = _group getVariable [QEGVAR(tasks,inBuilding), false];

if (_inBuilding && {CBA_missionTime > (_group getVariable [QEGVAR(tasks,finishedBuildingPatrol), CBA_missionTime])}) then {
    _inBuilding = false;
    _group setVariable [QEGVAR(tasks,buildingCheckTime), CBA_missionTime + 10];
};

private _buildingCheckTime = _group getVariable [QEGVAR(tasks,buildingCheckTime), CBA_missionTime];
private _checkProbability = (1 - _distance/(_group getVariable [QEGVAR(tasks,distance), _leader distance _targetPos]))*100 min 70;

if (_unitType in ["infantry", "wheeled"] && {CBA_missionTime >= _buildingCheckTime} && {_distance < _checkingDistance} && {HASHGET(_settings,patrolBuildings)} && {!_inBuilding} && {random 100 < _checkProbability}) then {
    if (_unitType isEqualTo "wheeled") then {
        _group setVariable [QEGVAR(tasks,checkBuildings), true];
        [QEGVAR(tasks,disembark), _group] call CBA_fnc_localEvent;
    } else {
        [QEGVAR(tasks,patrolBuildings), _group] call CBA_fnc_localEvent;
    };
};

// Perform the next check in 10 seconds
_group setVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime + 5];
