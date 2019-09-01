#define BRIEFINGTEAMMENUMAIN(TEAMNAME,ICONNAME) class GVAR(DOUBLES(Configure,TEAMNAME)) {\
    text = QUOTE(Configure TEAMNAME Briefing);\
    action = QUOTE(edit3DENMissionAttributes QQGVAR(DOUBLES(Menu,TEAMNAME)));\
    picture = QUOTE(\a3\3DEN\Data\Displays\Display3DEN\PanelRight\ICONNAME.paa);\
}

class GVAR(Folder) {
    text = "Configure Briefings";
    items[] = {
        QGVAR(Notes_Configure),
        QGVAR(Export),
        QGVAR(Configure_Blufor),
        QGVAR(Configure_Opfor),
        QGVAR(Configure_Indfor),
        QGVAR(Configure_Civilian)
    };
    picture = "\a3\3DEN\Data\Cfg3DEN\Comment\texture_ca.paa";
};

BRIEFINGTEAMMENUMAIN(Blufor,side_west_ca);
BRIEFINGTEAMMENUMAIN(Opfor,side_east_ca);
BRIEFINGTEAMMENUMAIN(Indfor,side_guer_ca);
BRIEFINGTEAMMENUMAIN(Civilian,side_civ_ca);

class GVAR(Notes_Configure) {
    text = "Configure Mission Notes";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(MissionNotes));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

class GVAR(Export) {
    text = "Export Briefing";
    action = QUOTE([] call EFUNC(Briefing,ExportBriefings););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveFlying_ca.paa";
};
