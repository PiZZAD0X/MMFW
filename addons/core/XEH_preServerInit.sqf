#include "script_component.hpp"
EXEC_CHECK(SERVER);

LOG("Server Pre Init");

private _ServerPreInit = GETMVALUE(ServerPreInit,"");
LOG_1("_ServerPreInit:%1",_ServerPreInit);
if !(_ServerPreInit isEqualTo "") then {
    call compile _ServerPreInit;
};

[QGVAR(TeamsInitEvent), {
    GVAR(Teams) = [];
    {
        _x params ["_side","_namevar","_teamTypeNum"];
        private _teamType = ["player","ai","both"] select _teamTypeNum;
        [_side,_namevar,_teamType] call FUNC(AddTeam);
        _side call FUNC(CreateRespawnMarker);
    } foreach [
        [west,GVAR(TeamName_Blufor),GVAR(TeamType_Blufor)],
        [east,GVAR(TeamName_Opfor),GVAR(TeamType_Opfor)],
        [independent,GVAR(TeamName_Indfor),GVAR(TeamType_Indfor)],
        [civilian,GVAR(TeamName_Civilian),GVAR(TeamType_Civilian)]
    ];
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerSpawned), {
    _this call FUNC(EventPlayerSpawned);
}] call CBA_fnc_addEventHandler;

[QEGVAR(JiP,ServerEvent), {
    params ["_unit"];
}] call CBA_fnc_addEventHandler;

[QEGVAR(EndConditions,TimelimitServer), {
    params ["_command","_client",["_arg", 0, [0, ""]]];
    switch (_command) do {
        case "check": {
            private _timeLimit = (GETMVAR(Timelimit,60));
            [QEGVAR(EndConditions,TimelimitClient), ["check", _timeLimit], _client] call CBA_fnc_targetEvent;
        };
        case "extend": {
            if (_arg > 0) then {
                private _newTimeLimit = ((EGETMVAR(EndConditions,Timelimit,60)) + _arg);
                ESETMVAR(EndConditions,Timelimit,_newTimeLimit);
                [QEGVAR(EndConditions,TimelimitClient), ["extend", _newTimeLimit], _client] call CBA_fnc_targetEvent;
            };
        };
        case "message": {
            if (_arg isEqualType "") then {
                ESETMVAR(EndConditions,Timelimit_Message,_arg);
                [QEGVAR(EndConditions,TimelimitClient), ["message", _arg], _client] call CBA_fnc_targetEvent;
            };
        };
        default {};
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(RespawnedEvent), {
    LOG_1("started Respawned_Event with %1",_this);
    params ["_unit", "_corpse"];
    [_unit] call FUNC(EventRespawned);
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
            _x params ["", "_side", "_type", "_total", "_current"];
            if (((GETVAR(_unit,Side,sideUnknown)) isEqualto _side) && {((_type == "player" && isPlayer _unit) || (_type == "ai" && !(isPlayer _unit)) || (_type == "both"))}) exitWith {
                if (_unit call FUNC(isAlive)) then {
                    _x set [3, _total - 1];
                    _x set [4, _current - 1];
                };
            };
        } forEach GVAR(Teams);
        SETPVAR(_unit,Side,nil);
        SETPVAR(_unit,Tracked,nil);
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(RecievePlayerVarRequest), {
    params ["_object"];
    private _allVars = (allVariables _object) select {!(((toLower(str _x)) find (toLower(QUOTE(PREFIX)))) isEqualto -1)};
    private _varArray = _allVars apply {
        private _varstring = _x;
        private _value = _object getVariable _varstring;
        [_varstring,_value]
    };
    [QGVAR(RecievePlayerVars), [_object,_varArray], _object] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Respawn,AddToQueueEvent), {
    params ["_unit", "_newSide", "_queueVar", "_message"];
    private _queue = missionNamespace getVariable [_queueVar, []];
    _queue pushBackUnique [_unit, _newSide, _message];
    missionNamespace setVariable [_queueVar, _queue];
}] call CBA_fnc_addEventHandler;

[QEGVAR(Respawn,RequestTeamTicketEvent), {
    params ["_unit", "_newSide", "_teamRespawnMarker", "_queueVar"];
    LOG_2("RequestTicketEvent",_unit);
    //Team Tickets
    private _ticketVar = switch (side _unit) do {
        case west: {QEGVAR(Respawn,TeamTicketsRemaining_Blufor)};
        case east: {QEGVAR(Respawn,TeamTicketsRemaining_Opfor)};
        case independent: {QEGVAR(Respawn,TeamTicketsRemaining_Indfor)};
        case civilian: {QEGVAR(Respawn,TeamTicketsRemaining_Civ)};
    };
    private _ticketsRemaining = missionNamespace getVariable [_ticketVar, 30];
    if (_ticketsRemaining > 0) then {
        DEC(_ticketsRemaining);
        missionNamespace setVariable [_ticketVar, _ticketsRemaining];
        [QEGVAR(Respawn,RecieveTeamTicketEvent), [_unit, true, _ticketsRemaining, _newSide, _teamRespawnMarker, _queueVar], _unit] call CBA_fnc_targetEvent;
    } else {
        [QEGVAR(Respawn,RecieveTeamTicketEvent), [_unit, false, _ticketsRemaining, _newSide, _teamRespawnMarker, _queueVar], _unit] call CBA_fnc_targetEvent;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(TeamsInitEvent), []] call CBA_fnc_localEvent;
