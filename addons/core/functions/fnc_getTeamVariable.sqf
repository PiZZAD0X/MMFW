/*
 * Author: Olsen
 *
 * Retrieve variable for a set team from GVAR(Teams).
 *
 * Arguments:
 * 0: Team name <string>
 * 1: Index of variable to retrieve <number>
 *
 * Return Value:
 * 0 <number> if not found, var value <any> if found
 *
 * Public: No
 */

#include "script_component.hpp"

params [
    ["_team", "", [""]],
    ["_index", 0, [0]]
];
private _findIndex = GVAR(Teams) findIf {_x select 0 == _team};
if (_findIndex isEqualto -1) exitWith {
    ERROR_1("Critical:<br></br>Team ""%1"" does not exist.", _team)
};
private _return = GVAR(Teams) select _findIndex select _index;

_return
