#include "script_component.hpp"
EDEN_CHECK;

private _loadoutsList = (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []]);
copytoClipboard (str _loadoutsList);
LOG("Loadout settings copied to clipboard");
