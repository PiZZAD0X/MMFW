#include "script_component.hpp"
EXEC_CHECK(ALL);

params [
    "_target",
    "_elev",
    ["_rand", 100, [0]],
    ["_steer", false, [false]]
];
LOG_2("Executing Start in Parachute on %1 with args: %2",_target,_this);

private _class = ["NonSteerable_Parachute_F","Steerable_Parachute_F"] select _steer;

[{!isnull (_this select 0)}, {
    params ["_target","_elev","_rand","_class"];
    private _random = floor (random _rand);
    private _chute = _class createVehicle [0,0,0];
    _chute setPosATL [(getPosATL _target select 0), (getPosATL _target select 1), _elev + _random];
    _target moveIndriver _chute;
}, [_target,_elev,_rand,_class]] call CBA_fnc_waitUntilAndExecute;
