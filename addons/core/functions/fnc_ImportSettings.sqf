/*    Description: Imports UO_FW mission attributes from clipboard or profilenamespace
 *    Arguments:
 *         STRING - Setting preset name, not used if copying from clipboard
 *         BOOL - Clipboard mode, false imports settings from named array from profileNamespace
 *    Return Value:
 *         ARRAY
 *    Author
 *        R3vo & PiZZADOX
 */


#include "script_component.hpp"
EDEN_CHECK;

params [["_name","",[""]],["_clipBoardMode",0,[0]]];
LOG_2("Import Settings called, _name: %1 _clipboard: %2",_name,_clipBoardMode);

if (_clipBoardMode isEqualto 1) then {
    private _settingsArray = call compile copyFromClipboard;
    {
        _x params ["_section","_class","_value"];
        _section set3DENMissionAttribute [_class,_value];
    } foreach _settingsArray;
} else {
    private _profileArray = profileNamespace getvariable [QGVAR(ProfileSettingsArray),[]];
    if (_profileArray isEqualto []) exitwith {};
    private _found = false;
    {
        _x params ["_nameArray","_settingsArray"];
        if (_nameArray isEqualto _name) exitwith {
            _found = true;
            {
                _x params ["_section","_class","_value"];
                LOG_3("_section: %1 _class: %2 _value: %3",_section,_class,_value);
                _section set3DENMissionAttribute [_class,_value];
            } foreach _settingsArray;
            LOG_1("Loaded %1 Settings Preset from Profile!",_name);
        };
    } foreach _profileArray;
    if !(_found) exitwith {
        ERROR_1("%1 Settings Preset not found in Profile!",_name);
    };
};
[] call FUNC(BasicSettings3DEN);
