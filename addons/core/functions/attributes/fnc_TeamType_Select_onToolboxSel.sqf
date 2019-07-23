#include "script_component.hpp"
EDEN_CHECK;

params ["_control","_value"];
private _config = _control getvariable [QGVAR(ParentCfg),""];
private _name = gettext (_config >> "property");
missionNamespace setvariable [_name,_value];
