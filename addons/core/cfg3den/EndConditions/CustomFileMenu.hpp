class EGVAR(EndConditions,Custom_File) {
    displayName = "Custom File";
    collapsed = 0;
    class Attributes {
        class EGVAR(EndConditions,File) {
            property = QEGVAR(EndConditions,File);
            displayName = "Custom End Condition File";
            tooltip = "Loads file on server as end conditions instead of framework category settings.";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(EndConditions,File_Path) {
            property = QEGVAR(EndConditions,File_Path);
            displayName = "Path to End Condition File";
            tooltip = "Path to End Condition File";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
