class GVAR(ViewDistanceSettings) {
    displayName = "View Distance Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(VisionPlayerEnabled) {
            property = QGVAR(VisionPlayerEnabled);
            displayName = "Player View-distance";
            tooltip = "Enable Player View-distance";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(PlayerViewDistance) {
            property = QGVAR(PlayerViewDistance);
            displayName = "Player View-distance";
            tooltip = "Set the Player View-distance in meters. Minimum of 200 meters enforced by A3 engine. Players might not see all the way to the limit due to fog but AI can.";
            control = QGVAR(200To10000Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "2500";
            typeName = "NUMBER";
        };
        class GVAR(VisionAIEnabled) {
            property = QGVAR(VisionAIEnabled);
            displayName = "AI Viewdistance";
            tooltip = "Enable AI Viewdistance";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(AIViewDistance) {
            property = QGVAR(AIViewDistance);
            displayName = "AI View-distance";
            tooltip = "Set the AI View-distance in meters. Minimum of 200 meters enforced by A3 engine.";
            control = QGVAR(200To10000Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "2500";
            typeName = "NUMBER";
        };
    };
};
