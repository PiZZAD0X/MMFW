/*
 * Author: Olsen
 *
 * Changes value in GVAR(Teams) for set team.
 *
 * Arguments:
 * 0: Team name <string>
 * 1: Index of variable to change <number>
 * 2: Value to set variable to <any>
 *
 * Return Value:
 * found <bool>
 *
 * Public: No
 */


#include "script_component.hpp"

params [
    ["_team", "", [""]],
    ["_index", 0, [0]],
    "_value"
];
private _findIndex = GVAR(Teams) findIf {_x select 0 == _team};
if (_findIndex isEqualto -1) exitWith {
    ERROR_1("Critical:<br></br>Team ""%1"" does not exist.", _team);
    false
};
(GVAR(Teams) select _findIndex) set [_index, _value];
true
