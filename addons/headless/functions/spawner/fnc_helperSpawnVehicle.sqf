/*
 * Author: TheMagnetar
 * Helper routine for spawning a random group of units with vehicles.
 *
 * Arguments:
 * 0: Config entry <STRING>
 * 1: Settings <HASH>
 * 2: Side <STRING>
 * 3: Size <NUMBER>
 * 4: Marker <STRING>
 * 6: Position <ARRAY> (default: [])
 *
 * Return Value:
 * None
 *
 * Example:
 * ["usmcWheeled", [], "west", 5, "marker", 0.05] call mmfw_spawn_fnc_helperSpawnVehicle
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_configEntry", "_settings", "_side", "_size", ["_targetPos", []]];

private _vehiclePool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "vehicles");
private _crewPool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "crew");
private _cargoLeaders = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "cargoLeaders");
private _cargoPool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "cargo");
private _pilotPool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "pilot");
private _random = (getNumber (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "random")) == 1;

_size params ["_groupSize", "_cargoSize"];
if (_random) then {
    {
        if (count _x > 1) then {
           _x = [_x, 10] call EFUNC(commonai,shuffleArray);
        };
    } forEach [_vehiclePool, _crewPool, _cargoLeaders, _cargoPool, _pilotPool];
} else {
    _groupSize = count _vehiclePool;
};

private _spawnVehicles = [];

for "_i" from 1 to _groupSize do {

    private _vehicle = objNull;
    private _crewUnits = [];
    private _pilots = [];
    private _cargoUnits = [];

    if (_random) then {
        _vehicle = selectRandom _vehiclePool;
        private _roles = _vehicle call BIS_fnc_vehicleRoles;
        private _turrets = [_vehicle, false] call BIS_fnc_allTurrets;

        _cargoUnits pushBack (selectRandom _cargoLeaders);

        private _numCargo = 0;

        {
            private _role = toLower (_x select 0);
            switch (_role) do {
                case "cargo": {
                    if (_numCargo < (_cargoSize - 1)) then {
                        _cargoUnits pushBack (selectRandom _cargoPool);
                        _numCargo = _numCargo + 1;
                    };
                };
                case "driver": {
                    if (_vehicle isKindOf "Air") then {
                        _pilots pushBack (selectRandom _pilotPool);
                    } else {
                        _crewUnits pushBack (selectRandom _crewPool);
                    };
                };
                case "gunner": {
                    if (_vehicle isKindOf "Air") then {
                        _pilots pushBack (selectRandom _pilotPool);
                    } else {
                        _crewUnits pushBack (selectRandom _crewPool);
                    };
                };
                case "commander": {
                    _crewUnits pushBack (selectRandom _crewPool);
                };
                case "turret": {
                    if (_vehicle isKindOf "Air" && {getNumber ([_vehicle, _x select 1] call CBA_fnc_getTurret >> "isCopilot") == 1}) then {
                        _pilots pushBack (selectRandom _pilotPool);
                    } else {
                        if (_x select 1 in _turrets) then {
                            _crewUnits pushBack (selectRandom _crewPool);
                        } else {
                            if (_numCargo < (_cargoSize - 1)) then {
                                _cargoUnits pushBack (selectRandom _cargoPool);
                                _numCargo = _numCargo + 1;
                            };
                        };
                    };
                };
            };
        } forEach _roles;
    } else {
        _vehicle = _vehiclePool select (_i - 1);
        _crewUnits = _crewPool;
        _pilots = _pilotPool;

        _cargoUnits = [];
        _cargoUnits append _cargoLeaders;
        _cargoUnits append _cargoPool;
    };

    _spawnVehicles pushBack [_vehicle, _crewUnits, _cargoUnits, _pilots];
};

EGVAR(spawner,spawnQueue) pushBack [_spawnVehicles, _side, _targetPos, _settings];

if (EGVAR(spawner,spawnGroupPFH) isEqualTo -1) then {
    EGVAR(spawner,spawnGroupPFH) = [DEFUNC(spawner,spawnGroupPFH), 1, []] call CBA_fnc_addPerFrameHandler;
};
