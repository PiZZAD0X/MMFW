#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_vehicle"];

LOCAL_CHECK(_vehicle);
//IGNORE_PRIVATE_WARNING ["_thisArgs"];
LOG_1("AI Drivers Check Vehicle:%1",_vehicle);

[QEGVAR(Core,SettingsLoaded), {
    _thisArgs params ["_vehicle"];
    LOG_1("AI Drivers eventhandler :%1",_vehicle);
    private _allowNV = GETMVAR(NVEnabled,false);
    private _allowFlip = GETMVAR(FlipEnabled,false);
    if (GETMVAR(AllVehs,false)) exitwith {
        LOG_1("AI Drivers in allVehs :%1",_vehicle);
        [QGVAR(Enabled_Event), [_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
    };
    if !((GETMVAR(VehClasses,[])) findIf {_vehicle isKindOf _x} isEqualTo -1) exitwith {
        LOG_1("AI Drivers in VehClasses :%1",_vehicle);
        [QGVAR(Enabled_Event), [_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
    };
    if (GETVAR(_vehicle,VehEnabled,false)) then {
        LOG_1("AI Drivers vehicle enabled :%1",_vehicle);
        private _allowNV = GETVAR(_vehicle,VehNVEnabled,false);
        private _allowFlip = GETVAR(_vehicle,VehFlipEnabled,false);
        [QGVAR(Enabled_Event), [_vehicle,_allowNV,_allowFlip]] call CBA_fnc_globalEventJIP;
    };
}, [_vehicle]] call CBA_fnc_addEventHandlerArgs;
