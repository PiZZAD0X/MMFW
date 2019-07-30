/*
 * Author: TheMagnetar
 * Handles entered. Inspired by FUPS.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_onFlank
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if !(CBA_missionTime >= (_group getVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime])) exitWith {};

if ((units _group) findIf {alive _x} isEqualTo -1) exitWith {deleteGroup _group;};

if (!local _group) exitWith {
    _group setVariable [QEGVAR(tasks,targetPos), _group getVariable [QEGVAR(tasks,targetPos)], true];
};

private _leader = leader _group;
if (_leader distance (_group getVariable QEGVAR(tasks,targetPos)) < CLOSE_ATTACK_DISTANCE) exitWith {
     [QEGVAR(tasks,taskAttack), _group] call CBA_fnc_localEvent;
};

// Perform the next check in 5 seconds
_group setVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime + 1];
