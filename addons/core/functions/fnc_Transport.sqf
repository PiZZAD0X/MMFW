/*    Description: Sends display text event to group leader requesting transport for JiP player
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        Olsen & Starfox64 & PiZZADOX
 */


#include "script_component.hpp"
if !(hasInterface) exitWith {};

params ["_target"];
private _targets = [];
{
    if (leader _x isEqualto _x) then {
        _targets set [count _targets, _x];
    };
} forEach ([(side player)] call FUNC(AlivePlayers));
["ace_common_displayTextStructured", [["%1 joined the mission and is requesting transport.", name player], 1.5, _target], [_target]] call CBA_fnc_targetEvent;
[player,1,["ACE_SelfActions","Jip_Transport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
