/*
 * Author: TheMagnetar
 * Uncaches all units and vehicles in a group.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_uncacheFullGroup
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if !(_group getVariable [QEGVAR(caching,fullCached), false]) exitWith {};

_group setVariable [QEGVAR(caching,fullCached), false, true];

private _units = units _group;
_units append ([_group] call EFUNC(vehicle,getGroupVehicles));

{
    _x enableSimulationGlobal true;
    _x hideObjectGlobal false;
} forEach _units;
