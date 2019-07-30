/*
 * Author: TheMagnetar
 * Handle garrison entered state
 *
 * Arguments:
 * 0: Group <OBJECT> (default: objNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [nearestBuilding player] call mmfw_tasks_fnc_onGarrisonEntered
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

private _inBuilding = [_group, true] call EFUNC(building,moveInBuilding);

if !(_inBuilding) exitWith {
    private _settings = _group getVariable [QEGVAR(commonai,settings), []];
    HASHSET(_settings,task,"patrol");
    HASHSET(_settings,perimeterSettings,[getPos (leader _group), 100]);
    _group setVariable [QEGVAR(commonai,settings), _settings];
    [group this, QEGVAR(tasks,taskPatrol)] call EFUNC(tasks,changeAssignedTask);
    [QEGVAR(tasks,patrolBuildings), _group] call CBA_fnc_localEvent;

    private _marker = HASHGET(_settings,marker);
    WARNING_3("No building for group in %1 (Garrisson). Switching to patrol with center %2 and radius %3.",_marker,getPos (leader _group),100);
};

_group setVariable [QEGVAR(tasks,inBuilding), true];
