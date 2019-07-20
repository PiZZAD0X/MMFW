#include "script_component.hpp"
EXEC_CHECK(ALL);

LOG("Spawned_Event called");
[QGVAR(SpawnedEvent), _this] call CBA_fnc_serverEvent;
