#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Event), {
    if !(GETMVAR(Enable,false)) exitwith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Safe Start", "Extra safety for mission start", "Olsen and PiZZADOX"]] call CBA_fnc_localEvent;
    [{(!isNull player) && {(EGETPLVAR(Gear,GearReady,false))}}, {
        if !((currentWeapon player) isEqualto "") then {
            [player, (currentWeapon player), (currentMuzzle player)] call ace_safemode_fnc_lockSafety;
        };
        if (GETMVAR(Lowered,true)) then {
            player action ["WeaponOnBack", player];
        };
        if (GETMVAR(Unloaded,true)) then {
            private _magazineClass = currentMagazine player;
            player setAmmo [currentWeapon player, 0];
            player addMagazines [_magazineClass, 1];
            private _result = [player, _magazineClass, -1, true] call CBA_fnc_addMagazine;
        };
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(Event), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
