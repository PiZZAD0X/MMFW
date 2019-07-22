#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(ParaFlareCreateLightEvent), {
    params ["_flare","_colour"];
    [{
        params ["_flare", "_colour"];
        private _flareLight = "#lightpoint" createVehicleLocal [0,0,0];
        [{!isNull (_this select 1)}, {
            params ["_flare", "_flareLight", "_colour"];
            _flareLight lightAttachObject [_flare, [0,0,0]];
            private _brightness = (GETMVAR(ParaFlare_Brightness,15));
            diag_log format ["_brightness: %1",_brightness];
            _flareLight setLightBrightness _brightness;
        	_flareLight setLightUseFlare false;
        	_flareLight setLightColor _colour;
            [{((getPosATL (_this select 0)) select 2) < 0.25}, {
                params ["_flare", "_flareLight"];
        		if (alive _flareLight) then {deleteVehicle _flareLight};
        		if (alive _flare) then {deleteVehicle _flare};
        	}, [_flare,_flareLight], 60, {
                params ["", "_flareLight"];
        		if (alive _flareLight) then {deleteVehicle _flareLight};
        	}] call CBA_fnc_waitUntilAndExecute;
        }, [_flare, _flareLight, _colour]] call CBA_fnc_waitUntilAndExecute;
    }, [_flare, _colour], 2.6] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

ADDON = true;
