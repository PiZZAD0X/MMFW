/*
 * Author: TheMagnetar
 * Executed when units enter the Patrol Random state.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_onPatrolRandomStateEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

// Do not generate any new waypoint
if !(_group getVariable [QEGVAR(tasks,generateWaypoint), true]) exitWith {
    _group setVariable [QEGVAR(tasks,generateWaypoint), true];
};

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _execStatements = "";
private _condition = "true";

if (HASHGET(_settings,waitAtWaypoint)) then {
    private _unitType = HASHGET(_settings,type);

    if (_unitType isEqualTo "infantry") then {
        _execStatements = QUOTE([ARR_2(QQEGVAR(tasks,wait), group this)] call CBA_fnc_localEvent);
    } else {
        private _vehicle = vehicle (leader _group);
        _execStatements = QUOTE([ARR_2(QQEGVAR(tasks,disembark), [ARR_4(group this, true, true, false)])] call CBA_fnc_localEvent);
        _condition = QUOTE(speed (vehicle (leader this)) == 0);
    };
} else {
    _execStatements = QUOTE([ARR_2(QQEGVAR(tasks,doTask), group this)] call CBA_fnc_localEvent);
};

private _marker = HASHGET(_settings,marker);
private _targetPos = [_group, _marker, ["MOVE", _execStatements, _condition]] call EFUNC(waypoint,generateWaypoint);
_group setVariable [QEGVAR(tasks,distance), (getPosWorld (leader _group)) distance2D _targetPos];
