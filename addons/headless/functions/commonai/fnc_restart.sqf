/*
 * Author: TheMagnetar
 * Reenables all AI management.
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: objNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_core_fnc_restart
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

if (_group getVariable [QEGVAR(commonai,settings), []] isEqualTo []) exitWith {
    ERROR_1("Group %1 has not been initialised",_group);
};

_group setVariable [QEGVAR(commonai,enabled), true, true];
