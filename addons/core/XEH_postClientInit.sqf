#include "script_component.hpp"
EXEC_CHECK(CLIENTHC);

LOG("ClientHC Post Init");

if (hasInterface) then {
    LOG("Client Post Init");

    ["endMission", {
        private _msg = "Mission ended by admin";
        if ((_this select 0) isEqualto []) then {
            _msg = _msg + ": " + (_this select 0);
        };
        _msg call FUNC(EndMission);
    }, "admin"] call CBA_fnc_registerChatCommand;

    [{!(isNull player)}, {
        //Global client init including JiPs
        [{
            [{
                [QGVAR(RegisterFrameworkEvent), []] call CBA_fnc_localEvent;
            }] call CBA_fnc_execNextFrame;
        }] call CBA_fnc_execNextFrame;

        if (didJIP && {(CBA_missionTime < ((EGETMVAR(JIP,Denytime,5)) * 60))}) exitwith {
            [QEGVAR(JiP,PlayerEvent), []] call CBA_fnc_localEvent;
            [QEGVAR(JiP,ServerEvent), [player]] call CBA_fnc_serverEvent;
        };
        //Global client init excluding JiPs - init here should be replicated after JiP ability determined
        [QGVAR(PlayerInitEvent), []] call CBA_fnc_localEvent;
        [QGVAR(PlayerInitEHEvent), []] call CBA_fnc_localEvent;
    }] call CBA_fnc_WaitUntilAndExecute;
} else {
    LOG("HC Post Init");
    if (EGETMVAR(AI,ViewDistance_Enforce,false)) then {
        setViewDistance EGETMVAR(AI,ViewDistance,2500);
    } else {
        if (GETMVAR(VisionAIEnabled,false)) then {
            setViewDistance (GETMVAR(AIViewDistance,2500));
            TRACE_1("AI Headless Viewdistance",(GETMVAR(AIViewDistance,2500)));
        };
    };
};
