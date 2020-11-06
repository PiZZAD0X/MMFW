#include "script_component.hpp"
EXEC_CHECK(CLIENT);

LOG("Client Pre Init");

[QGVAR(RecievePlayerVars), {
    params ["_playerUnit","_varArray"];
    if !(local _playerUnit) exitwith {};
    {
        _x params ["_propertyName","_value"];
        player setvariable [_propertyName,_value];
    } foreach _varArray;
    [QGVAR(SettingsLoaded), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(RegisterModuleEvent), {
    if !(hasInterface) exitwith {};
    params ["_name", "_description", "_author"];
    [{!(isNull player)}, {
        params ["_name", "_description", "_author"];
        if !(player diarySubjectExists QGVAR(Menu)) then {
            player createDiarySubject [QGVAR(Menu), "Mission Framework"];
        };
        if (isNil QGVAR(ModuleDiaryEntries)) then {GVAR(ModuleDiaryEntries) = []};
        //IGNORE_PRIVATE_WARNING ["_x"];
        if ((GVAR(ModuleDiaryEntries) findIf {_name isEqualto _x}) isEqualto -1) then {
            GVAR(ModuleDiaryEntries) append [_name];
            player createDiaryRecord [QGVAR(Menu), [_name,"<font size='16'>" + _name + "</font><br/>Description: " + _description + "<br/>by " + _author]];
        };
    },[_name, _description, _author]] call CBA_fnc_WaitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(RegisterFrameworkEvent), {
    if !(player diarySubjectExists QGVAR(Menu)) then {
        player createDiarySubject [QGVAR(Menu), "Mission Framework"];
    };
    private _info = "
    <font size='18'>Mission Maker Framework</font><br/>
    The Mission Maker framework is an addon based utility and function library for making missions.<br/>
    <br/>
    Find out more about the framework on GitHub.<br/>
    <br/>
    <br/>
    Current Version: " + QUOTE(VERSION);
    player createDiaryRecord [QGVAR(Menu), ["Framework Info", _info]];
}] call CBA_fnc_addEventHandler;

[{!(isNull player)}, {
    LOG_1("Client call waituntil player: %1",player);
    [QGVAR(RecievePlayerVarRequest), [player]] call CBA_fnc_serverEvent;
    SETMVAR(SpawnPos,(getposATL player));
    GVAR(TeamTag) = switch (side player) do {
        case WEST: {"BLUFOR"};
        case EAST: {"OPFOR"};
        case INDEPENDENT: {"INDFOR"};
        case CIVILIAN: {"CIVILIAN"};
        default {"BLUFOR"};
    };
}] call CBA_fnc_WaitUntilAndExecute;

[QGVAR(EndMissionPlayerEvent), {
    params ["_scenario","_timeLimit","_teams"];
    [_scenario,_timeLimit,_teams] call FUNC(EndScreen);
}] call CBA_fnc_addEventHandler;

[QGVAR(EndmissionEvent), {
    params ["_scenario","_timeLimit","_teams"];
    [QGVAR(EndMissionPlayerEvent), [_scenario,_timeLimit,_teams]] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Spectator,StartSpectateEvent), {
    [] call FUNC(Spectate);
}] call CBA_fnc_addEventHandler;

[QEGVAR(Spectator,EndSpectateEvent), {
    [] call FUNC(endSpectate);
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerRespawnEvent), {
    params [
        ["_message", "", [""]],
        "_newSide",
        "_teamRespawnMarker"
    ];
    private _delay = switch (side player) do {
        case west: {(MGETMVAR(Respawn_Delay_BLUFOR,5))};
        case east: {(MGETMVAR(Respawn_Delay_OPFOR,5))};
        case independent: {(MGETMVAR(Respawn_Delay_Indfor,5))};
        case civilian: {(MGETMVAR(Respawn_Delay_Civ,5))};
    };
    [{
        params [
            ["_message", "", [""]],
            "_newSide",
            "_teamRespawnMarker"
        ];
        [_message, _newSide, _teamRespawnMarker] call FUNC(HandlePlayerRespawn);
    }, [_message, _newSide, _teamRespawnMarker], _delay] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Respawn,RecieveTeamTicketEvent), {
    params [
        "_unit",
        "_response",
        "_ticketsRemaining",
        "_newSide",
        "_teamRespawnMarker",
        "_queueVar"
    ];
    LOG_1("RecieveTicketEvent",_this);
    LOCAL_CHECK(_unit);
    if (_response) then {
        private _message = if (_ticketsRemaining isEqualTo 0) then {
            "Your team has no respawn tickets remaining."
        } else {
            private _pluralForm = ["tickets","ticket"] select (_ticketsRemaining isEqualTo 1);
            (format ["Your team has %1 respawn %2 remaining.",_ticketsRemaining,_pluralForm])
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
        "Your team had no respawn tickets remaining <br/> Enabling spectator." call BIS_fnc_titleText;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerInitEvent), {
    if (GETMVAR(ViewDistance_Enforce,false)) then {
        setViewDistance GETMVAR(ViewDistance,2500);
    };
    enableSaving [false, false];
    enableEngineArtillery false;
    enableRadio false;
    enableSentences false;
    0 fadeRadio 0;
    player addRating 100000;
    player setvariable ["BIS_noCoreConversations",true,true];
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerInitEHEvent), {
    SETPLPVAR(Dead,false);
    SETPLPVAR(HasDied,false);
    SETPLPVAR(Spectating,false);
    SETPLPVAR(Body,player);
    GVAR(PlayerHitHandle) = [player, "Hit", FUNC(HitHandler), []] call CBA_fnc_addBISEventHandler;
    [QGVAR(PlayerSpawned), player] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;

[QEGVAR(EndConditions,TimelimitClient), {
    params ["_command", ["_arg", 0, [0, ""]]];
    switch (_command) do {
        case "check": {
            private _timeLeft = _arg - (CBA_missionTime / 60);
            private _text = format ["TimeLimit: %1 Time Remaining: %2", _arg, _timeLeft];
            [_text, 1.5, ACE_Player, 10] call ace_common_fnc_displayTextStructured;
        };
        case "extend": {
            private _timeLeft = _arg - (CBA_missionTime / 60);
            private _text = format ["TimeLimit set to: %1 Time Remaining: %2", _arg, _timeLeft];
            [_text, 1.5, ACE_Player, 10] call ace_common_fnc_displayTextStructured;
        };
        case "message": {
            private _text = format ["TimeLimit message set to: %1", _arg];
            [_text, 1.5, ACE_Player, 10] call ace_common_fnc_displayTextStructured;
        };
        default {};
    };
}] call CBA_fnc_addEventHandler;

[QEGVAR(JiP,PlayerEvent), {
    private _side = side player;
    if ((((EGETMVAR(JiP,Type_BLUFOR,0)) isEqualto 2) && {_side isEqualto west})
        || {((EGETMVAR(JiP,Type_OPFOR,0)) isEqualto 2) && {_side isEqualto east}}
        || {((EGETMVAR(JiP,Type_Indfor,0)) isEqualto 2) && {_side isEqualto independent}}
        || {((EGETMVAR(JiP,Type_Civ,0)) isEqualto 2) && {_side isEqualto civilian}}
    ) exitwith {
        ["This mission does not support JIP for your team, enabling spectator"] call FUNC(parsedTextDisplay);
        [QGVAR(UnTrackEvent), [player]] call CBA_fnc_serverEvent;
        [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
        SETPLPVAR(JIPExcluded,true);
    };
    // Player can JiP, initialize player vars and EHs
    [QGVAR(PlayerInitEHEvent), []] call CBA_fnc_localEvent;
    [QGVAR(PlayerInitEvent), []] call CBA_fnc_localEvent;
    [] call FUNC(GiveActions);
}] call CBA_fnc_addEventHandler;
