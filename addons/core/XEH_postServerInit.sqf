#include "script_component.hpp"
EXEC_CHECK(SERVER);

LOG("Server Post Init");

GVAR(EventDisconnectHandle) = addMissionEventHandler ["HandleDisconnect", {_this call FUNC(EventDisconnect);}];

SETMPVAR(MissionEnded,false);
SETMPVAR(ServerInitialized,true);

[{CBA_missionTime > 1}, {
    ESETMVAR(Respawn,TeamTicketsRemaining_Blufor,(EGETMVAR(Respawn,TeamTickets_Blufor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Opfor,(EGETMVAR(Respawn,TeamTickets_Opfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Indfor,(EGETMVAR(Respawn,TeamTickets_Indfor,30)));
    ESETMVAR(Respawn,TeamTicketsRemaining_Civ,(EGETMVAR(Respawn,TeamTickets_Civ,30)));
}] call CBA_fnc_WaitUntilAndExecute;

private _ServerPostInit = GETMVALUE(ServerPostInit,"");
LOG_1("_ServerPostInit:%1",_ServerPostInit);
if !(_ServerPostInit isEqualTo "") then {
    call compile _ServerPostInit;
};
