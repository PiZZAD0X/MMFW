class EGVAR(Respawn,Folder) {
    text = "Configure Respawn";
    items[] = {
        QEGVAR(Respawn,Main),
        QEGVAR(Respawn,Configure_BLUFOR),
        QEGVAR(Respawn,Configure_OPFOR),
        QEGVAR(Respawn,Configure_Indfor),
        QEGVAR(Respawn,Configure_Civilian)
    };
    picture = "\a3\3DEN\Data\CfgWaypoints\loiter_ca.paa";
};

class EGVAR(Respawn,Main) {
    text = "General Respawn Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,Settings_Main););
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

#define RESPAWNTEAMMENUMAIN(TEAMNAME,ICONNAME) class EGVAR(Respawn,DOUBLES(Configure,TEAMNAME)) {\
    text = QUOTE(TEAMNAME Respawn Settings);\
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Respawn,DOUBLES(Settings,TEAMNAME)));\
    picture = QUOTE(\a3\3DEN\Data\Displays\Display3DEN\PanelRight\ICONNAME.paa);\
}

RESPAWNTEAMMENUMAIN(Blufor,side_west_ca);
RESPAWNTEAMMENUMAIN(Opfor,side_east_ca);
RESPAWNTEAMMENUMAIN(Indfor,side_guer_ca);
RESPAWNTEAMMENUMAIN(Civilian,side_civ_ca);
