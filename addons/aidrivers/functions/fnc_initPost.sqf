#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_vehicle"];

//IGNORE_PRIVATE_WARNING ["_thisArgs"];
LOG_1("Ai Drivers Check Vehicle:%1",_vehicle);
if !(local _vehicle) exitwith {};

[QEGVAR(Core,SettingsLoaded), {
    _thisArgs params ["_vehicle"];
    private _allowNV = GETMVAR(NVEnabled,false);
	private _allowFlip = GETMVAR(FlipEnabled,false);
    if (GETMVAR(AllVehs,false)) exitwith {
        [QGVAR(Enabled_Event),[_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
        [QEGVAR(Core,RegisterModuleEvent), ["AI Drivers", "Module for adding AI Drivers to vehicles", "BlackHawk, PiZZADOX and Sacher"]] call CBA_fnc_globalEventJIP;
    };
    if ((typeOf _vehicle) in (GETMVAR(VehClasses,[]))) exitwith {
        [QEGVAR(Core,RegisterModuleEvent), ["AI Drivers", "Module for adding AI Drivers to vehicles", "BlackHawk, PiZZADOX and Sacher"]] call CBA_fnc_globalEventJIP;
        [QGVAR(Enabled_Event),[_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
    };
    if (GETVAR(_vehicle,VehEnabled,false)) then {
        private _allowNV = GETVAR(_vehicle,VehNVEnabled,false);
    	private _allowFlip = GETVAR(_vehicle,VehFlipEnabled,false);
        [QGVAR(Enabled_Event),[_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
        [QEGVAR(Core,RegisterModuleEvent), ["AI Drivers", "Module for adding AI Drivers to vehicles", "BlackHawk, PiZZADOX and Sacher"]] call CBA_fnc_globalEventJIP;
    };
}, [_vehicle]] call CBA_fnc_addEventHandlerArgs;
