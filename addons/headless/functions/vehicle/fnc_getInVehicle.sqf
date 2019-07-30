/*
 * Author: TheMagnetar
 * Embark units to a vehicle.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Distance <NUMBER> (default )
 *
 * Return Value:
 * Nearest vehicles suitable for the group
 *
 * Example:
 * [vehicle player, [player]] call mmfw_vehicle_fnc_getInVehicle
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_vehicle", "_units"];

private _emptyPositions = [_vehicle] call EFUNC(vehicle,emptyPositions);

private _leader = leader (_units select 0);

if (((vehicle _leader) isEqualTo _leader) && {"commander" in _emptyPositions}) then {
    _leader assignAsCommander _vehicle;
    _emptyPositions deleteAt (_emptyPositions find "commander");
};

// Prioritise driver, gunner and commander seats
{
    private _unit = _x;
    private _assigned = false;
    if ("driver" in _emptyPositions) then {
        _unit assignAsDriver _vehicle;
        _emptyPositions deleteAt (_emptyPositions find "driver");
        _assigned = true;
    };

    if ("gunner" in _emptyPositions && {!_assigned}) then {
        _unit assignAsGunner _vehicle;
        _emptyPositions deleteAt (_emptyPositions find "gunner");
        _assigned = true;
    };

    if ("commander" in _emptyPositions && {!_assigned}) then {
        _unit assignAsCommander _vehicle;
        _emptyPositions deleteAt (_emptyPositions find "commander");
        _assigned = true;
    };

    {
        if (["turret", _unit] in _emptyPositions && {!_assigned}) exitWith {
            _unit assignAsTurret [_vehicle, _x];
            _assigned = true;
        };
    } forEach (allTurrets [_vehicle, false]);

    // After filling in crew positions, try to fill in cargo ones
    {
        if (_x select 0 isEqualTo "turret" && {!_assigned}) exitWith {
            _unit assignAsTurret [_vehicle, _x select 1];
        };

        if (_x select 0 isEqualTo "cargo" && {!_assigned}) exitWith {
            _unit assignAsCargoIndex [_vehicle, _x select 1];
        };
    } forEach _emptyPositions;
} forEach _units;

_units orderGetIn true;
