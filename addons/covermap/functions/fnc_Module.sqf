#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        EXEC_CHECK(ALL);
        if !(GETMVAR(Enabled,false)) exitWith {};
        _input params ["_logic",["_isActivated",true,[true]]];
        LOG_1("Starting Module function for CoverMap %1",_logic);
        if !(_isActivated) exitWith {};
        private _AOName = if (is3den) then {
            ((_logic get3DENAttribute QGVAR(AOName)) select 0)
        } else {
            GETVAR(_logic,AOName,"Area0");
        };
        private _AOZoom = if (is3den) then {
            ((_logic get3DENAttribute QGVAR(ZoomLevel)) select 0)
        } else {
            GETVAR(_logic,ZoomLevel,0.4);
        };
        private _loc = getPosATL _logic;
        private _size = _logic getVariable ["objectArea", [100, 100]];
        _size params ["_radiusX","_radiusY"];
        private _direction = getdir _logic;
        private _area = [_loc,_radiusX,_radiusY,_direction,true];
        if (isNil QGVAR(AOArray)) then {
            GVAR(AOArray) = [[_AOName,_area,_AOZoom,_logic]];
        } else {
            GVAR(AOArray) pushback [_AOName,_area,_AOZoom,_logic];
        };
        if !(is3DEN) then {
            publicvariable QGVAR(AOArray);
        };
    };
    case "attributesChanged3DEN": {
        if !(GETMVAR(Enabled,false)) exitWith {};
        _input params ["_logic",["_isActivated",true,[true]]];
        LOG_1("Starting Module function for CoverMap %1",_logic);
        if !(_isActivated) exitWith {};
        private _AOName = ((_logic get3DENAttribute QGVAR(AOName)) select 0);
        private _AOZoom = (_logic get3DENAttribute QGVAR(ZoomLevel)) select 0;
        private _loc = getPosATL _logic;
        private _size = _logic getVariable ["objectArea", [100, 100]];
        _size params ["_radiusX","_radiusY"];
        private _direction = getdir _logic;
        private _area = [_loc,_radiusX,_radiusY,_direction,true];
        if (isNil QGVAR(AOArray)) then {
            GVAR(AOArray) = [[_AOName,_area,_AOZoom,_logic]];
        } else {
            GVAR(AOArray) pushback [_AOName,_area,_AOZoom,_logic];
        };
    };
    default {};
};
true
