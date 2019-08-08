#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl"];

if !(typename _value isEqualTo typename "") then {
    _value = str _value;
};
private _unit = ((get3denselected "object") select 0);
(_this controlsGroupCtrl 100) ctrlSetText _value;
SETVAR(_unit,ManualUnitClass,_value);
