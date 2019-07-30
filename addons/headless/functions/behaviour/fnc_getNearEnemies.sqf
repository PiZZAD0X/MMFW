/*
 * Author: TheMagnetar
 * Returns an array of dead bodies within the given distance visible by the unit
 *
 * Arguments:
 * 0: Unit <OBJECT><ARRAY>
 * 1: Radius <NUMBER> (default: -1)
 *
 * Return Value:
 * Array of dead bodies <ARRAY>
 *
 * Example:
 * [player, 100] call mmfw_behaviour_fnc_getNearEnemies
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_unit", ["_radius", -1]];

private _targets = _unit nearTargets _radius;

_targets
