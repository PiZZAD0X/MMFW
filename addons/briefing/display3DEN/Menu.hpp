class EGVAR(Briefing,Folder) {
    text = "Configure Briefings";
    items[] = {QEGVAR(Briefing,Configure_Blufor),QEGVAR(Briefing,Configure_Opfor),QEGVAR(Briefing,Configure_Indfor),QEGVAR(Briefing,Configure_Civ),QEGVAR(Briefing,Notes_Configure),QEGVAR(Briefing,Export)};
    picture = "\a3\3DEN\Data\Cfg3DEN\Comment\texture_ca.paa";
};

class EGVAR(Briefing,Configure_Blufor) {
    text = "Configure Blufor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Blufor));
};

class EGVAR(Briefing,Configure_Opfor) {
    text = "Configure Opfor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Opfor));
};

class EGVAR(Briefing,Configure_Indfor) {
    text = "Configure Indfor Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Indfor));
};

class EGVAR(Briefing,Configure_Civ) {
    text = "Configure Civilian Briefing";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,Civilian));
};

class EGVAR(Briefing,Notes_Configure) {
    text = "Configure Mission Notes";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Briefing,MissionNotes));
};

class EGVAR(Briefing,Export) {
    text = "Export Briefing";
    action = QUOTE([] call EFUNC(Briefing,ExportBriefings););
};
