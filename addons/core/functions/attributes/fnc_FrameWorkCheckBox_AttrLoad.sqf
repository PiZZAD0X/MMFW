#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_config"];

(_ctrl controlsGroupCtrl 100) cbsetchecked _value;
if (_value) then {
    [] call FUNC(3denEH);
};
