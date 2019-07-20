class EGVAR(Respawn,Settings_BLUFOR) {
    displayName = "BLUFOR Respawn Settings";
    class AttributeCategories {
        #include "Respawn\BluforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_OPFOR) {
    displayName = "OPFOR Respawn Settings";
    class AttributeCategories {
        #include "Respawn\OpforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Indfor) {
    displayName = "Indfor Respawn Settings";
    class AttributeCategories {
        #include "Respawn\IndforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Civ) {
    displayName = "Civilian Respawn Settings";
    class AttributeCategories {
        #include "Respawn\CivilianRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Main) {
    displayName = "General Respawn Settings";
    class AttributeCategories {
        #include "Respawn\MainRespawn.hpp"
    };
};

class EGVAR(EndConditions,SettingsMenu) {
    displayName = "End Condition Settings";
    class AttributeCategories {
      #include "EndConditions\TimelimitMenu.hpp"
      #include "EndConditions\CustomFileMenu.hpp"
      #include "EndConditions\SleepMenu.hpp"
    };
};

class EGVAR(EndConditions,Category_1_Menu) {
    displayName = "Category 1 Settings";
    class AttributeCategories {
        #include "EndConditions\Category1Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_2_Menu) {
    displayName = "Category 2 Settings";
    class AttributeCategories {
        #include "EndConditions\Category2Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_3_Menu) {
    displayName = "Category 3 Settings";
    class AttributeCategories {
        #include "EndConditions\Category3Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_4_Menu) {
    displayName = "Category 4 Settings";
    class AttributeCategories {
        #include "EndConditions\Category4Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_5_Menu) {
    displayName = "Category 5 Settings";
    class AttributeCategories {
        #include "EndConditions\Category5Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_6_Menu) {
    displayName = "Category 6 Settings";
    class AttributeCategories {
        #include "EndConditions\Category6Menu.hpp"
    };
};

class EGVAR(Export,Menu) {
    displayName = "Export Settings";
    class AttributeCategories {
        class EGVAR(Export,Category) {
            displayName = "Export Mission Settings";
            collapsed = 0;
            class Attributes {
                class EGVAR(Export,ExportToProfile) {
                    property = QEGVAR(Export,ExportToProfile);
                    displayName = "Export Settings to Profile";
                    tooltip = "Enter the name of the settings preset that will be saved to your profile";
                    control = QEGVAR(Export,ToProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class EGVAR(Export,ExportToClipboard) {
                    property = QEGVAR(Export,ExportToClipboard);
                    displayName = "Export Settings to Clipboard";
                    tooltip = "Export Settings to Clipboard";
                    control = QEGVAR(Export,ToClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
                class EGVAR(Export,ExportLoadoutToProfile) {
                    property = QEGVAR(Export,ExportLoadoutToProfile);
                    displayName = "Export Loadouts to Profile";
                    tooltip = "Enter the name of the settings preset that will be saved to your profile";
                    control = QEGVAR(Export,LoadoutToProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class EGVAR(Export,ExportLoadoutToClipboard) {
                    property = QEGVAR(Export,ExportLoadoutToClipboard);
                    displayName = "Export Loadouts to Clipboard";
                    tooltip = "Export Loadouts to Clipboard";
                    control = QEGVAR(Export,LoadoutToClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
            };
        };
    };
};

class EGVAR(Import,Menu) {
    displayName = "Import Settings";
    class AttributeCategories {
        class EGVAR(Import,Menu) {
            displayName = "Import Mission Settings";
            collapsed = 0;
            class Attributes {
                class EGVAR(Import,ImportfromProfile) {
                    property = QEGVAR(IMPORT,ImportfromProfile);
                    displayName = "Import Settings from Profile";
                    tooltip = "";
                    control = QEGVAR(Import,FromProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class EGVAR(Import,ImportFromClipboard) {
                    property = QEGVAR(Import,ImportFromClipboard);
                    displayName = "Import Settings from Clipboard";
                    tooltip = "Import Settings from Clipboard";
                    control = QEGVAR(Import,FromClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
                class EGVAR(IMPORT,ImportLoadoutfromProfile) {
                    property = QEGVAR(IMPORT,ImportLoadoutfromProfile);
                    displayName = "Import Loadouts from Profile";
                    tooltip = "";
                    control = QEGVAR(Import,LoadoutFromProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class EGVAR(Import,ImportLoadoutFromClipboard) {
                    property = QEGVAR(Import,ImportLoadoutFromClipboard);
                    displayName = "Import Loadouts from Clipboard";
                    tooltip = "";
                    control = QEGVAR(Import,LoadoutFromClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
            };
        };
    };
};

class GVAR(Version_DummyCategory) {
    displayName = "Dummy attribute, should never show up";
    class AttributeCategories {
        class GVAR(Version_Attributes) {
            displayName = "Dummy attribute, should never show up";
            collapsed = 0;
            class Attributes {
                class GVAR(Version_Created) {
                    property = QGVAR(Version_Created);
                    displayName = "";
                    tooltip = "";
                    control = "EditShort";
                    expression = SCENARIO_EXPRESSION;
                    defaultValue = "''";
                };
                class GVAR(Version_Updated) {
                    property = QGVAR(Version_Updated);
                    displayName = "";
                    tooltip = "";
                    control = "EditShort";
                    expression = SCENARIO_EXPRESSION;
                    defaultValue = "''";
                };
            };
        };
    };
};
