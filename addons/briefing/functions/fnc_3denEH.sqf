#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

private _author = GETMVALUE(MissionNotes_Author,"");

if (_author isEqualTo "") then {
    private _profile = profileNameSteam;
    LOG_1("Setting mission Author value to %1",_profile);
    QGVAR(MissionNotes) set3DENMissionAttribute [QGVAR(MissionNotes_Author),_profile];
};
