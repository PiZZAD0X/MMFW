#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    case "init": {
        EXEC_CHECK(ALL);
        if !(is3DEN) then {
            if !(GETMVAR(Enabled,false)) exitWith {};
            _input params ["_logic",["_isActivated",true,[true]]];
            LOG_1("Starting Module function for CoverMap %1",_logic);
            if !(_isActivated) exitWith {};
            private _AOName = GETVAR(_logic,AOName,"Area0");
            _AOName = toLower(_AOName);
            private _AOZoom = GETVAR(_logic,ZoomLevel,0.4);
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
            publicvariable QGVAR(AOArray);
        };
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
