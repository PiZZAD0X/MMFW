/*
 * Author: PiZZADOX
 *
 * Checks and adds debug message
 *
 * Arguments:
 * 0: message <string>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */


#include "script_component.hpp"

params ["_basicmsg","_detailedmsg"];

if (GETMVAR(Debug_Enabled,false) && {!(GETMVAR(Detailed_Enabled,false))}) then {
    if (_basicmsg isEqualto "") exitwith {};
    if !((typename _basicmsg) isEqualto "STRING") then {
        private _basicmsgprint = format ["%1",_basicmsg];
        _basicmsgprint call FUNC(DebugMessage);
    } else {
        _basicmsg call FUNC(DebugMessage);
    };
};
if (GETMVAR(Detailed_Enabled,false)) then {
    if (_detailedmsg isEqualto "") exitwith {};
    if !((typename _detailedmsg) isEqualto "STRING") then {
        private _detailedmsgprint = format ["%1",_detailedmsg];
        _detailedmsgprint call FUNC(DebugMessage);
    } else {
        _detailedmsg call FUNC(DebugMessage);
    };
};
