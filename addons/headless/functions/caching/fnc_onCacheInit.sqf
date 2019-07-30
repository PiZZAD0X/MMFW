/*
 * Author: TheMagnetar
 * Initialises cache state machine.
 *
 * Arguments:
 * 0: Group <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1] call mmfw_cache_fnc_onCacheInit
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group"];

_group setVariable [QEGVAR(caching,cached), false];

if ([_group] call EFUNC(caching,shouldCache)) then {
    [QEGVAR(caching,cache), _group] call CBA_fnc_localEvent;
} else {
    [QEGVAR(caching,uncache), _group] call CBA_fnc_localEvent;
};
