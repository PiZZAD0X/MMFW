/*    Description: Gives players Jip actions
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        Olsen & Starfox64 & PiZZADOX
 */

#include "script_component.hpp"
if !(hasInterface) exitWith {};

private ["_type","_distance"];

switch (side player) do {
    case west: {
        _type = EGETMVAR(Respawn,Type_BLUFOR,0);
        _distance = EGETMVAR(Respawn,Distance_BLUFOR,200);
    };
    case east: {
        _type = EGETMVAR(Respawn,Type_OPFOR,0);
        _distance = EGETMVAR(Respawn,Distance_OPFOR,200);
    };
    case independent: {
        _type = EGETMVAR(Respawn,Type_Indfor,0);
        _distance = EGETMVAR(Respawn,Distance_Indfor,200);
    };
    case civilian: {
        _type = EGETMVAR(Respawn,Type_Civilian,0);
        _distance = EGETMVAR(Respawn,Distance_Civilian,200);
    };
};
LOG_1("Adding Jip Actions: Type=%1",_type);
switch (_type) do {
    case 0: {
        private _teleportAction = ["Jip_Teleport_Action", "Teleport To Squad", "", {
            params ["_target", "_player", "_args"];
            _args params ["_distance"];
            [_target,_args] call FUNC(Teleport);
        }, {((player distance (GETMVAR(SpawnPos,(getpos player)))) < ((_this select 2 ) select 0))}, {}, [_distance]] call ace_interact_menu_fnc_createAction;
        [player, 1, ["ACE_SelfActions"], _teleportAction] call ace_interact_menu_fnc_addActionToObject;
        [{
            params ["_args","_idPFH"];
            _args params ["_distance","_startTime"];
            if (CBA_missionTime > (_startTime + ((EGETMVAR(Respawn,EXPIRETIME,(5))) * 60))) exitwith {
                [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                ["JIP teleport option lost, it has been %1 minutes since you spawned.",(EGETMVAR(Respawn,EXPIRETIME,5))] call FUNC(parsedTextDisplay);
            };
            if (player distance (GETMVAR(SpawnPos,(getpos player))) > _distance) exitwith {
                [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                [["JIP teleport option lost, you went beyond %1 meters from your spawn location",_distance]] call FUNC(parsedTextDisplay);
            };
        }, 10, [_distance,CBA_missiontime]] call CBA_fnc_addPerFrameHandler;
    };
    case 1: {
        private _transportAction = ["Jip_Transport_Action", "Request Transport", "", {
            params ["_target", "_player", "_args"];
            _args params ["_distance"];
            [_target,_args] call FUNC(Transport);
        }, {((player distance (GETMVAR(SpawnPos,(getpos player)))) < ((_this select 2 ) select 0))}, {}, [_distance]] call ace_interact_menu_fnc_createAction;
        [player, 1, ["ACE_SelfActions"], _transportAction] call ace_interact_menu_fnc_addActionToObject;
        [{
            params ["_args","_idPFH"];
            _args params ["_distance","_startTime"];
            if (CBA_missionTime > (_startTime + ((EGETMVAR(Respawn,EXPIRETIME,(5))) * 60))) exitwith {
                [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                ["JIP teleport option lost, it has been %1 minutes since you spawned.",(EGETMVAR(Respawn,EXPIRETIME,(5)))] call FUNC(parsedTextDisplay);
            };
            if (player distance (GETMVAR(SpawnPos,(getpos player))) > _distance)exitwith {
                [player,1,["ACE_SelfActions","Jip_Transport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                [["JIP teleport option lost, you went beyond %1 meters from your spawn location",_distance]] call FUNC(parsedTextDisplay);
            };
        }, 10, [_distance,CBA_missiontime]] call CBA_fnc_addPerFrameHandler;
    };
    default {};
};
