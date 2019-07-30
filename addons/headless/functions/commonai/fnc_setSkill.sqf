/*
 * Author: TheMagnetar
 * Handles assigning the additional options to the group.
 *
 * Arguments:
 * 0: Group <OBJECT>
 * 1: Skill <ARRAY>
 *  0: Skill for units <ARRAY>
 *  1: Skill for leader units <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player, [[0.2], [0.8]]] call mmfw_core_fnc_setSkill
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_group", "_skillArray"];

_skillArray params ["_skill", "_skillLeader"];

if (_skill isEqualTo [] || {_skillLeader isEqualTo []}) exitWith {};

private _skillCategory = [];

if ((toLower (_skill select 0)) isEqualTo "general") then {
    _skillCategory = ["general"];
} else {
    _skillCategory = ["aimingShake", "aimingSpeed", "endurance", "spotDistance", "spotTime", "courage", "reloadSpeed", "commanding"];
};

{
    private _unit = _x;
    if (_unit isKindOf "CAManBase") then {
        private _selectedSkill = _skill;

        if (leader _group == _unit) then {
            _selectedSkill = _skillLeader;
        };

        {
            private _val = 0;
            if ((_selectedSkill select _forEachIndex) isEqualType []) then {
                (_selectedSkill select _forEachIndex) params ["_min", "_max"];

                _val = _min + random [_max - _min];
            } else {
                _val = (_selectedSkill select _forEachIndex);
            };
            _unit setSkill [_x, _val];
        } forEach _skillCategory;
    };
} forEach (units _group);
