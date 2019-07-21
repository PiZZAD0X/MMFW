#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(LocalEvent), {
    {
        private _parachuteType = ["NONE","NONSTEERABLE","STEERABLE"] select (GETVAR(_x,Type,0));
        private _altitude = GETVAR(_x,Altitude,300);
        private _randomAltitude = GETVAR(_x,RandomAltitude,100);
        switch (_parachuteType) do {
            case "NONE": {};
            case "NONSTEERABLE": {
                [_x,_altitude,_randomAltitude,false] call FUNC(DoParachute);
            };
            case "STEERABLE": {
                [_x,_altitude,_randomAltitude,true] call FUNC(DoParachute);
            };
        };
    } forEach (allUnits select {local _x && {(!isPlayer _x)}});
}] call CBA_fnc_addEventHandler;

ADDON = true;
