#include "script_component.hpp"

params ["_side", "_class"];

private _teamvar = switch (_side) do {
    case west: {
        GVAR(ExpendedAmmunition_BLUFOR)
    };
    case east: {
        GVAR(ExpendedAmmunition_OPFOR)
    };
    case independent: {
        GVAR(ExpendedAmmunition_Indfor)
    };
    case civilian: {
        GVAR(ExpendedAmmunition_Civ)
    };
};

private _index = _teamvar findIf {(_x select 0) isEqualto _class};
if (_index isEqualto -1) then {
    _teamvar pushBack [_class, 1];
} else {
    (_teamvar select _index) params ["_name", "_count"];
    _teamvar set [_index, [_name, (_count + 1)]];
};
