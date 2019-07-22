class GVAR(Category) {
    displayName = "Safe Start Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Enable Safe Start";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(Lowered) {
            property = QGVAR(Lowered);
            displayName = "Start Lowered";
            tooltip = "Enable Lowered Weapon on Mission Start";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(Unloaded) {
            property = QGVAR(Unloaded);
            displayName = "Start Unloaded";
            tooltip = "Enable Unloaded Weapon on Mission Start";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
