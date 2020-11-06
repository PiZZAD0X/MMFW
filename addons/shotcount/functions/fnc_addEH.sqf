#include "script_component.hpp"
EXEC_CHECK(ALL);

if !(GETMVAR(Enabled,false)) exitwith {};
[QEGVAR(Core,RegisterModuleEvent), ["Shot Count", "Count shots fired by units", "Beta, TinfoilHate, PiZZADOX and Sacher"]] call CBA_fnc_localEvent;
