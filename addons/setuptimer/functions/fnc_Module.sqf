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
            private _position = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
            _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
            private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];

            if (hasInterface) then {
                [_logic,_area,_selectedSide,_time] call FUNC(TimerExec);
            };
        };
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
