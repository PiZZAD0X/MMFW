/*
 * Author: Olsen
 *
 * Ends mission in orderly fashion and displays end screen.
 * Sends the team stats, time limit, scenario and executes QGVAR(EndmissionEvent) on all players machines.
 *
 * Arguments:
 * 0: text to display in end screen <string>
 *
 * Return Value:
 * nothing
 *
 * Public: Yes
 */


#include "script_component.hpp"
if !(isServer) exitWith {};

params ["_message"];

if (CBA_missiontime > (60 + (EGETMVAR(EndConditions,ConditionSleep,0)))) then {
    SETMPVAR(MissionEnded,true);
    //endmission hooks for modules
    if (EGETMVAR(ShotCount,Enabled,false)) then {
        LOG("Calculating ShotCount Data");
        [] call EFUNC(ShotCount,endCount);
    };
    GVAR(Teams) apply {
        private _team = (_x select 0);
        private _assets = _team call FUNC(GetDamagedAssets);
        _x set [5, _assets select 0];
        _x set [6, _assets select 1];
    };
    [QGVAR(EndmissionEvent), [_message,EGETMVAR(EndConditions,Timelimit,60),GVAR(Teams)]] call CBA_fnc_globalEvent;
} else {
    ERROR_2("End Conditions have just been triggered. Mission might need to be ended manually! Time:%2 Safetime:%1",(60 + (EGETMVAR(EndConditions,ConditionSleep,0))),CBA_missiontime);
};
