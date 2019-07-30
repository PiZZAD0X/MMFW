/*
 * Author: TheMagnetar
 * Function called when entering disembark state.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player] call mmfw_tasks_fnc_onDisembarkStateEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

private _vehicles = [_group] call EFUNC(vehicle,getGroupVehicles);

private _settings = _group getVariable [QEGVAR(commonai,settings), []];
private _allowWater = HASHGET(_settings,allowWater);
private _allowLand = HASHGET(_settings,allowLand);

{
    [_x, true, true, false, _allowLand, _allowWater] call EFUNC(vehicle,disembark);
} forEach _vehicles;
