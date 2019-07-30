/*
 * Author: TheMagnetar
 * Deletes all groups assigned to a marker.
 *
 * Arguments:
 * 0: Marker <STRING> (default: "")
 * 1: Filter <CODE> (default: {})
 *
 * Return Value:
 * None
 *
 * Example:
 * ["marker1", {true}] call mmfw_core_fnc_deleteMarkerGroups
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

    private _units = units _x;
    _units append ([_x] call EFUNC(vehicle,getGroupVehicles));

    {
        deleteVehicle _x;
    } forEach _units;

    deleteGroup _x;
} forEach _groups;
