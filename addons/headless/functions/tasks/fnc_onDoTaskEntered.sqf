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
 * [group player] call mmfw_tasks_fnc_onDoTaskStateEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
[HASHGET(_settings,task), _group] call CBA_fnc_localEvent;
