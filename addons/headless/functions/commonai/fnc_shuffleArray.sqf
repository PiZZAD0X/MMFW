/*
 * Author: TheMagnetar
 * Shuffles an array.
 *
 * Arguments:
 * 0: Array to be shuffled <ARRAY>
 *
 * Return Value:
 * Suffled array
 *
 * Example:
 * [[0,1, 2, 3], 50] call mmfw_core_fnc_shuffleArray
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_array", "_iterations"];

private _length = count _array;

for "_iter" from 1 to _iterations do {
    _array pushBack (_array deleteAt (floor random _length));
};

_array
