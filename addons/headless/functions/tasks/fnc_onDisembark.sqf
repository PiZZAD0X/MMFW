/*
 * Author: TheMagnetar
 * Disembark units from a vehicle.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Distance <NUMBER> (default )
 *
 * Return Value:
 * Nearest vehicles suitable for the group
 *
 * Example:
 * [leader group player] call mmfw_vehicle_fnc_getNearVehicles
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if (!local _group) exitWith {};

private _disembarkUnits = (units _group) select {alive _x && {_x getVariable [QEGVAR(vehicle,markedForDisembark), false]}};

if (_disembarkUnits isEqualTo []) exitWith {};

// Units that have just disembarked
private _markAsDisembarked = _disembarkUnits select {vehicle _x == _x && {!(_x getVariable [QEGVAR(vehicle,disembarked), false])}};
{
    _x setVariable [QEGVAR(vehicle,disembarked), true];
    _group setSpeedMode "FULL";
    _x doMove (_x getVariable [QEGVAR(vehicle,checkedPos), [0,0,0]]);
} forEach _markAsDisembarked;

// Select units that are ready
private _unitsToStop = _disembarkUnits select {(moveToCompleted _x || {moveToFailed _x}) && {!(_x getVariable [QEGVAR(vehicle,ready), false])}};
{
    _x setUnitPos "MIDDLE";
    doStop _x;
    _x setVariable [QEGVAR(vehicle,ready), true];
    _x setVariable [QEGVAR(vehicle,waitUntil), CBA_missionTime + 5 + random 5];
} forEach _unitsToStop;

private _readyUnits = _disembarkUnits select {CBA_missionTime > (_x getVariable [QEGVAR(vehicle,waitUntil), CBA_missionTime])};

// Wait until all units are in position and waited enough time
if (count _readyUnits != count _disembarkUnits) exitWith {};

{
    _x setUnitPos "UP";
    _x setVariable [QEGVAR(vehicle,ready), false];
    _x setVariable [QEGVAR(vehicle,disembarked), false];
    _x setVariable [QEGVAR(vehicle,markedForDisembark), false];
    _x setVariable [QEGVAR(vehicle,waitUntil), nil];
} forEach _disembarkUnits;

[QEGVAR(tasks,embark), _group] call CBA_fnc_localEvent;

/*
if (_group getVariable [QEGVAR(tasks,checkBuildings), false]) then {
    [QEGVAR(tasks,patrolBuildings), _group] call CBA_fnc_localEvent;
    _group setVariable [QEGVAR(tasks,checkBuildings), false];
} else {
    [QEGVAR(tasks,patrol), _group] call CBA_fnc_localEvent;
};*/
