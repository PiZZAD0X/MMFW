#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
EXEC_CHECK(ALL);

LOG("Spawned_Event called");
[QGVAR(SpawnedEvent), _this] call CBA_fnc_serverEvent;
