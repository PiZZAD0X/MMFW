#include "script_component.hpp"
EXEC_CHECK(SERVER);

//IGNORE_PRIVATE_WARNING ["_x"];
params ["_className"];
private _ret = "Error";
if (isNil QGVAR(classNames)) then {GVAR(classNames) = [];};
private _foundClass = GVAR(classNames) findIf {(_x select 0) isEqualto _className};
if (_foundClass isEqualto -1) then {
    private _cfg = (configFile >> "CfgMagazines" >> _className);
    _ret = getText(_cfg >> "displayName");
    GVAR(classNames) pushBack [_className,_ret];
} else {
    _ret = ((GVAR(classNames) select _foundClass) select 1);
};

_ret
