/*
 * Author: TheMagnetar
 * Returns all vehicles of a group
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * Group vehicles <ARRAY>
 *
 * Example:
 * [player] call mmfw_core_fnc_getGroupVehicles
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

private _assignedVehicles = [];
{
    if (vehicle _x != _x) then {
        assignedVehicles pushBackUnique (vehicle _x);
        _assignedVehicles pushBackUnique (vehicle _x);
    };
} forEach (units _group);

_assignedVehicles
