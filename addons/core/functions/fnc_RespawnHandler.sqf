#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_unit", "_corpse"];
SETPLPVAR(Body,_corpse);

private _respawnType = switch (side _unit) do {
    case west: {
        ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select EGETMVAR(Respawn,Type_BLUFOR,0)
    };
    case east: {
        ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select EGETMVAR(Respawn,Type_OPFOR,0)
    };
    case independent: {
        ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select EGETMVAR(Respawn,Type_Indfor,0)
    };
    case civilian: {
        ["ONELIFE","UNLIMITED","INDTICK","TEAMTICK"] select EGETMVAR(Respawn,Type_Civilian,0)
    };
};

TRACE_1("",_respawnType);

if (_respawnType in ["UNLIMITED", "INDTICK", "TEAMTICK"]) then {
    private _newSide = switch (side _unit) do {
        case west: {[blufor,opfor,independent,civilian] select EGETMVAR(Respawn,NewTeam_BLUFOR,0)};
        case east: {[blufor,opfor,independent,civilian] select EGETMVAR(Respawn,NewTeam_OPFOR,0)};
        case independent: {[blufor,opfor,independent,civilian] select EGETMVAR(Respawn,NewTeam_INDFOR,0)};
        case civilian: {[blufor,opfor,independent,civilian] select EGETMVAR(Respawn,NewTeam_CIV,0)};
    };
    private _teamVar = [_newSide] call FUNC(getTeamVar);
    private _queueVar = switch _newSide do {
        case west: {QEGVAR(Respawn,Queue_Blufor)};
        case east: {QEGVAR(Respawn,Queue_Opfor)};
        case independent: {QEGVAR(Respawn,Queue_Indfor)};
        case civilian: {QEGVAR(Respawn,Queue_Civ)};
    };
    private _eligibleRespawnLocations = [_teamVar] call FUNC(getRespawnLocations);
    private _teamRespawnMarker = if (_eligibleRespawnLocations isEqualTo []) then {
        objNull
    } else {
        if (EGETMVAR(Respawn,RandomRespawnLocations,false)) then {
            selectRandom _eligibleRespawnLocations
        } else {
            _eligibleRespawnLocations select (count _eligibleRespawnLocations - 1)
        };
    };
    switch (_respawnType) do {
        case "INDTICK": {
            //Individual Tickets
            private _indTicketsRemaining = GETMVAR(IndTicketsRemaining,0);
            LOG_1("_indTicketsRemaining: %1",_indTicketsRemaining);
            if (_indTicketsRemaining > 0) then {
                DEC(_indTicketsRemaining);
                SETMVAR(IndTicketsRemaining,_indTicketsRemaining);
                private _message = if (_indTicketsRemaining isEqualTo 0) then {
                    "You have no respawn tickets remaining."
                } else {
                    private _pluralForm = ["tickets","ticket"] select (_indTicketsRemaining isEqualTo 1);
                    (format ["You have %1 respawn %2 remaining.",_indTicketsRemaining,_pluralForm])
                };
                if (_teamRespawnMarker isEqualTo objNull && {!(EGETMVAR(Respawn,SpawnPosRespawn,false))}) then {
                    [QEGVAR(Spectator,StartSpectateEvent), [], _unit] call CBA_fnc_localEvent;
                    "There are no eligible respawn points! Respawn points can be activated during the mission." call BIS_fnc_titleText;
                    [QEGVAR(Respawn,AddToQueueEvent), [_unit, _newSide, _queueVar, _message]] call CBA_fnc_serverEvent;
                } else {
                    [QGVAR(PlayerRespawnEvent), [_message, _newSide, _teamRespawnMarker]] call CBA_fnc_localEvent;
                };
            } else {
                [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
                "You had no respawn tickets remaining <br/> Enabling spectator." call BIS_fnc_titleText;
            };
        };
        case "TEAMTICK": {
            //Team Tickets
            [QEGVAR(Respawn,RequestTeamTicketEvent), [_unit, _newSide, _teamRespawnMarker, _queueVar]] call CBA_fnc_serverEvent;
        };
        case "UNLIMITED": {
            if (_teamRespawnMarker isEqualTo objNull && {!(EGETMVAR(Respawn,SpawnPosRespawn,false))}) then {
                [QEGVAR(Spectator,StartSpectateEvent), [], _unit] call CBA_fnc_localEvent;
                "There are no eligible respawn points! Respawn points can be activated during the mission." call BIS_fnc_titleText;
                [QEGVAR(Respawn,AddToQueueEvent), [_unit, _newSide, _queueVar, _respawnType]] call CBA_fnc_serverEvent;
            } else {
                [QGVAR(PlayerRespawnEvent), ["", _newSide, _teamRespawnMarker]] call CBA_fnc_localEvent;
            };
        };
    };
} else {
    [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
};
