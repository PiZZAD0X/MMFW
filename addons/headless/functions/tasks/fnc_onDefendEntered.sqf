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
 * [group player] call mmfw_tasks_fnc_onDefendStateEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _marker = HASHGET(_settings,marker);

_marker = [_marker] call EFUNC(waypoint,selectRandomMarker);
[_group, _marker] call CBA_fnc_taskDefend;
