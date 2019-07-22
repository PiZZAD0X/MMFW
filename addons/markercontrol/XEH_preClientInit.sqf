#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Event), {
    if !(GETMVAR(Enabled,true)) exitWith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Marker Control", "Allows the mission maker to create markers visible to a single side and per briefing.", "Olsen, Sacher and PiZZADOX"]] call CBA_fnc_localEvent;
    private _markers = [];
    private _markersBriefing = [];
    {
        LOG_1("Checking %1 Marker in BluforMarkers",_x);
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            LOG_1("Checking %1 Marker in getMissionLayerEntities",_x);
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                LOG_1("%1 Marker in getMissionLayerEntities",_x);
                {_markers pushBack [west, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markers pushBack [west, _x];
            LOG_1("%1 Marker pushedback in BluforMarkers",_x);
        };
    } forEach (GETMVAR(BluforMarkers,[]));
    {
        LOG_1("Checking %1 Marker in BluforMarkers",_x);
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            LOG_1("Checking %1 Marker in getMissionLayerEntities",_x);
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                LOG_1("%1 Marker in getMissionLayerEntities",_x);
                {_markersBriefing pushBack [west, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markersBriefing pushBack [west, _x];
            LOG_1("%1 Marker pushedback in BluforMarkers",_x);
        };
    } forEach (GETMVAR(BluforBriefingMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markers pushBack [east, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markers pushBack [east, _x];
        };
    } forEach (GETMVAR(OpforMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markersBriefing pushBack [east, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markersBriefing pushBack [east, _x];
        };
    } forEach (GETMVAR(OpforBriefingMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markers pushBack [independent, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markers pushBack [independent, _x];
        };
    } forEach (GETMVAR(IndforMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markersBriefing pushBack [independent, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markersBriefing pushBack [independent, _x];
        };
    } forEach (GETMVAR(IndforBriefingMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markers pushBack [civilian, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markers pushBack [civilian, _x];
        };
    } forEach (GETMVAR(CivilianMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markersBriefing pushBack [civilian, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markersBriefing pushBack [civilian, _x];
        };
    } forEach (GETMVAR(CivilianBriefingMarkers,[]));
    {
        if !((getMissionLayerEntities _x) isEqualTo []) then {
            if !(((getMissionLayerEntities _x) select 1) isEqualto []) then {
                {_markers pushBack [sideLogic, _x];} foreach ((getMissionLayerEntities _x) select 1);
            };
        } else {
            _markers pushBack [sideLogic, _x];
        };
    } forEach (GETMVAR(SystemMarkers,[]));
    LOG_1("_markers: %1",_markers);
    {
        _x params ["_side","_marker"];
        LOG_2("_side: %1 _marker: %2",_side,_marker);
        if !(_side isEqualto (side player)) then {
            _marker setMarkerAlphaLocal 0;
        };
    } forEach _markers;
    LOG_1("_markersBriefing: %1",_markersBriefing);
    {
        _x params ["_side","_marker"];
        LOG_2("_side: %1 _marker: %2",_side,_marker);
        if !(_side isEqualto (side player)) then {
            _marker setMarkerAlphaLocal 0;
        };
    } forEach _markersBriefing;
    [{(CBA_missionTime > 0)}, {
        params ["_markersBriefing"];
        {
            _x params ["_side","_marker"];
            _marker setMarkerAlphaLocal 0;
        } forEach _markersBriefing;
    }, [_markersBriefing]] call CBA_fnc_WaitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(Event), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
