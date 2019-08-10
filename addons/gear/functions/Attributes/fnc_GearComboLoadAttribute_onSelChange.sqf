
#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_cursel"];

private _value = _control lbData _cursel;
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,UnitGearType,_value);
