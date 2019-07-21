#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_startTextArray"];

private ["_month","_hour","_min"];

switch (date select 1) do {
    case 1: {_month = "January"};
    case 2: {_month = "February"};
    case 3: {_month = "March"};
    case 4: {_month = "April"};
    case 5: {_month = "May"};
    case 6: {_month = "June"};
    case 7: {_month = "July"};
    case 8: {_month = "August"};
    case 9: {_month = "September"};
    case 10: {_month = "October"};
    case 11: {_month = "November"};
    case 12: {_month = "December"};
};

private _day = format ["%1th", date select 2];

if (((date select 2) mod 10) < 4) then {
    switch ((date select 2) mod 10) do {
        case 1: {_day = format ["%1st", date select 2]};
        case 2: {_day = format ["%1nd", date select 2]};
        case 3: {_day = format ["%1rd", date select 2]};
        case 4: {_day = format ["%1th", date select 2]};
        default {_day = format ["%1th", date select 2]};
    };
};

private _h = date select 3;
private _m = date select 4;
if (date select 4 isEqualto 60) then {_h = _h + 1;};
if (_h < 10) then {
    _hour = "0" + format ["%1", _h];
} else {
    _hour = format ["%1", _h];
};
if (date select 4 isEqualto 60) then {_m = 0};
if (_m < 10) then {
    _min = "0" + format ["%1H", _m];
} else {
    _min = format ["%1H", _m];
};

private _unparsedText = "<t align='right' size='1.2'>";

for "_i" from 0 to ((count _startTextArray) -1) do {
    private _line = _startTextArray select _i;
    switch (_line select 0) do {
        case "TitleQUOTE": {
            _unparsedText = _unparsedText + format ["<t font='PuristaBold' size='1.6'>""%1""</t>", _line select 1];
        };
        case "Title": {
            _unparsedText = _unparsedText + format ["<t font='PuristaBold' size='1.6'>%1</t>", _line select 1];
        };
        case "TEXT": {
            _unparsedText = _unparsedText + format ["%1", _line select 1];
        };
        case "DATE": {
            _unparsedText = _unparsedText + format ["%2 %3", _day, _month];
        };
        case "TIME": {
            _unparsedText = _unparsedText + format ["%1", (_hour + _min)];
        };
        case "DATETIME": {
            _unparsedText = _unparsedText + format ["%1, %2 %3", (_hour + _min), _day, _month];
        };
    };

    if (_i < count _startTextArray -1) then {
        _unparsedText = _unparsedText + "<br/>";
    }
};

_unparsedText = _unparsedText + "</t>";

LOG_1("Executing Start Text with %1",_unparsedText);

[{(CBA_missionTime > 10)},{
    _this spawn BIS_fnc_textTiles;
},[parsetext _unparsedText, true, nil, 10, 0.7, 0]] call CBA_fnc_WaitUntilAndExecute;
