/*
 * Author: Olsen
 *
 * Adds new team.
 *
 * Arguments:
 * 0: side of new team <side>
 * 1: name of new team <string>
 * 2: type of new team: "ai"/"player"/"both" <string>
 *
 * Return Value:
 * nothing
 *
 * Public: Yes
 */


#include "script_component.hpp"
EXEC_CHECK(SERVER);

params [["_side", sideUnknown, [sideUnknown]],["_name", "Unknown", [""]],["_Type", "both", [""]]];

if (isMultiplayer) then {
    GVAR(Teams) set [count (GVAR(Teams)), [_name, _side, _Type,  0, 0, [], []]];
} else {
    GVAR(Teams) set [count (GVAR(Teams)), [_name, _side, "both",  0, 0, [], []]];
};
