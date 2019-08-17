#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_unit"];

removeHeadgear _unit;
removeGoggles _unit;
removeVest _unit;
removeBackpack _unit;
removeUniform _unit;
removeAllWeapons _unit;
removeAllAssignedItems _unit;
