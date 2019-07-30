/*
 * Author: TheMagnetar
 * Registers the buildings entered by a group.
 *
 * Arguments:
 * 0: Buildings <ARRAY>
 * 1: Buildings are added <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_building, true] call mmfw_building_fnc_handleEnteredBuildings
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_newBuildings"];

private _checkedBuildings = missionNamespace getVariable [QEGVAR(building,checkedBuildings), []];

// Delete older entries
private _toDelete = [];
{
    if (_x select 1 + 500 >= CBA_missionTime) then {
        _toDelete pushBack _forEachIndex;
    };
} forEach _checkedBuildings;

{
    _checkedBuildings deleteAt _forEachIndex;
} forEach _toDelete;

{
    _checkedBuildings pushBack [_x, CBA_missionTime];
} forEach _newBuildings;

missionNamespace setVariable [QEGVAR(building,checkedBuildings), _checkedBuildings, true];
