#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Event), {
    if !(GVAR(Enabled)) exitwith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Anti ND", "Extra Safety for mission start", "Starfox64, PiZZADOX and Sacher"]] call CBA_fnc_localEvent;
    [{(!isNull ace_player)}, {
        private _FiredEh = player addEventHandler ["FiredMan", {
            params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];
            if (((EGETMVAR(Core,SpawnPos,(getpos player))) distance player) <= GVAR(Distance)) then {
                deleteVehicle _projectile;
                if (_magazine call BIS_fnc_isThrowable) then {
                    player addMagazine _magazine;
                } else {
                    player setAmmo [currentWeapon player, (player ammo currentWeapon player) + 1];
                };
                if (((EGETMVAR(Core,SpawnPos,(getpos player))) distance player) >= GVAR(Distance)) then {
                    [["Anti-ND protection active!<br/>Time Remaining: %1 seconds.",(round (GVAR(Time) - CBA_missionTime))]] call EFUNC(Core,parsedTextDisplay);
                } else {
                    [["Anti-ND protection active!<br/>Distance from Base: %1 out of %2 meters.<br/>Time Remaining: %1 seconds.",(round ((EGETMVAR(Core,SpawnPos,(getpos player))) distance player)),(round GVAR(Distance)),(round (GVAR(Time) - CBA_missionTime))]] call EFUNC(Core,parsedTextDisplay);
                };
            };
        }];
        SETPLVAR(ND_EHid,_FiredEh);
        SETPLVAR(ND_Active,true);
        //player setvariable [QEGVAR(AntiND,),];
        //player setvariable [QEGVAR(AntiND,ND_Active),true];
        [{(CBA_missionTime > GVAR(Time))}, {
            player removeEventHandler ["FiredMan", _this];
            SETPLVAR(ND_EHid,"DISABLED");
            SETPLVAR(ND_Active,false);
        }, _FiredEh] call CBA_fnc_waitUntilAndExecute;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(Event), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
