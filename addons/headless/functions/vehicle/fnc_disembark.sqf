/*
 * Author: TheMagnetar
 * Disembark units from a vehicle.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Unassign vehicle <BOOL> (default: true)
 * 2: Do perimeter <BOOL> (default: true)
 * 3: Force disembark all units <BOOL> (default: false)
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_vehicle_fnc_disembark
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_vehicle", ["_unassign", true], ["_doPerimeter", true], ["_forceAll", false], ["_allowWater", false], ["_allowLand", true]];

private _units = [_vehicle, _forceAll] call EFUNC(vehicle,selectUnitsDisembark);

if (_units isEqualTo []) exitWith {};

private _group = group (_units select 0);
private _assignedGroupVehicles = _group getVariable [QEGVAR(vehicle,assignedVehicles), []];
_assignedGroupVehicles pushBackUnique _vehicle;
_group setVariable [QEGVAR(vehicle,assignedVehicles), []];

private _count = count _units;
private _dirIncrease = 0; private _dirOffset = 0;
switch (true) do {
    case (_count == 1): {_dirIncrease = 0; _dirOffset = 180;};
    case (_count == 2): {_dirIncrease = 120; _dirOffset = 120;}; // Units form a perimeter at the back of the vehicle with an angle of 120 degrees.
    case (_count >= 3 && {_count <= 5}): {_dirIncrease = 180/(_count -1); _dirOffset = 90;};
    case (_count > 5 && {_count <= 8}): {_dirIncrease = 240/(_count -1); _dirOffset = 60;};
    case (_count > 8): {_dirIncrease = 360/(_count - 1); _dirOffset = 0;};
};

{
    _x setVariable [QEGVAR(vehicle,assignedVehicle), _vehicle];
    if (_unassign) then {
        unassignVehicle _x;
    };

    doGetOut _x;
    [_x] allowGetIn false;
    _x setVariable [QEGVAR(vehicle,markedForDisembark), true];

    private _tries = 0;
    // Calculate new position
    while {_tries < 50 && {_doPerimeter}} do {
        // Start by checking the back of the vehicle
        private _dir = (getDir _vehicle) + (_dirOffset + random 10 - 5);
        _dirOffset = _dirOffset + _dirIncrease;

        private _trialPos = _vehicle getPos [20 + random 10 -5, _dir];

        if ((_allowWater && {surfaceIsWater _trialPos}) || {_allowLand && {!surfaceIsWater _trialPos}}) then {
            private _checkedPos = [];
            _checkedPos = _trialPos findEmptyPosition [0, 5, typeOf _x];

            if (_checkedPos isEqualTo []) then {
                _tries = _tries + 1;
            } else {
                _x setVariable [QEGVAR(vehicle,checkedPos), _checkedPos];
                if (EGVAR(core,debugEnabled)) then {
                    private _markerName = format ["marker_%1", CBA_missionTime + random 1];
                    createMarker [_markerName, _checkedPos];
                    _markerName setMarkerShape "icon";
                    _markerName setMarkerType "hd_dot";
                    _markerName setMarkerColor "colorGreen";
                };
                _tries = 50;
            };
        } else {
            _tries = _tries + 1;
        };
    };
} forEach _units;
