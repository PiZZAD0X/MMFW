
#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_control", "_code", "_shift", "_control", "_alt"];
if (_code isEqualto 35 && {!_shift} && {_control} && {!_alt} && {(GETMVAR(keyHandler_display_hidden,false))}) then {
    ([] call BIS_fnc_displayMission) createDisplay "RscDisplayEGSpectator";
    SETMVAR(keyHandler_display_hidden,false);
    GVAR(keyHandleEG) = (findDisplay 60492) displayAddEventHandler ["keyDown", {[] call FUNC(keyHandleEG);}];
    if (GETMVAR(Killcam_active,false)) then {
        GVAR(killcam_keyHandle) = (findDisplay 60492) displayAddEventHandler ["keyDown", {[] call FUNC(KillCamToggleKeyH);}];
    };
};
