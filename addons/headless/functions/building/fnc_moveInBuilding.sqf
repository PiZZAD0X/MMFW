/*
 * Author: TheMagnetar
 * Move the some of all the unitss of the group to the near buildings.
 *
 * Arguments:
 * 0: Group <OBJECT> (default: objNull)
 * 1: Perform patrol <BOOL> (default: true)
 *
 * Return Value:
 * None
 *
 * Example:
 * [nearestBuilding player] call mmfw_building_fnc_moveInBuilding
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

private _unitsToMove = [];
private _rejectedUnits = [];

// Exclude the leader in patrolling the buildings
private _leader = leader _group;
private _units = units _group;
_units deleteAt (_units find _leader);

{
    if (_x isKindOf "CAManBase" && {alive _x} && {unitReady _x} && {vehicle _x == _x} && {canStand _x}) then {
        _unitsToMove pushBack _x;
    } else {
        if (_x != vehicle _x && {!(_x in (crew (vehicle _x)))}) then {
            _unitsToMove pushBack _x;
        } else {
            _rejectedUnits pushBack _x;
        };
    };
} foreach _units;

if (_unitsToMove isEqualTo []) exitWith {};

private _buildings = [_leader] call EFUNC(building,getNearBuildings);
if (_buildings isEqualTo []) exitWith {};

// Suffle array
_buildings = [_buildings, 2] call EFUNC(commonai,shuffleArray);

private _enteredBuildings = [];
{
    private _buildingIsChecked = [_x] call EFUNC(building,wasBuildingEntered);
    private _buildingPos = [_x] call EFUNC(building,getBuildingPos);
    private _building = _x;

    if !(_buildingPos isEqualTo [] && {!_buildingIsChecked}) then {
        private _maxUnits = round (2 * (1 + count (_buildingPos)/5));
        private _assignedUnits = [];
        private _unitCount = 0;
        {
            if (_unitCount == _maxUnits) exitWith {};
            _x setVariable [QEGVAR(building,inBuilding), [true, _building, _buildingPos]];
            _enteredBuildings pushBackUnique _building;
            _assignedUnits pushBack _x;

            if (EGVAR(commonai,debugEnabled)) then {
                private _markerName = format ["marker_%1", CBA_missionTime + random 1];
                createMarker [_markerName, getPos _building];
                _markerName setMarkerShape "icon";
                _markerName setMarkerType "hd_dot";
                _markerName setMarkerColor "colorBlack";
            };

            _unitsToMove deleteAt (_unitsToMove find _x);
        } forEach _unitsToMove;
    };

    if (_unitsToMove isEqualTo []) exitWith {};
} forEach _buildings;

if (_enteredBuildings isEqualTo []) then {
    false
} else {
    [QEGVAR(building,handleEnteredBuildings), [_enteredBuildings]] call CBA_fnc_serverEvent;
    true
};
