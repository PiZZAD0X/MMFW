/*
 * Author: TheMagnetar
 * Helper routine for spawning group of units
 *
 * Arguments:
 * 0: Unit array. First position is always the leader <ARRAY>
 * 1: Marker <STRING>
 * 2: Unit type <STRING>
 * 3: Unit side <STRING>
 * 4: Position <ARRAY><OBJECT><LOCATION><GROUP>
 * 5: Settings <HASH>
 *
 * Return Value:
 * Group <OBJECT>
 *
 * Example:
 * [units, "east", [], []] call mmfw_spawn_fnc_helperSpawnGroup
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_units", "_side", "_position", "_settings"];

_position = _position call CBA_fnc_getPos;

private _group = objNull;
switch (toLower _side) do {
    case "civilian": {_group = createGroup civilian};
    case "east": {_group = createGroup east};
    case "resistance": {_group = createGroup resistance};
    case "west": {_group = createGroup west};
    default {_group = createGroup east};
};

_group setVariable [QEGVAR(spawner,settings), _settings, true];

if !(_position isEqualTo []) then {
    _group setVariable [QEGVAR(commonai,startPosition), _position];
};

_group setVariable [QEGVAR(commonai,settings), _settings];
_group setVariable [QEGVAR(spawner,unitsToSpawn), _units];

private _template = HASHGET(_settings,template);

if !(_template isEqualTo "") then {
    private _templateValues = [EGVAR(commonai,groupTemplates), _template] call CBA_fnc_hashGet;

    _templateValues params ["", "", "", "_loadout", "_rank", "_skill"];
    _group setVariable [QEGVAR(spawner,template), [_loadout, _rank, _skill]];
};

[_group, _settings] call EFUNC(commonai,applyOptionsPreSpawn);

[DEFUNC(spawner,spawnUnitsGroupPFH), 0.1, _group] call CBA_fnc_addPerFrameHandler;
