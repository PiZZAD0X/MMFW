class GVAR(Category) {
    displayName = "Shot Count Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Shot Count";
            tooltip = "Enable Shot Count";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
    };
};
