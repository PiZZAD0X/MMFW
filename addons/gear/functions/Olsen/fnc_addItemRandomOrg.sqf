/*
 * Author: Olsen
 *
 * Add random item to unit.
 *
 * Arguments:
 * 0: unit <object> and loadout name <string> <array>
 * 1: items <array>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit", "_loadoutType", "_items", ["_amount",1,[1]], ["_position", "NONE", [""]]];

if (count _items > 1) then {
    if (typeName (_items select 1) == "ARRAY") then {
        _position = "ARRAY";
    } else {
        if (typeName (_items select 1) == "SCALAR") then {
            _amount = _items select 1;
            if (count _items > 2) then {
                _position = _items select 2;
            };
            _items = _items select 0;
        };
    };
};

private _randomPick = (_items select (([1, count _items] call FUNC(RandomRange)) - 1));
if (_position == "ARRAY") then {
    if ((_randomPick select 0) isEqualType "ARRAY") then {
        {
            ([_unit, _loadoutType] + _x) call FUNC(AddItemOrg);
        } forEach _randomPick;
    } else {
        ([_unit, _loadoutType] + _randomPick) call FUNC(AddItemOrg);
    };
} else {
    [_unit, _loadoutType, _randomPick, _amount, _position] call FUNC(AddItemOrg);
};
