#include "script_component.hpp"
EXEC_CHECK(SERVER);

LOG("Server Post Init");

GVAR(EventDisconnectHandle) = addMissionEventHandler ["HandleDisconnect", {_this call FUNC(EventDisconnect);}];

if (EGETMVAR(AI,ViewDistance_Enforce,false)) then {
    setViewDistance EGETMVAR(AI,ViewDistance,2500);
} else {
    if (GETMVAR(VisionAIEnabled,false)) then {
        setViewDistance (GETMVAR(AIViewDistance,2500));
        TRACE_1("AI Server Viewdistance",(GETMVAR(AIViewDistance,2500)));
    };
};

SETMPVAR(MissionEnded,false);
SETMPVAR(ServerInitialized,true);

[{CBA_missionTime > 1}, {
    ESETMVAR(Respawn,TeamTicketsRemaining_Blufor,(EGETMVAR(Respawn,TeamTickets_Blufor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Opfor,(EGETMVAR(Respawn,TeamTickets_Opfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Indfor,(EGETMVAR(Respawn,TeamTickets_Indfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Civ,(EGETMVAR(Respawn,TeamTickets_Civ,30)));
    [] call FUNC(Init);
}] call CBA_fnc_WaitUntilAndExecute;
