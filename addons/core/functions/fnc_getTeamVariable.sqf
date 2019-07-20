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
EXEC_CHECK(ALL);

params [["_team", "", [""]],["_index", 0, [0]]];
private _return = 0;
private _found = false;
{
    if ((_x select 0) isEqualto _team) exitWith {
        _return = (_x select _index);
        _found = true;
    };
} forEach GVAR(Teams);

if !(_found) then {
    ERROR_1("Critical:<br></br>Team ""%1"" does not exist.", _team)
};

_return
