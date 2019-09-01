#include "script_component.hpp"
EXEC_CHECK(SERVER);

//[_logic,_zoneName,_area,_repeatable,_capArray,_timeArray,_messagesArray,_colours,_hidden,_silent,_automessages,_ratioNeeded,_cond] passed array
//params ["","_zoneName","","","","","","","","","","",["_cond","true",[""]]];
private _logic = _this select 1;
private _cond = _this select 12;

[QEGVAR(Core,RegisterModuleEvent), ["Capture Zone", "Creates Capture Zone objectives for variable declares and end condition requirements", "Sacher and PiZZADOX"]] call CBA_fnc_globalEvent;

LOG_1("CaptureZone Loop called with this: %1",_this);
if (!(_this call FUNC(Validate))) exitWith {
    ERROR_1("CaptureZone %1 failed to Validate",_logic);
};

private _condCompiled = compile _cond;

if (call _condCompiled) exitwith {
    _this call FUNC(Loop);
};

[{call (_this select 1)}, {
    (_this select 0) call FUNC(Loop);
}, [_this, _condCompiled]] call CBA_fnc_waitUntilAndExecute;
