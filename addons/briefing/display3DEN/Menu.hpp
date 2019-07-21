class EGVAR(Briefing,Folder) {
    text = "Configure Briefings";
    items[] = {
        QEGVAR(Briefing,Notes_Configure),
        QEGVAR(Briefing,Export),
        QEGVAR(Briefing,Configure_Blufor),
        QEGVAR(Briefing,Configure_Opfor),
        QEGVAR(Briefing,Configure_Indfor),
        QEGVAR(Briefing,Configure_Civ)
    };
    picture = "\a3\3DEN\Data\Cfg3DEN\Comment\texture_ca.paa";
};

class EGVAR(Briefing,Configure_Blufor) {
    text = "Configure Blufor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Blufor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa";
};

class EGVAR(Briefing,Configure_Opfor) {
    text = "Configure Opfor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Opfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa";
};

class EGVAR(Briefing,Configure_Indfor) {
    text = "Configure Indfor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Indfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa";
};

class EGVAR(Briefing,Configure_Civ) {
    text = "Configure Civilian Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Civilian));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa";
};

class EGVAR(Briefing,Notes_Configure) {
    text = "Configure Mission Notes";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,MissionNotes));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

class EGVAR(Briefing,Export) {
    text = "Export Briefing";
    action = QUOTE([] call EFUNC(Briefing,ExportBriefings););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveFlying_ca.paa";
};
