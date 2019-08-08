/*
 * Author: Olsen
 *
 * Remove all gear from vehicle.
 *
 * Arguments:
 * 0: vehicle <object>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);

params ["_vehicle"];

clearItemCargoGlobal _vehicle;
clearMagazineCargoGlobal _vehicle;
clearWeaponCargoGlobal _vehicle;
clearBackpackCargoGlobal _vehicle;
