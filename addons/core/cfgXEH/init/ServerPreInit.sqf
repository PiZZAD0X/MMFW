#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
EXEC_CHECK(SERVER);

LOG("Server Pre Init");

[QGVAR(TeamsInitEvent), {
    GVAR(Teams) = [];
    {
        _x params ["_side","_namevar","_teamTypeNum"];
        private _teamType = ["player","ai","both"] select _teamTypeNum;
        [_side,_namevar,_teamType] call FUNC(AddTeam);
        _side call FUNC(CreateRespawnMarker);
        createCenter _side;
    } foreach [[west,GVAR(TeamName_Blufor),GVAR(TeamType_Blufor)],[east,GVAR(TeamName_Opfor),GVAR(TeamType_Opfor)],[independent,GVAR(TeamName_Indfor),GVAR(TeamType_Indfor)],[civilian,GVAR(TeamName_Civ),GVAR(TeamType_Civ)]];
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerSpawned), {
    _this call FUNC(EventPlayerSpawned);
}] call CBA_fnc_addEventHandler;

[QEGVAR(JiP,ServerEvent), {
    params ["_unit"];
}] call CBA_fnc_addEventHandler;

[QGVAR(TrackAssetEvent), {
    params [["_asset", objNull, [objNull]],["_name", "", [""]],["_team", "", [""]]];
    private _asset = vehicle (_asset);
    SETPVAR(_asset,AssetName,_name);
    SETPVAR(_asset,AssetTeam,_team);
}] call CBA_fnc_addEventHandler;

[QGVAR(RespawnedEvent), {
    LOG_1("started Respawned_Event with %1",_this);
    _this call FUNC(EventRespawned);
}] call CBA_fnc_addEventHandler;

[QGVAR(KilledEvent), {
    LOG_1("started Killed_Event with %1",_this);
    _this call FUNC(EventKilled);
}] call CBA_fnc_addEventHandler;

[QGVAR(SpawnedEvent), {
    LOG_1("started Spawned_Event with %1",_this);
    _this call FUNC(EventSpawned);
}] call CBA_fnc_addEventHandler;

[QGVAR(TrackEvent), {
    params ["_unit"];
    if !(GETVAR(_unit,Tracked,false)) then {
        SETPVAR(_unit,Side,(side _unit));
        SETPVAR(_unit,Tracked,true);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(DontTrackEvent), {
    params ["_unit"];
    SETPVAR(_unit,DontTrack,true);
}] call CBA_fnc_addEventHandler;

[QGVAR(UnTrackEvent), {
    params ["_unit"];
    if (GETVAR(_unit,Tracked,false)) then {
        {
            _x params ["", "_side", "_Type", "_total", "_current"];
            if (((GETVAR(_unit,Side,sideUnknown)) isEqualto _side) && {((_Type == "player" && isPlayer _unit) || (_Type == "ai" && !(isPlayer _unit)) || (_Type == "both"))}) exitWith {
                if (_unit call FUNC(Alive)) then {
                    _x set [3, _total - 1];
                    _x set [4, _current - 1];
                };
            };
        } forEach GVAR(Teams);
        SETPVAR(_unit,Side,nil);
        SETPVAR(_unit,Tracked,nil);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(TrackAllUnitsEvent), {
    {
        if (!(GETVAR(_x,DontTrack,false))) then {
            _x call FUNC(TrackUnit);
        };
    } foreach allUnits;
}] call CBA_fnc_addEventHandler;

[QGVAR(RecievePlayerVarRequest), {
    params ["_object","_clientID"];
    LOG_1("Var Request _object: %1",_object);
    LOG_1("Var Request _clientID: %1",_clientID);
    private _allUOVars = (allVariables _object) select {!(((toLower(str _x)) find (toLower(QUOTE(PREFIX)))) isEqualto -1)};
    private _varArray = [];
    {
        private _varstring = _x;
        private _value = _object getVariable _varstring;
        _varArray pushback [_varstring,_value];
    } foreach _allUOVars;
    LOG_1("Var Request Array: %1",_varArray);
    [QGVAR(RecievePlayerVars), [_object,_varArray], _object] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerRespawnRequestTicketEvent), {
    params ["_unit","_ticketType"];
    LOG_2("RequestTicketEvent",_unit,_ticketType);
    switch (_ticketType) do {
        case "IND": {
            //Individual Tickets
            if ((GETVAR(_unit,IndTicketsRemaining,"")) isEqualTo "") then {
                switch (side _unit) do {
                    case west: {
                        SETVAR(_unit,IndTicketsRemaining,GVAR(IndTickets_Blufor));
                    };
                    case east: {
                        SETVAR(_unit,IndTicketsRemaining,GVAR(IndTickets_Blufor));
                    };
                    case independent: {
                        SETVAR(_unit,IndTicketsRemaining,GVAR(IndTickets_Blufor));
                    };
                    case civilian: {
                        SETVAR(_unit,IndTicketsRemaining,GVAR(IndTickets_Blufor));
                    };
                };
            };
            private _indTicketsRemaining = (GETVAR(_unit,IndTicketsRemaining,0));
            LOG_1("_indTicketsRemaining: %1",_indTicketsRemaining);
            if (_indTicketsRemaining > 0) then {
                DEC(_indTicketsRemaining);
                SETVAR(_unit,IndTicketsRemaining,_indTicketsRemaining);
                [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,true,"IND",_indTicketsRemaining], [_unit]] call CBA_fnc_targetEvent;
            } else {
                [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,false,"IND",_indTicketsRemaining], [_unit]] call CBA_fnc_targetEvent;
            };
        };
        case "TEAM": {
            //Team Tickets
            switch (side _unit) do {
                case west: {
                    private _ticketsRemaining = EGETMVAR(Respawn,TeamTicketsRemaining_Blufor,30);
                    if (_ticketsRemaining > 0) then {
                        DEC(_ticketsRemaining);
                        ESETMVAR(Respawn,TeamTicketsRemaining_Blufor,_ticketsRemaining);
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,true,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    } else {
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,false,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    };
                };
                case east: {
                    private _ticketsRemaining = EGETMVAR(Respawn,TeamTicketsRemaining_Opfor,30);
                    if (_ticketsRemaining > 0) then {
                        DEC(_ticketsRemaining);
                        ESETMVAR(Respawn,TeamTicketsRemaining_Opfor,_ticketsRemaining);
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,true,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    } else {
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,false,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    };
                };
                case independent: {
                    private _ticketsRemaining = EGETMVAR(Respawn,TeamTicketsRemaining_Indfor,30);
                    if (_ticketsRemaining > 0) then {
                        DEC(_ticketsRemaining);
                        ESETMVAR(Respawn,TeamTicketsRemaining_Indfor,_ticketsRemaining);
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,true,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    } else {
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,false,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    };
                };
                case civilian: {
                    private _ticketsRemaining = EGETMVAR(Respawn,TeamTicketsRemaining_Civ,30);
                    if (_ticketsRemaining > 0) then {
                        DEC(_ticketsRemaining);
                        ESETMVAR(Respawn,TeamTicketsRemaining_Civ,_ticketsRemaining);
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,true,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    } else {
                        [QGVAR(PlayerRespawnRecieveTicketEvent), [_unit,false,"TEAM",_ticketsRemaining], [_unit]] call CBA_fnc_targetEvent;
                    };
                };
                default {};
            };
        };
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerRespawnAddToQueueEvent), {
    params ["_unit","_side","_timeadded","_gearclass","_originalGroup","_isLeader"];
}] call CBA_fnc_addEventHandler;

[QGVAR(TeamsInitEvent), []] call CBA_fnc_localEvent;
