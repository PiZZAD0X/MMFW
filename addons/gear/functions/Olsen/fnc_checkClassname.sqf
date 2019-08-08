/*
 * Author: BlackHawk
 *
 * Check if item classname is valid.
 *
 * Arguments:
 * 0: classname <string>
 *
 * Return Value:
 * is valid <bool>
 *
 * Public: No
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);

params [
    ["_class", "", [""]],
    ["_unit", objNull, [objNull]]
];

private _result = (
    isClass (configfile >> "CfgWeapons" >> _class)
    || {(isClass (configFile >> "CfgMagazines" >> _class))}
    || {(isClass (configFile >> "CfgGlasses" >> _class))}
    || {(isClass (configFile >> "CfgVehicles" >> _class))}
);

if (!_result) then {
    if (!isMultiplayer) then {
        ERROR_1("Invalid classname given! %1",_class);
    };
    [_class, {
        params ["_class"];
        if (!isNil QGVAR(MissingGear_found)) then {
            if !(_class in GVAR(MissingGear_found)) then {
                ERROR_1("Framework has detected an invalid classname - %1! Mission will continue but some parts of gear will be missing.",(str _class));
                GVAR(MissingGear_found) pushBackUnique _class;
            };
        } else {
            ERROR_1("Framework has detected an invalid classname - %1! Mission will continue but some parts of gear will be missing.",(str _class));
            GVAR(MissingGear_found) = [_class];
        };
    }] remoteExec ["BIS_fnc_call", 0, true];

    if (!isNull _unit) then {
        [_class, _unit] remoteExecCall [QFUNC(makeUnitsList), 2, false];
    };
};

_result
