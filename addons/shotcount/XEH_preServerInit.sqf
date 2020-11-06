#include "script_component.hpp"
EXEC_CHECK(SERVER);

[QGVAR(CountEvent), {
    if !(GETMVAR(Enabled,false)) exitwith {};
    params [
        ["_side", sideUnknown, [sideUnknown]],
        ["_className", "", [""]]
    ];
    private _displayName = [_className, "CfgMagazines"] call EFUNC(Core,getDisplayName);
    [_side, _displayName] call FUNC(shotCount);
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    if !(GETMVAR(Enabled,false)) exitwith {};
    GVAR(ExpendedAmmunition_BLUFOR) = [];
    GVAR(ExpendedAmmunition_Indfor) = [];
    GVAR(ExpendedAmmunition_OPFOR) = [];
    GVAR(ExpendedAmmunition_Civ) = [];
    GVAR(classNames) = [];
}] call CBA_fnc_addEventHandler;
