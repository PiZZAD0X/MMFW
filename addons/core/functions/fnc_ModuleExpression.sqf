#include "script_component.hpp"
EXEC_CHECK;

params ["_obj","_propertyName","_value"];

_obj setVariable [_propertyName, _value, true];
