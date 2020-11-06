/*
 * Author: Olsen && PiZZADOX
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
if !(isServer) exitWith {};

params [
    ["_side", sideUnknown, [sideUnknown]],
    ["_name", "Unknown", [""]],
    ["_type", "both", [""]]
];

if !(isMultiplayer) then {
    _type = "both";
};

GVAR(Teams) pushBack [_name, _side, _type,  0, 0, [], []];
