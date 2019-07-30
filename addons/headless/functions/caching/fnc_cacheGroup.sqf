/*
 * Author: TheMagnetar
 * Caches all units in a group except the leader or the driver
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_cacheGroup
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

_group setVariable [QEGVAR(caching,cached), true, true];

private _leader = leader _group;
{
    if (!(_x isEqualTo _leader) && {!("driver" isEqualTo (assignedVehicleRole _x))}) then {
        _x enableSimulationGlobal false;
        _x hideObjectGlobal true;
    };
} forEach (units _group);
