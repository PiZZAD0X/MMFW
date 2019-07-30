/*
 * Author: TheMagnetar
 * Activates all groups assigned to a marker (groups are hidden).
 *
 * Arguments:
 * 0: Marker <STRING> (default: "")
 * 1: Filter <CODE> (default: {})
 *
 * Return Value:
 * None
 *
 * Example:
 * ["marker1", {true}] call mmfw_core_fnc_activateMarkerGroups
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_marker", "", [""]],
    ["_filter", {}, [{}]]
];

private _groups = [_marker, _filter] call EFUNC(commonai,getMarkerGroups);

{
    [_x] call EFUNC(caching,uncacheFullGroup);
} forEach _groups;
