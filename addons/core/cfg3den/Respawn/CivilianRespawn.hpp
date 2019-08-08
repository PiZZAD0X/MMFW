class EGVAR(TeamRespawnSettings,Civ) {
    displayName = "Civilian Respawn Settings";
    collapsed = 0; //_respawnTypeArray = [['1 Life','ONELIFE'],['Unlimited','UNLIMITED'],['Individual Tickets','INDTICKETS'],['Team Tickets','TEAMTICKETS'],['Wave','WAVE'],['Triggered','TRIGGERED']];
    class Attributes {
        class EGVAR(Respawn,Type_Civ) {
            displayName = "Respawn System";
            tooltip = QUOTE(Type of respawn system for Civilian. Place down a GameLogic object with name MGVAR(RESPAWN_CIV) to define respawn location.);
            control = QEGVAR(Respawn,Combo_Civ);
            defaultValue = "0";
            property = QEGVAR(Respawn,Type_Civ);
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Respawn,Templates_Civ) {
            property = QEGVAR(Respawn,Templates_Civ);
            displayName = "Respawn System Settings";
            tooltip = "";
            control = QEGVAR(Respawn,Templates_Civ);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "['']";
        };
        class EGVAR(Respawn,NewTeam_Civ) {
            property = QEGVAR(Respawn,NewTeam_Civ);
            displayName = "Respawn Side";
            tooltip = "Determines what side the originally Civilian players will spawn on. Enabling this setting requires respawned players to join a new group.";
            respawnTypes[] = {1,2,3};
            control = QEGVAR(Respawn,Side_Combo);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "3";
        };
        class EGVAR(Respawn,Delay_Civ) {
            property = QEGVAR(Respawn,Delay_Civ);
            displayName = "Respawn Delay";
            tooltip = "Delay in seconds between a player being killed and respawning. Must be more than 5 seconds.";
            respawnTypes[] = {1,2,3,4,5};
            control = QGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "5";
            validate = "number";
        };
        class EGVAR(Respawn,IndTickets_Civ) {
            property = QEGVAR(Respawn,IndTickets_Civ);
            displayName = "Individual Respawn Tickets";
            tooltip = "Number of individual respawns.";
            respawnTypes[] = {2};
            control = QGVAR(1To10Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "2";
            validate = "number";
        };
        class EGVAR(Respawn,TeamTickets_Civ) {
            property = QEGVAR(Respawn,TeamTickets_Civ);
            displayName = "Team Respawn Tickets";
            tooltip = "Number of team respawns.";
            respawnTypes[] = {3};
            control = QGVAR(10To100Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "30";
            validate = "number";
        };
    };
};

class EGVAR(Spectator,Civ) {
    displayName = "Civilian Spectate Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(Spectator,EnabledTeams_Civ) {
            property = QEGVAR(Spectate,EnabledTeams_Civ);
            displayName = "Spectate Teams";
            tooltip = "Teams that this team can spectate.";
            control = QEGVAR(Spectator,Teams_Attribute);
            defaultValue = "['BLUFOR','OPFOR','Indfor','Civ']";
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Spectator,KillCam_Civ) {
            property = QEGVAR(Spectate,KillCam_Civ);
            displayName = "Killcam";
            tooltip = "This setting enables the specator killcam functionality.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,AIEnabled_Civ) {
            property = QEGVAR(Spectate,AIEnabled_Civ);
            displayName = "Spectate AI";
            tooltip = "Enable Spectating AI Entities.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,FreeCam_Civ) {
            property = QEGVAR(Spectate,FreeCam_Civ);
            displayName = "Spectator Freecam";
            tooltip = "Enable Freecam Ability in Spectator.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,3rdPerson_Civ) {
            property = QEGVAR(Spectate,3rdPerson_Civ);
            displayName = "Spectator Third Person";
            tooltip = "Enable Third Person Ability in Spectator.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
    };
};

class EGVAR(TeamJIPSettings,Civ) {
    displayName = "Civilian JiP Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(JIP,Type_Civ) {
            property = QEGVAR(JIP,Type_Civ);
            displayName = "JiP Type";
            tooltip = "TELEPORT: Player can teleport to his squad. TRANSPORT: Player can send a hint to all group leaders requesting transport. DENY: Player is killed and put in spectator.";
            control = QEGVAR(JIP,TypeAtt);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(JIP,Distance_Civ) {
            property = QEGVAR(JIP,Distance_Civ);
            displayName = "JiP Distance";
            tooltip = "If distance to group members upon spawn is greater than this you will be granted the defined JiP action";
            control = QGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "200";
        };
        class EGVAR(JIP,SpawnDistance_Civ) {
            property = QEGVAR(JIP,SpawnDistance_Civ);
            displayName = "Spawn Radius";
            tooltip = "Exiting this radius will remove the JiP actions from the player.";
            control = QGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "50";
        };
    };
};
