#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrlEdit"];

private _value = ctrlText _ctrlEdit;
private _unit = ((get3denselected "object") select 0);
SETVAR(_unit,ManualUnitClass,_value);
