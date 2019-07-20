class EGVAR(EndConditions,Timelimit_Settings) {
    displayName = "Timelimit Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,Timelimit_Enabled) {
            property = QEGVAR(EndConditions,Timelimit_Enabled);
            displayName = "Mission Time Limit";
            tooltip = "Enables mission time limit";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,Timelimit) {
            property = EGVAR(EndConditions,Timelimit);
            displayName = "Time Limit";
            tooltip = "Ends mission after this time has been reached. Time in minutes";
            control = QMGVAR(30To120Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "30";
        };
        class EGVAR(EndConditions,Timelimit_Message) {
            property = QEGVAR(EndConditions,Timelimit_Message);
            displayName = "Time Limit Message";
            tooltip = "Message displayed on time limit reached";
            control = "Edit";
            validate = "string";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Time Limit Reached!'";
        };
    };
};
