class GVAR(CommanderSettings_Category) {
    displayName = "Commander Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(CommanderEnabled) {
            property = QGVAR(CommanderEnabled);
            displayName = "Enable Commander";
            tooltip = "";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
