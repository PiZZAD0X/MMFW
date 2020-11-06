#include "script_component.hpp"

params ["_unit"];

[QEGVAR(Core,RegisterModuleEvent), ["Hostage Control", "Allows the mission maker to easily add hostages to their missions.", "Starfox64, TrainDoctor and PiZZADOX"]] call CBA_fnc_globalEventJiP;

private _moduleAreaName = (GETVAR(_unit,RescueLocation,"No Area Selected"));
if (_moduleAreaName isEqualTo "No Area Selected") exitwith {
    ERROR_1("Hostage Rescue Area not defined: %1!",_unit);
};
LOG_2("%1 set to hostage with rescue area of %2",_unit,_moduleAreaName);

private _index = GVAR(AreaArray) findIf {_x select 0 isEqualTo _moduleAreaName};
if (_index isEqualTo -1) exitwith {
    ERROR_2("Hostage: %1 Area: %2 not found in Area Arrays",_unit,_moduleAreaName);
};
private _moduleArea = GVAR(AreaArray) select _index select 1;

SETPVAR(_unit,IsUntied,false);
SETPVAR(_unit,IsRescued,false);

[{(CBA_missionTime > 0)},{
    params ["_unit","_moduleArea"];

    [QGVAR(ACEActionsEvent), [_unit]] call CBA_fnc_globalEventJiP;
    _unit setBehaviour "CARELESS";
    _unit allowFleeing 0;
    _unit setCaptive true;
    [_unit, "Acts_AidlPsitMstpSsurWnonDnon04", 1] call ace_common_fnc_doAnimation;
    _unit disableAI "MOVE";

    //IGNORE_PRIVATE_WARNING ["_thisID","_thisType"];
    private _EhAnimDone = [_unit, "AnimDone", {
        params ["_unit", "_anim"];
        if ((!alive _unit) || (GETVAR(_unit,IsRescued,false)) || (GETVAR(_unit,IsUntied,false))) exitWith {
            _unit removeEventHandler [_thisType, _thisID];
        };
        [_unit, "Acts_AidlPsitMstpSsurWnonDnon04", 1] call ace_common_fnc_doAnimation;
    }, []] call CBA_fnc_addBISEventHandler;

    SETVAR(_unit,EhAnimDone,_EhAnimDone);

    [{
        params ["_argNested", "_idPFH"];
        _argNested params ["_unit","_moduleArea","_lastCheckedTime"];
        private _timeDifference = (CBA_missionTime - _lastCheckedTime);
        if (_timeDifference < 5) exitwith {};
        _argNested set [2,(CBA_missionTime)];
        if ((animationState _unit != "acts_aidlpsitmstpssurwnondnon04") && {(GETVAR(_unit,IsUntied,false))} && {(_unit inArea _moduleArea)}) exitwith {
            if ((vehicle _unit) isEqualto _unit) then {
                [_unit] joinSilent grpNull;
                _unit disableAI "MOVE";
                [_unit, "AmovPsitMstpSnonWnonDnon_ground", 1] call ace_common_fnc_doAnimation;
                _unit disableAI "ANIM";
            };
            SETPVAR(_unit,IsRescued,true);
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
        if (GETVAR(_unit,IsRescued,false)) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
    }, 5, [_unit,_moduleArea,CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
}, [_unit,_moduleArea]] call CBA_fnc_WaitUntilAndExecute;
