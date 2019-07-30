/*
 * Author: TheMagnetar
 * Moves all units to the specified positions
 *
 * Arguments:
 * 0: Units <ARRAY>
 * 1: Positions <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_core_fnc_moveUnitsToPositions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_units", "_positions"];

if (count _units != count _positions) exitWith {
    ERROR_2("Different number of units (%1) and positions (%2)",count _units, count _positions);
};

{
    _x setPosATL (_positions select _forEachIndex);
} forEach _units;
