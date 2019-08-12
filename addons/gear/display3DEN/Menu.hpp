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

class GVAR(Configure_Blufor) {
    text = "Configure Blufor Gear";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Menu_Blufor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa";
};

class GVAR(Configure_Opfor) {
    text = "Configure Opfor Gear";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Menu_Opfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa";
};

class GVAR(Configure_Indfor) {
    text = "Configure Indfor Gear";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Menu_Indfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa";
};

class GVAR(Configure_Civ) {
    text = "Configure Civilian Gear";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Menu_Civ));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa";
};

class GVAR(Folder) {
    text = "Configure Gear";
    items[] = {
        QGVAR(Settings),
        QGVAR(LoadOnAll),
        QGVAR(Configure_Blufor),
        QGVAR(Configure_Opfor),
        QGVAR(Configure_Indfor),
        QGVAR(Configure_Civ)
    };
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\arsenal_ca.paa";
};
