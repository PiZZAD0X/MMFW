#include "script_component.hpp"
EXEC_CHECK(SERVER);

[QEGVAR(Core,SettingsLoaded), {
    if (GETMVAR(Enabled,false)) then {
        setViewDistance GETMVAR(AIViewDistance,2500);
    	setTerrainGrid 50;
    	if (GETMVAR(ForceTimeEnable,false)) then {
            private _forceTime = GETMVAR(ForceTime,[12,00]);
    		private _forcedDate = [date select 0, date select 1, date select 2, _forceTime select 0, _forceTime select 1];
    		GVAR(TimeHandlePFH) = [{
    			params ["_argNested", "_idPFH"];
    			_argNested params ["_forcedDate"];
    			setdate _forcedDate;
    		}, 1, [_forcedDate]] call CBA_fnc_addPerFrameHandler;
    	};
    };
}] call CBA_fnc_addEventHandler;
