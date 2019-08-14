class GVAR(ViewDistanceSettings) {
    displayName = "View Distance Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(VisionPlayerEnabled) {
            property = QGVAR(VisionPlayerEnabled);
            displayName = "Force Player View Distance";
            tooltip = "Enable Player View-distance";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(PlayerViewDistance) {
            property = QGVAR(PlayerViewDistance);
            displayName = "Player View Distance";
            tooltip = "Set the Player view distance in meters. Minimum of 200 meters enforced by A3 engine.";
            control = QGVAR(200To10000Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "2500";
            typeName = "NUMBER";
        };
        class GVAR(ForceTerrain_Enabled) {
            property = QGVAR(ForceTerrain_Enabled);
            displayName = "Force TerrainGrid";
            tooltip = "Force terrain grid to prevent far away objects from appearing as floating.";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};
