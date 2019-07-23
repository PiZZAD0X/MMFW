#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_config"];

private _name = gettext (_config >> "property");
private _value = missionNamespace getvariable [_name,""];
_value
