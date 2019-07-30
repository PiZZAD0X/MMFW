/*
 * Author: TheMagnetar
 * Random position on a rectangular marker.
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
 * [2, 3, 0.5, 0,5, 60] call mmfw_waypoint_fnc_recMarkerRandomPos
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_sizeX", "_sizeY", "_centerX", "_centerY", "_markerDir"];

private _randX = random (_sizeX * 2) - _sizeX;
private _randY = random (_sizeY * 2) - _sizeY;

private _xRnd = _centerX + _randX;
private _yRnd = _centerY + _randY;

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
