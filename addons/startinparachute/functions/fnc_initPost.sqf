#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_obj"];
if !(_obj isKindOf "Man") exitwith {};

[{!isNull (_this select 0)},{
    params ["_obj"];
    private _parachuteType = ["NONE","NONSTEERABLE","STEERABLE"] select (GETVAR(_obj,Type,0));
    private _altitude = GETVAR(_obj,Altitude, 300);
    private _randomAltitude = GETVAR(_obj,RandomAltitude, 100);
    switch (_parachuteType) do {
        case "NONE": {};
        case "NONSTEERABLE": {
            [_obj,_altitude,_randomAltitude,false] call FUNC(DoParachute);
        };
        case "STEERABLE": {
            [_obj,_altitude,_randomAltitude,true] call FUNC(DoParachute);
        };
    };
}, [_obj]] call CBA_fnc_waitUntilandExecute;
