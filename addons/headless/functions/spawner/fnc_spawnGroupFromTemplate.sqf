/*
 * Author: TheMagnetar
 * Creates a group template.
 *
 * Arguments:
 * 0: Template name <STRING> (default: "")
 * 1: Group size either in [min, max] format or a defined number <ARRAY><NUMBER>
 * 2: Marker <STRING> (default: "")
 * 3: Position <ARRAY><OBJECT><LOCATION><GROUP> (default: [])
 * 4: Additional options for the group <ARRAY> (default: [])
 *
 * Return Value:
 * None
 *
 * Example:
 * ["SpecOps", "marker", 2] call mmfw_spawn_fnc_spawnGroupFromTemplate
 * ["SpecOps", "marker", 3, [], [["SpawnInBuildings", true]]] call mmfw_spawn_fnc_spawnGroupFromTemplate
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_templateName", "", [""]],
    ["_numGroups", 0, [[], 0], [2]],
    ["_marker", "", ["", []]],
    ["_position", [], [[], objNull, grpNull, locationNull], [0, 2, 3]],
    ["_overrideOptions", [], [[]]]
];

if (!([_marker] call EFUNC(waypoint,checkMarkerInput))) exitWith {};

private _template = [EGVAR(commonai,groupTemplates), _templateName] call CBA_fnc_hashGet;
if !(_template isEqualType []) exitWith {
    ERROR_1("Undefined template name %1",_templateName);
};

_template params ["_side", "_settings", "_units"];
_position = _position call CBA_fnc_getPos;

// Determine group size
private _num = [_numGroups] call EFUNC(commonai,getRandomMinMax);

if !(_overrideOptions isEqualTo []) then {
    [_settings, _overrideOptions] call EFUNC(commonai,parseOptions);
};

private _inRandomPosition = HASHGET(_settings,randomPosition);
private _inRandomBuilding = HASHGET(_settings,spawnInBuilding);
if (!_inRandomPosition && {!_inRandomBuilding} && {_position isEqualTo []}) then {
    HASHSET(_settings,randomPosition,true);
};

for "_i" from 1 to _num do {
    private _toSpawn =+ [_units, _marker, HASHGET(_settings,type), _side, _position, _settings, []];
    EGVAR(spawner,spawnQueue) pushBack _toSpawn;
};

if (EGVAR(spawner,spawnGroupPFH) isEqualTo -1) then {
    EGVAR(spawner,spawnGroupPFH) = [DEFUNC(spawner,spawnGroupPFH), 1, []] call CBA_fnc_addPerFrameHandler;
};
