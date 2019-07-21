#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];
if !(local _unit) exitWith {};

LOG("Respawned_Event called");
[QGVAR(RespawnedEvent), _unit] call CBA_fnc_serverEvent;

if (isPlayer _unit) then {
    [_unit] call FUNC(RespawnHandler);
};
