#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if !(EGETMVALUE(Core,Enabled,false)) exitWith {};

private _missionFrameworkVersionCreatedStr = (GETMVALUE(Version_Created,""));
if (_missionFrameworkVersionCreatedStr isEqualto "") then {
    SETMVAR(Version_CreatedNum,102);
    INFO("Mission Created with Framework Version: Legacy");
} else {
    private _missionFrameworkVersionCreated = parseNumber ((_missionFrameworkVersionCreatedStr splitString ".") joinString "");
    SETMVAR(Version_CreatedNum,_missionFrameworkVersionCreated);
    INFO_1("Mission Created with Framework Version:%1",_missionFrameworkVersionCreatedStr);
};

private _missionFrameworkVersionStr = (GETMVALUE(Version_Updated,""));
if (_missionFrameworkVersionStr isEqualto "") then {
    SETMVAR(Version_UpdatedNumber,102);
    INFO("Mission Updated with Framework Version: Legacy");
} else {
    private _missionFrameworkVersion = parseNumber ((_missionFrameworkVersionStr splitString ".") joinString "");
    SETMVAR(Version_UpdatedNumber,_missionFrameworkVersion);
    INFO_1("Mission Updated with Framework Version:%1",_missionFrameworkVersionStr);
};

ADDON = true;
