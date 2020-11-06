class GVAR(Category) {
    displayName = "Auto Track Asset Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Enables Auto Track Asset";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(Blufor) {
            property = QGVAR(Blufor);
            displayName = "Blufor";
            tooltip = "Enables Auto Track for Blufor";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(Opfor) {
            property = QGVAR(Opfor);
            displayName = "Opfor";
            tooltip = "Enables Auto Track for Opfor";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(Indfor) {
            property = QGVAR(Indfor);
            displayName = "Indfor";
            tooltip = "Enables Auto Track for Indfor";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(Civfor) {
            property = QGVAR(Civfor);
            displayName = "Civfor";
            tooltip = "Enables Auto Track for Civfor";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(TrackEmpty) {
            property = QGVAR(TrackEmpty);
            displayName = "Empty";
            tooltip = "Enables Auto Track for empty vehicles";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
    };
};
