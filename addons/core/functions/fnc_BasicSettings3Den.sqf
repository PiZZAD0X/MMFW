/*    Description: Main UO Framework Init. Declares needed vars, calls core functions
 *    Arguments:
 *         N/A
 *    Return Value:
 *         N/A
 *    Author
 *        Sacher
 */

#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

LOG("BasicSettings3Den called");

"Multiplayer" set3DENMissionAttribute ["respawn",3];
"Multiplayer" set3DENMissionAttribute ["respawndelay",5];
"Multiplayer" set3DENMissionAttribute ["disabledAI",true];
"Multiplayer" set3DENMissionAttribute ["respawnDialog",0];
"Multiplayer" set3DENMissionAttribute ["RespawnButton",1];
"Multiplayer" set3DENMissionAttribute ["respawnTemplates",["Base"]];
"Scenario" set3DENMissionAttribute ["EnableDebugConsole",1];
"Scenario" set3DENMissionAttribute ["enableTargetDebug",1];

if ((EGETMVALUE(Briefing,MissionNotes_Author,"")) isEqualTo "") then {
    QEGVAR(Briefing,MissionNotes) set3DENMissionAttribute [QEGVAR(Briefing,MissionNotes_Author),profileNameSteam];
};

if ((EGETMVALUE(Core,Version_Created,"")) isEqualTo "") then {
    QGVAR(Version_DummyCategory) set3DENMissionAttribute [QGVAR(Version_Created),QUOTE(VERSION)];
};

QGVAR(Version_DummyCategory) set3DENMissionAttribute [QGVAR(Version_Updated),QUOTE(VERSION)];
