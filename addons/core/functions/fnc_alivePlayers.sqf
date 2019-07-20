/*
 * Author: TrainDoctor & PiZZADOX & TheMagnetar
 *
 * Returns an array of all alive players. Can return alive players of given sides
 *
 * Arguments:
 * 0: side <side> (optional)
 *
 * Return Value:
 * array
 *
 * Public: Yes
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);

private _alivePlayers = allPlayers select {(alive _x) && {!(GETVAR(_x,Dead,false))} && {!(_x isKindOf "HeadlessClient_F")}};

if (count _this > 0) then {
    private _lowerThis = [];
    {
        if (_x isEqualType sideUnknown) then {
            _lowerThis pushback (tolower (str _x));
        };
        if (_x isEqualType "") then {
            _lowerThis pushback (tolower _x);
        };
    } foreach _this;
    LOG_1("_lowerThis var: %1",_lowerThis);

    private _return = [];

    if (("blufor" in _lowerThis) || ("west" in _lowerThis)) then {
        _return append (_alivePlayers select {side _x isEqualto west});
    };

    if (("opfor" in _lowerThis) || ("east" in _lowerThis)) then {
        _return append (_alivePlayers select {side _x isEqualto east});
    };

    if (("independent" in _lowerThis) || ("resistance" in _lowerThis) || ("guer" in _lowerThis)) then {
        _return append (_alivePlayers select {side _x isEqualto independent});
    };

    if (("civilian" in _lowerThis)) then {
        _return append (_alivePlayers select {side _x isEqualto civilian});
    };

    _return
} else {
  _alivePlayers
};
