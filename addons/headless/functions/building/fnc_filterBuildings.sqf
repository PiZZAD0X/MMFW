/*
 * Author: TheMagnetar
 * Filters the given buildings
 *
 * Arguments:
 * 0: Unit or position <OBJECT><ARRAY>
 * 1: Radius <NUMBER> (default: 25)
 * 2: Return only the nearest building <BOOL> (default: false)
 *
 * Return Value:
 * Array of buildings <ARRAY> or the nearest building <OBJECT>
 *
 * Example:
 * [nearestBuilding player] call mmfw_building_fnc_getNearBuildings
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_buildings", "_filter"];

{
    _x params ["_key", "_value"];
    private _filteredBuildings = [];

    switch (_key) do {
        case "area": {
            _filteredBuildings = _buildings select {_x inArea _value};
        };
        case "enterable": {
            // Enterable buildings are those that a) can be entered b) do not have occupied positions
            _filteredBuildings = _buildings select {count (_x buildingPos -1) > 0 && {_x getVariable [QEGVAR(building,freePositions), -1] == -1 || {_x getVariable [QEGVAR(building,freePositions), -1] > 0}}};
        };
        case "blacklist": {
            _filteredBuildings = _buildings select {
                private _bldg = _x;
                private _passFilter = true;
                {
                    if (_bldg in _x) exitWith {_passFilter = false;};
                } forEach _value;

                _passFilter;
            };
        };
    };

    _buildings = _filteredBuildings;
} forEach _filter;

_buildings
