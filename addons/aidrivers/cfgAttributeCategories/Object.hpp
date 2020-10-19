class GVAR(Options) {
    displayName = "AI Driver Options";
    collapsed = 1;
    class Attributes {
        class GVAR(DescriptionObject) {
            description = "AI Drivers adds an action to spawn an AI driver that is controllable by the commander of the vehicle to minimize the players needed to crew the vehicle.";
            control = "StructuredText2";
        };
        class GVAR(VehEnabled) {
            displayName = "AI Driver";
            tooltip = "Enable AI driver for this vehicle";
            property = QGVAR(VehEnabled);
            control = "CheckBox";
            expression = ENTITY_EXPRESSION;
            condition = "objectVehicle";
            defaultValue = "(false)";
        };
        class GVAR(VehNVEnabled) {
            property = QGVAR(VehNVEnabled);
            displayName = "Night Vision";
            tooltip = "Whether the player can use NVGs in AI Driver view";
            control = "CheckBox";
            condition = "objectVehicle";
            expression = ENTITY_EXPRESSION;
            defaultValue = "(false)";
        };
        class GVAR(VehFlipEnabled) {
            property = QGVAR(VehFlipEnabled);
            displayName = "Flip Vehicle";
            tooltip = "Whether the player can flip the vehicle via ACE action";
            control = "CheckBox";
            condition = "objectVehicle";
            expression = ENTITY_EXPRESSION;
            defaultValue = "(true)";
        };
    };
};
