/*
 * Author: Olsen
 *
 * Counts units on set side in area of set diameter around object.
 *
 * Arguments:
 * 0: side <side>
 * 1: radious <number>
 * 2: center of area <object>
 *
 * Return Value:
 * amount of units in area <number>
 *
 * Public: Yes
*/

#include "script_component.hpp"

params [
    ["_side", sideUnknown, [sideUnknown]],
    ["_radius", 0, [0]],
    ["_logic", objNull, [objNull]],
    ["_noUntracked", false]
];

private _count = {
    (side _x isEqualto _side)
    && {!_noUntracked && {!(GETVAR(_x,DontTrack,false))}}
    && {_x call FUNC(isAlive)}
    && {(_x distance _logic) < _radius}
} count allUnits;

_count
