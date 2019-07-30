/*
 * Author: TheMagnetar
 * Selects a marker randomly.
 *
 * Arguments:
 * 0: Group <STRING><ARRAY> (default: "")
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_waypoint_fnc_organizeMarkers
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_markers"];

if (_markers isEqualType "") exitWith {
    [[_markers, 100]]
};

private _totalWeight = 0;

{
    _totalWeight = _totalWeight + (_x select 1);
} forEach _markers;

{
    _x set [1, (_x select 1)/_totalWeight*100];
} forEach _markers;

_markers
