/*
 * Author: TheMagnetar
 * Makes a unit patrol a building.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 *
 * Example:
 * [group player] call mmfw_building_fnc_patrolBuilding
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_unit", ["_deleteBuildingPos", true]];

if (!alive _unit) exitWith {
    _unit setVariable [QEGVAR(building,inBuilding), [false]];
};

private _buildingPatrol = _unit getVariable [QEGVAR(building,inBuilding), [false]];
if !(_buildingPatrol select 0) exitWith {};

_buildingPatrol params ["", "_building", ["_buildingPos", []], ["_waitUntilTime", CBA_missionTime], ["_returnLeader", false]];

if (_buildingPos isEqualTo []) exitWith {
    if (!_returnLeader) then {
        _unit doMove (formationPosition _unit);
        // Give the unit 10 seconds to go back to the leader
        _unit setVariable [QEGVAR(building,inBuilding), [true, _building, _buildingPos, CBA_missionTime + 10, true]];
    } else {
        if (moveToCompleted _unit || {moveToFailed _unit} || {!alive _unit} || {CBA_missionTime > _waitUntilTime}) then {
            _unit setVariable [QEGVAR(building,inBuilding), [false]];
        };
    };
};

if (moveToCompleted _unit || {moveToFailed _unit} || {!alive _unit} || {CBA_missionTime >= _waitUntilTime}) then {
    private _index = floor random (count _buildingPos);
    _unit doMove (_building buildingPos _index);
    if (_deleteBuildingPos) then {_buildingPos deleteAt _index;};
    // Give the unit 20 seconds before switching to the next building position
    _unit setVariable [QEGVAR(building,inBuilding), [true, _building, _buildingPos, CBA_missionTime + 20, _returnLeader]];
};
