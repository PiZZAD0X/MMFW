#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl", "_value", "_config"];
TRACE_3("",_ctrl,_value,_config);

private _control = (_ctrl controlsGroupCtrl 100);
_control setvariable [QGVAR(parentcontrolcfg),_config];
private _attProperty = getText (_config >> "property");
missionNamespace setvariable [_attProperty,_value];
lbClear _control;
{
    private _colourArray = getArray (_x >> "color");
    if !(_colourArray isEqualto []) then {
        private _colourName = configName _x;
        private _colour = _colourArray call BIS_fnc_colorConfigToRGBA;
        if (_colour isEqualTo [0,0,0,0]) then {
            {
                _colour set [_forEachIndex, call compile _x];
            } forEach _colourArray;
        };
        private _index = _control lbadd _colourName;
        _control lbsetdata [_index,_colourName];
        _control lbsetpicture [_index,'#(argb,8,8,3)color(1,1,1,1)'];
        _control lbsetpicturecolor [_index,_colour];
        _control lbsetpicturecolorselected [_index,_colour];
        if (_value isEqualto _colourName) then {
            _control lbSetCurSel _index;
            missionNamespace setvariable [_attProperty,_value];
        };
    };
} forEach configProperties [configFile >> "CfgMarkerColors"];
