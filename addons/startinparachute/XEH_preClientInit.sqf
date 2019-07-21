#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(PlayerEvent), {
    if !(GETMVAR(Enabled,false)) exitwith {};
    [{(!isNull player)}, {
        [{
            private _parachuteType = ["NONE","NONSTEERABLE","STEERABLE"] select (GETPLVAR(Type,0));
            if (_parachuteType isEqualTo 0) exitwith {};
            private _altitude = GETPLVAR(Altitude,300);
            private _randomAltitude = GETPLVAR(RandomAltitude,100);
            switch (_parachuteType) do {
                case "NONE": {};
                case "NONSTEERABLE": {
                    [player,_altitude,_randomAltitude,false] call FUNC(DoParachute);
                };
                case "STEERABLE": {
                    [player,_altitude,_randomAltitude,true] call FUNC(DoParachute);
                };
            };
        }] call CBA_fnc_ExecNextFrame;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(PlayerEvent), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
