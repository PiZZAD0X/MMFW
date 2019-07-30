/*
 * Author: TheMagnetar
 * Helper function for creating a template of a group of infantry units.
 *
 * Arguments:
 * 0: Group to clone <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group player1] call mmfw_core_fnc_helperTemplateInfantry
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_modelGroup"];

// Generate units
private _unitsToSpawn = [];
private _loadout = [];
private _rank = [];
private _skill = [];

private _leader = leader _modelGroup;
_unitsToSpawn pushBack (typeOf _leader);
_loadout pushBack (getUnitLoadout _leader);
_rank pushBack (rank _leader);
_skill pushBack (skill _leader);

private _unitsGroup = units _modelGroup;
_unitsGroup deleteAt (_unitsGroup find _leader);

{
    _unitsToSpawn pushBack (typeOf _x);
    _loadout pushBack (getUnitLoadout _x);
    _rank pushBack (rank _x);
    _skill pushBack (skill _x)
} forEach _unitsGroup;

[_unitsToSpawn, _loadout, _rank, _skill]
