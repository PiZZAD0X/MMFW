#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(PlayerEvent), {
    if !(GETMVAR(Enabled,false)) exitwith {};
    [{(!isNull ace_player)}, {
        [{
            private _parachuteType = ["NONE","NONSTEERABLE","STEERABLE"] select (GETPLVAR(Type,0));
            if (_parachuteType isEqualTo "NONE") exitwith {};
            private _altitude = GETPLVAR(Altitude,300);
            private _randomAltitude = GETPLVAR(RandomAltitude,100);
            switch (_parachuteType) do {
                case "NONE": {};
                case "NONSTEERABLE": {
                    [player,_altitude,_randomAltitude,false] call FUNC(doParachute);
                };
                case "STEERABLE": {
                    [player,_altitude,_randomAltitude,true] call FUNC(doParachute);
                };
            };
        }] call CBA_fnc_ExecNextFrame;
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    if (GETMVAR(Enabled,false)) then {
        [QEGVAR(Core,RegisterModuleEvent), ["Start in Parachute", "Starts players in parachutes", "Briland and Sacher"]] call CBA_fnc_globalEventJiP;
    };
    [QGVAR(PlayerEvent), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
