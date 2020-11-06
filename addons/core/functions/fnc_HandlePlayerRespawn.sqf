#include "script_component.hpp"

params [
    ["_message", "", [""]],
    "_newSide",
    ["_location", objNull, [objNull]]
];

if (GETMVAR(Spectating,false)) then {
    [] call FUNC(endSpectate);
};

private _templateSettings = switch (side player) do {
    case west: {EGETMVAR(Respawn,Templates_BLUFOR,[])};
    case east: {EGETMVAR(Respawn,Templates_OPFOR,[])};
    case independent: {EGETMVAR(Respawn,Templates_Indfor,[])};
    case civilian: {EGETMVAR(Respawn,Templates_Civilian,[])};
};

// Re call player init event
[QGVAR(PlayerInitEvent), []] call CBA_fnc_localEvent;

// Remove Killed Displays
private _deathScreenType = (EGETMVAR(Respawn,DeathScreenType,"FADE"));
switch (_deathScreenType) do {
    case "FADE": {
        (QGVAR(KilledLayer)) cutText ["","BLACK IN", 5];
        [QGVAR(DeathHearing), 0, false] call ace_common_fnc_setHearingCapability;
        0 fadeSound 1;
    };
    case "INSTANT": {
        (QGVAR(KilledLayer)) cutText ["","BLACK IN", 5];
        [QGVAR(DeathHearing), 0, false] call ace_common_fnc_setHearingCapability;
        0 fadeSound 1;
    };
    case "VR": {
        0 fadeSound 1;
        playSound ("Transition" + str (1 + floor random 3));
        [] call BIS_fnc_VRFadeIn;
    };
    default {
        (QGVAR(KilledLayer)) cutText ["","BLACK IN", 5];
        [QGVAR(DeathHearing), 0, false] call ace_common_fnc_setHearingCapability;
        0 fadeSound 1;
    };
};

// Handle Group Join
if ((QEGVAR(RTemplatesS,JoinGroup)) in _templateSettings) then {
    private _oldGroup = GETMVAR(OLDGROUP,grpnull);
    [player] joinSilent _oldGroup;
    TRACE_1("Respawnside joingroup:",_oldGroup);
} else {
    if !(_newSide isEqualTo side player) then {
        private _newGroup = createGroup _newSide;
        [player] joinSilent _newGroup;
    };
    TRACE_1("Respawn Side:",_newSide);
};

// Handle Teleport Locations
if (_location isEqualTo objNull) then {
    if ((EGETMVAR(Respawn,AreaRespawn,5)) > 0) then {
        [ACE_player, GVAR(SpawnPos), (EGETMVAR(Respawn,AreaRespawn,5))] call CBA_fnc_setPos;
    } else {
        ACE_player setPosATL GVAR(SpawnPos)
    };
} else {
    private _area = GETVAR(_location,Area,[]);
    private _zPos = getPosATL _location select 2;
    _area params ["_pos", "_radiusX", "_radiusY"];
    private _pos = if (_radiusX isEqualTo 0 && {_radiusY isEqualTo 0}) then {
        _pos
    } else {
        [_area] call CBA_fnc_randPosArea
    };
    if (GETVAR(_location,HandleHeight,false)) then {
        _pos params ["_xPos", "_yPos"];
        ACE_player setPosATL [_xPos, _yPos, _zPos];
    } else {
        ACE_player setPos _pos;
    };
};

// Handle Module and Gear Settings
//CoverMap
if ((QEGVAR(RTemplatesS,CoverMap)) in _templateSettings) then {
    [QEGVAR(CoverMap,InitEvent), []] call CBA_fnc_localEvent;
};
//SafeStart
if ((QEGVAR(RTemplatesS,SafeStart)) in _templateSettings) then {
    [QEGVAR(SafeStart,Event), []] call CBA_fnc_localEvent;
};
//Team Colour
if ((QEGVAR(RTemplatesS,TeamColour)) in _templateSettings) then {
    [QEGVAR(TeamColour,Event), []] call CBA_fnc_localEvent;
};
//Map and Compass Remover
if ((QEGVAR(RTemplatesS,MapAndCompassRemover)) in _templateSettings) then {
    [QEGVAR(MapAndCompassRemover,PlayerEvent), []] call CBA_fnc_localEvent;
};
//Gear
if ((QEGVAR(RTemplatesS,Gear)) in _templateSettings) then {
    [QEGVAR(Gear,PlayerGearLoad), []] call CBA_fnc_localEvent;
};
//Acre
if ((QEGVAR(RTemplatesS,Acre)) in _templateSettings) then {
    [QEGVAR(Acre,AddRadio_Event), []] call CBA_fnc_localEvent;
};
//StartInParachute
if ((QEGVAR(RTemplatesS,StartInParachute)) in _templateSettings) then {
    [QEGVAR(StartInParachute,LocalEvent), []] call CBA_fnc_localEvent;
};

if !(_message isEqualTo "") then {
    _message call BIS_fnc_titleText;
};
