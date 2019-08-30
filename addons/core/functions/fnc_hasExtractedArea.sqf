/*
 * Author: BlackHawk
 *
 * Checks if given part of team has extracted to set area.
 * This function accounts for team starting in extraction area.
 *
 * Arguments:
 * 0: team name <string>
 * 1: extraction area marker <string>
 * 2: part of team that has to extract (0.8 - 80%, etc.) <number> (OPTIONAL)
 *
 * Return Value:
 * has team extracted <bool>
 *
 * Public: Yes
 */


#include "script_component.hpp"
EXEC_CHECK(SERVER);

params [["_team", "", [""]],["_area", [], [[]]],["_ratio", 1, [0]]];

private _side = [_team, 1] call FUNC(getTeamVariable);
private _count = {
    (_x inArea _area)
} count ([_side] call FUNC(alivePlayers));

private ["_respawnTypeNum","_result"];

_result = false;
_ratio = _ratio/100;

switch (_side) do {
    case west: {
        _respawnTypeNum = EGETMVAR(EndConditions,hasDeparted_BLUFOR,false);
        if (_count >= _ratio * ([_team, 4] call FUNC(getTeamVariable))) then {
            if (_respawnTypeNum) then {
                _result = true;
            };
        } else {
            ESETMPVAR(EndConditions,hasDeparted_BLUFOR,true);
        };
    };
    case east: {
        _respawnTypeNum = EGETMVAR(EndConditions,hasDeparted_OPFOR,false);
        if (_count >= _ratio * ([_team, 4] call FUNC(getTeamVariable))) then {
            if (_respawnTypeNum) then {
                _result = true;
            };
        } else {
            ESETMPVAR(EndConditions,hasDeparted_OPFOR,true);
        };
    };
    case independent: {
        _respawnTypeNum = EGETMVAR(EndConditions,hasDeparted_Indfor,false);
        if (_count >= _ratio * ([_team, 4] call FUNC(getTeamVariable))) then {
            if (_respawnTypeNum) then {
                _result = true;
            };
        } else {
            ESETMPVAR(EndConditions,hasDeparted_Indfor,true);
        };
    };
    case civilian: {
        _respawnTypeNum = EGETMVAR(EndConditions,hasDeparted_Civ,false);
        if (_count >= _ratio * ([_team, 4] call FUNC(getTeamVariable))) then {
            if (_respawnTypeNum) then {
                _result = true;
            };
        } else {
            ESETMPVAR(EndConditions,hasDeparted_Civ,true);
        };
    };
    default {_result = false;};
};

_result
