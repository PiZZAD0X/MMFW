class GVAR(Folder) {
    text = "Configure AI";
    items[] = {
        QGVAR(Configure_MainSettings)
    };
    picture = QPATHTOF(resources\aicontrolmodule_ca.paa);
};

class GVAR(Configure_MainSettings) {
    text = "Configure AI Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(MainSettings));
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};
