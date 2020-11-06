#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit", "_corpse"];
LOCAL_CHECK(_unit);

[QGVAR(RespawnedEvent), [_unit, _corpse]] call CBA_fnc_serverEvent;

if (isPlayer _unit) then {
    [_unit, _corpse] call FUNC(RespawnHandler);
};
