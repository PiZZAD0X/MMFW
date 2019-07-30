/*
 * Author: TheMagnetar
 * Checks marker array format.
 *
 * Arguments:
 * 0: Marker(s) <STRING><ARRAY> (default: "")
 *
 * Return Value:
 * Marker input correctly formated <BOOL>
 *
 * Example:
 * ["marker1"] call mmfw_waypoint_fnc_checkMarkerInput
 * [["marker1", 20], ["marker2", 70], ["marker3", 10]] call mmfw_waypoint_fnc_checkMarkerInput
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_markers", "", ["", []]]
];

if (_markers isEqualTo "" || {_markers isEqualTo []}) exitWith {
    ERROR("Empty markers");
    false
};

if (_markers isEqualType "") exitWith {
    private _correct = true;

    if ((getMarkerColor _markers) isEqualTo "") then {
        ERROR_1("Marker %1 does not exist", _markers);
        _correct = false;
    };

    _correct
};

if (_markers isEqualType []) exitWith {
    private _correct = true;

    {
        if (count _x != 2) exitWith {
            _correct = false;
        };

        if (!((_x select 0) isEqualType "") || {!((_x select 1) isEqualType 0)}) exitWith {
            _correct = false;
        };
    } forEach _markers;

    _correct
};
