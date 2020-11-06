
#include "script_component.hpp"

//37 is DIK code for K
if ((_this select 1) isEqualto 37) then {
    if (GETMVAR(killcam_toggle,false)) then {
        SETMVAR(killcam_toggle,false);
        "KillCamLayer" cutText ["", "PLAIN DOWN"];
    } else {
        SETMVAR(killcam_toggle,true);
        "KillCamLayer" cutText ["Line shows LINE OF SIGHT from postion of enemy to player's position during the time of death.\nPress K to toggle hud markers off.\n\nTHIS FRAMEWORK FEATURE IS WIP. It may contain bugs and may be updated or changed at any point.", "PLAIN DOWN"];
    };
};
