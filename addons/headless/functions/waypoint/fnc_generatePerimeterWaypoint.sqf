/*
 * Author: TheMagnetar
 * Generates a set of waypoints for perimeter patrolling.
 *
 * Arguments:
 * 0: Group <OBJECT> (default: [])
 * 1: Center of the waypoint patrol <ARRAY>
 * 2: Radius of the waypoint patrol <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_waypoint_fnc_generatePerimeterWaypoint
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [["_group", objNull], "_center", "_radius", ["_options", []]];

// Taken from CBA_fnc_taskPatrol.sqf
private _count = floor (4 + _radius/25);
private _step = 360 / _count;
private _offset = random _step;
private _statements = [];

_options params [["_waypointType", "MOVE"], ["_execStatements", ""], ["_condition", "true"]];
_statements pushBack _execStatements;

for "_i" from 1 to _count do {
    // Gaussian distribution avoids all waypoints ending up in the center
    private _rad = _radius * random [0.4, 0.75, 1];

    // Alternate sides of circle & modulate offset
    private _theta = (_i % 2) * 180 + sin (deg (_step * _i)) * _offset + _step * _i;

    if (_i == _count) then {
        _statements pushBack QUOTE(_group setVariable [ARR_2(QQEGVAR(tasks,patrolFinished), true)]);
        private _settings = _group getVariable [QEGVAR(commonai,settings), []];
        if !((HASHGET(_settings,task)) isEqualTo QEGVAR(waypoint,patrol)) then {
            _statements pushBack QUOTE([ARR_2(QQEGVAR(waypoint,doTask), _group)] call CBA_fnc_localEvent);
        };
    };

    [_group, _center getPos [_rad, _theta], _waypointType, _statements joinString ";", _condition] call EFUNC(waypoint,addWaypoint);

    if (EGVAR(commonai,debugEnabled)) then {
        private _markerName = format ["marker_%1_%2", CBA_missionTime, _i];
        createMarker [_markerName, _center getPos [_rad, _theta]];
        _markerName setMarkerShape "icon";
        _markerName setMarkerType "hd_dot";
        _markerName setMarkerColor "colorRed";
    };
};
