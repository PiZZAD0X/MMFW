class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(CaptureZoneModule): EGVAR(Core,BaseModule) {
        displayName = "Capture Zone (Circle)"; // Name displayed in the menu
        // Name of function triggered once conditions are met
        function = QFUNC(Module);
        // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
        functionPriority = 0;
        scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 1;
        curatorInfoType = "RscDisplayAttributeModuleNuke";
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        icon = QPATHTOF(resources\capzonemodule_ca.paa);

        class AttributeValues {
            size3[] = {100,100,-1};
            IsRectangle = 0;
        };

        class Attributes {
            class GVAR(ZoneName) {
                displayName = "Zone name";
                tooltip = "Name of CaptureZone used in End Conditions reference and in automated message mode. Also a variable that gets set to true once the CaptureZone is captured.";
                property = QGVAR(ZoneName);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'CaptureZone0'";
                typeName = "STRING";
                validate = "none";
            };
            class GVAR(RatioNeeded) {
                displayName = "Ratio Needed";
                tooltip = "Ratio needed to capture the zone. Larger team / team in second place.";
                property = QGVAR(RatioNeeded);
                control = QEGVAR(Core,0To100Step5_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "75";
                validate = "NUMBER";
                typeName = "number";
            };
            class GVAR(Cap_Blufor) {
                displayName = "Blufor Cap Mode";
                tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
                property = QGVAR(Cap_Blufor);
                control = QGVAR(TeamAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "0";
                typeName = "number";
            };
            class GVAR(Time_Blufor) {
                displayName = "Time to Capture";
                tooltip = "Time needed for Blufor to capture the zone in seconds. Set to 0 for instant capture";
                property = QGVAR(Time_Blufor);
                control = QEGVAR(Core,0To600Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                typeName = "NUMBER";
                validate = "number";
            };
            class GVAR(MessageCapturing_Blufor) {
                displayName = "Capturing Message";
                tooltip = "Message to display when Blufor is capturing the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCapturing_Blufor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'BLUFOR is capturing the zone!'";
                validate = "none";
            };
            class GVAR(MessageCaptured_Blufor) {
                displayName = "Capturing Message";
                tooltip = "Message to display when Blufor captures the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCaptured_Blufor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'BLUFOR has captured the zone!'";
                validate = "none";
            };
            class GVAR(Colour_Blufor) {
                displayName = "Colour";
                tooltip = "Blufor Colour";
                property = QGVAR(Colour_Blufor);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'colorBLUFOR'";
                validate = "none";
            };
            class GVAR(Cap_Opfor) {
                displayName = "Opfor Cap Mode";
                tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
                property = QGVAR(Cap_Opfor);
                control = QGVAR(TeamAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "0";
                typeName = "number";
            };
            class GVAR(Time_Opfor) {
                displayName = "Time to Capture";
                tooltip = "Time needed for Opfor to capture the zone in seconds. Set to 0 for instant capture";
                property = QGVAR(Time_Opfor);
                control = QEGVAR(Core,0To600Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                typeName = "NUMBER";
                validate = "number";
            };
            class GVAR(MessageCapturing_Opfor) {
                displayName = "Capturing Message";
                tooltip = "Message to display when Opfor is capturing the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCapturing_Opfor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Opfor is capturing the zone!'";
                validate = "none";
            };
            class GVAR(MessageCaptured_Opfor) {
                displayName = "Captured Message";
                tooltip = "Message to display when Opfor captures the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCaptured_Opfor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Opfor has captured the zone!'";
                validate = "none";
            };
            class GVAR(Colour_Opfor) {
                displayName = "Colour";
                tooltip = "Opfor Colour";
                property = QGVAR(Colour_Opfor);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'colorOPFOR'";
                validate = "none";
            };
            class GVAR(Cap_Indfor) {
                displayName = "Indfor Cap Mode";
                tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
                property = QGVAR(Cap_Indfor);
                control = QGVAR(TeamAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "0";
                typeName = "number";
            };
            class GVAR(Time_Indfor) {
                displayName = "Time to Capture";
                tooltip = "Time needed for Indfor to capture the zone in seconds. Set to 0 for instant capture";
                property = QGVAR(Time_Indfor);
                control = QEGVAR(Core,0To600Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                typeName = "NUMBER";
                validate = "number";
            };
            class GVAR(MessageCapturing_Indfor) {
                displayName = "Capturing Message";
                tooltip = "Message to display when Indfor is capturing the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCapturing_Indfor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Indfor is capturing the zone!'";
                validate = "none";
            };
            class GVAR(MessageCaptured_Indfor) {
                displayName = "Captured Message";
                tooltip = "Message to display when Indfor captures the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCaptured_Indfor);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Indfor has captured the zone!'";
                validate = "none";
            };
            class GVAR(Colour_Indfor) {
                displayName = "Colour";
                tooltip = "Indfor Colour";
                property = QGVAR(Colour_Indfor);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'colorIndependent'";
                validate = "none";
            };
            class GVAR(Cap_Civ) {
                displayName = "Civilian Cap Mode";
                tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";
                property = QGVAR(Cap_Civ);
                control = QGVAR(TeamAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "0";
                typeName = "number";
            };
            class GVAR(Time_Civ) {
                displayName = "Time to Capture";
                tooltip = "Time needed for Civilian to capture the zone in seconds. Set to 0 for instant capture";
                property = QGVAR(Time_Civ);
                control = QEGVAR(Core,0To600Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                typeName = "NUMBER";
                validate = "number";
            };
            class GVAR(MessageCapturing_Civ) {
                displayName = "Capturing Message";
                tooltip = "Message to display when Civilian is capturing the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCapturing_Civ);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Civilian is capturing the zone!'";
                validate = "none";
            };
            class GVAR(MessageCaptured_Civ) {
                displayName = "Captured Message";
                tooltip = "Message to display when Civilian captures the zone. Leave empty to disable this hint";
                property = QGVAR(MessageCaptured_Civ);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'Civilian has captured the zone!'";
                validate = "none";
            };
            class GVAR(Colour_Civ) {
                displayName = "Colour";
                tooltip = "Civilian Colour";
                property = QGVAR(Colour_Civ);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'colorCivilian'";
                validate = "none";
            };
            class GVAR(ContestedMessage) {
                displayName = "Contested Message";
                tooltip = "Message to display when the zone is contested. Leave empty to disable this hint";
                property = QGVAR(ContestedMessage);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'The zone is contested!'";
                typeName = "STRING";
                validate = "none";
            };
            class GVAR(Colour_Contested) {
                displayName = "Contested Colour";
                tooltip = "Contested Colour";
                property = QGVAR(Colour_Contested);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'ColorYellow'";
                validate = "none";
            };
            class GVAR(UncontestedMessage) {
                displayName = "Uncontested Message";
                tooltip = "Message to display when the zone is uncontested. Leave empty to disable this hint";
                property = QGVAR(UncontestedMessage);
                control = "Edit";
                expression = MODULE_EXPRESSION;
                defaultValue = "'The zone is uncontested!'";
                typeName = "STRING";
                validate = "none";
            };
            class GVAR(Colour_Uncontested) {
                displayName = "Uncontested Colour";
                tooltip = "Uncontested Colour";
                property = QGVAR(Colour_Uncontested);
                control = QGVAR(ColourCombo);
                expression = MODULE_EXPRESSION;
                defaultValue = "'ColorGrey'";
                validate = "none";
            };
            class GVAR(AutoMessages) {
                displayName = "Automated Messages";
                tooltip = "Enables automated messages based off of zone name. eg. For a zone named 'Everon' and a team called 'USMC', message would be 'USMC is capturing Everon!'";
                property = QGVAR(AutoMessages);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "false";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Hidden) {
                displayName = "Hidden";
                tooltip = "Hides the CaptureZone on the map. No markers are displayed if setting is enabled.";
                property = QGVAR(Hidden);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "false";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Silent) {
                displayName = "Silent";
                tooltip = "Does not show CaptureZone hints to players. No hints are displayed if this setting is enabled.";
                property = QGVAR(Silent);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "false";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Mode) {
                displayName = "Recapture";
                tooltip = "Can this area be recaptured? If disabled, zone will deactivate once a CaptureZone team captures it.";
                property = QGVAR(Mode);
                control = QGVAR(ModeAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "1";
                typeName = "NUMBER";
                validate = "none";
            };
            class GVAR(Condition) {
                displayName = "Custom Condition";
                tooltip = "Enter a custom condition that must be met for this zone to be captured. Default: true";
                property = QGVAR(Condition);
                control = "EditCode";
                expression = MODULE_EXPRESSION;
                defaultValue = "'true'";
            };
        };
    };

    class GVAR(CaptureZoneModule_R) : GVAR(CaptureZoneModule) {
        displayName = "Capture Zone (Rectangle)";
        class AttributeValues {
            IsRectangle = 1;
        };
    };
};
