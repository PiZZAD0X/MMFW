/*
 * Author: TheMagnetar
 * Disembark units from a vehicle.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Distance <NUMBER> (default )
 *
 * Return Value:
 * Nearest vehicles suitable for the group
 *
 * Example:
 * [leader group player] call mmfw_vehicle_fnc_getNearVehicles
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_state"];

if (!local _group) exitWith {};

private _vehicle = _group getVariable [QEGVAR(vehicle,assignedVehicle), objNull];
if (isNull _vehicle) exitWith {
    [QEGVAR(tasks,doTask), _group] call CBA_fnc_localEvent;
};

private _allUnitsEmbarked = true;
{
    if ((vehicle _x == _x) && {alive _x}) exitWith {
        _allUnitsEmbarked = false;
    };
} forEach (units _group);

if (_allUnitsEmbarked) then {
    _group setSpeedMode "LIMITED";
    [QEGVAR(tasks,doTask), _group] call CBA_fnc_localEvent;
};
