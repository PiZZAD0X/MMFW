/*
 * Author: TheMagnetar
 * Helper routine for spawning a random group of infantry units.
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
 * ["usmcInfantry", [], "west", 5, "marker", 0.05] call mmfw_spawn_fnc_helperSpawnInfantry
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_configEntry", "_settings", "_side", "_size", ["_targetPos", []]];

private _leaderPool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "leaders");
private _unitPool = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "units");

private _random = (getNumber (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "random")) == 1;
private _spawnUnits = [];

if (_random) then {
    _unitPool = [_unitPool, 10] call EFUNC(commonai,shuffleArray);

    if (count _leaderPool > 1) then {
        _leaderPool = [_leaderPool, 10] call EFUNC(commonai,shuffleArray);
    };

    _spawnUnits pushBack (selectRandom _leaderPool);

    // Ignore leader
    for "_i" from 1 to (_size - 1) do {
        _spawnUnits pushBack (selectRandom _unitPool);
    };
} else {
    _spawnUnits append _leaderPool;
    _spawnUnits append _unitPool;
};

EGVAR(spawner,spawnQueue) pushBack [_spawnUnits, _side, _targetPos, _settings];

if (EGVAR(spawner,spawnGroupPFH) isEqualTo -1) then {
    EGVAR(spawner,spawnGroupPFH) = [DEFUNC(spawner,spawnGroupPFH), 1, []] call CBA_fnc_addPerFrameHandler;
};
