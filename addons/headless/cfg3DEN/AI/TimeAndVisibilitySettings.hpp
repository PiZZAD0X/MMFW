class GVAR(TimeAndVisibilitySettings_Category) {
    displayName = "Visibility Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(AIViewDistanceEnabled) {
            property = QGVAR(AIViewDistanceEnabled);
            displayName = "AI Viewdistance";
            tooltip = "Force AI Viewdistance";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(AIViewDistance) {
            property = QGVAR(AIViewDistance);
            displayName = "AI Viewdistance";
            tooltip = "Set the AI Viewdistance in meters. Minimum of 200 meters enforced by A3 engine.";
            control = QEGVAR(Core,200To10000Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "2500";
            typeName = "NUMBER";
        };
        class GVAR(ForceTimeEnable) {
            property = QGVAR(ForceTimeEnable);
            displayName = "Force AI Time";
            tooltip = "";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(ForceTime) {
            property = QGVAR(ForceTime);
            displayName = "Forced AI Time";
            tooltip = "";
            control = QGVAR(SliderTimeDay);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "43200";
        };
    };
};
