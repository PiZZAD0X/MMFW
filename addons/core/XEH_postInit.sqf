#include "script_component.hpp"

private _GlobalPostInit = (GETMVALUE(GlobalPostInit,""));
LOG_1("_GlobalPostInit:%1",_GlobalPostInit);
if !(_GlobalPostInit isEqualTo "") then {
    call compile _GlobalPostInit;
};
