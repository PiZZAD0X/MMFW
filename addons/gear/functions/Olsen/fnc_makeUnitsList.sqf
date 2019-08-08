/*
 * Author: BlackHawk
 *
 * Creates array on the server containing all units with missing gear type
 *
 * Arguments:
 * 0: class <string>
 * 1: unit <object>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */

params ["_class", "_unit"];

if (isNil QGVAR(MissingGear)) then {
    GVAR(MissingGear) = [];
    [{CBA_missionTime > 0}, {publicVariable QGVAR(MissingGear)}] call CBA_fnc_waitUntilAndExecute;
};

private _index = -1;

{
    if ((_x select 0) == _class) exitWith {_index = _forEachIndex};
} foreach GVAR(MissingGear);

if (_index != -1) then {
    ((GVAR(MissingGear) select _index) select 1) pushBackUnique _unit;
} else {
    GVAR(MissingGear) pushBack [_class, [_unit]];
};

if (CBA_missionTime > 0) then {
    publicVariable QGVAR(MissingGear);
};
