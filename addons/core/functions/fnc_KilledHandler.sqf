
#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_unit", "_killer", "_instigator"];

SETMVAR(OldGroup,(group player));
SETPLPVAR(Dead,true);

[{
    params ["_unit"];
    [_unit] joinSilent grpNull;
}, [_unit], 2] call CBA_fnc_WaitAndExecute;


//we check if player didn't kill himself or died for unknown reasons
if ((vehicle _instigator != vehicle _unit) && {!isNull _instigator}) then {
    //this is the standard case (killed EH got triggered by getting shot)
    LOG("Getting killer by killed EH");
    ESETMVAR(Spectator,Killcam_unit_pos,(ASLtoAGL (eyePos _unit)));
    ESETMVAR(Spectator,Killcam_killer,_instigator);
    ESETMVAR(Spectator,Killcam_killer_pos,(ASLtoAGL (eyePos _instigator)));
} else {
    private _aceLastDamage = _unit getVariable ["ace_medical_lastDamageSource", objNull];
    if !(_aceLastDamage isEqualTo objNull) then {
        LOG("Getting killer by ACE Last Source");
         ESETMVAR(Spectator,Killcam_unit_pos,_unitPos);
         ESETMVAR(Spectator,Killcam_killer,_aceLastDamage);
         ESETMVAR(Spectator,Killcam_killer_pos,(getPos _aceLastDamage));
    } else {
        //we will try to retrieve info from our hit EH
        LOG("Getting killer by hit EH");
        private _last_hit_info = EGETMVAR(Spectator,Killcam_LastHit,[]);
        //hit info retrieved, now we check if it's not caused by fall damage etc.
        //also we won't use info that's over 10 seconds old
        if !(_last_hit_info isEqualto []) then {
            _last_hit_info params ["_data", "_time", "_unitPos", "_killerPos"];
            if ((_time + 10 > CBA_MissionTime) &&
            {(_data select 1) != objNull} &&
            {(_data select 1) != player}
            ) then {
                LOG("HIT data check successful");
                ESETMVAR(Spectator,Killcam_unit_pos,_unitPos);
                ESETMVAR(Spectator,Killcam_killer,(_data select 1));
                ESETMVAR(Spectator,Killcam_killer_pos,_killerPos);
            } else {
                LOG("HIT data not valid");
                //everything failed, we set value we will detect later
                ESETMVAR(Spectator,Killcam_unit_pos,(ASLtoAGL (eyePos _unit)));
                ESETMVAR(Spectator,Killcam_killer,objNull);
                ESETMVAR(Spectator,Killcam_killer_pos,[ARR_3(0,0,0)]);
            };
        } else {
            LOG("HIT, KILLED and ACE EHs not valid");
            ESETMVAR(Spectator,Killcam_unit_pos,(ASLtoAGL (eyePos _unit)));
            ESETMVAR(Spectator,Killcam_killer,objNull);
            ESETMVAR(Spectator,Killcam_killer_pos,[ARR_3(0,0,0)]);
        };
    };

};


private _deathScreenType = (EGETMVAR(Respawn,DeathScreenType,"FADE"));
switch (_deathScreenType) do {
    case "FADE": {
        private _damage = EGETMVAR(Spectator,Killcam_LastHitDamage,0.5);
        private _fadeInSpeed = (1.001 - _damage);
        [{
            params ["_fadeInSpeed"];
            0 fadeSound 0;
            (QGVAR(KilledLayer)) cutText ["<t color='#FF0000' size='2.0'>YOU ARE DEAD</t>", "BLACK", _fadeInSpeed, true, true];
            [QGVAR(DeathHearing), 0, true] call ace_common_fnc_setHearingCapability;
        }, [_fadeInSpeed]] call CBA_fnc_execNextFrame;
    };
    case "INSTANT": {
        [{
            0 fadeSound 0;
            (QGVAR(KilledLayer)) cutText ["<t color='#FF0000' size='2.0'>YOU ARE DEAD</t>", "BLACK", 0, true, true];
            [QGVAR(DeathHearing), 0, true] call ace_common_fnc_setHearingCapability;
        }] call CBA_fnc_execNextFrame;
    };
    case "VR": {
        [{
            playSound "Simulation_Fatal";
            0 fadeSound 0;
            [] call BIS_fnc_VRFadeOut;
        }] call CBA_fnc_execNextFrame;
    };
    default {
        private _damage = EGETMVAR(Spectator,Killcam_LastHitDamage,0.5);
        private _fadeInSpeed = (1.001 - _damage);
        [{
            params ["_fadeInSpeed"];
            0 fadeSound 0;
            (QGVAR(KilledLayer)) cutText ["<t color='#FF0000' size='2.0'>YOU ARE DEAD</t>", "BLACK", _fadeInSpeed, true, true];
            [QGVAR(DeathHearing), 0, true] call ace_common_fnc_setHearingCapability;
        }, [_fadeInSpeed]] call CBA_fnc_execNextFrame;
    };
};
