#include "script_component.hpp"
EDEN_CHECK;

//IGNORE_PRIVATE_WARNING ["_x"];

private _attributeValues = [];
private _sections = QUOTE(!(((str(configname _x)) find QN(PREFIX)) isEqualto -1)) configClasses (Configfile >> "Cfg3DEN" >> "Mission");
{
    private _section = configName _x;
    private _children = [configfile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories",2,false] call BIS_fnc_returnChildren;
    {
        private _attributeName = "";
        _attributeName = getText (_x >> "data");
        private _attributeValue = _section get3DENMissionAttribute _attributeName;
        if (isNil "_attributeValue") then {
            _attributeName = configName _x;
            _attributeValue = _section get3DENMissionAttribute _attributeName;
            if (isNil "_attributeValue") then {
                _attributeName = getText (_x >> "property");
                _attributeValue = _section get3DENMissionAttribute _attributeName;
                _attributeValues pushBack [_section,_attributeName,_attributeValue];
            } else {
                _attributeValues pushBack [_section,_attributeName,_attributeValue];
            };
        } else {
            _attributeValues pushBack [_section,_attributeName,_attributeValue];
        };
    } foreach _children;
} foreach _sections;

copytoClipboard (str _attributeValues);
LOG("Mission settings copied to clipboard");
