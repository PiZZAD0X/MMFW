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
    ESETMPVAR(Core,MissionEnded,false);
};
private _delay = (GETMVAR(ConditionDelay,0));
private _frequency = (GETMVAR(ConditionSleep,30));
if (_frequency < 30) then {
    SETMVAR(ConditionSleep,30);
    _frequency = 30;
};

[{
    //timelimit loop
    if ((GETMVAR(Timelimit_Enabled,true))) then {
        if ((GETMVAR(Timelimit,60)) > 0) then {
            LOG_1("checking timelimit: %1",(GETMVAR(Timelimit,60)));
            LOG_1("checking timelimit message: %1",(GETMVAR(Timelimit_Message,60)));
            [{
                params ["_argNested", "_idPFH"];
                _argNested params ["_timelimit","_message",["_lastCheckedTime",CBA_missionTime]];
                private _timeDifference = (CBA_missionTime - _lastCheckedTime);
                if (_timeDifference <= 1) exitwith {};
                _argNested set [2,CBA_missionTime];
                if (EGETMVAR(Core,MissionEnded,false)) exitwith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
                if ((CBA_missionTime / 60) > _timelimit) exitWith {
                    _message call FUNC(EndMission);
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
            }, 60, [(GETMVAR(Timelimit,60)),(GETMVAR(Timelimit_Message,60)),CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
        } else {
            ERROR_1("invalid timelimit: %1",(GETMVAR(Timelimit,60)));
        };
    };

    //exit for custom file
    if (GETMVAR(File,false)) then {
        if !((GETMVAR(File_Path,"")) isEqualto "") then {
            private _endScript = (compile preprocessFileLineNumbers (GETMVAR(File_Path,"")));
            [{
                params ["_args","_PFHid"];
                _args params [["_frequency",30,[30]],"_endScript",["_lastCheckedTime",CBA_missionTime]];
                if (CBA_missionTime < (_lastCheckedTime + _frequency)) exitwith {};
                _args set [2,CBA_missionTime];
                if (EGETMVAR(Core,MissionEnded,false)) exitwith {
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
    #include "defines\Category1Loop.hpp"
    #include "defines\Category2Loop.hpp"
    #include "defines\Category3Loop.hpp"
    #include "defines\Category4Loop.hpp"
    #include "defines\Category5Loop.hpp"
    #include "defines\Category6Loop.hpp"
}, [], _delay] call CBA_fnc_waitAndExecute;
