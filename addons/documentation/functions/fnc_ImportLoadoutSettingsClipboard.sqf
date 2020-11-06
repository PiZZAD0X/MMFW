#include "script_component.hpp"
EDEN_CHECK;

private _loadoutList = (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []]);
private _copyData = call compile copyFromClipboard;
if (_loadoutList isEqualTo []) then {
    missionNamespace setVariable ["ace_arsenal_defaultLoadoutsList", _copyData];
} else {
    ace_arsenal_defaultLoadoutsList append _copyData;
};
LOG("Loaded Loadout Settings from Clipboard!");
