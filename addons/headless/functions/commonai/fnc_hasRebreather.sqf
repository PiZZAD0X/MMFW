/*
 * Author: TheMagnetar
 * Returns wether a unit has a rebreather equipped
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Unit has a rebreather <BOOL>
 *
 * Example:
 * [player] call mmfw_core_fnc_hasRebreather
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_unit"];

private _vest = vest _unit;

_vest isKindOf "V_RebreatherB"
