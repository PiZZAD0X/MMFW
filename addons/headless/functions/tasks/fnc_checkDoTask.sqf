/*
 * Author: TheMagnetar
 * Checks if a group should start doing something
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * Do task? <BOOL>
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_checkDoTask
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _task = HASHGET(_settings,task);

!(_task isEqualTo "donothing")
