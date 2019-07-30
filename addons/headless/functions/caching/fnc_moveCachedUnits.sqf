/*
 * Author: TheMagnetar
 * Moves cached unit close to leader positions so that they can be affected by explosions or artillery fire.
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

{
    if (!simulationEnabled _x && {vehicle _x == _x}) then {
        _x setPosATL (formationPosition _x);
    };
} forEach (units _group);

[QEGVAR(caching,cache), _group] call CBA_fnc_localEvent;
