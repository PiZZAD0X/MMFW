/*
 * Author: TheMagnetar
 * Adds a waypoint to the specified group.
 *
 * Arguments:
 * 0: Group <OBJECT> (default: [])
 * 1: Target Position <ARRAY>
 * 2: Waypoint type <STRING> (default: "")
 * 3: Statemets execution at waypoint completion <STRING> (default: "")
 *
 * Return Value:
 * Waypoint <WAYPOINT>
 *
 * Example:
 * [group player, getPos _target, "MOVE", "hint 'moving'"] call mmfw_waypoint_fnc_generateWaypoint
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_targetPos", ["_waypointType", ""], ["_execStatements", ""], ["_condition", "true"], ["_radius", 0], ["_completionRadius", -1]];

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
if (_completionRadius isEqualTo -1) then {
    _completionRadius = HASHGET(_settings,reachedDistance);
};

private _waypoint = _group addWaypoint [_targetPos, _radius];

_waypoint setWaypointPosition [_targetPos, 0];

if (_waypointType isEqualTo "") then {
    switch (HASHGET(_settings,task)) do {
        default { _waypointType = "MOVE"; };
    };
};

_waypoint setWaypointType _waypointType;
_waypoint setWaypointCompletionRadius _completionRadius;

if (HASHGET(_settings,randomBehaviour)) then {
    _waypoint setWaypointFormation (selectRandom (HASHGET(_settings,formation)));
    _waypoint setWaypointSpeed (selectRandom (HASHGET(_settings,speed)));
    _waypoint setwaypointBehaviour (selectRandom (HASHGET(_settings,behaviour)));
    _waypoint setwaypointCombatMode (selectRandom (HASHGET(_settings,combatMode)));
} else {
    _waypoint setWaypointFormation "NO CHANGE";
    _waypoint setWaypointSpeed "UNCHANGED";
    _waypoint setwaypointbehaviour "UNCHANGED";
    _waypoint setwaypointCombatMode "NO CHANGE";
};

//_waypoint setWaypointCompletionRadius ([_settings, [_settings, "reachedDistance"]] call CBA_fnc_hashGet);
private _statements = [_execStatements, HASHGET(_settings,execWaypoint)];
_waypoint setWaypointStatements [_condition, _statements joinString ";"];

_waypoint
