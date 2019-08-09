#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl","_value","_valuevar"];

private _selectedRespawnType = missionNamespace getvariable [_valueVar,0];
private _pictureChecked = gettext (configfile >> "ctrlCheckbox" >> "textureChecked");
private _pictureUnchecked = gettext (configfile >> "ctrlCheckbox" >> "textureUnchecked");
private _defaultTemplates = [
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesNone"),
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesUnlimited"),
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesIndTick"),
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesTeamTick"),
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesWave"),
    getarray (configfile >> QGVAR(RespawnTemplates) >> "respawnTemplatesTriggered")
];
private _isDefault = _value isequalto [""];
{
    private _cfgTemplate = _x;
    private _scope = if (isnumber (_cfgTemplate >> "scope")) then {
        getnumber (_cfgTemplate >> "scope")
    } else {
        2
    };
    private _respawnTypes = getarray (_cfgTemplate >> "respawnTypes");
    {
        private _respawnType = _x;
        private _ctrlListbox = _ctrl controlsGroupCtrl (100 + _respawnType);
        private _selected = if ((_respawnType == _selectedRespawnType) && {!_isDefault}) then {
            _value
        } else {
            _defaultTemplates select _respawnType
        };
        if ((_scope > 1) && {(count _respawnTypes == 0) || _respawnType in _respawnTypes}) then {
            private _data = configname _cfgTemplate;
            private _name = gettext (_cfgTemplate >> "displayName");
            if (_name == "") then {_name = _data};
            private _lbAdd = _ctrlListbox lbadd _name;
            _ctrlListbox lbsetdata [_lbAdd,_data];
            private _active = _data in _selected;
            _ctrlListbox lbsetvalue [_lbAdd,[0,1] select _active];
            _ctrlListbox lbsetpicture [_lbAdd,[_pictureUnchecked,_pictureChecked] select _active];
        };
    } foreach [0,1,2,3,4,5];
} foreach configproperties [configfile >> QGVAR(RespawnTemplates),"isclass _x"];
{
    private _ctrlListbox = _ctrl controlsGroupCtrl (100 + _x);
    _ctrlListbox ctrlshow (_x == _selectedRespawnType);
    lbsort _ctrlListbox;
} foreach [0,1,2,3,4,5];
