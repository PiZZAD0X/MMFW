#include "script_component.hpp"
EXEC_CHECK(ALL);

if !(GETMVAR(Enabled,false)) exitwith {};
[QEGVAR(Core,RegisterModuleEvent), ["Shot Count", "Count shots fired by units", "Beta, TinfoilHate, PiZZADOX and Sacher"]] call CBA_fnc_localEvent;

params ["_obj"];

if !((GETVAR(_obj,firedEH,"")) isEqualto "") exitWith {};
SETVAR(_obj,originalSide,side _obj);

if (_obj isKindOf "Man") then {
    GVAR(firedEHhandle) = _obj addEventHandler ["FiredMan", {
        params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];
        if (isPlayer _unit) then {
            if !(GETPLVAR(ND_Active,false)) then {
                [QGVAR(EHEvent), [side _unit,_magazine]] call CBA_fnc_serverEvent;
            };
        } else {
            [QGVAR(EHEvent), [side _unit,_magazine]] call CBA_fnc_serverEvent;
        };
    }];
    SETVAR(_obj,firedEh,_firedEHhandle);
} else {
    GVAR(firedEHhandle) = _obj addEventHandler ["FiredMan",  {
        params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];
        [QGVAR(EHEvent), [side _unit,_magazine]] call CBA_fnc_serverEvent;
    }];
    if !(crew _obj isEqualto []) then {
        {
            SETVAR(_x,firedEh,_firedEHhandle);
            SETVAR(_x,originalSide,(side _obj));
        } forEach crew _obj;
    };
    SETVAR(_obj,firedEh,_firedEHhandle);
};
