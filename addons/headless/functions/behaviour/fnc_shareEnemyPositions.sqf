/*
 * Author: TheMagnetar
 * Share enemy positions with other groups of the same side.
 *
 * Arguments:
 * 0: Group <OBJECT>
 * 1: Radius <NUMBER> (default: -1)
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player, 100] call mmfw_behaviour_fnc_shareEnemyPositions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", ["_radius", -1]];

private _knownEnemies = _group getVariable [QEGVAR(behaviour,knownEnemies), []];
if (_knownEnemies isEqualTo []) exitWith {};

if (_radius isEqualTo -1) then {
    _group getVariable [QEGVAR(behaviour,shareDistance), 500];
};

private _leader = leader _group;
private _side = side _leader;
private _Groups = allGroups select {_x getVariable [QEGVAR(commonai,enabled), false] && {side (leader _x) isEqualTo _side}};

{
    private _grpEnemies = _group getVariable [QEGVAR(behaviour,knownEnemies), []];
    _grpEnemies append _knownEnemies;
    _grpEnemies = _grpEnemies arrayIntersect _grpEnemies;

    // Take care of groups not being local
    if (!local _x) then {
        _group setVariable [QEGVAR(behaviour,knownEnemies), _grpEnemies, true];
    };
} forEach _Groups;
