/*
 * Author: Olsen
 *
 * Counts number of casualties on set team
 *
 * Arguments:
 * 0: team <string>
 *
 * Return Value:
 * casualty count <number>
 *
 * Public: Yes
 */


#include "script_component.hpp"

params ["_team"];
private _count = 0;
private _start = [_team, 3] call FUNC(GetTeamVariable);
private _current = [_team, 4] call FUNC(GetTeamVariable);
if (_start isEqualto 0) then {
    ERROR_1("Casualty count:<br></br>Warning no units on team ""%1"".", _team);
} else {
    _count = _start - _current;
};

_count
