class GVAR(TeamsSettings) {
    displayName = "Team Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(TeamType_Blufor) {
            property = QGVAR(TeamType_Blufor);
            displayName = "Type";
            tooltip = "Set team to either AI, Player Controlled, or Both";
            control = QGVAR(TeamType_Select);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(TeamName_Blufor) {
            property = QGVAR(TeamName_Blufor);
            displayName = "Name";
            tooltip = "Set team name";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'BLUFOR TEAM'";
        };
        class GVAR(TeamType_Opfor) {
            property = QGVAR(TeamType_Opfor);
            displayName = "Type";
            tooltip = "Set team to either AI, Player Controlled, or Both";
            control = QGVAR(TeamType_Select);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(TeamName_Opfor) {
            property = QGVAR(TeamName_Opfor);
            displayName = "Name";
            tooltip = "Set team name";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'OPFOR TEAM'";
        };
        class GVAR(TeamType_Indfor) {
            property = QGVAR(TeamType_Indfor);
            displayName = "Type";
            tooltip = "Set team to either AI, Player Controlled, or Both";
            control = QGVAR(TeamType_Select);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(TeamName_Indfor) {
            property = QGVAR(TeamName_Indfor);
            displayName = "Name";
            tooltip = "Set team name";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'Indfor TEAM'";
        };
        class GVAR(TeamType_Civ) {
            property = QGVAR(TeamType_Civ);
            displayName = "Type";
            tooltip = "Set team to either AI, Player Controlled, or Both";
            control = QGVAR(TeamType_Select);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(TeamName_Civ) {
            property = QGVAR(TeamName_Civ);
            displayName = "Name";
            tooltip = "Set team name";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'CIVILIAN TEAM'";
        };
    };
};
