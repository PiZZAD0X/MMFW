#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch (_mode) do {
    // Default object init
    case "init": {
        EXEC_CHECK(SERVER);
        if (!is3DEN) then {
            _input params ["_logic",["_isActivated",true,[true]]];
            if !(_isActivated) exitWith {};
            private _zoneName = GETVAR(_logic,ZoneName,"");
            private _position = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100, 0, false]];
            _size params ["_radiusX", "_radiusY", "_direction", "_isRectangle"];
            private _area = [_position, _radiusX, _radiusY, _direction, _isRectangle];
            private _mode = ["ONCE","HOLD","REPEATABLE"] select (GETVAR(_logic,Mode,1));
            private _ratioNeeded = ((GETVAR(_logic,RatioNeeded,75)) / 100);
            private _BluforCap = (GETVAR(_logic,Cap_Blufor,0));
            private _OpforCap = (GETVAR(_logic,Cap_Opfor,0));
            private _IndforCap = (GETVAR(_logic,Cap_Indfor,0));
            private _CivCap = (GETVAR(_logic,Cap_Civilian,0));
            private _capArray = [_BluforCap,_OpforCap,_IndforCap,_CivCap];
            private _BluforTime = (GETVAR(_logic,Time_Blufor,30));
            private _OpforTime = (GETVAR(_logic,Time_Opfor,30));
            private _IndforTime = (GETVAR(_logic,Time_Indfor,30));
            private _CivTime = (GETVAR(_logic,Time_Civilian,30));
            private _timeArray = [_BluforTime,_OpforTime,_IndforTime,_CivTime];
            private _BluforMessageCapturing = GETVAR(_logic,MessageCapturing_Blufor,"BLUFOR is capturing the zone!");
            private _BluforMessageCaptured = GETVAR(_logic,MessageCaptured_Blufor,"BLUFOR has captured the zone!");
            private _OpforMessageCapturing = GETVAR(_logic,MessageCapturing_Opfor,"Opfor is capturing the zone!");
            private _OpforMessageCaptured = GETVAR(_logic,MessageCaptured_Opfor,"Opfor has captured the zone!");
            private _IndforMessageCapturing = GETVAR(_logic,MessageCapturing_Indfor,"Indfor is capturing the zone!");
            private _IndforMessageCaptured = GETVAR(_logic,MessageCaptured_Indfor,"Indfor has captured the zone!");
            private _CivMessageCapturing = GETVAR(_logic,MessageCapturing_Civ,"Civilian is capturing the zone!");
            private _CivMessageCaptured = GETVAR(_logic,MessageCaptured_Civ,"Civilian has captured the zone!");
            private _ContestedMessage = GETVAR(_logic,ContestedMessage,"The zone is contested!");
            private _UncontestedMessage = GETVAR(_logic,UncontestedMessage,"The zone is uncontested!");
            private _messagesArray = [[_BluforMessageCapturing,_BluforMessageCaptured],
                                        [_OpforMessageCapturing,_OpforMessageCaptured],
                                        [_IndforMessageCapturing,_IndforMessageCaptured],
                                        [_CivMessageCapturing,_CivMessageCaptured],
                                        _ContestedMessage,
                                        _UncontestedMessage];
            private _BluforColour = GETVAR(_logic,Colour_Blufor,"colorBLUFOR");
            if (_BluforColour isEqualTo 'NONE') then {_BluforColour = "colorBLUFOR"};
            private _OpforColour = GETVAR(_logic,Colour_Opfor,"colorOPFOR");
            if (_OpforColour isEqualTo 'NONE') then {_OpforColour = "colorOPFOR"};
            private _IndforColour = GETVAR(_logic,Colour_Indfor,"colorIndependent");
            if (_IndforColour isEqualTo 'NONE') then {_IndforColour = "colorIndependent"};
            private _CivColour = GETVAR(_logic,Colour_Civilian,"colorCivilian");
            if (_CivColour isEqualTo 'NONE') then {_CivColour = "colorCivilian"};
            private _ContestedColour = GETVAR(_logic,Colour_Uncontested,"ColorYellow");
            if (_ContestedColour isEqualTo 'NONE') then {_ContestedColour = "ColorYellow"};
            private _UncontestedColour = GETVAR(_logic,Colour_Contested,"ColorGrey");
            if (_UncontestedColour isEqualTo 'NONE') then {_UncontestedColour = "ColorGrey"};
            private _colours = [_BluforColour,
                                _OpforColour,
                                _IndforColour,
                                _CivColour,
                                _ContestedColour,
                                _UncontestedColour
                                ];
            private _hidden = GETVAR(_logic,Hidden,false);
            private _silent = GETVAR(_logic,Silent,false);
            private _automessages = GETVAR(_logic,AutoMessages,false);
            private _cond = GETVAR(_logic,Condition,true);
            private _AICount = GETVAR(_logic,AICount,true);
            [_logic,_zoneName,_area,_mode,_capArray,_timeArray,_messagesArray,_colours,_hidden,_silent,_automessages,_ratioNeeded,_cond,_AICount] call FUNC(Init);
        };
    };
    // When some attributes were changed (including position and rotation)
    case "attributesChanged3DEN": {};
    default {};
};
true
