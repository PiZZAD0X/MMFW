class GVAR(Category) {
    displayName = "Start In Parachute Options";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Start In Parachute";
            tooltip = "Enables Parachute Unit Option";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
    };
};
