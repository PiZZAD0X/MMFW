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
 * [group1] call mmfw_cache_fnc_uncacheGroup
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

_group setVariable [QEGVAR(caching,cached), false, true];

{
    if (!simulationEnabled _x) then {
        _x enableSimulationGlobal true;
        _x hideObjectGlobal false;
        if (vehicle _x == _x) then {
            _x setPosATL (formationPosition _x);
        };
    };
} forEach (units _group);
