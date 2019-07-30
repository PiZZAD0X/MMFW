/*
 * Author: TheMagnetar
 * Returns near vehicles the unit is aware of that can be used by the group.
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

params ["_unit", "_distance"];

_unit nearentities [["CAR","TANK","SHIP","HELICOPTER"], _distance];
