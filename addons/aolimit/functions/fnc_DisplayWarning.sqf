#include "script_component.hpp"
if !(hasInterface) exitwith {};

params ["_display"];

[{!(displayNull isEqualto _this)}, {
    params ["_display"];
    TRACE_1("AOLimit waituntil",_display);
    private _endTime = (CBA_missionTime + (GETMVAR(TimeLeft,30)));
    private _nextBeep = _endTime - 10;

    [QGVAR(Warning)] call BIS_fnc_showNotification;

    SETMVAR(DisplayOpen,true);

    GVAR(SoftPFHhandle) = [{
        params ["_argNested", "_idPFH"];
        _argNested params ["_endTime","_nextBeep","_display",["_colorSet",["IGUI","TEXT_RGB"]]];
        TRACE_2("", _display, _argNested);

        private _ctrlTime = _display displayCtrl 1003;
        private _shouldDisplay = GETMVAR(Display,false);
        private _timeleft = _endTime - CBA_missionTime;

        if ((!_shouldDisplay) || !(alive player)) exitwith {
            SETMVAR(DisplayOpen,false);
            [{
                params ["_display"];
                LOG_1("_display waituntil: %1",_display);
                _display closeDisplay 1;
            }, [_display], 1] call CBA_fnc_waitAndExecute;
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (_timeLeft <= 0) exitwith {
            SETMVAR(DisplayOpen,false);
            _ctrlTime ctrlSetText "00:00.000";
            [{
                player setDamage 1;
                _this closeDisplay 1;
            }, _display, 1] call CBA_fnc_waitAndExecute;
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (CBA_missionTime >= _nextBeep) then {
            playSound "Beep_Target";
            _nextBeep = _nextBeep + 1;
            _argNested set [1,_nextBeep];
        };

        if (_timeLeft <= 10) then {
            if (_timeLeft <= 5) then {
                _colorSet = ["IGUI","ERROR_RGB"];
                _argNested set [3,_colorSet];
            } else {
                _colorSet = ["IGUI","WARNING_RGB"];
                _argNested set [3,_colorSet];
            }
        };

        private _colour = _colorSet call bis_fnc_displaycolorget;
        _ctrlTime ctrlSetTextColor _colour;
        private _timeString = [_timeLeft,"MM:SS.MS"] call bis_fnc_secondsToString;
        _ctrlTime ctrlSetText _timeString;

    }, 0, [_endTime,_nextBeep,_display]] call CBA_fnc_addPerFrameHandler;
}, _display] call CBA_fnc_waitUntilAndExecute;
