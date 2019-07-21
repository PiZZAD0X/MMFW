#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(Event), {
    [{(!isNull player) && {(CBA_missionTime > 1)}}, {
        private _colour = (GETPLVAR(Colour,"NONE"));
        if (_colour isEqualto "White") then {_colour = "MAIN";};
        if !(_colour isEqualto "NONE") then {
            ["CBA_teamColorChanged", [player, _colour]] call CBA_fnc_globalEvent;
        };
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    [QGVAR(Event), []] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;
