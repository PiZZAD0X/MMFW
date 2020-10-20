#include "script_component.hpp"

params ["_teamVar"];

private _list = (GETMVAR(RespawnList,[])) select {
    private _logic = _x;
    private _teamSetting = GETVAR(_logic,Side,"BLUFOR");
    private _cond = GETVAR(_logic,Cond,{true});
    ((_teamSetting isEqualTo _teamVar) && _cond)
};

_list
