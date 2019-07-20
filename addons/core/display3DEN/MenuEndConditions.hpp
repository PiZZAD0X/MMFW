class EGVAR(EndConditions,Folder) {
    text = "Configure End Conditions";
    items[] = {
        EGVAR(EndConditions,Settings),
        EGVAR(EndConditions,Settings_Category1),
        EGVAR(EndConditions,Settings_Category2),
        EGVAR(EndConditions,Settings_Category3),
        EGVAR(EndConditions,Settings_Category4),
        EGVAR(EndConditions,Settings_Category5),
        EGVAR(EndConditions,Settings_Category6)
    };
    picture = "\a3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa";
};

class EGVAR(EndConditions,Settings) {
    text = "Configure End Conditions";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,SettingsMenu)););
    picture = "\a3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa";
};

class EGVAR(EndConditions,Settings_Category1) {
    text = "Configure Condition Category 1";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_1_Menu)););
};

class EGVAR(EndConditions,Settings_Category2) {
    text = "Configure Condition Category 2";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_2_Menu)););
};

class EGVAR(EndConditions,Settings_Category3) {
    text = "Configure Condition Category 3";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_3_Menu)););
};

class EGVAR(EndConditions,Settings_Category4) {
    text = "Configure Condition Category 4";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_4_Menu)););
};

class EGVAR(EndConditions,Settings_Category5) {
    text = "Configure Condition Category 5";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_5_Menu)););
};

class EGVAR(EndConditions,Settings_Category6) {
    text = "Configure Condition Category 6";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(EndConditions,Category_6_Menu)););
};
