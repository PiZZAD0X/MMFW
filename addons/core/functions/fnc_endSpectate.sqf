
#include "script_component.hpp"
if !(hasInterface) exitwith {};

if !(GETPLVAR(Spectating,false)) exitwith {};

SETPLPVAR(Spectating,false);
SETPLPVAR(Dead,false);
player setCaptive false;
player allowDamage true;
[player, false] remoteExecCall ["hideObject", 0];
[player, false] remoteExecCall ["hideObjectGlobal", 2];
player call EFUNC(Gear,RemoveAllGear);
if (!isNil QGVAR(keyHandle46)) then {
    (findDisplay 46) displayRemoveEventHandler ["keyDown",GVAR(keyHandle46)];
};

["Terminate"] call BIS_fnc_EGSpectator;

[QEGVAR(Spectator,EndHookEvent), []] call CBA_fnc_localEvent;
