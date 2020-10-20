#include "script_component.hpp"

params [["_team", west, [west]]];

private _teamVar = switch _team do {
    case west: {"BLUFOR"};
    case east: {"OPFOR"};
    case independent: {"INDFOR"};
    case civilian: {"CIVILIAN"};
    default {"BLUFOR"};
};

_teamVar
