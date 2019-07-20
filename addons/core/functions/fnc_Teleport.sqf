/*    Description: Teleports player to most senior alive group member
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        Olsen & Starfox64 & PiZZADOX
 */


#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_target"];
private _target = (leader player);
if (player isEqualto _target || !(_target call FUNC(Alive))) then {
    private _rank = -1;
    {
        if (rankId _x > _rank && {(_target call FUNC(Alive))}) then {
            _rank = rankId _x;
            _target = _x;
        };
    } forEach ((units group player) - [player]);
};
if (!((_target call FUNC(Alive)) && {((_target isEqualto vehicle _target) || ((vehicle _target) call FUNC(HasEmptyPositions)))})) then {
    private _rank = -1;
    private _count = 0;
    {
        if (_x call FUNC(Alive)) then {
            _count = _count + 1;
            if ((rankId _x > _rank) && {(!(_x isEqualto vehicle _x) || ((vehicle _x) call FUNC(HasEmptyPositions)))}) then {
                _rank = rankId _x;
                _target = _x;
            };
        };
    } forEach ((units group player) - [player]);
    if (_rank isEqualto -1) then {
        _target = objNull;
        if (_count isEqualto 0) then {
            [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
            ["No one left in the squad, cannot teleport!"] call FUNC(parsedTextDisplay);
        } else {
            ["Not possible to JIP teleport to anyone, please try again later"] call FUNC(parsedTextDisplay);
        };
    };
};
if (!isNull(_target)) then {
    if (_target isEqualto vehicle _target) then {
        private _moveInSuccess = player moveInAny (vehicle _target);
        [{!(isNil (this select 0))}, {
            params ["_moveInSuccess"];
            if (_moveInSuccess) then {
                [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                ["ace_common_displayTextStructured", [["%1 joined the mission and teleported into the vehicle.", name player], 1.5, _target], [_target]] call CBA_fnc_targetEvent;
            } else {
                ["Failed to move into leader's vehicle, please try again later."] call FUNC(parsedTextDisplay);
            };
        }, [_moveInSuccess]] call CBA_fnc_WaitUntilAndExecute;
    } else {
        private _stance = stance _target;
        switch (_stance) do {
            case "CROUCH": {
                player playActionNow "PlayerCrouch";
            };
            case "PRONE": {
                player playActionNow "PlayerProne";
            };
            case "STAND": {
                player playActionNow "PlayerStand";
            };
            default {};
        };
        private _pos = [(_target getpos [getdir _target, -2]), 1, 10, 1, 0, 25, 0] call BIS_fnc_findSafePos;
        if (_pos distance _target <= 10) then {
            private _enemy = false;
            if ((GETMVAR(EnemyDISTANCE,100)) > 0) then {
                private _nearestentitiesArray = _target nearEntities [["Car", "Motorcycle", "Tank", "Man"], GETMVAR(EnemyDISTANCE,100)];
                {
                    if ([side _x, side player] call BIS_fnc_sideIsEnemy) exitwith {_enemy = true;};
                } foreach _nearestentitiesArray;
            };
            if !(_enemy) then {
                player setPos (_pos);
                [player,1,["ACE_SelfActions","Jip_Teleport_Action"]] call ace_interact_menu_fnc_removeActionFromObject;
                ["ace_common_displayTextStructured", [["%1 joined the mission and teleported to you.", name player], 1.5, _target], [_target]] call CBA_fnc_targetEvent;
                private _eventhandlerdamage = player addEventHandler ["HandleDamage",{
                    params ["_unit","","_damage","_shooter"];
                    if (side _shooter isEqualto side _unit) then { _damage = 0};
                    _damage
                }];
                [{
                    player removeEventHandler ["HandleDamage", _eventhandlerdamage];
                }, [_eventhandlerdamage], 3] call CBA_fnc_WaitAndExecute;
            } else {
                ["Enemies are too close to group leader, please try again later"] call FUNC(parsedTextDisplay);
            };
        } else {
            ["Not possible to JIP teleport to group leader, please try again later"] call FUNC(parsedTextDisplay);
        };
    };
} else {
    ["Something went wrong, target doesn't exist."] call FUNC(parsedTextDisplay);
};
