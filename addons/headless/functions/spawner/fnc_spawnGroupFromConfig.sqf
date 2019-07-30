/*
 * Author: TheMagnetar
 * Spawns a group defined in a config entry.
 *
 * Arguments:
 * 0: Config entry <STRING> (default: "")
 * 1: Group size either in [min, max] format or a defined number <ARRAY><NUMBER> (default: 0)
 * 2: Marker <STRING> (default: "")
 * 3: Position <ARRAY><OBJECT><LOCATION><GROUP> (default: [])
 * 4: Additional options for the group <ARRAY> (default: [])
 *
 * Return Value:
 * None
 *
 * Example:
 * ["infantryUSMC", [2, 5], "marker"] call mmfw_spawn_fnc_spawnGroupFromConfig
 ^ ["infantryUSMC", 4, "marker", player] call mmfw_spawn_fnc_spawnGroupFromConfig
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_configEntry", "", [""]],
    ["_groupSize", 0, [[], 0], [2]],
    ["_marker", "", ["", []]],
    ["_position", [], [[], objNull, grpNull, locationNull], [0, 2, 3]],
    ["_overrideOptions", [], [[]]]
];

if !([_marker] call EFUNC(waypoint,checkMarkerInput)) exitWith {};

if (_configEntry isEqualTo "" || {!isClass (missionConfigFile >> "CfgGroupCompositions" >> _configEntry)}) exitWith {
    ERROR_1("Empty or invalid config entry %1",_configEntry);
};

_position = _position call CBA_fnc_getPos;

// Basic options should be always defined
private _options = [];
{
    private _values = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> _x);
    _options pushBack [_x, _values];
} forEach ["behaviour", "combatMode", "formation", "speed", "skill", "skillLeader"];

// Additional options defined in config
private _options = getArray (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "options");

// Init settings for the group
private _settings = [] call CBA_fnc_hashCreate;
private _type = toLower (getText (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "type"));
_settings = [_settings, _marker, _type] call EFUNC(commonai,setBasicSettings);
_settings = [_settings, _options] call EFUNC(commonai,parseOptions);

if !(_overrideOptions isEqualTo []) then {
    [_settings, _overrideOptions] call EFUNC(commonai,parseOptions);
};

// Determine group size
private _size = if (_type isEqualTo "infantry") then {
    [_groupSize] call EFUNC(commonai,getRandomMinMax);
} else {
    _groupSize params ["_gSize", "_cargoSize"];
    [[_groupSize select 0] call EFUNC(commonai,getRandomMinMax), [_groupSize select 1] call EFUNC(commonai,getRandomMinMax)];
};

// Determine group side
private _side = getText (missionConfigFile >> "CfgGroupCompositions" >> _configEntry >> "side");

// Generate units
if (_type isEqualTo "infantry") then {
    [_configEntry, _settings, _side, _size, _position] call EFUNC(spawner,helperSpawnInfantry);
} else {
    [_configEntry, _settings, _side, _size, _position] call EFUNC(spawner,helperSpawnVehicle);
};
