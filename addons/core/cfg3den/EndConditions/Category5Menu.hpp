class EGVAR(EndConditions,MainSettings_Category5) {
    displayName = "Category Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,Enabled_5) {
            property = QEGVAR(EndConditions,Enabled_5);
            displayName = "Enable Category";
            tooltip = "Toggle Activation of the End Condition Category";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,Mode_5) {
            property = QEGVAR(EndConditions,Mode_5);
            displayName = "Category Mode";
            tooltip = "Whether or not the condition fires if any condition is true, or if all conditions are true. Extract condition must be true in both cases.";
            control = QEGVAR(EndConditions,ModeAttribute);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(EndConditions,Message_5) {
            property = QEGVAR(EndConditions,Message_5);
            displayName = "Category Message";
            tooltip = "Message displayed when end condition category is triggered";
            control = "Edit";
            validate = "string";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'End condition 5 fired!'";
        };
    };
};

class EGVAR(EndConditions,CasualtySettings_Category5) {
    displayName = "Casualty Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_5);
            displayName = "BLUFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_5);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_5);
            displayName = "OPFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_5);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Indfor_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Indfor_5);
            displayName = "Indfor Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Indfor_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Indfor_5);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Civ_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Civ_5);
            displayName = "CIVILIAN Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Civ_5) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Civ_5);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,EntitySettings_Category5) {
    displayName = "Entity Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,EntitiesAlive_Array_5) {
            property = QEGVAR(EndConditions,EntitiesAlive_Array_5);
            displayName = "Alive Entities";
            tooltip = "Array of entities checked for alive status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDead_Array_5) {
            property = QEGVAR(EndConditions,EntitiesDead_Array_5);
            displayName = "Dead Entities";
            tooltip = "Array of entities checked for dead status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDamaged_Array_5) {
            property = QEGVAR(EndConditions,EntitiesDamaged_Array_5);
            displayName = "Damaged Entities";
            tooltip = "Array of entities checked for over 50 percent damage or immobilized status. Includes dead state. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,HostageSettings_Category5) {
    displayName = "Hostage Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,HostageRescued_Array_5) {
            property = QEGVAR(EndConditions,HostageRescued_Array_5);
            displayName = "Hostage(s) Rescued";
            tooltip = "Array of hostages that must be rescued for the end condition to fire. leave blank to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,VariableSettings_Category5) {
    displayName = "Custom Variable Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CustomVariables_Array_5) {
            property = QEGVAR(EndConditions,CustomVariables_Array_5);
            displayName = "Custom Variables";
            tooltip = "Array of variables to check for true status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,ExtractionSettings_Category5) {
    displayName = "Extraction Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,ExtractionEnabled_5) {
            property = QEGVAR(EndConditions,ExtractionEnabled_5);
            displayName = "Require Extraction";
            tooltip = "Require Extraction in addition to end conditions for this category.";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,ExtractionTeam_5) {
            property = QEGVAR(EndConditions,ExtractionTeam_5);
            displayName = "Team";
            tooltip = "Team required to be in extract area.";
            control = QEGVAR(EndConditions,ExtractTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class EGVAR(EndConditions,ExtractionMarker_5) {
            property = QEGVAR(EndConditions,ExtractionMarker_5);
            displayName = "Extraction Marker";
            tooltip = "Marker name of extraction area.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(EndConditions,ExtractionRatio_5) {
            property = QEGVAR(EndConditions,ExtractionRatio_5);
            displayName = "Ratio";
            tooltip = "Percentage of alive personnel inside the marker to be considered extracted. Default 75";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,CaptureZoneSettings_Category5) {
    displayName = "CaptureZone Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CaptureZoneCaptured_Array_5) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Array_5);
            displayName = "CaptureZone Names";
            tooltip = "List of CaptureZones names that must be captured for the end condition to fire. Leave empty to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,CaptureZoneCaptured_Team_5) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Team_5);
            displayName = "CaptureZone Team";
            tooltip = "Team that must activate the CaptureZones for the condition to fire.";
            control = QEGVAR(EndConditions,CaptureZoneTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};
