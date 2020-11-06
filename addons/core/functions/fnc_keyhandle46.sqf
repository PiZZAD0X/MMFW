
#include "script_component.hpp"

params ["_control", "_code", "_shift", "_control", "_alt"];
if (_code isEqualto 35 && {!_shift} && {_control} && {!_alt} && {(EGETMVAR(Spectator,keyHandler_display_hidden,false))}) then {
    ([] call BIS_fnc_displayMission) createDisplay "RscDisplayEGSpectator";
    ESETMVAR(Spectator,keyHandler_display_hidden,false);
    EGVAR(Spectator,keyHandleEG) = (findDisplay 60492) displayAddEventHandler ["keyDown", {[] call FUNC(keyHandleEG);}];
    if (EGETMVAR(Spectator,Killcam_active,false)) then {
        EGVAR(Spectator,killcam_keyHandle) = (findDisplay 60492) displayAddEventHandler ["keyDown", {[] call FUNC(KillCamToggleKeyH);}];
    };
};
