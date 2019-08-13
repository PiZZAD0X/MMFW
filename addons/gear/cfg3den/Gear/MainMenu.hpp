class GVAR(MainSettings) {
    displayName = "Main Gear Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(GearHandle) {
            property = QGVAR(GearHandle);
            displayName = "Editor Gear Handler";
            tooltip = "Enable Automatic Gear Handling";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
    };
};

class GVAR(Ace_Arsenal) {
    displayName = "Ace Arsenal Gear Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(ACEAR_System_Enabled) {
            property = QGVAR(ACEAR_System_Enabled);
            displayName = "Enable ACE Arsenal System";
            tooltip = "Should Gear System be enabled";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
    };
};

class GVAR(Olsen) {
    displayName = "Olsen Gear Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(Olsen_Enabled) {
            property = QGVAR(Olsen_Enabled);
            displayName = "Enable Olsen System";
            tooltip = "Should Olsen Gear be enabled";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Olsen_OverfillEnabled) {
            property = QGVAR(Olsen_OverfillEnabled);
            displayName = "Enable Gear overfill";
            tooltip = "Forces adding an item to inventory. Works only if container is specified!";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Olsen_FaceRemovalEnabled) {
            property = QGVAR(Olsen_FaceRemovalEnabled);
            displayName = "Force remove facewear";
            tooltip = "When set to false, facewear types that are whitelisted will not be removed";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(Olsen_PathToGear) {
            property = QGVAR(Olsen_PathToGear);
            displayName = "Path to Gearscript";
            tooltip = "Path to the gearscript file in your mission folder";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Gear.sqf'";
        };
    };
};
