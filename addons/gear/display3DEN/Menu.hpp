class GVAR(Settings) {
    text = "Configure Gear Settings";
    action = QUOTE(edit3DENMissionAttributes QN(GVAR(Settings)););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa";
};

class GVAR(LoadOnAll) {
    text = "Load Gear On All Entities";
    action = QUOTE([] call EFUNC(Gear,setAllEntityGear););
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};


#define GEARTEAMMENUMAIN(TEAMNAME,ICONNAME) class GVAR(DOUBLES(Configure,TEAMNAME)) {\
    text = QUOTE(Configure TEAMNAME Gear);\
    action = QUOTE(edit3DENMissionAttributes QQGVAR(DOUBLES(Menu,TEAMNAME)));\
    picture = QUOTE(\a3\3DEN\Data\Displays\Display3DEN\PanelRight\ICONNAME.paa);\
}

GEARTEAMMENUMAIN(Blufor,side_west_ca);
GEARTEAMMENUMAIN(Opfor,side_east_ca);
GEARTEAMMENUMAIN(Indfor,side_guer_ca);
GEARTEAMMENUMAIN(Civilian,side_civ_ca);

class GVAR(Folder) {
    text = "Configure Gear";
    items[] = {
        QGVAR(Settings),
        QGVAR(LoadOnAll),
        QGVAR(DOUBLES(Configure,Blufor)),
        QGVAR(DOUBLES(Configure,Opfor)),
        QGVAR(DOUBLES(Configure,Indfor)),
        QGVAR(DOUBLES(Configure,Civilian))
    };
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa";
};
