/*    Description: Gets cached displaynames for classes
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */

#include "script_component.hpp"

params [
    ["_class", "", [""]],
    ["_cfg", "CfgVehicles", [""]]
];

private _index = GVAR(CachedDisplayNames) findIf {_x select 0 isEqualTo _class};
private _return = if (_index isEqualTo -1) then {
    private _displayName = [(configFile >> _cfg >> typeOf _class), "displayName", "unknownName"] call BIS_fnc_returnConfigEntry;
    if (_displayName isEqualTo "unknownName") then {
        ERROR_1("%1 has unknown displayName", _class);
    };
    GVAR(CachedDisplayNames) pushBackUnique [_class, _displayName];
    _displayName
} else {
    GVAR(CachedDisplayNames) select _index select 1
};
_return
