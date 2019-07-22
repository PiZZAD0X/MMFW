class GVAR(Category) {
    displayName = "Cover Map Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Enable Cover Map Module";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(AllowSwitching) {
            property = QGVAR(AllowSwitching);
            displayName = "Allow Map AO Switching";
            tooltip = "Allow players to switch AOs their character has defined via ace interaction in the map";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(DefaultAO_BLUFOR) {
            property = QGVAR(DefaultAO_BLUFOR);
            displayName = "BLUFOR Starting AO";
            tooltip = "Set the BLUFOR Map area to corresponding CoverMap AO name.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Area0'";
            validate = "STRING";
        };
        class GVAR(DefaultAO_OPFOR) {
            property = QGVAR(DefaultAO_OPFOR);
            displayName = "OPFOR Starting AO";
            tooltip = "Set the OPFOR Map area to corresponding CoverMap AO name.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Area0'";
            validate = "STRING";
        };
        class GVAR(DefaultAO_Indfor) {
            property = QGVAR(DefaultAO_Indfor);
            displayName = "Indfor Starting AO";
            tooltip = "Set the Indfor Map area to corresponding CoverMap AO name.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Area0'";
            validate = "STRING";
        };
        class GVAR(DefaultAO_Civ) {
            property = QGVAR(DefaultAO_Civ);
            displayName = "Civilian Starting AO";
            tooltip = "Set the Civilian Map area to corresponding CoverMap AO name.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Area0'";
            validate = "STRING";
        };
    };
};
