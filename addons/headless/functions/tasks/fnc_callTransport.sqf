/*
 * Author: TheMagnetar
 * Checks if a group should start doing something
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * Do task? <BOOL>
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_checkDoTask
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_type", ["_requestedType", ""]];

if !(_type isEqualTo "infantry") exitWith {};

private _unitCount = {alive _x} count (units _group);
private _pickUpPos = getPosATL (leader _group);

// Check if a transport is available within a certain radius
private _availableGroups = [];
private _enabledGroups = allGroups select {_x getVariable [QEGVAR(commonai,enabled), false]};

{
    private _settings = _x getVariable [QEGVAR(commonai,settings), []];
    private _task = HASHGET(_settings,task);
    if (_task isEqualTo "transport" && {!(_x getVariable [QEGVAR(tasks,inMission), false])}) then {
        // Check if the transport can go to the designated coordinates
        private _positionAllowed = false;

        private _targetPos = waypointPosition [_x, 0];
        if ((surfaceIsWater _targetPos && {surfaceIsWater _pickUpPos}) && {HASHGET(_settings,allowWater)}) then {
            _positionAllowed = true;
        };

        if (!surfaceIsWater _targetPos && {!surfaceIsWater _pickUpPos} && {HASHGET(_settings,allowLand)}) then {
            _positionAllowed = true;
        };

        if (_requestedType != "") then {
            private _transportType = HASHGET(_settings,type);
            if !(_transportType isEqualTo toLower _requestedType) then {
                _positionAllowed = false;
            };
        };

        if (_positionAllowed) then {
            // Check if the vehicle transport has enough empty cargo spaces
            private _vehicle = vehicle (leader _x);
            private _availablePositions = {isNull (_x select 0)} count (fullCrew [_vehicle, "cargo", true]) ;

            if (_availablePositions >= _unitCount) then {
                _availableGroups pushBack [_vehicle distance2D _group, _x];
            };
        };
    };
} forEach _enabledGroups;

// Get the nearest transport
_availableGroups sort true;
private _groupTransport = (_availableGroups select 0) select 1;
_groupTransport setVariable [QEGVAR(tasks,inMission), true];
[_groupTransport, _pickupPos, "MOVE"] call EFUNC(waypoint,addWaypoint);
