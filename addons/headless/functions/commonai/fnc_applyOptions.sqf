/*
 * Author: TheMagnetar
 * Applies the settings to the group.
 *
 * Arguments:
 * 0: Group <OBJECT> (Default: objNull)
 * 1: Settings <HASH>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player call mmfw_core_fnc_applyOptions
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", ["_settings", []]];

if (_settings isEqualTo []) then {
    _settings = _group getVariable [QEGVAR(commonai,settings), []];
};

_group setBehaviour (selectRandom (HASHGET(_settings,behaviour)));
_group setCombatMode (selectRandom (HASHGET(_settings,combatMode)));
_group setFormation (selectRandom (HASHGET(_settings,formation)));
_group setSpeedMode (selectRandom (HASHGET(_settings,speed)));

private _skill = HASHGET(_settings,skill);
private _skillLeader = HASHGET(_settings,skillLeader);
[_group, [_skill, _skillLeader]] call EFUNC(commonai,setSkill);

// Init settings
[_group] call compile (HASHGET(_settings,init));

private _templateName = HASHGET(_settings,createTemplate);
if !(_templateName isEqualTo "") then {
    [_group, _templateName, _settings] call EFUNC(commonai,createTemplate);
};

// Handle spawn and waypoint markers and group register
private _markers = HASHGET(_settings,marker);
private _deleteSpawnMarkers = HASHGET(_settings,deleteSpawnMarkers);
private _waypointMarkers = HASHGET(_settings,waypointMarkers);

private _startPosition = _group getVariable [QEGVAR(commonai,startPosition), []];
if (_startPosition isEqualTo []) then {
    _startPosition = getPos (leader _group);
};

if (_deleteSpawnMarkers) then {
    if !(_waypointMarkers isEqualTo []) then {
        _markers = [];
    } else {
        ERROR_1("Delete spawn markers option was active for group %1 without specifying additional waypoint markers",_group);
    };
};

_markers append _waypointMarkers;

_markers = [_markers] call EFUNC(waypoint,organizeMarkers);
HASHSET(_settings,marker,_markers);

if (HASHGET(_settings,fullCache)) then {
    [_group] call EFUNC(caching,cacheFullGroup);
};
