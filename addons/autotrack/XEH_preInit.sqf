#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(AutoTrackTeamArray) = [];

if (GETMVAR(Blufor,false)) then {
    GVAR(AutoTrackTeamArray) append [blufor];
};

if (GETMVAR(Opfor,false)) then {
    GVAR(AutoTrackTeamArray) append [opfor];
};

if (GETMVAR(Indfor,false)) then {
    GVAR(AutoTrackTeamArray) append [independent];
};

if (GETMVAR(Civfor,false)) then {
    GVAR(AutoTrackTeamArray) append [civilian];
};

ADDON = true;
