/*
 * Author: TheMagnetar
 * Random position on an elliptical marker.
 *
 * Arguments:
 * 0: Length X <NUMBER>
 * 1: Length Y <NUMBER>
 * 2: X coordinate of the marker's center <NUMBER>
 * 3: Y coordinate of the marker's center <NUMBER>
 * 4: Marker direction in degrees <NUMBER>
 *
 * Return Value:
 * Random point <ARRAY> ([0,0] if invalid marker)
 *
 * Example:
 * [2, 3, 0.5, 0,5, 60] call mmfw_waypoint_fnc_elipMarkerRandomPos
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_sizeX", "_sizeY", "_centerX", "_centerY", "_markerDir"];

// Apply inverse CFG technique to get a random angle and radius
private _rnd = (random 1) / 4;
private _theta = (_sizeY * tan (_rnd*360)) atan2 _sizeX;

private _v = random 1;

if (_v >= 0.25 && _v < 0.5) then {_theta = 180 - _theta};
if (_v >= 0.5 && _v < 0.75) then {_theta = 180 + _theta};
if (_v >=  0.75) then {_theta = -_theta};

private _maxRadius = _sizeX * _sizeY / sqrt( (_sizeY*cos(_theta))^2 + (_sizeX*sin(_theta))^2);
private _radius = _maxRadius*sqrt(random 1);

private _xRnd = _centerX + _radius*cos(_theta);
private _yRnd = _centerY + _radius*sin(_theta);

private ["_xCoord", "_yCoord"];

if (_markerDir != 0) then {
    // Apply 2D rotation matrix
    _xCoord = cos(_markerDir)*_xRnd - sin(_markerDir)*_yRnd;
    _yCoord = sin(_markerDir)*_xRnd + cos(_markerDir)*_yRnd;
} else {
    _xCoord = _xRnd;
    _yCoord = _yRnd;
};

[_xCoord, _yCoord];
