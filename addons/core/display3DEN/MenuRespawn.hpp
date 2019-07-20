class EGVAR(Respawn,Folder) {
    text = "Configure Respawn";
    items[] = {QEGVAR(Respawn,Main),QEGVAR(Respawn,BLUFOR),QEGVAR(Respawn,OPFOR),QEGVAR(Respawn,Indfor),QEGVAR(Respawn,Civilian)};
    picture = "\a3\3DEN\Data\Cfg3DEN\History\changeAttributes_ca.paa";
};

class EGVAR(Respawn,BLUFOR) {
    text = "BLUFOR Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Respawn,Settings_BLUFOR)););
};

class EGVAR(Respawn,OPFOR) {
    text = "OPFOR Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Respawn,Settings_OPFOR)););
};

class EGVAR(Respawn,Indfor) {
    text = "Indfor Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Respawn,Settings_Indfor)););
};

class EGVAR(Respawn,Civilian) {
    text = "Civilian Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Respawn,Settings_Civ)););
};

class EGVAR(Respawn,Main) {
    text = "General Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Respawn,Settings_Main)););
};
