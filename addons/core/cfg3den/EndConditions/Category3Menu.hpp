class EGVAR(EndConditions,MainSettings_Category3) {
    displayName = "Category Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,Enabled_3) {
            property = QEGVAR(EndConditions,Enabled_3);
            displayName = "Enable Category";
            tooltip = "Toggle Activation of the End Condition Category";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,Mode_3) {
            property = QEGVAR(EndConditions,Mode_3);
            displayName = "Category Mode";
            tooltip = "Whether or not the condition fires if any condition is true, or if all conditions are true. Extract condition must be true in both cases.";
            control = QEGVAR(EndConditions,ModeAttribute);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(EndConditions,Message_3) {
            property = QEGVAR(EndConditions,Message_3);
            displayName = "Category Message";
            tooltip = "Message displayed when end condition category is triggered";
            control = "Edit";
            validate = "string";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'End condition 3 fired!'";
        };
    };
};

class EGVAR(EndConditions,CasualtySettings_Category3) {
    displayName = "Casualty Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_3);
            displayName = "BLUFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_3);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_3);
            displayName = "OPFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_3);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Indfor_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Indfor_3);
            displayName = "Indfor Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Indfor_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Indfor_3);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Civ_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Civ_3);
            displayName = "CIVILIAN Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Civ_3) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Civ_3);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,EntitySettings_Category3) {
    displayName = "Entity Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,EntitiesAlive_Array_3) {
            property = QEGVAR(EndConditions,EntitiesAlive_Array_3);
            displayName = "Alive Entities";
            tooltip = "Array of entities checked for alive status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDead_Array_3) {
            property = QEGVAR(EndConditions,EntitiesDead_Array_3);
            displayName = "Dead Entities";
            tooltip = "Array of entities checked for dead status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDamaged_Array_3) {
            property = QEGVAR(EndConditions,EntitiesDamaged_Array_3);
            displayName = "Damaged Entities";
            tooltip = "Array of entities checked for over 50 percent damage or immobilized status. Includes dead state. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,HostageSettings_Category3) {
    displayName = "Hostage Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,HostageRescued_Array_3) {
            property = QEGVAR(EndConditions,HostageRescued_Array_3);
            displayName = "Hostage(s) Rescued";
            tooltip = "Array of hostages that must be rescued for the end condition to fire. leave blank to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,VariableSettings_Category3) {
    displayName = "Custom Variable Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CustomVariables_Array_3) {
            property = QEGVAR(EndConditions,CustomVariables_Array_3);
            displayName = "Custom Variables";
            tooltip = "Array of variables to check for true status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,ExtractionSettings_Category3) {
    displayName = "Extraction Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,ExtractionEnabled_3) {
            property = QEGVAR(EndConditions,ExtractionEnabled_3);
            displayName = "Require Extraction";
            tooltip = "Require Extraction in addition to end conditions for this category.";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,ExtractionTeam_3) {
            property = QEGVAR(EndConditions,ExtractionTeam_3);
            displayName = "Team";
            tooltip = "Team required to be in extract area.";
            control = QEGVAR(EndConditions,ExtractTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class EGVAR(EndConditions,ExtractionMarker_3) {
            property = QEGVAR(EndConditions,ExtractionMarker_3);
            displayName = "Extraction Marker";
            tooltip = "Marker name of extraction area.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(EndConditions,ExtractionRatio_3) {
            property = QEGVAR(EndConditions,ExtractionRatio_3);
            displayName = "Ratio";
            tooltip = "Percentage of alive personnel inside the marker to be considered extracted. Default 75";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,CaptureZoneSettings_Category3) {
    displayName = "CaptureZone Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CaptureZoneCaptured_Array_3) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Array_3);
            displayName = "CaptureZone Names";
            tooltip = "List of CaptureZones names that must be captured for the end condition to fire. Leave empty to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,CaptureZoneCaptured_Team_3) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Team_3);
            displayName = "CaptureZone Team";
            tooltip = "Team that must activate the CaptureZones for the condition to fire.";
            control = QEGVAR(EndConditions,CaptureZoneTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};
