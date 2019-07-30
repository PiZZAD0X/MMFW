/*
 * Author: TheMagnetar
 * Caches all units and vehicles in a group.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_cacheFullGroup
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if (_group getVariable [QEGVAR(caching,fullCached), false]) exitWith {};

_group setVariable [QEGVAR(caching,cached), false, true];
_group setVariable [QEGVAR(caching,fullCached), true, true];

private _units = units _group;
_units append ([_group] call EFUNC(vehicle,getGroupVehicles));

{
    _x enableSimulationGlobal false;
    _x hideObjectGlobal true;
} forEach _units;
