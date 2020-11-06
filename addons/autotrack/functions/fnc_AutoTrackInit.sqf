#include "script_component.hpp"
EXEC_CHECK(SERVER);

if !(GETMVAR(Enabled,false)) exitWith {};

params ["_vehicle"];
[QEGVAR(Core,RegisterModuleEvent), ["Auto Track Assets", "Automatically runs Asset Tracking on AI vehicles.", "Starfox64, Sacher and PiZZADOX"]] call CBA_fnc_globalEvent;
[{(!isNull (_this select 0))},{
    params ["_vehicle"];
    if ((side _vehicle) in GVAR(AutoTrackTeamArray) || {(GETMVAR(TrackEmpty,false)) && {(side _vehicle) isEqualTo sideEmpty}}) then {
        if ((GETVAR(_vehicle,AssetName,"")) isEqualTo "") then {
            private _index = (EGVAR(Core,Teams)) findIf {_x select 1 isEqualTo (side _vehicle)};
            if (_index isEqualTo -1) exitWith {
                ERROR("Cannot find team for autoTrackInit");
            };
            ((EGVAR(Core,Teams)) select _index) params ["_name", "_side", "_type", "_start", "_current", "_disabled", "_destroyed"];
            private _displayName = [_vehicle] call EFUNC(Core,getDisplayName);
            [QGVAR(TrackAssetEvent),[_vehicle, _displayName, _name]] call CBA_fnc_localEvent;
        };
    };
}, [_vehicle]] call CBA_fnc_WaitUntilAndExecute;
