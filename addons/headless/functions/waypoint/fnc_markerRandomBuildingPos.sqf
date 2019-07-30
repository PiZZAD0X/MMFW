/*
 * Author: TheMagnetar
 * Returns a random building position in a marker.
 *
 * Arguments:
 * 0: Marker <STRING> (default: "")
 * 1: Condition <ARRAY> (default: [false, true, false])
 *  0: Allow waypoint on water <BOOL>
 *  1: Allow waypoint on land <BOOL>
 *  2: Force waypoint on roads <BOOL>
 * 2: Check radius for a valid unit position <ARRAY> (default: [0, 50, ""])
 *  0: Min radius <NUMBER>
 *  1: MAx radius <NUBMER>
 *  2: Object classname <STRING>
 *
 * Return Value:
 * Random point <ARRAY> ([0,0] if invalid marker)
 *
 * Example:
 * ["marker"] call mmfw_waypoint_fnc_markerRandomBuildingPos
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

// Get all buildings
params ["_numPos", "_position", "_filter"];

private _center = 0;
private _radius = 0;

if (_position isEqualType "") then {
    _center = getMarkerPos _position;
    (getMarkerSize _position) params ["_radiusX", "_radiusY"];
    _radius = _radiusX max _radiusY;
} else {
    if ((_position select 0) isEqualType []) then {
        private _marker = [_position] call EFUNC(waypoint,selectRandomMarker);
        _center = getMarkerPos _marker;
        (getMarkerSize _marker) params ["_radiusX", "_radiusY"];
        _radius = _radiusX max _radiusY;
    } else {
        _center = _position select 0;
        _radius = _position select 1;
    };
};

private _buildings = [_center, _radius] call EFUNC(building,getNearBuildings);

private _filteredBuildings = [_buildings, _filter] call EFUNC(building,filterBuildings);

if (_filteredBuildings isEqualTo []) exitWith {[]};

private _building = ([_filteredBuildings, 5] call EFUNC(commonai,shuffleArray)) select 0;
private _freePos = _building getVariable [QEGVAR(waypoint,freePositions), -1];

if (_freePos isEqualTo -1) then {
    _freePos = _building buildingPos -1;
};

private _returnPositions = [];

if (count _freePos < _numPos) then {
    _building setVariable [QEGVAR(waypoint,freePositions), []];
    _returnPositions =+ _freePos;
    _returnPositions append ([_numPos - (count _freePos), [getPos _building, 25], _filter, false] call EFUNC(waypoint,markerRandomBuildingPos));
} else {
    _returnPositions =+ ([_freePos, 5] call EFUNC(commonai,shuffleArray)) select [1, _numPos];
    {
        _freePos deleteAt (_freePos find _x);
    } forEach _returnPositions;

    _building setVariable [QEGVAR(waypoint,freePositions), _freePos];
};

_returnPositions
