#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Event), {
    if !(GETMVAR(Enabled,true)) exitWith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Marker Control", "Allows the mission maker to create markers visible to a single side and per briefing.", "Olsen, Sacher and PiZZADOX"]] call CBA_fnc_localEvent;
    private _markers = [];
    private _markersBriefing = [];
    MARKERSTEAMCHECK(west,BluforMarkers,BluforBriefingMarkers);
    MARKERSTEAMCHECK(east,OpforMarkers,OpforBriefingMarkers);
    MARKERSTEAMCHECK(independent,IndforMarkers,IndforBriefingMarkers);
    MARKERSTEAMCHECK(civilian,CivilianMarkers,CivilianBriefingMarkers);
    (GETMVAR(SystemMarkers,[])) apply {
        private _layerEntities = getMissionLayerEntities _x;
        if !(_layerEntities isEqualTo []) then {
            if !((_layerEntities select 1) isEqualto []) then {
                (_layerEntities select 1) apply {_markers pushBackUnique [sideLogic, _x]};
            };
        } else {
            _markers pushBackUnique [sideLogic, _x];
        };
    };
    TRACE_1("",_markers);
    _markers apply {
        _x params ["_side", "_marker"];
        if !(_side isEqualto (side player)) then {
            _marker setMarkerAlphaLocal 0;
        };
    };
    TRACE_1("",_markersBriefing);
    _markersBriefing apply {
        _x params ["_side", "_marker"];
        if !(_side isEqualto (side player)) then {
            _marker setMarkerAlphaLocal 0;
        };
    };
    [{(CBA_missionTime > 0)}, {
        params ["_markersBriefing"];
        _markersBriefing apply {
            _x params ["_side", "_marker"];
            _marker setMarkerAlphaLocal 0;
        };
    }, [_markersBriefing]] call CBA_fnc_WaitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(Event), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
