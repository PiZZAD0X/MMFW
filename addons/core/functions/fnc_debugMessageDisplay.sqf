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

params ["_message"];

if (isNil QGVAR(DebugMessages)) then {GVAR(DebugMessages) = [];};

if (!(_message in GVAR(DebugMessages))) then {
    GVAR(DebugMessages) pushback _message;
};

if (isNull (uiNamespace getVariable [QGVAR(DisplayID),displaynull])) then {
    QGVAR(Layer) cutRsc [QGVAR(Display), "PLAIN"];
};

[{
    params ["_message"];
    [{!(isNull (uiNamespace getVariable [QGVAR(DisplayID),displaynull]))}, {
        params ["_message"];
        [] call FUNC(refreshDebug);
        [{
            GVAR(DebugMessages) = GVAR(DebugMessages) - [_message];
            [] call FUNC(refreshDebug);
        }, [_message], 30] call CBA_fnc_waitAndExecute;
    }, [_message]] call CBA_fnc_waitUntilAndExecute;
}, [_message]] call CBA_fnc_execNextFrame;
