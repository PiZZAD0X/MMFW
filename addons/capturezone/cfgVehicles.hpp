#define CAPZONETEAMATTR(TEAMNAME,TEAMCOLOUR) class GVAR(DOUBLES(TEAMNAME,Title)) {\
    property = QGVAR(DOUBLES(TEAMNAME,Title));\
    tooltip = "";\
    displayName = QUOTE(TEAMNAME);\
    control = "SubTitleIndent";\
};\
class GVAR(DOUBLES(Cap,TEAMNAME)) {\
    property = QGVAR(DOUBLES(Cap,TEAMNAME));\
    displayName = QUOTE(TEAMNAME Cap Mode);\
    tooltip = "Whether or not the team can capture the zone, and whether they are checked in the player count.";\
    control = QGVAR(TeamAttribute);\
    expression = MODULE_EXPRESSION;\
    defaultValue = "0";\
    typeName = "number";\
};\
class GVAR(DOUBLES(Time,TEAMNAME)) {\
    property = QGVAR(DOUBLES(Time,TEAMNAME));\
    displayName = "Time to Capture";\
    tooltip = "Time needed for this team to capture the zone in seconds. Set to 0 for instant capture";\
    control = QEGVAR(Core,0To600Step1_Slider);\
    expression = MODULE_EXPRESSION;\
    defaultValue = "30";\
    typeName = "NUMBER";\
    validate = "number";\
};\
class GVAR(DOUBLES(MessageCapturing,TEAMNAME)) {\
    property = QGVAR(DOUBLES(MessageCapturing,TEAMNAME));\
    displayName = "Capturing Message";\
    tooltip = "Message to display when this team is capturing the zone. Leave empty to disable this hint";\
    control = "Edit";\
    expression = MODULE_EXPRESSION;\
    defaultValue = QUOTE(QN(TEAMNAME is capturing the zone!));\
    validate = "none";\
};\
class GVAR(DOUBLES(MessageCaptured,TEAMNAME)) {\
    displayName = "Capturing Message";\
    tooltip = "Message to display when this team captures the zone. Leave empty to disable this hint";\
    property = QGVAR(DOUBLES(MessageCaptured,TEAMNAME));\
    control = "Edit";\
    expression = MODULE_EXPRESSION;\
    defaultValue = QUOTE(QN(TEAMNAME has captured the zone!));\
    validate = "none";\
};\
class GVAR(DOUBLES(Colour,TEAMNAME)) {\
    property = QGVAR(DOUBLES(Colour,TEAMNAME));\
    displayName = "Colour";\
    tooltip = QUOTE(TEAMNAME Colour);\
    control = QGVAR(ColourCombo);\
    expression = MODULE_EXPRESSION;\
    defaultValue = QUOTE(QN(TEAMCOLOUR));\
    validate = "none";\
}

class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(CaptureZoneModule): EGVAR(Core,BaseModule) {
        displayName = "Capture Zone"; // Name displayed in the menu
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
        canSetAreaShape = 1;
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
            class GVAR(AICount) {
                displayName = "Count AI";
                tooltip = "Whether the CaptureZone counts AI units in the capture count or only players.";
                property = QGVAR(AICount);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
            };

            CAPZONETEAMATTR(Blufor,colorBLUFOR);
            CAPZONETEAMATTR(Opfor,colorOPFOR);
            CAPZONETEAMATTR(Indfor,colorIndependent);
            CAPZONETEAMATTR(Civilian,colorCivilian);

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
        scope = 0;
        displayName = "Capture Zone (Rectangle)";
        class AttributeValues {
            IsRectangle = 1;
        };
    };
};
