#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QEGVAR(Core,SettingsLoaded), {
    if !(GETMVAR(Enabled,false)) exitWith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Start Text", "Displays animated text on mission start.", "Sacher"]] call CBA_fnc_localEvent;
    [{(!isNull player) && {(CBA_missionTime > 1)}}, {
        private _dateType = [["DATE"],["TIME"],["DATETIME"]] select (GETMVAR(TimeSelect,2));
        private _startTextArray = [];
        switch (side player) do { //Checks what team the player is on
            case west: {
                private _TitleQuoteVar = GETMVAR(TitleQuote_Blufor,"");
                private _textVar = GETMVAR(Text_Blufor,"");
                if !(_TitleQuoteVar isEqualto "" ) then {_startTextArray pushBack ["TitleQUOTE", _TitleQuoteVar];};
                if !(_textVar isEqualto "" ) then {_startTextArray pushBack ["TEXT", _textVar];};
            };
            case east: {
                private _TitleQuoteVar = GETMVAR(TitleQuote_Opfor,"");
                private _textVar = GETMVAR(Text_Opfor,"");
                if !(_TitleQuoteVar isEqualto "" ) then {_startTextArray pushBack ["TitleQUOTE", _TitleQuoteVar];};
                if !(_textVar isEqualto "" ) then {_startTextArray pushBack ["TEXT", _textVar];};
            };
            case independent: {
                private _TitleQuoteVar = GETMVAR(TitleQuote_Indfor,"");
                private _textVar = GETMVAR(Text_Indfor,"");
                if !(_TitleQuoteVar isEqualto "" ) then {_startTextArray pushBack ["TitleQUOTE", _TitleQuoteVar];};
                if !(_textVar isEqualto "" ) then {_startTextArray pushBack ["TEXT", _textVar];};
            };
            case civilian: {
                private _TitleQuoteVar = GETMVAR(TitleQuote_Civ,"");
                private _textVar = GETMVAR(Text_Civ,"");
                if !(_TitleQuoteVar isEqualto "" ) then {_startTextArray pushBack ["TitleQUOTE", _TitleQuoteVar];};
                if !(_textVar isEqualto "" ) then {_startTextArray pushBack ["TEXT", _textVar];};
            };
        };
        _startTextArray pushBack _dateType;
        [_startTextArray] call FUNC(Init);
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
