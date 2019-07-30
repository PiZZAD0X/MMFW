/*
 * Author: TheMagnetar
 * Returns a value between the specified minimum and maximum
 *
 * Arguments:
 * 0: Range [min, max] or number <ARRAY><NUMBER>
 *
 * Return Value:
 * Random number between min and max values <NUMBER>
 *
 * Example:
 * [[1, 3]] call mmfw_core_fnc_getRandomMinMax
 * [1] call mmfw_core_fnc_getRandomMinMax
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_range", 0, [[], 0], [2]]
];

private _value = 0;
if (_range isEqualType []) then {
    _range params ["_minSize", "_maxSize"];
    _value = _minSize + floor (random (_maxSize - _minSize));
} else {
    _value = _range;
};

_value
