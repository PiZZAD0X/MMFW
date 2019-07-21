class EGVAR(Briefing,MissionNotes) {
    displayName = "Mission Notes";
    collapsed = 0;
    class Attributes {
        class EGVAR(Briefing,MissionNotes_Enable) {
            property = QEGVAR(Briefing,MissionNotes_Enable);
            displayName = "Enable Mission Notes";
            tooltip = "Enables Mission Notes";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,MissionNotes_Author) {
            property = QEGVAR(Briefing,MissionNotes_Author);
            displayName = "Mission Author";
            tooltip = "Mission Author";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,MissionNotes_Testers) {
            property = QEGVAR(Briefing,MissionNotes_Testers);
            displayName = "Mission Testers and Additional Credit";
            tooltip = "Mission Testers and Additional Credit";
            control = "Edit";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,MissionNotes_Conditions) {
            property = QEGVAR(Briefing,MissionNotes_Conditions);
            displayName = "End Conditions";
            tooltip = "Describe the specific end conditions for the mission here";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,MissionNotes_Custom) {
            property = QEGVAR(Briefing,MissionNotes_Custom);
            displayName = "Mission Specific Notes";
            tooltip = "Put any special notes for the mission in here";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
         class EGVAR(Briefing,MissionNotes_Changelog) {
            property = QEGVAR(Briefing,MissionNotes_Changelog);
            displayName = "Mission Changelog";
            tooltip = "Put any changes for the mission in here(Bugfixes and such)";
            control = "EditMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,MissionNotes_GM) {
            property = QEGVAR(Briefing,MissionNotes_GM);
            displayName = "Allow Game Mastering";
            tooltip = "Allow Game Mastering";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";

        };
    };
};
