#include "script_component.hpp"
EXEC_CHECK(CLIENT);

#include "functions\defines\TeamMacro.hpp"

[QEGVAR(Core,SettingsLoaded), {
    if !(GETMVAR(Enabled,false)) exitWith {};
    [QEGVAR(Core,RegisterModuleEvent), ["Start Text", "Displays animated text on mission start.", "Sacher"]] call CBA_fnc_localEvent;
    [{(!isNull ace_player) && {(CBA_missionTime > 1)}}, {
        private _dateType = [["DATE"],["TIME"],["DATETIME"]] select (GETMVAR(TimeSelect,2));
        private _startTextArray = [];
        switch (side ace_player) do { //Checks what team the player is on
            case west: {
                STARTTEXTTEAMMACRO(Blufor);
            };
            case east: {
                STARTTEXTTEAMMACRO(Opfor);
            };
            case independent: {
                STARTTEXTTEAMMACRO(Indfor);
            };
            case civilian: {
                STARTTEXTTEAMMACRO(Civilian);
            };
        };
        _startTextArray pushBack _dateType;
        [_startTextArray] call FUNC(Init);
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
