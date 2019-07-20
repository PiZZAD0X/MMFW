#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
EXEC_CHECK(CLIENT);

LOG("Client Pre Init");

[QGVAR(RecievePlayerVars), {
    params ["_playerUnit","_varArray"];
    LOG_1("Var Recieve _playerUnit: %1",_playerUnit);
    LOG_1("Var Recieve _varArray: %1",_varArray);
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
            player createDiarySubject [QGVAR(Menu), "UO Framework"];
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
        player createDiarySubject [QGVAR(Menu), "UO Framework"];
    };
    private _info = "
    <font size='18'>United Operations Framework</font><br/>
    The United Operations framework is an addon based utility and function library for making missions.<br/>
    <br/>
    Find out more about the framework on GitHub.<br/>
    github.com/unitedoperations/UnitedOperationsFramework<br/>
    <br/>
    Current Version: " + VERSIONSTR;
    player createDiaryRecord [QGVAR(Menu), ["Framework Info", _info]];
}] call CBA_fnc_addEventHandler;

[{!(isNull player)}, {
    LOG_1("Client call waituntil player: %1",player);
    [QGVAR(RecievePlayerVarRequest), [player,clientOwner]] call CBA_fnc_serverEvent;
    SETMVAR(SpawnPos,(getpos player));
    switch (side player) do {
        case WEST: {SETMVAR(TeamTag,"BLUFOR");};
        case EAST: {SETMVAR(TeamTag,"OPFOR");};
        case INDEPENDENT: {SETMVAR(TeamTag,"Indfor");};
        case CIVILIAN: {SETMVAR(TeamTag,"CIVILIAN");};
        default {SETMVAR(TeamTag,"BLUFOR");};
    };
}] call CBA_fnc_WaitUntilAndExecute;

[QGVAR(EndMissionPlayerEvent), {
    params ["_scenario"];
    [_scenario] call FUNC(EndScreen);
}] call CBA_fnc_addEventHandler;

[QGVAR(EndmissionEvent), {
    params ["_scenario"];
    [QGVAR(EndMissionPlayerEvent), [_scenario]] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Spectator,StartSpectateEvent), {
    [] call EFUNC(Spectator,Spectate);
}] call CBA_fnc_addEventHandler;

[QEGVAR(Spectator,EndSpectateEvent), {
    [] call EFUNC(Spectator,endSpectate);
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerRespawnEvent), {
}] call CBA_fnc_addEventHandler;

[QGVAR(PlayerRespawnRecieveTicketEvent), {
    params ["_unit","_response","_ticketType","_ticketsRemaining"];
    LOG_1("RecieveTicketEvent",_this);
    if !(local _unit) exitwith {};
    private ["_delay"];
    switch (side player) do {
        case west: {
            _delay = MGETMVAR(Respawn_Delay_BLUFOR,5);
        };
        case east: {
            _delay = MGETMVAR(Respawn_Delay_OPFOR,5);
        };
        case independent: {
            _delay = MGETMVAR(Respawn_Delay_Indfor,5);
        };
        case civilian: {
            _delay = MGETMVAR(Respawn_Delay_Civ,5);
        };
    };
    [{
        params ["_response","_ticketType","_ticketsRemaining"];
        switch (_ticketType) do {
            case "IND": {
                if (_response) then {
                    [QGVAR(PlayerRespawnEvent), []] call CBA_fnc_localEvent;
                    if (_ticketsRemaining isEqualTo 0) exitwith {
                        "You have no respawn tickets remaining." call BIS_fnc_titleText;
                    };
                    private _pluralForm = "tickets";
                    if (_ticketsRemaining isEqualTo 1) then {
                        _pluralForm = "ticket";
                    };
                    (format ["You have %1 respawn %2 remaining.",_ticketsRemaining,_pluralForm]) call BIS_fnc_titleText;
                } else {
                    [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
                    "You had no respawn tickets remaining<br />Enabling spectator." call BIS_fnc_titleText;
                };
            };
            case "TEAM": {
                if (_response) then {
                    [QGVAR(PlayerRespawnEvent), []] call CBA_fnc_localEvent;
                    if (_ticketsRemaining isEqualTo 0) exitwith {
                        "Your team has no respawn tickets remaining." call BIS_fnc_titleText;
                    };
                    private _pluralForm = "tickets";
                    if (_ticketsRemaining isEqualTo 1) then {
                        _pluralForm = "ticket";
                    };
                    (format ["Your team has %1 respawn %2 remaining.",_ticketsRemaining,_pluralForm]) call BIS_fnc_titleText;
                } else {
                    [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
                    "Your team had no respawn tickets remaining<br />Enabling spectator." call BIS_fnc_titleText;
                };
            };
        };
    }, [_response,_ticketType,_ticketsRemaining], (_delay + 3)] call CBA_fnc_WaitAndExecute;
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

[QEGVAR(JiP,PlayerEvent), {
    if ((((EGETMVAR(JiP,Type_BLUFOR,0)) isEqualto 2) && {(side player isEqualto west)})
        || (((EGETMVAR(JiP,Type_OPFOR,0)) isEqualto 2) && {(side player isEqualto east)})
        || (((EGETMVAR(JiP,Type_Indfor,0)) isEqualto 2) && {(side player isEqualto independent)})
        || (((EGETMVAR(JiP,Type_Civ,0)) isEqualto 2) && {(side player isEqualto civilian)})
    ) exitwith {
        ["This mission does not support JIP for your team, enabling spectator"] call FUNC(parsedTextDisplay);
        [QGVAR(UnTrackEvent), [player]] call CBA_fnc_serverEvent;
        [QEGVAR(Spectator,StartSpectateEvent), []] call CBA_fnc_localEvent;
        SETPLPVAR(JIPExcluded,true);
    };
    // Player can JiP, initialize player vars and EHs
    [QGVAR(PlayerInitEHEvent), []] call CBA_fnc_localEvent;
    [QGVAR(PlayerInitEvent), []] call CBA_fnc_localEvent;
    [] call EFUNC(JiP,GiveActions);
}] call CBA_fnc_addEventHandler;
