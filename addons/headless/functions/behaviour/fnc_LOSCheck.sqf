#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

//unit 1, unit 2
params ["_unit","_target"];
private ["_cansee"];

private _canseeReturn = false;
private _sightLevel = _unit getVariable [QEGVAR(Behaviour,Unit_BunkerSightLevel), (EGETMVAR(Behaviour,BunkerSightLevel,0.2))];

private _getpos1 = getPosWorld (vehicle _unit);
private _getposTarget = if (vehicle _target == _target) then {
    AGLToASL (_target modelToWorld (_target selectionPosition "spine3"))
} else {
    getPosWorld (vehicle _target)
};
//private _unitdirtotarget = (vehicle _unit) getdir (vehicle _unit);
//private _aheadUnit = (vehicle _unit) getpos [10,_unitdirtotarget];
//private _eyeP1 = [_aheadUnit select 0, _aheadUnit select 1, (_getpos1 select 2) + 0.5];
private _eyeP2 = [_getposTarget select 0, _getposTarget select 1,(_getposTarget select 2) + 0.5];

if ((vehicle _unit) != _unit) then {
    _cansee = [(vehicle _unit), "VIEW", objNull] checkVisibility [getPosWorld (vehicle _unit), _eyeP2];
} else {
    _cansee = [_unit, "VIEW", objNull] checkVisibility [eyepos _unit, _eyeP2];
};

if (GETMVAR(Debug,false)) then {
	LOG_3("_unit: %1 _cansee: %2 _target: %3",_unit,_cansee,_target);
};

if (_cansee > _sightLevel) then {_canseeReturn = true;};

_canseeReturn
