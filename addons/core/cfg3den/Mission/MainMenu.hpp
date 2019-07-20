class GVAR(MainSettings) {
    displayName = "Main Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable Framework";
            tooltip = "Enable Framework";
            control = QGVAR(FrameworkCheckbox);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(MissionType) {
            property = QGVAR(MissionType);
            displayName = "Mission Type";
            tooltip = "Determines Mission Type";
            control = QGVAR(MissionTypeAttribute);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};
