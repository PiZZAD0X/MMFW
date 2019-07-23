class GVAR(Folder) {
    text = "Configure ACRE";
    items[] = {
        QGVAR(Configure_MainSettings),
        QGVAR(Configure_Blufor),
        QGVAR(Configure_Opfor),
        QGVAR(Configure_Indfor),
        QGVAR(Configure_Civ)
    };
    picture = QPATHTOF(resources\RadioIcon_Radio.paa);
};

class GVAR(Configure_Blufor) {
    text = "Configure Blufor ACRE";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Blufor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa";
};

class GVAR(Configure_Opfor) {
    text = "Configure Opfor ACRE";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Opfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa";
};

class GVAR(Configure_Indfor) {
    text = "Configure Indfor ACRE";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Indfor));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa";
};

class GVAR(Configure_Civ) {
    text = "Configure Civilian ACRE";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Civilian));
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa";
};

class GVAR(Configure_MainSettings) {
    text = "Configure ACRE Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(MainSettings));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};
