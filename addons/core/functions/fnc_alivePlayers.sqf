/*
 * Author: PiZZADOX
 *
 * Returns an array of all alive players. Can return alive players of given sides
 *
 * Arguments:
 * 0: side <side> (optional)
 *
 * Return Value:
 * array
 *
 * Public: Yes
*/

#include "script_component.hpp"

params [["_teams", [], [[]]]];

private _alivePlayers = allPlayers select {
    _x call FUNC(isAlive)
    && {!(_x isKindOf "HeadlessClient_F")}
};

private _return = if !(_teams isEqualto []) then {
    _alivePlayers select {side _x in _teams}
} else {
    _alivePlayers
};

_return
