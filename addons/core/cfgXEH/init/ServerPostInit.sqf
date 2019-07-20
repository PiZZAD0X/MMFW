#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
EXEC_CHECK(SERVER);

LOG("Server Post Init");

GVAR(EventRespawnedHandle) = addMissionEventHandler ["EntityRespawned", {_this call FUNC(EventRespawned);}];
GVAR(EventKilledHandle) = addMissionEventHandler ["EntityKilled", {_this call FUNC(EventKilled);}];
GVAR(EventDisconnectHandle) = addMissionEventHandler ["HandleDisconnect", {_this call FUNC(EventDisconnect);}];

if (EGETMVAR(AI,ViewDistance_Enforce,false)) then {
    setViewDistance EGETMVAR(AI,ViewDistance,2500);
};

SETMPVAR(MissionEnded,false);
SETMPVAR(ServerInitialized,true);

[{CBA_missionTime > 1}, {
    ESETMVAR(Respawn,TeamTicketsRemaining_Blufor,(EGETMVAR(Respawn,TeamTickets_Blufor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Opfor,(EGETMVAR(Respawn,TeamTickets_Opfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Indfor,(EGETMVAR(Respawn,TeamTickets_Indfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Civ,(EGETMVAR(Respawn,TeamTickets_Civ,30)));
    [] call EFUNC(EndConditions,Init);
}] call CBA_fnc_WaitUntilAndExecute;
