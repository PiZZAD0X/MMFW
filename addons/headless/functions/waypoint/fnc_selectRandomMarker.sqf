/*
 * Author: TheMagnetar
 * Selects a marker randomly.
 *
 * Arguments:
 * 0: Marker(s) <STRING><ARRAY> (default: "")
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_waypoint_fnc_selectRandomMarker
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_markers", [], [[]]]
];

if (_markers isEqualTo []) exitWith {
    ERROR("Empty markers");
    ""
};

// Sum chances
private _rnd = (count _markers) random 100;
private _previousWeight = 0;
private _selectedMarker = "";
{
    _x params ["_marker", "_weight"];

    if (_rnd < _weight && {_rnd >= _previousWeight}) exitWith {
        _selectedMarker = _marker;
    };

    _previousWeight = _weight;
} forEach _markers;

_selectedMarker
