/*
 * Author: TheMagnetar
 * Gets all groups assigned to the marker.
 *
 * Arguments:
 * 0: Marker <STRING> (default: "")
 * 1: Filter <CODE> (default: {})
 *
 * Return Value:
 * Groups <ARRAY>
 *
 * Example:
 * ["marker", {true}] call mmfw_core_fnc_getMarkerGroups
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_marker", "", [""]],
    ["_filter", {}, [{}]]
];

private _groups = missionNamespace getVariable [format [QGVAR(%1), _marker], []];

private _filteredGroups = [];
{
    if ((_filter isEqualTo {}) || {[_x] call _filter}) then {
        _filteredGroups pushBack _x;
    };
} forEach _groups;

_filteredGroups
