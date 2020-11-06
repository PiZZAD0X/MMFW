/*
 * Author: Olsen
 *
 * Outputs disabled and destroyed tracked assets for set team.
 *
 * Arguments:
 * 0: team <string>
 *
 * Return Value:
 * disabled and destroyed assets <array>
 *
 * Public: No
 */


#include "script_component.hpp"

params ["_team"];

private _disabledAssets = [];
private _destroyedAssets = [];
{
    if ((GETVAR(_x,AssetTeam,sideUnknown)) isEqualto _team) then {
        if (alive _x) then {
            if ((!canMove _x) || (!canFire _x)) then {
                _disabledAssets set [count _disabledAssets, (GETVAR(_x,AssetName,objNull))];
            };
        } else {
            _destroyedAssets set [count _destroyedAssets, (GETVAR(_x,AssetName,objNull))];
        };
    };
} forEach vehicles;
TRACE_1("Destroyed Assets",_destroyedAssets);
TRACE_1("Disabled Assets",_disabledAssets);
_destroyedAssets = _destroyedAssets call FUNC(StackNames);
_disabledAssets = _disabledAssets call FUNC(StackNames);
[_disabledAssets, _destroyedAssets]
