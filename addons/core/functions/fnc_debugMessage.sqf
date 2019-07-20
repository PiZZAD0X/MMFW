/*
 * Author: PiZZADOX
 *
 * Checks and adds debug message
 *
 * Arguments:
 * 0: message <string>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);

if !(UO_FW_Server_DEBUG_Allowed) exitWith {};

params ["_message"];

if (isMultiplayer) then {
    [QGVAR(DebugMessageEvent), [_message]] call CBA_fnc_globalEvent;
} else {
    [_message] call FUNC(debugMessageDisplay);
};
