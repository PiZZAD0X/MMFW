/*    Description: Checks end conditions in a loop and ends mission if conditions met
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */


#include "script_component.hpp"
EXEC_CHECK(SERVER);

LOG("EndConditions Init");

if (isNil QGVAR(MissionEnded)) then {
    SETMPVAR(MissionEnded,false);
};
private _delay = (EGETMVAR(EndConditions,ConditionDelay,0));
private _frequency = (EGETMVAR(EndConditions,ConditionSleep,30));
if (_frequency < 30) then {
    SETMVAR(ConditionSleep,30);
    _frequency = 30;
};

[{
    //timelimit loop
    if ((EGETMVAR(EndConditions,Timelimit_Enabled,true))) then {
        if ((EGETMVAR(EndConditions,Timelimit,60)) > 0) then {
            LOG_1("checking timelimit: %1",(EGETMVAR(EndConditions,Timelimit,60)));
            LOG_1("checking timelimit message: %1",(EGETMVAR(EndConditions,Timelimit_Message,60)));
            [{
                params ["_argNested", "_idPFH"];
                _argNested params ["_message",["_lastCheckedTime",CBA_missionTime]];
                private _timeDifference = (CBA_missionTime - _lastCheckedTime);
                if (_timeDifference <= 1) exitwith {};
                _argNested set [2,CBA_missionTime];
                if (GETMVAR(MissionEnded,false)) exitwith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
                if ((CBA_missionTime / 60) > (EGETMVAR(EndConditions,Timelimit,60))) exitWith {
                    _message call FUNC(EndMission);
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
            }, 10, [(EGETMVAR(EndConditions,Timelimit_Message,"Time Limit Reached!")),CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
        } else {
            ERROR_1("invalid timelimit: %1",(EGETMVAR(EndConditions,Timelimit,60)));
        };
    };

    //exit for custom file
    if (EGETMVAR(EndConditions,File,false)) then {
        if !((EGETMVAR(EndConditions,File_Path,"")) isEqualto "") then {
            private _endScript = compile preprocessFileLineNumbers (EGETMVAR(EndConditions,File_Path,""));
            [{
                params ["_args","_PFHid"];
                _args params [["_frequency",30,[30]],"_endScript",["_lastCheckedTime",CBA_missionTime]];
                if (CBA_missionTime < (_lastCheckedTime + _frequency)) exitwith {};
                _args set [2,CBA_missionTime];
                if (GETMVAR(MissionEnded,false)) exitwith {
                    [_PFHid] call CBA_fnc_removePerFrameHandler;
                };
                _args set [2,_lastCheckedTime];
                [] call _endScript;
            }, 60, [_frequency,_endScript]] call CBA_fnc_addPerFrameHandler;
        } else {
            ERROR("No file found for End Conditions!");
        };
    };

    //Category 1 loop
    #include "defines\CategoryLoop.hpp"
    CATEGORYLOOP(1);
    CATEGORYLOOP(2);
    CATEGORYLOOP(3);
    CATEGORYLOOP(4);
    CATEGORYLOOP(5);
    CATEGORYLOOP(6);
}, [], _delay] call CBA_fnc_waitAndExecute;
