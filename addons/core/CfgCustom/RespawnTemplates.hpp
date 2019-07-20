class MGVAR(RespawnTemplates) {
    respawnTemplatesNone[] = {};
    respawnTemplatesUnlimited[] = {QEGVAR(RTemplatesS,JoinGroup),QEGVAR(RTemplatesS,SafeStart),QEGVAR(RTemplatesS,ACRE),QEGVAR(RTemplatesS,Gear),QEGVAR(RTemplatesS,CoverMap),QEGVAR(RTemplatesS,MapAndCompassRemover)};
    respawnTemplatesIndTick[] = {QEGVAR(RTemplatesS,JoinGroup),QEGVAR(RTemplatesS,SafeStart),QEGVAR(RTemplatesS,ACRE),QEGVAR(RTemplatesS,Gear),QEGVAR(RTemplatesS,CoverMap),QEGVAR(RTemplatesS,MapAndCompassRemover)};
    respawnTemplatesTeamTick[] = {QEGVAR(RTemplatesS,JoinGroup),QEGVAR(RTemplatesS,SafeStart),QEGVAR(RTemplatesS,ACRE),QEGVAR(RTemplatesS,Gear),QEGVAR(RTemplatesS,CoverMap),QEGVAR(RTemplatesS,MapAndCompassRemover)};
    respawnTemplatesWave[] = {QEGVAR(RTemplatesS,JoinGroup),QEGVAR(RTemplatesS,SafeStart),QEGVAR(RTemplatesS,ACRE),QEGVAR(RTemplatesS,Gear),QEGVAR(RTemplatesS,CoverMap),QEGVAR(RTemplatesS,MapAndCompassRemover)};
    respawnTemplatesTriggered[] = {QEGVAR(RTemplatesS,JoinGroup),QEGVAR(RTemplatesS,SafeStart),QEGVAR(RTemplatesS,ACRE),QEGVAR(RTemplatesS,Gear),QEGVAR(RTemplatesS,CoverMap),QEGVAR(RTemplatesS,MapAndCompassRemover)};
    class EGVAR(RTemplatesS,JoinGroup) {
        displayName = "Rejoin Group on Respawn";
        respawnTypes[] = {1,2,3,5};
    };
    class EGVAR(RTemplatesS,SafeStart) {
        displayName = "Run SafeStart Module Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,CoverMap) {
        displayName = "Run Unit CoverMap Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,TeamColour) {
        displayName = "Run Unit TeamColour Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,StartInParachute) {
        displayName = "Run Unit StartInParachute Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,Gear) {
        displayName = "Run Unit Gear Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,ACRE) {
        displayName = "Run Unit ACRE Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    class EGVAR(RTemplatesS,MapAndCompassRemover) {
        displayName = "Run MapAndCompassRemover Unit Settings on Respawn";
        respawnTypes[] = {1,2,3,4,5};
    };
    //class EGVAR(RTemplatesS,GearHandle) {
    //    displayName = "Handle Gear Classes for Wave Respawns";
    //    respawnTypes[] = {4};
    //};
    //class EGVAR(RTemplatesS,TriggerReset) {
    //    displayName = "Reset Trigger Variable after Spawning a Wave/Queue of Players";
    //    respawnTypes[] = {5};
    //};
};
