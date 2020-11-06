#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];
LOCAL_CHECK(_unit);

[{!isNull (_this select 0)},{
    params ["_unit"];
    private _parachuteType = ["NONE","NONSTEERABLE","STEERABLE"] select (GETVAR(_unit,Type,0));
    private _altitude = GETVAR(_unit,Altitude, 300);
    private _randomAltitude = GETVAR(_unit,RandomAltitude, 100);
    switch (_parachuteType) do {
        case "NONE": {};
        case "NONSTEERABLE": {
            [_unit,_altitude,_randomAltitude,false] call FUNC(DoParachute);
        };
        case "STEERABLE": {
            [_unit,_altitude,_randomAltitude,true] call FUNC(DoParachute);
        };
    };
}, [_unit]] call CBA_fnc_waitUntilandExecute;
