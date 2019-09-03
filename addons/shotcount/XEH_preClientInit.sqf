#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(DisplayEvent), {
    if !(GETMVAR(Enabled,false)) exitwith {};
    LOG_1("Display_Event published with: %1",_this);
    [{!((uiNamespace getVariable [QGVAR(EndScreen),""]) isEqualto "")}, {
        params ["_textBLU","_textOPF","_textIND","_textCIV"];
        private _endscreenDiag = (uiNamespace getVariable QGVAR(EndScreen));
        LOG_1("_endscreenDiag: %1",_endscreenDiag);
        private _bottomLeft = 3004;
        private _bottomMiddleLeft = 3005;
        private _bottomMiddleRight = 3006;
        private _bottomRight = 3007;
        (_endscreenDiag displayCtrl _bottomLeft) ctrlSetStructuredText parseText _textBLU;
        (_endscreenDiag displayCtrl _bottomMiddleLeft) ctrlSetStructuredText parseText _textOPF;
        (_endscreenDiag displayCtrl _bottomMiddleRight) ctrlSetStructuredText parseText _textIND;
        (_endscreenDiag displayCtrl _bottomRight) ctrlSetStructuredText parseText _textCIV;
    }, _this] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
