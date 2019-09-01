#define CATEGORY3DENNAME(MENUNUM) EGVAR(EndConditions,DOUBLES(Settings_Category,MENUNUM))

class EGVAR(EndConditions,Folder) {
    text = "Configure End Conditions";
    items[] = {
        EGVAR(EndConditions,Settings),
        CATEGORY3DENNAME(1),
        CATEGORY3DENNAME(2),
        CATEGORY3DENNAME(3),
        CATEGORY3DENNAME(4),
        CATEGORY3DENNAME(5),
        CATEGORY3DENNAME(6)
    };
    picture = "\a3\ui_f\data\IGUI\RscTitles\MPProgress\timer_ca.paa";
};

class EGVAR(EndConditions,Settings) {
    text = "Configure Main Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(EndConditions,SettingsMenu););
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

#define CATEGORY3DEN(MENUNUM) class EGVAR(EndConditions,DOUBLES(Settings_Category,MENUNUM)) {\
    text = QUOTE(Configure Condition Category MENUNUM);\
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(EndConditions,TRIPLES(Category,MENUNUM,Menu)););\
}

CATEGORY3DEN(1);
CATEGORY3DEN(2);
CATEGORY3DEN(3);
CATEGORY3DEN(4);
CATEGORY3DEN(5);
CATEGORY3DEN(6);
