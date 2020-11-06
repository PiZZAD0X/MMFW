
#include "script_component.hpp"

params ["_control", "_code", "_shift", "_control", "_alt"];
private _acre = ["ACRE2", "HeadSet"] call CBA_fnc_getKeybind;
if (!isNil "_acre") then {
    _acre params ["","","","","_action","_keys"];
    if (_code isEqualto (_keys select 0) && {(_keys select 1) isEqualTo [_shift, _control, _alt]}) then {
        [] call _action;
    };
};
if (_code isEqualto 35 && {!_shift} && {_control} && {!_alt}) then {
    if (!(GVAR(keyHandler_display_hidden))) then {
        (findDisplay 60492) closedisplay 1;
        GVAR(keyHandler_display_hidden) = true;
    };
};
