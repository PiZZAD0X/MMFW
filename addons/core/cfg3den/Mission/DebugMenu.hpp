class EGVAR(Debug,Category) {
    displayName = "Debug Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(Debug,Debug_Enabled) {
            property = QEGVAR(Debug,Debug_Enabled);
            displayName = "Enable Debug";
            tooltip = "Toggle debug mode.";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Debug,Detailed_Enabled) {
            property = QEGVAR(Debug,Detailed_Enabled);
            displayName = "Detailed Debug";
            tooltip = "Toggle detailed debug mode.";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
