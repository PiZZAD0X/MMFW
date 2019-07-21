#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_ctrl","_config"];

private _unit = ((get3denselected "object") select 0);
private _name = gettext (_config >> "property");
private _value = _unit getvariable [_name,0];
_value
