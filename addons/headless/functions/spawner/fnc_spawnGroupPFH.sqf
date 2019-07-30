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
 * [[], 2] call mmfw_spawn_fnc_spawnGroupPFH
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_param", "_handle"];

if (EGVAR(spawner,spawnQueue) isEqualTo []) exitWith {
    [EGVAR(spawner,spawnGroupPFH)] call CBA_fnc_removePerFrameHandler;
    EGVAR(spawner,spawnGroupPFH) = -1;
};

private _toSpawn = EGVAR(spawner,spawnQueue) deleteAt 0;
_toSpawn params [
    ["_entity", [], [[]]],
    ["_side", "", [""]],
    ["_position", [], [[]]],
    ["_settings", []]
];

[_entity, _side, _position, _settings] call EFUNC(spawner,helperSpawnGroup);
