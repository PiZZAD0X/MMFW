#include "script_component.hpp"

[QGVAR(TrackAssetEvent), {
    params [
        ["_asset", objNull, [objNull]],
        ["_name", "", [""]],
        ["_team", "", [""]]
    ];
    private _asset = vehicle (_asset);
    SETPVAR(_asset,AssetName,_name);
    SETPVAR(_asset,AssetTeam,_team);
}] call CBA_fnc_addEventHandler;
