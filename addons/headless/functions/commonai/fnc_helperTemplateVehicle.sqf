/*
 * Author: TheMagnetar
 * Helper function for creating a template of a group with vehicles.
 *
 * Arguments:
 * 0: Group to clone <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [gropu player1] call mmfw_spawn_fnc_helperTemplateVehicle
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_modelGroup"];

private _units = units _modelGroup;
private _vehicleUnits = [];
{
    if (_x != vehicle _x) then {
        _vehicleUnits pushBackUnique (vehicle _x);
    }
} forEach _units;

private _unitsToSpawn = [];
private _loadout = [];
private _rank = [];
private _skill = [];

{
    private _vehicle = typeOf _x;

    private _crewUnits = [];
    private _pilots = [];
    private _cargoUnits = [];
    private _turrets = [_vehicle, false] call BIS_fnc_allTurrets;

    private _loadoutCrew = [];
    private _rankCrew = [];
    private _skillCrew = [];

    private _loadoutCargo = [];
    private _rankCargo = [];
    private _skillCargo = [];

    private _loadoutPilots = [];
    private _rankPilots = [];
    private _skillPilots = [];

    {
        private _role = toLower (_x select 1);
        private _unit = _x select 0;
        private _unitType = typeOf _unit;

        switch (_role) do {
            case "cargo": {
                _cargoUnits pushBack _unitType;
                _loadoutCargo pushBack (getUnitLoadout _unit);
                _rankCargo pushBack (rank _unit);
                _skillCargo pushBack (skill _unit);
            };
            case "driver": {
                if (_vehicle isKindOf "Air") then {
                    _pilots pushBack _unitType;
                    _loadoutPilots pushBack (getUnitLoadout _unit);
                    _rankPilots pushBack (rank _unit);
                    _skillPilots pushBack (skill _unit);
                } else {
                    _crewUnits pushBack _unitType;
                    _loadoutCrew pushBack (getUnitLoadout _unit);
                    _rankCrew pushBack (rank _unit);
                    _skillCrew pushBack (skill _unit);
                };
            };
            case "gunner": {
                if (_vehicle isKindOf "Air") then {
                    _pilots pushBack _unitType;
                    _loadoutPilots pushBack (getUnitLoadout _unit);
                    _rankPilots pushBack (rank _unit);
                    _skillPilots pushBack (skill _unit);
                } else {
                    _crewUnits pushBack _unitType;
                    _loadoutCrew pushBack (getUnitLoadout _unit);
                    _rankCrew pushBack (rank _unit);
                    _skillCrew pushBack (skill _unit);
                };
            };
            case "commander": {
                _crewUnits pushBack _unitType;
                _loadoutCrew pushBack (getUnitLoadout _unit);
                _rankCrew pushBack (rank _unit);
                _skillCrew pushBack (skill _unit);
            };
            case "turret": {
                if (_vehicle isKindOf "Air" && {getNumber ([_vehicle, _x select 3] call CBA_fnc_getTurret >> "isCopilot") == 1}) then {
                    _pilots pushBack _unitType;
                    _loadoutPilots pushBack (getUnitLoadout _unit);
                    _rankPilots pushBack (rank _unit);
                    _skillPilots pushBack (skill _unit);
                } else {
                    if (_x select 3 in _turrets) then {
                        _crewUnits pushBack _unitType;
                        _loadoutCrew pushBack (getUnitLoadout _unit);
                        _rankCrew pushBack (rank _unit);
                        _skillCrew pushBack (skill _unit);
                    } else {
                        _cargoUnits pushBack _unitType;
                        _loadoutCargo pushBack (getUnitLoadout _unit);
                        _rankCargo pushBack (rank _unit);
                        _skillCargo pushBack (skill _unit);
                    };
                };
            };
        };
    } forEach fullCrew [_x, "", false];

    _unitsToSpawn pushBack [_vehicle, _crewUnits, _cargoUnits, _pilots];
    _loadout pushBack [[], _loadoutCrew, _loadoutCargo, _loadoutPilots];
    _rank pushBack [_rankCrew, _rankCargo, _rankPilots];
    _skill pushBack [_skillCrew, _skillCargo, _skillPilots];

} forEach _vehicleUnits;

[_unitsToSpawn, _loadout, _rank, _skill]
