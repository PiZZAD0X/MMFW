#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_target", "_caller"];
if (!isNull (GETVAR(_target,Driver,objnull))) then {
    [_target] call FUNC(RemoveUnit);
} else {
    [_target, _caller] call FUNC(CreateUnit);
};
