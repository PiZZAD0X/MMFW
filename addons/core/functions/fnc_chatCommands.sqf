#include "script_component.hpp"

["endMission", {
    private _msg = "Mission ended by admin";
    if !((_this select 0) isEqualto "") then {
        _msg = (_this select 0);
    };
    _msg call FUNC(EndMission);
}, "admin"] call CBA_fnc_registerChatCommand;

["timelimit", {
    ((_this select 0) splitString " ") params ["_command","_arg"];
    switch (_command) do {
        case "check": {
            [QEGVAR(EndConditions,TimelimitServer), ["check", player]] call CBA_fnc_serverEvent;
        };
        case "extend": {
            private _number = parseNumber _arg;
            if (_number > 0) then {
                [QEGVAR(EndConditions,TimelimitServer), ["extend", player, _number]] call CBA_fnc_serverEvent;
            };
        };
        case "extend": {
            if (_arg isEqualType "") then {
                [QEGVAR(EndConditions,TimelimitServer), ["message", player, _arg]] call CBA_fnc_serverEvent;
            };
        };
        default {};
    };
}, "admin"] call CBA_fnc_registerChatCommand;
