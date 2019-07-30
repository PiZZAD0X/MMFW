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
 * [group player] call mmfw_tasks_fnc_onFlankEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

private _targetPos = _group getVariable QEGVAR(tasks,targetPos);
private _leader = leader _group;

// Try to flank
private _dir = _leader getDir _targetPos;
_dir = if (random 1 < .5) then {_dir + 90} else {_dir - 90};

private _currentPos = getPosATL _leader;
private _dist = ((_currentPos distance _targetPos) * 2 / 3) min 200;
_targetPos = _currentPos getPos [_dist, _dir];

_group move _targetPos;
