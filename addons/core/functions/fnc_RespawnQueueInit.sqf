/*    Description: Checks end conditions in a loop and ends mission if conditions met
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */

#include "script_component.hpp"
if !(isServer) exitWith {};

LOG("RespawnQueue Init");

EGVAR(Respawn,Queue_Blufor) = [];
EGVAR(Respawn,Queue_Opfor) = [];
EGVAR(Respawn,Queue_Indfor) = [];
EGVAR(Respawn,Queue_Civ) = [];

EGVAR(Respawn,RespawnLocations_BLUFOR) = [];
EGVAR(Respawn,RespawnLocations_Opfor) = [];
EGVAR(Respawn,RespawnLocations_Indfor) = [];
EGVAR(Respawn,RespawnLocations_Civ) = [];

[{
    params ["", "_idPFH"];
    if (GETMVAR(MissionEnded,false)) exitwith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    [
        ["BLUFOR", EGVAR(Respawn,RespawnLocations_BLUFOR), QEGVAR(Respawn,RespawnLocations_BLUFOR)],
        ["OPFOR", EGVAR(Respawn,RespawnLocations_Opfor), QEGVAR(Respawn,RespawnLocations_Opfor)],
        ["INDFOR", EGVAR(Respawn,RespawnLocations_Indfor), QEGVAR(Respawn,RespawnLocations_Indfor)],
        ["CIVILIAN", EGVAR(Respawn,RespawnLocations_Civ), QEGVAR(Respawn,RespawnLocations_Civ)]
    ] apply {
        _x params ["_teamVar", "_array", "_qEGVar"];
        private _eligibleRespawnLocations = [_teamVar] call FUNC(getRespawnLocations);
        missionNamespace setVariable [_qEGVar, _eligibleRespawnLocations];
    };
}, 5, []] call CBA_fnc_addPerFrameHandler;

[{
    params ["", "_idPFH"];
    if (GETMVAR(MissionEnded,false)) exitwith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    [
        [EGVAR(Respawn,Queue_Blufor), EGVAR(Respawn,RespawnLocations_BLUFOR)],
        [EGVAR(Respawn,Queue_Opfor), EGVAR(Respawn,RespawnLocations_Opfor)],
        [EGVAR(Respawn,Queue_Indfor), EGVAR(Respawn,RespawnLocations_Indfor)],
        [EGVAR(Respawn,Queue_Civ), EGVAR(Respawn,RespawnLocations_Civ)]
    ] apply {
        _x params ["_array", "_locations"];
        if (!(_locations isEqualTo []) && {!(_array isEqualTo [])}) then {
            private _teamRespawnMarker = selectRandom _locations;
            private _element = _array deleteAt 0;
            _element params ["_unit", "_newSide", "_message"];
            [QGVAR(PlayerRespawnEvent), [_message, _newSide, _teamRespawnMarker], _unit] call CBA_fnc_targetEvent;
        };
    };
}, 1, []] call CBA_fnc_addPerFrameHandler;
