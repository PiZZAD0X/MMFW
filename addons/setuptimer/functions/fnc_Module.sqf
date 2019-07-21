#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch _mode do {
    case "init": {
        EXEC_CHECK(ALL);
        if (!is3DEN) then {
            _input params ["_logic",["_isActivated",true,[true]]];
            if !(_isActivated) exitWith {};
            private _selectedSide = [west,east,independent,civilian] select ((GETVAR(_logic,SideSelect,0)));
            private _time = GETVAR(_logic,Time,30);
            private _loc = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100]];
            _size params ["_radiusX","_radiusY"];
            private _direction = getdir _logic;
            private _isRectangle = if ((typeof _logic) isEqualTo QGVAR(SetupTimerModule_R)) then {true} else {false};
            private _area = [_loc,_radiusX,_radiusY,_direction,_isRectangle];

            [_logic,_area,_selectedSide,_time] call FUNC(TimerExec);
        };
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
