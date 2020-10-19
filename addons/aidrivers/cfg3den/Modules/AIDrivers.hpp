class GVAR(Settings) {
    displayName = "AI Drivers Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Description) {
            description = "AI Drivers adds an action to spawn an AI driver that is controllable by the commander of the vehicle to minimize the players needed to crew the vehicle.";
            control = "StructuredText2";
        };
        class GVAR(VehClasses) {
            property = QGVAR(VehClasses);
            displayName = "Vehicle Classes";
            tooltip = "Classes to give AI Drivers to at mission start. Leave blank to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class GVAR(AllVehs) {
            property = QGVAR(AllVehs);
            displayName = "All Vehicles";
            tooltip = "Give AI Driver actions to all vehicles at mission start";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(false)";
        };
        class GVAR(NVEnabled) {
            property = QGVAR(NVEnabled);
            displayName = "Night Vision";
            tooltip = "Whether the player can use NVGs in AI Driver view";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(false)";
        };
        class GVAR(FlipEnabled) {
            property = QGVAR(FlipEnabled);
            displayName = "Flip Vehicle";
            tooltip = "Whether the player can flip the vehicle via ACE action";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(true)";
        };
    };
};
