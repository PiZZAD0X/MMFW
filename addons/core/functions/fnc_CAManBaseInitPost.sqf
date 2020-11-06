#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];
LOCAL_CHECK(_unit);

[QGVAR(SpawnedEvent), _this] call CBA_fnc_serverEvent;
