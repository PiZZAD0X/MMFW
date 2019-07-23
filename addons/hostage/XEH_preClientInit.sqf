#include "script_component.hpp"

[QGVAR(ACEActionsEvent), {
    params ["_unit"];
    private _condition = {
        params ["_target", "_player"];
        LOG_2("_statement %1, %2",_target,_player);
        (!(GETVAR((_this select 0),IsRescued,false))
        && !(GETVAR((_this select 0),IsUntied,false))
        && {(alive (_this select 0))})
    };
    private _statement = {
        params ["_target", "_player"];
        LOG_2("_statement %1, %2",_target,_player);
        [_target,_player] call FUNC(Rescue);
    };
    private _rescueaction = ["RescueHostage", "Rescue Hostage","",_statement,_condition] call ace_interact_menu_fnc_createAction;
    [_unit, 0, ["ACE_MainActions"], _rescueaction] call ace_interact_menu_fnc_addActionToObject;
}] call CBA_fnc_addEventHandler;
