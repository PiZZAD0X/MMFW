/*
 * Author: TheMagnetar
 * Handles changing the leader while unit is cached
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_changeLeader
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

[_group] call EFUNC(caching,uncacheGroup);
private _leader = leader _group;
_group setVariable [QEGVAR(commonai,leader), _leader];

[_group] call EFUNC(caching,cacheGroup);

[QEGVAR(caching,cache), _group] call CBA_fnc_localEvent;
