/*
 * Author: TheMagnetar
 * Deletes a waypoint marker to the group.
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: grpNull)
 * 1: Marker <STRING> (Default: "")
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1, "marker"] call mmfw_waypoint_fnc_deleteWaypointMarker
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_group", grpNull, [grpNull]],
    ["_marker", "", [""]]
];

if (!local _group || {(getMarkerColor _marker) isEqualTo ""}) exitWith { false };

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _markers = HASHGET(_settings,marker);

private _index = -1;
{
    if (_x select 0 isEqualTo _marker) exitWith {
        _index = _forEachIndex;
    };
} forEach _markers;

if (_index isEqualTo -1) exitWith {false};

_markers deleteAt _index;

_markers = [_markers] call EFUNC(waypoint,organizeMarkers);

HASHSET(_settings,marker,_markers);

true
