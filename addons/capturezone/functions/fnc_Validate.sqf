#include "script_component.hpp"
EXEC_CHECK(SERVER);

//[_logic,_zoneName,_area,_repeatable,_capArray,_timeArray,_messagesArray,_colours,_hidden,_silent,_automessages,_ratioNeeded,_cond]
params ["_logic","_zoneName","_area","_repeatable","_capArray","_timeArray","_messagesArray","_colours","_hidden","_silent","_automessages","_ratioNeeded","_cond"];
private _isValid = true;
LOG_1("CaptureZone called with _this: %1",_this);

if (isNil QGVAR(ListArray)) then {
    GVAR(ListArray) = [];
};

if (_zoneName in GVAR(ListArray)) then {
    _isValid = false;
    ERROR_1("Duplicate name for CaptureZone %1. CaptureZone must have unique name!", _zoneName);
};

if ((count _area) < 4) then {
    _isValid = false;
    ERROR_1("Invalid area generated for CaptureZone %1", _zoneName);
};

if ((count _colours) < 6) then {
    _isValid = false;
    ERROR_1("No sides defined for capture for CaptureZone %1", _zoneName);
};

if (({!(_x isEqualto 2)} count _capArray) isEqualTo 0) exitwith {
    ERROR_1("CaptureZone %1 has no teams that can be counted!", _zoneName);
};

if (({_x isEqualto 0} count _capArray) isEqualto 0) exitwith {
    ERROR_1("CaptureZone %1 has no teams that can capture!", _zoneName);
};

_isValid
