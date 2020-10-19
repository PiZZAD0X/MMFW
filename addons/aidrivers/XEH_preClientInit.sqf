#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Enabled_Event), {
    params ["_vehicle","_allowNV","_allowFlip"];
    [_vehicle,_allowNV,_allowFlip] call FUNC(EnableAIDriver);
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,RegisterModuleEvent), ["AI Drivers", "Module for adding AI Drivers to vehicles", "BlackHawk, PiZZADOX and Sacher"]] call CBA_fnc_localEvent;
