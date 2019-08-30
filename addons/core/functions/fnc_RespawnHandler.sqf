
#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_unit", "_corpse"];

SETPLPVAR(Body,_corpse);

//handle respawn delays, Rsc, gear & module settings, location, etc
private ["_respawnType"];

switch (side player) do {
    case west: {
        private _respawnTypeNum = EGETMVAR(Respawn,Type_BLUFOR,0);
        _respawnType = ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select _respawnTypeNum;
    };
    case east: {
        private _respawnTypeNum = EGETMVAR(Respawn,Type_OPFOR,0);
        _respawnType = ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select _respawnTypeNum;
    };
    case independent: {
        private _respawnTypeNum = EGETMVAR(Respawn,Type_Indfor,0);
        _respawnType = ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select _respawnTypeNum;
    };
    case civilian: {
        private _respawnTypeNum = EGETMVAR(Respawn,Type_Civ,0);
        _respawnType = ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select _respawnTypeNum;
    };
};

LOG_1("_respawnType: %1",_respawnType);

switch (_respawnType) do {
    case "ONELIFE": {
        [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
    };
    case "UNLIMITED": {
        [QGVAR(PlayerRespawnEvent), []] call CBA_fnc_localEvent;
    };
    case "INDTICK": {
        [QGVAR(PlayerRespawnRequestTicketEvent), [player,"IND"]] call CBA_fnc_serverEvent;
    };
    case "TEAMTICK": {
        [QGVAR(PlayerRespawnRequestTicketEvent), [player,"TEAM"]] call CBA_fnc_serverEvent;
    };
    default {
        [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
    };
};
