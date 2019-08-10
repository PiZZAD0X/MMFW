
#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl", "_value", "_config"];

private _control = (_ctrl controlsGroupCtrl 100);
private _cfgEntries = [configFile >> QGVAR(Presets),0] call BIS_fnc_returnChildren;
if (_cfgEntries isEqualto []) then {
    lbClear _control;
    private _indexEmpty = _control lbadd "No Presets Defined";
    _control lbsetdata [_indexEmpty,"No Presets Defined"];
    _control lbsetValue [_indexEmpty,99];
    _control lbSetCurSel _indexEmpty;
} else {
    lbClear _control;
    private _indexNone = _control lbadd "None";
    _control lbsetdata [_indexNone,"NONE"];
    _control lbsetValue [_indexNone,99];
    _control lbSetCurSel _indexNone;
    {
        private _cfg = _x;
        private _displayName = getText(_cfg >> "displayName");
        private _displayDesc = getText(_cfg >> "displayDesc");
        private _authors = getArray (_cfg >> "authors");
        private _authorstr = "";
        {
            if (_x isEqualType "") then {
                if (_forEachIndex isEqualto 0) then {
                    _authorstr = _x;
                } else {
                    _authorstr = format ["%1, %2", _authorstr, _x];
                };
            };
        } forEach _authors;
        private _displayTooltip = format ["%1 Authors: %2", _displayDesc, _authorstr];
        private _index = _control lbadd _displayName;
        _control lbsetdata [_index,_displayName];
        _control lbsetValue [_index,_forEachIndex];
        _control lbSetTooltip [_index,_displayTooltip];
    } foreach _cfgEntries;
};
