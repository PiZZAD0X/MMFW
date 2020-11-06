#include "script_component.hpp"
//IGNORE_PRIVATE_WARNING ["_target","_player"];

params [
    "_veh",
    ["_enableNV", true, [true]],
    ["_enableFlip", true, [true]]
];

if (isNil QGVAR(Vehicle)) then {
    GVAR(Vehicle) = objNull;
};

if (GETVAR(_veh,hasActions,false)) exitwith {};

//AI driver action
private _addAction = ["ai_driver","Add AI driver","",{
    [_target, _player] call FUNC(CreateUnit);
},{
    (vehicle _player isEqualTo _target) && {((GETVAR(_target,driver,objnull)) isEqualTo objNull)} && {((assignedVehicleRole _player) select 0) == "Turret"} && {GVAR(Vehicle) in [objNull, vehicle _player]}
}] call ace_interact_menu_fnc_createAction;

private _removeAction = ["ai_driver","Remove AI driver","",{
    [_target] call FUNC(RemoveUnit);
},{
    (vehicle _player isEqualTo _target) && {!((GETVAR(_target,driver,objnull)) isEqualTo objNull)} && {((assignedVehicleRole _player) select 0) == "Turret"} && {GVAR(Vehicle) in [objNull, vehicle _player]}
}] call ace_interact_menu_fnc_createAction;

//unflip action
private _unflipAction = ["ai_driver_unflip","Unflip vehicle","",{
    [_target, surfaceNormal position _target] remoteExec ["setVectorUp", _target, false];
    (getposATL _target) params ["_xPos","_yPos","_zPos"];
    _target setPosATL [_xPos, _yPos, _zPos + 2];
},{
    (vehicle _player isEqualTo _target) && {!((GETVAR(_target,driver,objnull)) isEqualTo objNull)} && {((assignedVehicleRole _player) select 0) == "Turret"} && {(vectorUp _target) select 2 < 0}
}] call ace_interact_menu_fnc_createAction;

//engine off action
private _engineOffAction = ["ai_driver_engineoff","Turn off engine","",{
    [_target, false] remoteExec ["engineOn", _target];
},{
    (vehicle _player isEqualTo _target) && {!((GETVAR(_target,driver,objnull)) isEqualTo objNull)} && {((assignedVehicleRole _player) select 0) == "Turret"} && {isEngineOn _target}
}] call ace_interact_menu_fnc_createAction;

//PIP action
private _pipAction = ["ai_driver_pip","Enable/Disable driver's view","",{
    (isNil QGVAR(DriverCam) || {isNull GVAR(DriverCam)}) call  FUNC(ToggleDriverCam);
},{
    (vehicle _player isEqualTo _target) && {((assignedVehicleRole _player) select 0) == "Turret"} && {!isNull (GETVAR(_target,driver,objnull))}
}] call ace_interact_menu_fnc_createAction;

//toggle NV for PIP
private _pipNvAction = ["ai_driver_pip_nv","Enable/Disable NV in driver's view","",{
    if (isNil QGVAR(pipNvEnabled)) then {
        GVAR(pipNvEnabled) = false;
    };
    QGVAR(RTT) setPiPEffect ([[1], [0]] select GVAR(pipNvEnabled));
    GVAR(pipNvEnabled) = !GVAR(pipNvEnabled);
},{
    (vehicle _player == _target) &&
    {((assignedVehicleRole _player) select 0) == "Turret"} &&
    {(!isNil QGVAR(DriverCam) && {!isNull GVAR(DriverCam)})}
}] call ace_interact_menu_fnc_createAction;

[_veh, 1, ["ACE_SelfActions"], _addAction] call ace_interact_menu_fnc_addActionToObject;
[_veh, 1, ["ACE_SelfActions"], _removeAction] call ace_interact_menu_fnc_addActionToObject;
[_veh, 1, ["ACE_SelfActions"], _engineOffAction] call ace_interact_menu_fnc_addActionToObject;
[_veh, 1, ["ACE_SelfActions"], _pipAction] call ace_interact_menu_fnc_addActionToObject;

if ( _enableFlip) then {
    [_veh, 1, ["ACE_SelfActions"], _unflipAction] call ace_interact_menu_fnc_addActionToObject;
};

if (_enableNV) then {
    [_veh, 1, ["ACE_SelfActions"], _pipNvAction] call ace_interact_menu_fnc_addActionToObject;
};

SETPVAR(_veh,hasActions,true);
