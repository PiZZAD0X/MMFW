/*
 * Author: TheMagnetar
 * Spawn PFH.
 *
 * Arguments:
 * 0: Parameters <ARRAY>
 * 1: PerFrameHandler identifier <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[], 2] call mmfw_spawn_fnc_spawnUnitsGroupPFH
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_handle"];

private _unitsToSpawn = _group getVariable [QEGVAR(spawner,unitsToSpawn), []];

if (_unitsToSpawn isEqualTo []) exitWith {
    [_handle] call CBA_fnc_removePerFrameHandler;
    _group setVariable [QEGVAR(commonai,startPosition), nil];
    _group setVariable [QEGVAR(spawner,template), nil];
    _group setVariable [QEGVAR(spawner,unitsToSpawn), nil];

    private _settings = _group getVariable [QEGVAR(commonai,settings), []];
    [_group, _settings] call EFUNC(commonai,applyOptions);

    _group setVariable [QEGVAR(commonai,settings), _settings];

    // Register the group
    private _marker = _group getVariable [QEGVAR(commonai,registerMarker), ""];
    [QEGVAR(commonai,registerGroup), [_group, _marker]] call CBA_fnc_serverEvent;

    if !(HASHGET(_settings,release)) then {
        _group setVariable [QEGVAR(commonai,enabled), true];
    };
};

private _pos = _group getVariable [QEGVAR(commonai,startPosition), [0, 0, 0]];
private _position = [0, 0, 0];
if ((_pos select 0) isEqualType []) then {
    _position = _pos deleteAt 0;
} else {
    _position = _pos;
};
private _unitType = _unitsToSpawn deleteAt 0;

private _templateValues = _group getVariable [QEGVAR(spawner,template), []];
private _useTemplate = !(_templateValues isEqualTo []);
private _applyTemplate = {
    params ["_unit", "_loadout", "_rank", "_skill"];

    _unit setUnitLoadout _loadout;
    _unit setRank _rank;
    _unit setSkill _skill;
};

if (_unitType isEqualType "") then {
    private _unitPos = _position findEmptyPosition [0, 60, _unitType];
    private _spawnedUnit = _group createUnit [_unitType, _unitPos, [], 2, "FORM"];

    if (isNull (_group getVariable [QEGVAR(commonai,leader), objNull])) then {
        _group selectLeader _spawnedUnit;
        _group setVariable [QEGVAR(commonai,leader), _spawnedUnit, true];
    };

    if (_useTemplate) then {
        _templateValues params ["_loadout", "_rank", "_skill"];
        [_spawnedUnit, _loadout deleteAt 0, _rank deleteAt 0, _skill deleteAt 0] call _applyTemplate;
    };
} else {
    _unitType params ["_vehicle", ["_crew", []], ["_cargo", []], ["_pilots",[]]];

    _templateValues params ["_loadout", "_rank", "_skill"];
    (_loadout select 0) params ["_loadoutVeh", "_loadoutCrew", "_loadoutCargo", "_loadoutPilots"];
    (_rank select 0) params ["_rankCrew", "_rankCargo", "_rankPilots"];
    (_skill select 0) params ["_skillCrew", "_skillCargo", "_skillPilots"];

    private _unitPos = _position findEmptyPosition [0, 60, _vehicle];

    private _vehicleUnit = createVehicle [_vehicle, _unitPos, [], 20, "FORM"];
    private _vehicleRoles = fullCrew [_vehicleUnit, "", true];
    private _turrets = allTurrets [_vehicleUnit, false];
    private _hasCommander = false;
    private _hasGunner = false;

    private _handleUnitCreation = {
        params ["_group", "_unit", "_loadout", "_rank", "_skill", "_useTemplate"];

        private _nullPos = [0, 0, 0];
        private _spawnedUnit = _group createUnit [_unit, _nullPos, [], 0, "CAN_COLLIDE"];

        if (_useTemplate) then {
            [_spawnedUnit, _loadoutPilots deleteAt 0, _rankPilots deleteAt 0, _skillPilots deleteAt 0] call _applyTemplate;
        };

        _spawnedUnit
    };

    {
        private _role = toLower (_x select 1);
        private _unit = objNull;

        switch (_role) do {
            case "driver": {
                if (_vehicle isKindOf "Air") then {
                    if !(_pilots isEqualTo []) then {
                        _unit = [_group, _pilots deleteAt 0, _loadoutPilots deleteAt 0, _rankPilots deleteAt 0, _skillPilots deleteAt 0, _useTemplate] call _handleUnitCreation;
                    };
                } else {
                    if !(_crew isEqualTo []) then {
                        _unit = [_group, _crew deleteAt 0, _loadoutCrew deleteAt 0, _rankCrew deleteAt 0, _skillCrew deleteAt 0, _useTemplate] call _handleUnitCreation;
                    };
                };
                _unit moveInDriver _vehicleUnit;
            };

            case "gunner": {
                if (_vehicle isKindOf "Air") then {
                    if !(_pilots isEqualTo []) then {
                        _unit = [_group, _pilots deleteAt 0, _loadoutPilots deleteAt 0, _rankPilots deleteAt 0, _skillPilots deleteAt 0, _useTemplate] call _handleUnitCreation;
                    };
                } else {
                    if !(_crew isEqualTo []) then {
                        _unit = [_group, _crew deleteAt 0, _loadoutCrew deleteAt 0, _rankCrew deleteAt 0, _skillCrew deleteAt 0, _useTemplate] call _handleUnitCreation;
                    };
                };
                _hasGunner = true;
                _unit moveInGunner _vehicleUnit;
            };

            case "turret": {
                if (_vehicle isKindOf "Air" && {getNumber ([_vehicle, _x select 3] call CBA_fnc_getTurret >> "isCopilot") == 1}) then {
                    if !(_pilots isEqualTo []) then {
                        _unit = [_group, _pilots deleteAt 0, _loadoutPilots deleteAt 0, _rankPilots deleteAt 0, _skillPilots deleteAt 0, _useTemplate] call _handleUnitCreation;
                    };
                } else {
                    if (_x select 3 in _turrets) then {
                        if !(_crew isEqualTo []) then {
                            _unit = [_group, _crew deleteAt 0, _loadoutCrew deleteAt 0, _rankCrew deleteAt 0, _skillCrew deleteAt 0, _useTemplate] call _handleUnitCreation;
                        };
                    } else {
                        if !(_cargo isEqualTo []) then {
                            _unit = [_group, _cargo deleteAt 0, _loadoutCargo deleteAt 0, _rankCargo deleteAt 0, _skillCargo deleteAt 0, _useTemplate] call _handleUnitCreation;
                        };
                    };
                };
                _unit moveInTurret [_vehicleUnit, _x select 3];
            };

            case "commander": {
                if !(_crew isEqualTo []) then {
                    _unit = [_group, _crew deleteAt 0, _loadoutCrew deleteAt 0, _rankCrew deleteAt 0, _skillCrew deleteAt 0, _useTemplate] call _handleUnitCreation;

                    _hasCommander = true;
                    _unit moveInCommander _vehicleUnit;
                };
            };

            case "cargo": {
                if !(_cargo isEqualTo []) then {
                    _unit = [_group, _cargo deleteAt 0, _loadoutCargo deleteAt 0, _rankCargo deleteAt 0, _skillCargo deleteAt 0, _useTemplate] call _handleUnitCreation;

                    _unit assignAsCargoIndex [_vehicleUnit, _x select 2];
                    _unit moveInCargo _vehicleUnit;
                };
            };
        };
    } forEach _vehicleRoles;

    if (isNull (_group getVariable [QEGVAR(commonai,leader), objNull])) then {
        private _leader = objNull;

        if (_hasCommander) then {
            _leader = commander _vehicleUnit;
        } else {
            if (_vehicleUnit isKindOf "Air") then {
                _leader = driver _vehicleUnit;
            } else {
                if (_hasGunner) then {
                    _leader = gunner _vehicleUnit;
                } else {
                    _leader = driver _vehicleUnit
                };
            };
        };

        _group setVariable [QEGVAR(commonai,leader), _leader, true];
    };
};
