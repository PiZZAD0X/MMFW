/*
 * Author: TheMagnetar
 * Initialises a group.
 *
 * Arguments:
 * 0: Unit <OBJECT> (default: objNull)
 * 1: Marker <STRING> (default: "")
 * 2: Unit type <STRING> (default: "infantry")
 * 3: Options <ARRAY> (default: [])
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player, "marker", "wheeled"] call mmfw_core_fnc_init
 *
 * Public: Yes
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params [
    ["_unit", objNull, [objNull]],
    ["_marker", "", ["", []]],
    ["_type", "infantry", [""]],
    ["_options", [], [[]]]
];

// Only execute where the group is local
private _group = group _unit;
if (!local _group) exitWith {};

if !(EGVAR(commonai,debugEnabled)) then {
    diag_log format ["%1", marker];
    if (_marker isEqualType "") then {
        _marker setMarkerAlpha 0;
    } else {
        {
            _x setMarkerAlpha 0;
        } forEach _marker;
    };
};

// Create default values for the group
private _settings = [] call CBA_fnc_hashCreate;
_settings = [_settings, _marker, _type] call EFUNC(commonai,setBasicSettings);

HASHSET(_settings,behaviour,[behaviour (leader _group)]);
HASHSET(_settings,combatMode,[combatMode _group]);
HASHSET(_settings,formation,[formation _group]);
HASHSET(_settings,speed,[speedMode _group]);

_settings = [_settings, _options] call EFUNC(commonai,parseOptions);
[_group, _settings] call EFUNC(commonai,applyOptionsPreSpawn);
[_group, _settings] call EFUNC(commonai,applyOptions);

_group setVariable [QEGVAR(commonai,settings), _settings, true];

// Register the group
_marker = _group getVariable [QEGVAR(commonai,registerMarker), ""];
[QEGVAR(commonai,registerGroup), [_group, _marker]] call CBA_fnc_serverEvent;

if !(HASHGET(_settings,release)) then {
    _group setVariable [QEGVAR(commonai,enabled), true, true];
};
