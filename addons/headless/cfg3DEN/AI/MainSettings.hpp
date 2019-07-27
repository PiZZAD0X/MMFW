class GVAR(Settings_Category) {
    displayName = "Main AI Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable AI System";
            tooltip = "";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(CommanderEnabled) {
            property = QGVAR(CommanderEnabled);
            displayName = "Enable Commander";
            tooltip = "";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Debug) {
            property = QGVAR(Debug);
            displayName = "Enable Debug";
            tooltip = "";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(UseMarkers) {
            property = QGVAR(UseMarkers);
            displayName = "Enable Debug Markers";
            tooltip = "";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
