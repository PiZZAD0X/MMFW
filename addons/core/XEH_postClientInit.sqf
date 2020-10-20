#include "script_component.hpp"
EXEC_CHECK(CLIENTHC);

LOG("ClientHC Post Init");

if (hasInterface) then {
    LOG("Client Post Init");

    [] call FUNC(chatCommands);

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
        private _PlayerPostInit = switch (side player) do {
            case WEST: {
                GETMVALUE(BluforPostInit,"");
            };
            case EAST: {
                GETMVALUE(OpforPostInit,"");
            };
            case INDEPENDENT: {
                GETMVALUE(IndforPostInit,"");
            };
            case CIVILIAN: {
                GETMVALUE(CivilianPostInit,"");
            };
            default {""};
        };
        LOG_1("_PlayerPostInit:%1",_PlayerPostInit);
        if !(_PlayerPostInit isEqualTo "") then {
            call compile _PlayerPostInit;
        };

        private _indTickets = switch (side player) do {
            case west: {(EGETMVAR(Respawn,IndTickets_Blufor,2))};
            case east: {(EGETMVAR(Respawn,IndTickets_Opfor,2))};
            case independent: {(EGETMVAR(Respawn,IndTickets_Indfor,2))};
            case civilian: {(EGETMVAR(Respawn,IndTickets_Civ,2))};
        };
        SETMVAR(IndTicketsRemaining,_indTickets);

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
