class EGVAR(Respawn,Folder) {
    text = "Configure Respawn";
    items[] = {
        QEGVAR(Respawn,Main),
        QEGVAR(Respawn,BLUFOR),
        QEGVAR(Respawn,OPFOR),
        QEGVAR(Respawn,Indfor),
        QEGVAR(Respawn,Civilian)
    };
    picture = "\a3\3DEN\Data\Cfg3DEN\History\changeAttributes_ca.paa";
};

class EGVAR(Respawn,BLUFOR) {
    text = "BLUFOR Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_BLUFOR););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa";
};

class EGVAR(Respawn,OPFOR) {
    text = "OPFOR Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_OPFOR););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa";
};

class EGVAR(Respawn,Indfor) {
    text = "Indfor Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_Indfor););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa";
};

class EGVAR(Respawn,Civilian) {
    text = "Civilian Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_Civ););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa";
};

class EGVAR(Respawn,Main) {
    text = "General Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_Main););
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};
