/*
 * Author: TheMagnetar
 * Removes a group from the AI management addon
 *
 * Arguments:
 * 0: Group <OBJECT> (default: objNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_core_fnc_removeGroup
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if (!local _group) exitWith {};

if ((_group getVariable [QEGVAR(commonai,settings), []]) isEqualTo []) exitWith {
    ERROR_1("Group %1 has not been initialised",_group);
};

_group setVariable [QEGVAR(commonai,enabled), false];
