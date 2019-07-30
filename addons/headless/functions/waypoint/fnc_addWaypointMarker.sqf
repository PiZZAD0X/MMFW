/*
 * Author: TheMagnetar
 * Adds a waypoint marker to the group.
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: grpNull)
 * 1: Marker <STRING> (Default: "")
 * 2: Marker weight <NUMBER> (Default: 0)
 *
 * Return Value:
 * Operation successful <BOOL>
 *
 * Example:
 * [group1, "marker1", 50] call mmfw_waypoint_fnc_addWaypointMarker
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_group", grpNull, [grpNull]],
    ["_marker", "", [""]],
    ["_markerWeight", 0, [0]]
];

if (!local _group || {(getMarkerColor _marker) isEqualTo ""} || {_markerWeight isEqualTo 0}) exitWith { false };

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _markers = HASHGET(_settings,marker);

_markers append [_marker, _markerWeight];

_markers = [_markers] call EFUNC(waypoint,organizeMarkers);

HASHSET(_settings,marker,_markers);

true
