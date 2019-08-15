class GVAR(Category) {
    displayName = "Anti ND Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Description) {
            description = "Anti ND deletes ammunition fired with accidental discharge during spawn.";
            control = "StructuredText1";
        };
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Toggle activation";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(Time) {
            property = QGVAR(Time);
            displayName = "Time";
            tooltip = "Time in seconds after spawn after which Anti ND functionality is disabled";
            control = QEGVAR(Core,30To120Step1_Slider);
            validate = "number";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "30";
        };
        class GVAR(Distance) {
            property = QGVAR(Distance);
            displayName = "Distance";
            tooltip = "Distance in meters at which Anti ND functionality is disabled";
            control = QEGVAR(Core,50To250Step50_Slider);
            validate = "number";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "200";
        };
    };
};
