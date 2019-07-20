class EGVAR(EndConditions,MainSettings_Category6) {
    displayName = "Category Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,Enabled_6) {
            property = QEGVAR(EndConditions,Enabled_6);
            displayName = "Enable Category";
            tooltip = "Toggle Activation of the End Condition Category";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,Mode_6) {
            property = QEGVAR(EndConditions,Mode_6);
            displayName = "Category Mode";
            tooltip = "Whether or not the condition fires if any condition is true, or if all conditions are true. Extract condition must be true in both cases.";
            control = QEGVAR(EndConditions,ModeAttribute);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(EndConditions,Message_6) {
            property = QEGVAR(EndConditions,Message_6);
            displayName = "Category Message";
            tooltip = "Message displayed when end condition category is triggered";
            control = "Edit";
            validate = "string";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'End condition 6 fired!'";
        };
    };
};

class EGVAR(EndConditions,CasualtySettings_Category6) {
    displayName = "Casualty Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_BLUFOR_6);
            displayName = "BLUFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_BLUFOR_6);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_OPFOR_6);
            displayName = "OPFOR Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_OPFOR_6);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Indfor_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Indfor_6);
            displayName = "Indfor Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Indfor_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Indfor_6);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
        class EGVAR(EndConditions,CasualtyCount_Enabled_Civ_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Enabled_Civ_6);
            displayName = "CIVILIAN Casualty";
            tooltip = "Enables casualty limit for this team";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,CasualtyCount_Percentage_Civ_6) {
            property = QEGVAR(EndConditions,CasualtyCount_Percentage_Civ_6);
            displayName = "Casualty Percentage";
            tooltip = "End condition fires when team casualty percentage is over this number";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,EntitySettings_Category6) {
    displayName = "Entity Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,EntitiesAlive_Array_6) {
            property = QEGVAR(EndConditions,EntitiesAlive_Array_6);
            displayName = "Alive Entities";
            tooltip = "Array of entities checked for alive status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDead_Array_6) {
            property = QEGVAR(EndConditions,EntitiesDead_Array_6);
            displayName = "Dead Entities";
            tooltip = "Array of entities checked for dead status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,EntitiesDamaged_Array_6) {
            property = QEGVAR(EndConditions,EntitiesDamaged_Array_6);
            displayName = "Damaged Entities";
            tooltip = "Array of entities checked for over 50 percent damage or immobilized status. Includes dead state. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,HostageSettings_Category6) {
    displayName = "Hostage Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,HostageRescued_Array_6) {
            property = QEGVAR(EndConditions,HostageRescued_Array_6);
            displayName = "Hostage(s) Rescued";
            tooltip = "Array of hostages that must be rescued for the end condition to fire. leave blank to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,VariableSettings_Category6) {
    displayName = "Custom Variable Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CustomVariables_Array_6) {
            property = QEGVAR(EndConditions,CustomVariables_Array_6);
            displayName = "Custom Variables";
            tooltip = "Array of variables to check for true status. Leave blank to disable";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
    };
};

class EGVAR(EndConditions,ExtractionSettings_Category6) {
    displayName = "Extraction Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,ExtractionEnabled_6) {
            property = QEGVAR(EndConditions,ExtractionEnabled_6);
            displayName = "Require Extraction";
            tooltip = "Require Extraction in addition to end conditions for this category.";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,ExtractionTeam_6) {
            property = QEGVAR(EndConditions,ExtractionTeam_6);
            displayName = "Team";
            tooltip = "Team required to be in extract area.";
            control = QEGVAR(EndConditions,ExtractTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class EGVAR(EndConditions,ExtractionMarker_6) {
            property = QEGVAR(EndConditions,ExtractionMarker_6);
            displayName = "Extraction Marker";
            tooltip = "Marker name of extraction area.";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(EndConditions,ExtractionRatio_6) {
            property = QEGVAR(EndConditions,ExtractionRatio_6);
            displayName = "Ratio";
            tooltip = "Percentage of alive personnel inside the marker to be considered extracted. Default 75";
            control = QMGVAR(5To100Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "75";
        };
    };
};

class EGVAR(EndConditions,CaptureZoneSettings_Category6) {
    displayName = "CaptureZone Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,CaptureZoneCaptured_Array_6) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Array_6);
            displayName = "CaptureZone Names";
            tooltip = "List of CaptureZones names that must be captured for the end condition to fire. Leave empty to disable.";
            control = "EditArray";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "[]";
        };
        class EGVAR(EndConditions,CaptureZoneCaptured_Team_6) {
            property = QEGVAR(EndConditions,CaptureZoneCaptured_Team_6);
            displayName = "CaptureZone Team";
            tooltip = "Team that must activate the CaptureZones for the condition to fire.";
            control = QEGVAR(EndConditions,CaptureZoneTeam);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};
