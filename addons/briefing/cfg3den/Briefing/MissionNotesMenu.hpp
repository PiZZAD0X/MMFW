class GVAR(MissionNotes) {
    displayName = "Mission Notes";
    collapsed = 0;
    class Attributes {
        class GVAR(MissionNotes_Enable) {
            property = QGVAR(MissionNotes_Enable);
            displayName = "Enable Mission Notes";
            tooltip = "Enables Mission Notes";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(MissionNotes_Author) {
            property = QGVAR(MissionNotes_Author);
            displayName = "Mission Author";
            tooltip = "Mission Author";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(MissionNotes_Testers) {
            property = QGVAR(MissionNotes_Testers);
            displayName = "Mission Testers";
            tooltip = "Mission Testers and Additional Credit";
            control = "Edit";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class GVAR(MissionNotes_Conditions) {
            property = QGVAR(MissionNotes_Conditions);
            displayName = "End Conditions";
            tooltip = "Describe the specific end conditions for the mission here";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class GVAR(MissionNotes_Custom) {
            property = QGVAR(MissionNotes_Custom);
            displayName = "Mission Specific Notes";
            tooltip = "Put any special notes for the mission in here";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
         class GVAR(MissionNotes_Changelog) {
            property = QGVAR(MissionNotes_Changelog);
            displayName = "Mission Changelog";
            tooltip = "Put any changes for the mission in here(Bugfixes and such)";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class GVAR(MissionNotes_GM) {
            property = QGVAR(MissionNotes_GM);
            displayName = "Allow Game Mastering";
            tooltip = "Allow Game Mastering";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";

        };
    };
};
