/*    Description: Main Framework Init. Declares needed vars, calls core functions
 *    Arguments:
 *         N/A
 *    Return Value:
 *         N/A
 *    Author
 *        Sacher & PiZZADOX
 */

#include "script_component.hpp"
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
