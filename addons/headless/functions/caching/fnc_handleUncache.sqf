/*
 * Author: TheMagnetar
 * Handles groups that are not cached
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_handleCache
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

// Only when unit is local
if (!local _group) exitWith {
    _group setVariable [QEGVAR(caching,cached), false, true];
    _group setVariable [QEGVAR(commonai,leader), leader _group, true];
};

if (CBA_missionTime < (_group getVariable [QEGVAR(caching,lastCheck), CBA_missionTime])) exitWith {};

// Check in 10 seconds
_group setVariable [QEGVAR(caching,lastCheck), CBA_missionTime + 1];

if ([_group] call EFUNC(caching,shouldCache)) then {
    [QEGVAR(caching,cache), _group] call CBA_fnc_localEvent;
};
