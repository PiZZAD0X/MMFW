/*
 * Author: TheMagnetar
 * Returns if a building was checked by a group in the last x secods.
 *
 * Arguments:
 * 0: Marker <STRING> (Default: "")
 *
 * Return Value:
 * Random point <ARRAY> ([0,0] if invalid marker)
 *
 * Example:
 * ["marker"] call mmfw_building_fnc_markerRandomPos
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_building"];

private _checkedBuildings = missionNamespace getVariable [QEGVAR(building,checkedBuildings), []];

private _index = _checkedBuildings findIf {(_x select 0) isEqualTo _building};

_index != -1 && {(_checkedBuildings select _index) select 1 + 300 >= CBA_missionTime}
