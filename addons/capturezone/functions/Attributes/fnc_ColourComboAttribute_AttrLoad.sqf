#include "script_component.hpp"
EDEN_CHECK;

LOG("CaptueZoneAttribute Load started");

params ["_this", "_config", "_value"];

private _control = (_this controlsGroupCtrl 100);
_control setvariable [QMGVAR(parentcontrolcfg),_config];
private _attProperty = getText (_config >> "property");
missionNamespace setvariable [_attProperty,_value];
lbClear _control;
{
	private _colour = getArray (_x >> "color") call BIS_fnc_colorConfigToRGBA;
	private _colourName = configName _x;
    private _index = _control lbadd _colourName;
    _control lbsetdata [_index,_colourName];
    _control lbsetValue [_index,_forEachIndex];
    _control lbsetpicture [_index,'#(argb,8,8,3)color(1,1,1,1)'];\
    _control lbsetpicturecolor [_index,_colour];\
    _control lbsetpicturecolorselected [_index,_colour];\
    if (_value isEqualto _colourName) then {
        _control lbSetCurSel _index;
        SETMVAR(_attProperty,_value);
    };
} forEach configProperties [configFile >> "CfgMarkerColors"];
