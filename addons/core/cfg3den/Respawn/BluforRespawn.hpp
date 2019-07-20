class EGVAR(TeamRespawnSettings,Blufor) {
    displayName = "Blufor Respawn Settings";
    collapsed = 0;
    class Attributes {
        //_respawnTypeArray = [['1 Life','ONELIFE'],['Unlimited','UNLIMITED'],['Individual Tickets','INDTICKETS'],['Team Tickets','TEAMTICKETS'],['Wave','WAVE'],['Triggered','TRIGGERED']];
        class EGVAR(Respawn,Type_Blufor) {
            displayName = "Respawn System";
            tooltip = QUOTE(Type of respawn system for BLUFOR. Place down a GameLogic object with name MGVAR(RESPAWN_BLUFOR) to define respawn location.);
            control = QEGVAR(Respawn,Combo_Blufor);
            defaultValue = "0";
            property = QEGVAR(Respawn,Type_Blufor);
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Respawn,Templates_Blufor) {
            property = QEGVAR(Respawn,Templates_Blufor);
            displayName = "Respawn System Settings";
            tooltip = "";
            control = QEGVAR(Respawn,Templates_Blufor);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "['']";
        };
        class EGVAR(Respawn,NewTeam_Blufor) {
            property = QEGVAR(Respawn,NewTeam_Blufor);
            displayName = "Respawn Side";
            tooltip = "Determines what side the originally BLUFOR players will spawn on. Enabling this setting requires respawned players to join a new group.";
            respawnTypes[] = {1,2,3};
            control = QEGVAR(Respawn,Side_Combo);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class EGVAR(Respawn,Delay_Blufor) {
            property = QEGVAR(Respawn,Delay_Blufor);
            displayName = "Respawn Delay";
            tooltip = "Delay in seconds between a player being killed and respawning. Must be more than 5 seconds.";
            respawnTypes[] = {1,2,3,4,5};
            control = QMGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "5";
            validate = "number";
        };
        class EGVAR(Respawn,IndTickets_Blufor) {
            property = QEGVAR(Respawn,IndTickets_Blufor);
            displayName = "Individual Respawn Tickets";
            tooltip = "Number of individual respawns.";
            respawnTypes[] = {2};
            control = QMGVAR(1To10Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "2";
            validate = "number";
        };
        class EGVAR(Respawn,TeamTickets_Blufor) {
            property = QEGVAR(Respawn,TeamTickets_Blufor);
            displayName = "Team Respawn Tickets";
            tooltip = "Number of team respawns.";
            respawnTypes[] = {3};
            control = QMGVAR(10To100Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "30";
            validate = "number";
        };
        /*class EGVAR(Respawn,WaveSize_Blufor) {
            property = QEGVAR(Respawn,WaveSize_Blufor);
            displayName = "Wave Condition";
            tooltip = "Number of players needed to respawn a wave.";
            respawnTypes[] = {4};
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "8";
        };
        class EGVAR(Respawn,WaveGearMode_Blufor) {
            property = QEGVAR(Respawn,WaveGearMode_Blufor);
            displayName = "Wave Gear Mode";
            tooltip = "System for handling gear classes on Wave respawn mode.\
                 Only affects Wave system if 'Handle Gear Classes for Wave Respawns' setting is enabled.\
                 Loose: At least one squad leader, or officer is required to spawn the group. Players respawn with their starting gear class or their respawn gear class if set.\
                 Preferential: Gear classes must fulfill one of the gear class array minimums, players with starting gear classes that meet the minimum classes will fill those slots first.\
                 Strict: Gear classes must fulfill one of the gear class array minimums, players will spawn with their starting or respawn gear class.\
            ";
            respawnTypes[] = {4};
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Respawn,WaveGearModeArray_Blufor) {
            property = QEGVAR(Respawn,WaveGearMode_Blufor);
            displayName = "Wave Gear Mode";
            tooltip = "Gear class combinations for wave respawn gear handling.\
                Each array is a possible minimum gear check pass.\
                Limit players to specific gear minimum array via their respawn gear settings.\
            ";
            respawnTypes[] = {4};
            control = "EditCodeMulti3";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "BluforRifleSquad = [[6,10],['SQL',1,1],['TL',1,2],['AR',1,2],['RFL',0,2],['RFLAT',0,2]]; BluforVehicleCrew = [[2,3],['VCMD',1,1],['VCRW',1,2]];";
        };
        class EGVAR(Respawn,TriggeredCond_Blufor) {
            property = QEGVAR(Respawn,TriggeredCond_Blufor);
            displayName = "Triggered Condition";
            tooltip = "Triggered Respawn condition variable.";
            respawnTypes[] = {5};
            control = "EditCode";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Respawn,MaxRespawns_Blufor) {
            property = QEGVAR(Respawn,MaxRespawns_Blufor);
            displayName = "Wave/Triggered Respawn Limit";
            tooltip = "Total Respawns allowed for Wave and Triggered Respawn Modes. Set to 0 to have no limit.";
            respawnTypes[] = {4,5};
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
            typeName = "number";
        };*/
    };
};

class EGVAR(Spectator,Blufor) {
    displayName = "BLUFOR Spectate Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(Spectator,EnabledTeams_Blufor) {
            property = QEGVAR(Spectate,EnabledTeams_Blufor);
            displayName = "Spectate Teams";
            tooltip = "Teams that this team can spectate.";
            control = QEGVAR(Spectator,Teams_Attribute);
            defaultValue = "['BLUFOR','OPFOR','Indfor','CIVILIAN']";
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Spectator,KillCam_Blufor) {
            property = QEGVAR(Spectate,KillCam_Blufor);
            displayName = "Killcam";
            tooltip = "This setting enables the specator killcam functionality.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,AIEnabled_Blufor) {
            property = QEGVAR(Spectate,AIEnabled_Blufor);
            displayName = "Spectate AI";
            tooltip = "Enable Spectating AI Entities.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,FreeCam_Blufor) {
            property = QEGVAR(Spectate,FreeCam_Blufor);
            displayName = "Spectator Freecam";
            tooltip = "Enable Freecam Ability in Spectator.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class EGVAR(Spectator,3rdPerson_Blufor) {
            property = QEGVAR(Spectate,3rdPerson_Blufor);
            displayName = "Spectator Third Person";
            tooltip = "Enable Third Person Ability in Spectator.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
    };
};

class EGVAR(TeamJIPSettings,BLUFOR) {
    displayName = "BLUFOR JiP Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(JIP,Type_BLUFOR) {
            property = QEGVAR(JIP,Type_BLUFOR);
            displayName = "JiP Type";
            tooltip = "TELEPORT: Player can teleport to his squad. TRANSPORT: Player can send a hint to all group leaders requesting transport. DENY: Player is killed and put in spectator.";
            control = QEGVAR(JIP,TypeAtt);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "0";
        };
        class EGVAR(JIP,Distance_BLUFOR) {
            property = QEGVAR(JIP,Distance_BLUFOR);
            displayName = "JiP Distance";
            tooltip = "If distance to group members upon spawn is greater than this you will be granted the defined JiP action";
            control = QMGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "200";
        };
        class EGVAR(JIP,SpawnDistance_BLUFOR) {
            property = QEGVAR(JIP,SpawnDistance_BLUFOR);
            displayName = "Spawn Radius";
            tooltip = "Exiting this radius will remove the JiP actions from the player.";
            control = QMGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "50";
        };
    };
};
