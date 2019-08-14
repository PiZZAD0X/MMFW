class GVAR(ExportMenu) {
    displayName = "Export Settings";
    class AttributeCategories {
        class GVAR(ExportCategory) {
            displayName = "Export Mission Settings";
            collapsed = 0;
            class Attributes {
                class GVAR(ExportToProfile) {
                    property = QGVAR(ExportToProfile);
                    displayName = "Export Settings to Profile";
                    tooltip = "Enter the name of the settings preset that will be saved to your profile";
                    control = QGVAR(ToProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class GVAR(ExportToClipboard) {
                    property = QGVAR(ExportToClipboard);
                    displayName = "Export Settings to Clipboard";
                    tooltip = "Export Settings to Clipboard";
                    control = QGVAR(ToClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
                class GVAR(ExportLoadoutToProfile) {
                    property = QGVAR(ExportLoadoutToProfile);
                    displayName = "Export Loadouts to Profile";
                    tooltip = "Enter the name of the settings preset that will be saved to your profile";
                    control = QGVAR(LoadoutToProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class GVAR(ExportLoadoutToClipboard) {
                    property = QGVAR(ExportLoadoutToClipboard);
                    displayName = "Export Loadouts to Clipboard";
                    tooltip = "Export Loadouts to Clipboard";
                    control = QGVAR(LoadoutToClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
            };
        };
    };
};

class GVAR(ImportMenu) {
    displayName = "Import Settings";
    class AttributeCategories {
        class GVAR(ImportCategory) {
            displayName = "Import Mission Settings";
            collapsed = 0;
            class Attributes {
                class GVAR(ImportfromProfile) {
                    property = QGVAR(ImportfromProfile);
                    displayName = "Import Settings from Profile";
                    tooltip = "";
                    control = QGVAR(FromProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class GVAR(ImportFromClipboard) {
                    property = QGVAR(ImportFromClipboard);
                    displayName = "Import Settings from Clipboard";
                    tooltip = "Import Settings from Clipboard";
                    control = QGVAR(FromClipboardAttribute);
                    expression = "";
                    defaultValue = "[]";
                };
                class GVAR(ImportLoadoutfromProfile) {
                    property = QGVAR(ImportLoadoutfromProfile);
                    displayName = "Import Loadouts from Profile";
                    tooltip = "";
                    control = QGVAR(LoadoutFromProfileAttribute);
                    expression = "";
                    defaultValue = "''";
                };
                class GVAR(ImportLoadoutFromClipboard) {
                    property = QGVAR(ImportLoadoutFromClipboard);
                    displayName = "Import Loadouts from Clipboard";
                    tooltip = "";
                    control = QGVAR(LoadoutFromClipboardAttribute);
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
