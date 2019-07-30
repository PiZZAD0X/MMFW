/*
 * Author: TheMagnetar
 * Handles positioning a spawned group or editor placed groups with random start positions.
 *
 * Arguments:
 * 0: Group <OBJECT>
 * 1: Settings <HASH> (Default: [])
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_spawn_fnc_handleStartPosition
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", ["_settings", []]];

if (_settings isEqualTo []) then {
    _settings = _group getVariable [QEGVAR(commonai,settings), []];
};
private _inRandomPosition = HASHGET(_settings,randomPosition);
private _inRandomBuilding = HASHGET(_settings,spawnInBuilding);
private _blackListedMarkers = HASHGET(_settings,blacklist);

if (_blackListedMarkers isEqualTo "") then {
    _blackListedMarkers = [_blackListedMarkers];
};

private _spawnMarkers = HASHGET(_settings,marker);
private _marker = ([_spawnMarkers] call EFUNC(waypoint,selectRandomMarker));
private _position = _group getVariable [QEGVAR(commonai,startPosition), []];

// Exit if marker configuration is invalid and position is either empty or at [0, 0, 0]
if (!([_marker] call EFUNC(waypoint,checkMarkerInput)) && {_position isEqualTo [] || {_position isEqualTo [0, 0, 0]}}) exitWith {
    ERROR("Invalid marker configuration and/or empty or null position speficied");
};

// Only infantry units spawn in buildings
private _type = HASHGET(_settings,type);
if (!(_type isEqualTo "infantry") && {_inRandomBuilding}) then {
    _inRandomBuilding = false;
    HASHSET(_settings,spawnInBuilding,false);
};

private _units = units _group;
if (_units isEqualTo []) then {
    _units =+ (_group getVariable [QEGVAR(spawner,unitsToSpawn), []]);
} else {
    private _inMarker = "";
    private _leaderPos = position (leader _group);
    {
        if (_leaderPos inArea (_x select 0)) exitWith {
            _inMarker = _x select 0;
        };
    } forEach _spawnMarkers;

    _group setVariable [QEGVAR(commonai,registerMarker), _inMarker];
};

if (_inRandomPosition || {!(_position isEqualTo [])} ) exitWith {
    private _allowWater = HASHGET(_settings,allowWater);
    private _allowLand = HASHGET(_settings,allowLand);
    private _forceRoads = HASHGET(_settings,forceRoads);

    private _moveUnits = false;

    // Select a unit
    private _unit = "";
    if ((_units select 0) isEqualTypeAny ["", []]) then {
        if ((_units select 0) isEqualType "") then {
            _unit = _units select 0;
        } else {
            _unit = _units select 0 select 0;
        };
    } else {
        // These are editor placed units. Move them at the end of the function
        _moveUnits = true;
        private _unitInVehicle = _units findIf {vehicle _x != _x};
        if (_unitInVehicle != -1) then {
            _unit = typeOf (vehicle (_units select _unitInVehicle));
        } else {
            _unit = typeOf (_units select 0);
        };
    };

    if (_position isEqualTo [0, 0, 0]) then {
        _position = [_marker, [_allowWater, _allowLand, _forceRoads], [0, 50, _unit], _blackListedMarkers] call EFUNC(waypoint,markerRandomPos);
        _group setVariable [QEGVAR(commonai,registerMarker), _marker];
    } else {
        private _inMarker = "";
        {
            if (_position inArea (_x select 0)) exitWith {
                _inMarker = _x select 0;
            };
        } forEach _spawnMarkers;

        _group setVariable [QEGVAR(commonai,registerMarker), _inMarker];
    };

    if (_moveUnits) then {
        [_group, _position] call EFUNC(commonai,moveGroupToPosition);
    } else {
        _group setVariable [QEGVAR(commonai,startPosition), _position];
    };
};

if (_inRandomBuilding) exitWith {
    _group setVariable [QEGVAR(commonai,registerMarker), _marker];

    private _positions = [count _units, _marker, [["area", _marker], ["enterable", true], ["blacklist", _blackListedMarkers]], false] call EFUNC(waypoint,markerRandomBuildingPos);

    // Generate positions for all units
    if (count _units > count _positions) then {

        // Generate a random position since there are no suitable buildings
        if (_positions isEqualTo []) then {
            private _unitType = _units select 0;
            if !(_unitType isEqualTo "") then {
                _unitType = typeOf _unitType;
            };
            _positions pushBack ([_marker, [false, true, false], [0, 50, _unitType], _blackListedMarkers] call EFUNC(waypoint,markerRandomPos));
        };

        private _requiredPositions = (count _units) - (count _positions) - 1;
        private _numPositions = count _positions;
        for "_i" from 0 to _requiredPositions do {
            private _unitType = _units select (_numPositions + _i);
            if !(_unitType isEqualTo "") then {
                _unitType = typeOf _unitType;
            };
            _positions pushBack ((_positions select 0) findEmptyPosition [0, 60, _unitType]);
        };
    };

    private _moveUnits = false;
    if !((_units select 0) isEqualType "") then {
        _moveUnits = true;
    };

    if (_moveUnits) then {
        [units _group, _positions] call EFUNC(commonai,moveUnitsToPositions);
    } else {
        _group setVariable [QEGVAR(commonai,startPosition), _positions];
    };
};

if ((units _group) isEqualTo []) then {
    ERROR("No position assigned");
}
