#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_target"];

private _driver = GETVAR(_target,driver,objnull);
[false] call FUNC(ToggleDriverCam);

if (!isNull _driver) then {
    deleteVehicle _driver;
};

SETPVAR(_target,driver,objnull);
GVAR(Vehicle) = objNull;
hint "Driver Removed";
