#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

if ((GETMVALUE(Version_Created,"")) isEqualTo "") then {
    QGVAR(Version_DummyCategory) set3DENMissionAttribute [QGVAR(Version_Created),QUOTE(VERSION)];
};

QGVAR(Version_DummyCategory) set3DENMissionAttribute [QGVAR(Version_Updated),QUOTE(VERSION)];
