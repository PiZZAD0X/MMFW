#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

LOG("Mission Author started");

private _author = GETMVALUE(MissionNotes_Author,"");
LOG_1("Mission Author: %1",_author);

if ((GETMVALUE(MissionNotes_Author,"")) isEqualTo "") then {
    private _profile = profileNameSteam;
    LOG_1("Setting mission Author value to %1",_profile);
    QGVAR(MissionNotes) set3DENMissionAttribute [QGVAR(MissionNotes_Author),_profile];
};
