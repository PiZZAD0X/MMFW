/*
 * Author: TheMagnetar
 * Returns all empty positions of a vehicle
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 *
 * Return Value:
 * Empty positions <ARRAY>
 *
 * Example:
 * [group player] call mmfw_vehicle_fnc_emptyPositions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_vehicle"];

private _emptyPositions = [];

{
    if (isNull (_x select 0)) then {
        private _role = toLower (_x select 1);
        if (_role in ["cargo", "turret"]) then {
            if (_role isEqualTo "cargo") then {
                _emptyPositions pushBack ["cargo", _x select 2];
            } else {
                _emptyPositions pushBack ["turret", _x select 3];
            };
        } else {
            _emptyPositions pushBack _role;
        };
    };
} forEach (fullCrew [_vehicle, "", true]);

_emptyPositions
