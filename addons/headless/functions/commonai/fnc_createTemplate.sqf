/*
 * Author: TheMagnetar
 * Clones the units of a group.
 *
 * Arguments:
 * 0: Group to clone <OBJECT>
 * 1: Template name <STRING>
 * 2: Settings <HASH>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group1, "TemplateName", [["task", "attack"], ["forceRoads", true]]] call mmfw_core_fnc_createTemplate
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_modelGroup", ["_templateName", ""], ["_settings", []]];

if (_templateName isEqualTo "") exitWith {
    ERROR("Empty template name");
};

if (isClass (missionConfigFile >> "CfgGroupCompositions" >> _templateName)) exitWith {
    ERROR_1("Template name %1 already defined as config entry",_templateName);
};

private _exits = [EGVAR(commonai,groupTemplates), _templateName] call CBA_fnc_hashGet;
if !(isNil _exits) exitWith {
	ERROR_1("Template name %1 already defined",_templateName);
};

private _side = format ["%1", side _modelGroup];
if (_settings isEqualTo []) then {
    _settings =+ (_modelGroup getVariable [QEGVAR(commonai,settings), []]);
};

HASHSET(_settings,template,_templateName);

private _type = toLower (HASHGET(_settings,type));

private _helperFunction = missionNamespace getVariable QEFUNC(commonai,helperTemplateInfantry);

if !(_type isEqualTo "infantry") then {
    _helperFunction = missionNamespace getVariable QEFUNC(commonai,helperTemplateVehicle);
};

private _templateValues = [_modelGroup] call _helperFunction;

_templateValues params ["_units", "_loadout", "_rank", "_skill"];

[EGVAR(commonai,groupTemplates), _templateName, [_side, _settings, _units, _loadout, _rank, _skill]] call CBA_fnc_hashSet;
