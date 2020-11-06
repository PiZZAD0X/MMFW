#include "script_component.hpp"
EXEC_CHECK(ALL);

if !(GETMVAR(Enabled,false)) exitwith {};

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];
LOCAL_CHECK(_unit);

private _side = side _unit;
if (isPlayer _unit) then {
    if !(GETPLVAR(ND_Active,false)) then {
        [QGVAR(CountEvent), [_side, _magazine]] call CBA_fnc_serverEvent;
    };
} else {
    [QGVAR(CountEvent), [_side, _magazine]] call CBA_fnc_serverEvent;
};
