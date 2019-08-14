#include "script_component.hpp"
EDEN_CHECK;

private _settingsArray = call compile copyFromClipboard;
{
    _x params ["_section","_class","_value"];
    _section set3DENMissionAttribute [_class,_value];
} foreach _settingsArray;
[] call FUNC(BasicSettings3DEN);
