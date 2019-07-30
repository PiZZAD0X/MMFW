/*
 * Author: TheMagnetar
 * Applies the settings to the group before units are spawned
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: objNull)
 * 1: Settings <HASH>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_core_fnc_applyOptionsPreSpawn
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", ["_settings", []]];

if (_settings isEqualTo []) then {
    _settings = _group getVariable [QEGVAR(commonai,settings), []];
};

// PreSpawn code
[_group] call compile (HASHGET(_settings,preSpawn));

// Prepare the marker configuration in order to spawn/select initial position
private _marker = HASHGET(_settings,marker);
_marker = [_marker] call EFUNC(waypoint,organizeMarkers);

HASHSET(_settings,marker,_marker);

[_group, _settings] call EFUNC(commonai,handleStartPosition);
