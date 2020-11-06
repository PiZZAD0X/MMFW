#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QGVAR(ColourCheckInitEvent), {
    [{!isNull ace_player}, {
        private _teamColorAction = ["colorCheck_class", "Check Team Color", "", {
            private ["_str"];
            switch (assignedTeam player) do {
                case "BLUE": {_str = "<t size='1.5'>You are in <br/><t color='#0000FF'>BLUE</t> team.</t> "};
                case "RED": {_str = "<t size='1.5'>You are in <br/><t color='#FF0000'>RED</t> team.</t> "};
                case "GREEN": {_str = "<t size='1.5'>You are in <br/><t color='#00FF00'>GREEN</t> team.</t> "};
                case "YELLOW": {_str = "<t size='1.5'>You are in <br/><t color='#FFFF00'>YELLOW</t> team.</t> "};
                default {_str = "<t size='1.5'>You are in <br/><t color='#FFFFFF'>WHITE</t> team.</t> "};
            };
            hint parseText _str;
        }, {!isNil {assignedTeam player}}] call ace_interact_menu_fnc_createAction;
        [player, 1, ["ACE_SelfActions","ACE_TeamManagement"], _teamColorAction] call ace_interact_menu_fnc_addActionToObject;
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

//IGNORE_PRIVATE_WARNING ["_player","_target"];
[QGVAR(CheckMapInitEvent), {
    [{!isNull ace_player}, {
        private _shareMapAction = ["shareMap_class", "View Map", "", {
            params ["_target", "_player"];
            player linkItem "ItemMap";
            openMap true;
            [{!visibleMap || ((_this select 0) distance (_this select 1) > 3)}, {
                openMap false;
                player unlinkItem "ItemMap";
            },[_target,_player]] call CBA_fnc_waitUntilAndExecute;
        }, {
            (!("ItemMap" in assignedItems _player)) &&
            {("ItemMap" in assignedItems _target)} &&
            {(_target distance _player <= 3)} &&
            {(((side _player) getFriend (side _target)) >= 0.6)}
        }] call ace_interact_menu_fnc_createAction;
        ["CAManBase", 0, ["ACE_MainActions"], _shareMapAction, true] call ace_interact_menu_fnc_addActionToClass;
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

//IGNORE_PRIVATE_WARNING ["_thisID","_thisType"];
[QGVAR(CutGrassInitEvent), {
    [{!isNull ace_player}, {
        private _macheteAction = ["machete_class", "Cut Grass", "", {
            [player, "AnimDone", {
                params ["_unit", "_anim"];
                if (_anim isEqualTo "ainvpknlmstpslaywrfldnon_medic") then {
                    private _cutter = createVehicle ["ClutterCutter_small_EP1", [0,0,0], [], 0, "CAN_COLLIDE"];
                    _cutter setPos (_unit getPos [1, getDir _unit]);
                    _unit removeEventHandler [_thisType, _thisID];
                };
            }, []] call CBA_fnc_addBISEventHandler;
            player playMove "ainvpknlmstpslaywrfldnon_medic";
        }, {(stance player isEqualTo "CROUCH") && !(toLower(animationState player) isEqualTo "ainvpknlmstpslaywrfldnon_medic")}] call ace_interact_menu_fnc_createAction;
        [player, 1, ["ACE_SelfActions","ACE_Equipment"], _macheteAction] call ace_interact_menu_fnc_addActionToObject;
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(ParaFlaresInitEvent), {
    [{!isNull ace_player}, {
        private _paraFlareBaseMenu = ["SelfActions_ParaBaseClass", "Paraflares", "", {}, {true}] call ace_interact_menu_fnc_createAction;
        [player, 1, ["ACE_SelfActions","ACE_Equipment"], _paraFlareBaseMenu] call ace_interact_menu_fnc_addActionToObject;
        {
            _x params ["_name", "_magClass", "_colour", "_ammoType"];
            private _paraFlareActionTemp = [("SelfActions_LaunchParaFlare_" + _name), ("Launch " + _name + " Flare"), "", {
                (_this select 2) params ["_magClass", "_colour", "_ammoType"];
                private _result = [player, _magClass] call CBA_fnc_removeMagazine;
                if !(_result) exitwith {};
                private _pos = player modelToWorld [0, 1, 0];
                _pos = [_pos select 0, _pos select 1, (_pos select 2) + 1.5];
                player playActionNow "HandGunOn";
                [{
                    params ["_ammoType", "_pos", "_colour"];
                    [player,QGVAR(flareFire)] remoteExec ["say3D"];
                    [{
                        params ["_ammoType", "_pos", "_colour"];
                        private _flare = _ammoType createVehicle _pos;
                        private _vectorView = [(getCameraViewDirection player) select 0, (getCameraViewDirection player) select 1, ((getCameraViewDirection player) select 2) + 0.35];
                        private _vectorDir = _vectorView vectorMultiply 55;
                        _flare setVelocity _vectorDir;
                        [_flare,QGVAR(flareShot)] remoteExec ["say3D"];
                        [{!isNull (_this select 0)}, {
                            params ["_flare","_colour","_pos"];
                            [QGVAR(ParaFlareCreateLightEvent), [_flare,_colour,_pos]] call CBA_fnc_globalEvent;
                        }, [_flare,_colour,_pos]] call CBA_fnc_waitUntilAndExecute;
                    }, [_ammoType,_pos,_colour], 0.5] call CBA_fnc_waitAndExecute;
                }, [_ammoType,_pos,_colour], 0.5] call CBA_fnc_waitAndExecute;
            }, {
                (vehicle player isEqualto player) && {((_this select 2 select 0) in magazines player)}
            }, {}, [_magClass,_colour,_ammoType]] call ace_interact_menu_fnc_createAction;
            [player, 1, ["ACE_SelfActions","ACE_Equipment","SelfActions_ParaBaseClass"], _paraFlareActionTemp] call ace_interact_menu_fnc_addActionToObject;
        } foreach [
            ["White","FlareWhite_F",[1,1,1],"F_20mm_White"],
            ["Green","FlareGreen_F",[0.25,0.5,0.25],"F_20mm_Green"],
            ["Yellow","FlareYellow_F",[0.5,0.5,0.25],"F_20mm_Yellow"],
            ["Red","FlareRed_F",[0.5,0.25,0.25],"F_20mm_Red"],
            ["Large White",QGVAR(ParaFlare_White),[1,1,1],QGVAR(ParaFlare_Shot_White)],
            ["Large Green",QGVAR(ParaFlare_Green),[0.25,0.5,0.25],QGVAR(ParaFlare_Shot_Green)],
            ["Large Yellow",QGVAR(ParaFlare_Yellow),[0.5,0.5,0.25],QGVAR(ParaFlare_Shot_Yellow)],
            ["Large Red",QGVAR(ParaFlare_Red),[0.5,0.25,0.25],QGVAR(ParaFlare_Shot_Red)]
        ];
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

[QEGVAR(Core,SettingsLoaded), {
    if !(GETMVAR(Enable,false)) exitwith {};
    [{!isNull ace_player},{
        if (GETMVAR(CheckColour_Enabled,false)) then {
            [QGVAR(ColourCheckInitEvent), []] call CBA_fnc_localEvent;
        };
        if (GETMVAR(CheckMap_Enabled,false)) then {
            [QGVAR(CheckMapInitEvent), []] call CBA_fnc_localEvent;
        };
        if (GETMVAR(CutGrass_Enabled,false)) then {
            [QGVAR(CutGrassInitEvent), []] call CBA_fnc_localEvent;
        };
        if (GETMVAR(ParaFlares_Enabled,false)) then {
            [QGVAR(ParaFlaresInitEvent), []] call CBA_fnc_localEvent;
        };
        [QEGVAR(Core,RegisterModuleEvent), ["Self Actions", "Allows players to check their own team color, view other's maps, launch paraflares, and cut grass.", "TinfoilHate and PiZZADOX"]] call CBA_fnc_localEvent;
    }, []] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
