/*
 * Author: TheMagnetar
 * Checks if a unit has a visual on a position
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: objNull)
 * 1: Settings <HASH>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_core_fnc_applyOptions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    "_unit",
    "_tagetPosition",
    "_maxDistance",
    "_viewAngle",
    ["_ignoreObjects", [objNull, objNull], [[]]]
];

if (_tagetPosition isEqualType objNull) then {
    _tagetPosition = [_tagetPosition] call CBA_fnc_getPos;
} else {
    _tagetPosition = ATLtoASL ([_tagetPosition] call CBA_fnc_getPos);
};

private _hasVisual = false;
if (_unit distance _tagetPosition <= _maxDistance) then {
    // Check if it is between the view angle
    private _eyeDirection = eyeDirection _unit;
    _eyeDirection = (_eyeDirection select 0) atan2 (_eyeDirection select 1);
    private _eyePos = eyePos _unit;
    if ([eyePos _unit, _eyeDirection, _maxDistance, _viewAngle] call BIS_fnc_inAngleSector) then {
        private _visibility = [_ignoreObjects select 0, "VIEW", _ignoreObjects select 1] checkVisibility [_eyePos, _tagetPosition];

        if (_visibility > 0.6) then {
            _hasVisual = true;
        } else {
            _hasVisual = random 1 < _visibility;
        };
    };
};

_hasVisual
