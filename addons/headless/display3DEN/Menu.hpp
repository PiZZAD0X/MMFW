class GVAR(Folder) {
    text = "Configure AI";
    items[] = {
        QGVAR(Configure_MainSettings),
        QGVAR(Configure_CommanderSettings)
    };
    picture = QPATHTOF(resources\aicontrolmodule_ca.paa);
};

class GVAR(Configure_MainSettings) {
    text = "Configure AI Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(MainSettings));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

class GVAR(Configure_CommanderSettings) {
    text = "Configure Commander Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(CommanderSettings));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};
