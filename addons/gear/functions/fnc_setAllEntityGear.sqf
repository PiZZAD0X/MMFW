#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

{
    _x call FUNC(GearHandleEH);
} foreach (all3DENEntities select 0);
