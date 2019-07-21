#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QEGVAR(Core,SettingsLoaded), {
    [{!isNull player}, {
        private _briefing = [];
        switch (side player) do {
            case west: {
                #include "functions\defines\blufor_briefing.hpp"
            };
            case east: {
                #include "functions\defines\opfor_briefing.hpp"
            };
            case independent: {
                #include "functions\defines\indfor_briefing.hpp"
            };
            case civilian: {
                #include "functions\defines\civilian_briefing.hpp"
            };
        };
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
