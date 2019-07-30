/*
 * Author: TheMagnetar
 * Returns a random position in a marker.
 *
 * Arguments:
 * 0: Marker <STRING> (default: "")
 * 1: Condition <ARRAY> (default: [false, true, false])
 *  0: Allow waypoint on water <BOOL>
 *  1: Allow waypoint on land <BOOL>
 *  2: Force waypoint on roads <BOOL>
 * 2: Check radius for a valid unit position <ARRAY> (default: [0, 50, ""])
 *  0: Min radius <NUMBER>
 *  1: Max radius <NUBMER>
 *  2: Object classname <STRING>
 *
 * Return Value:
 * Random point <ARRAY> ([0,0] if invalid marker)
 *
 * Example:
 * ["marker"] call mmfw_waypoint_fnc_markerRandomPos
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_marker", "", ["", []]],
    ["_condition", [false, true, false]],
    ["_checkRadius", [0, 50, ""]],
    ["_blacklisted", [], [[]]]
];

if (_marker isEqualTo "" || {_marker isEqualTo []}) exitWith {[0, 0, 0]};

private _center = getMarkerPos _marker;
private _centerX = abs (_center select 0);
private _centerY = abs (_center select 1);

private _markerSize = getMarkerSize _marker;
private _sizeX = _markerSize select 0;
private _sizeY = _markerSize select 1;
private _markerDir = markerDir _marker;

private "_rndFunction";
if (toLower (markerShape _marker) == "rectangle") then {
    _rndFunction = missionNamespace getVariable QEFUNC(waypoint,recMarkerRandomPos);
} else {
    _rndFunction = missionNamespace getVariable QEFUNC(waypoint,elipMarkerRandomPos);
};

private _tries = 0;
private _targetPos = [];
_checkRadius params [["_minRadius", 0], ["_maxRadius", 0], ["_vehicleType", ""]];
_condition params [["_allowWater", false], ["_allowLand", true], ["_forceRoads", false]];

while {_tries < 50} do {
    private _trialPos = [_sizeX, _sizeY, _centerX, _centerY, _markerDir] call _rndFunction;
    private _found = false;

    private _inBlacklisted = false;
    {
        if (_trialPos inArea _x) exitWith {
            _inBlacklisted = true;
        };
    } forEach _blacklisted;

    if (!_inBlacklisted && {_allowWater} && {surfaceIsWater _trialPos}) then {
        _found = true;
    };

    if (!_inBlacklisted && {_allowLand} && {!surfaceIsWater _trialPos}) then {
        if (_forceRoads) then {
            private _roads = (_trialPos nearRoads 50);
            if !(_roads isEqualTo []) then {
                {
                    _trialPos = getPosATL (selectRandom _roads);
                    if ((_trialPos inArea _marker)) exitWith {_found = true};
                } forEach _roads;
            };
        } else {
            _found = true;
        };
    };

    if (!_inBlacklisted && {_allowWater} && {_allowLand} && {!_forceRoads}) then {
        _found = true;
    };

    if (_found) then {
        private _checkedPos = [];
        if (_vehicleType isEqualTo "") then {
            _checkedPos = _trialPos findEmptyPosition [_minRadius, _maxRadius];
        } else {
            _checkedPos = _trialPos findEmptyPosition [_minRadius, _maxRadius, _vehicleType];
        };

        {
            if (_checkedPos inArea _x) exitWith {
                _inBlacklisted = true;
            };
        } forEach _blacklisted;

        if (_checkedPos isEqualTo [] || {_inBlacklisted} || {!(_checkedPos inArea _marker)}) then {
            _tries = _tries + 1;
            _found = false;
        } else {
            _targetPos = _checkedPos;
            _tries = 50;
        };
    } else {
        _tries = _tries + 1;
    };
};

_targetPos
