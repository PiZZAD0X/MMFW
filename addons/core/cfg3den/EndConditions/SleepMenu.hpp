class EGVAR(EndConditions,SleepMenu) {
    displayName = "End Condition Loop Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,ConditionDelay) {
            property = QEGVAR(EndConditions,ConditionDelay);
            displayName = "End Condition Starting Delay";
            tooltip = "Time before any automatic end conditions are run!";
            control = QMGVAR(0To5Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(EndConditions,ConditionSleep) {
            property = QEGVAR(EndConditions,ConditionSleep);
            displayName = "End Condition Sleep";
            tooltip = "Time between end condition checks. Low values can cause server lag!";
            control = QMGVAR(30To100Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "30";
        };
    };
};
