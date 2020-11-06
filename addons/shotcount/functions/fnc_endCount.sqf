#include "script_component.hpp"

private ["_ShotCount_textBLU","_ShotCount_textOPF","_ShotCount_textIND","_ShotCount_textCIV"];

if !(GVAR(ExpendedAmmunition_BLUFOR) isEqualto []) then {
    _ShotCount_textBLU = "BLUFOR Munitions Expended:<br/>";
    {
        _x params ["_label","_count"];
        _ShotCount_textBLU = _ShotCount_textBLU + _label + ": " + str(_count) + " Rounds" + "<br/>";
    } foreach GVAR(ExpendedAmmunition_BLUFOR);
} else {
    _ShotCount_textBLU = "";
};

if !(GVAR(ExpendedAmmunition_OPFOR) isEqualto []) then {
    _ShotCount_textOPF = "OPFOR Munitions Expended:<br/>";
    {
        _x params ["_label","_count"];
        _ShotCount_textOPF = _ShotCount_textOPF + _label + ": " + str(_count) + " Rounds" + "<br/>";
    } foreach GVAR(ExpendedAmmunition_OPFOR);
} else {
    _ShotCount_textOPF = "";
};

if !(GVAR(ExpendedAmmunition_Indfor) isEqualto []) then {
    _ShotCount_textIND = "INDEPENDENT Munitions Expended:<br/>";
    {
        _x params ["_label","_count"];
        _ShotCount_textIND = _ShotCount_textIND + _label + ": " + str(_count) + " Rounds" + "<br/>";
    } foreach GVAR(ExpendedAmmunition_Indfor);
} else {
    _ShotCount_textIND = "";
};

if !(GVAR(ExpendedAmmunition_Civ) isEqualto []) then {
    _ShotCount_textCIV = "CIVILIAN Munitions Expended:<br/>";
    {
        _x params ["_label","_count"];
        _ShotCount_textCIV = _ShotCount_textCIV + _label + ": " + str(_count) + " Rounds" + "<br/>";
    } foreach GVAR(ExpendedAmmunition_Civ);
} else {
    _ShotCount_textCIV = "";
};

[QGVAR(DisplayEvent), [_ShotCount_textBLU,_ShotCount_textOPF,_ShotCount_textIND,_ShotCount_textCIV]] call CBA_fnc_globalEvent;
