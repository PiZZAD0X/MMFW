#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];

LOG("Killed_Event called");
[QGVAR(KilledEvent), _unit] call CBA_fnc_serverEvent;

if (isPlayer _unit) then {
    [_unit] call FUNC(KilledHandler);
};
