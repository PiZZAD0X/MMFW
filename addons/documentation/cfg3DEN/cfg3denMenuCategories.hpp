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
