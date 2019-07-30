/*
 * Author: TheMagnetar
 * Task defend.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_onDefendState
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if (!local _group) exitWith {};

if !(CBA_missionTime >= (_group getVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime])) exitWith {};

if ((units _group) findIf {alive _x} isEqualTo -1) exitWith {deleteGroup _group;};

// TODO: Call reinforcement checks

// Perform the next check in 5 seconds
_group setVariable [QEGVAR(tasks,nextCheckTime), CBA_missionTime + 5];
