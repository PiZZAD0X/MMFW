class GVAR(Settings_Category) {
    displayName = "Main ACRE Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable ACRE Framework";
            tooltip = "Toggle activation";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Scramble_Enabled) {
            property = QGVAR(Scramble_Enabled);
            displayName = "Enable Frequency Scramble";
            tooltip = "Toggle frequency scrambling";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Babel_Enabled) {
            property = QGVAR(Babel_Enabled);
            displayName = "Enable Babel";
            tooltip = "Toggle Babel activation";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
