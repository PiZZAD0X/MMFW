#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];
if !(local _unit) exitWith {};

LOG("Spawned_Event called");

[QGVAR(SpawnedEvent), _this] call CBA_fnc_serverEvent;
