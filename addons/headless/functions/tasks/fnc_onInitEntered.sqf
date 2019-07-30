/*
 * Author: TheMagnetar
 * Task patrol.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_onInitEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

if !(_group getVariable[QEGVAR(tasks,taskInit), false]) then {
    _group getVariable[QEGVAR(tasks,taskInit), true];
};

private _settings = _group getVariable [QEGVAR(commonai,settings), []];

// TODO make the reached distance depend on marker size?
HASHSET(_settings,reachedDistance,10);
HASHSET(_settings,checkingDistance,150);

if (HASHGET(_settings,task) == QEGVAR(tasks,patrolRandom) || {HASHGET(_settings,task) == QEGVAR(tasks,patrol)}) then {
    HASHSET(_settings,behaviour,["safe"]);
    HASHSET(_settings,speed,["limited"]);

    _group setBehaviour "safe";
    _group setSpeedMode "limited";
};

if (HASHGET(_settings,forceRoads)) then {
    (leader _group) forceFollowRoad true;
};

[_group] call EFUNC(waypoint,clearWaypoints);
_group setVariable [QEGVAR(commonai,settings), _settings, true];
