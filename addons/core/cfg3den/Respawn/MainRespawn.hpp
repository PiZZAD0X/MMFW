class EGVAR(Respawn,Category) {
    displayName = "General Respawn Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(Respawn,DeathScreenType) {
            property = QEGVAR(Respawn,DeathScreenType);
            displayName = "Death Screen";
            tooltip = "Set the type of death screen";
            control = QEGVAR(Respawn,DeathScreenTypeAttribute);
            defaultValue = "'FADE'";
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Respawn,KillCam) {
            property = QEGVAR(Respawn,KillCam);
            displayName = "Killcam";
            tooltip = "This setting enables the specator killcam functionality.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(true)";
        };
        class EGVAR(Respawn,RandomRespawnLocations) {
            property = QEGVAR(Respawn,RandomRespawnLocations);
            displayName = "Random Locations";
            tooltip = "Enables a random selection of eligible respawn locations.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(false)";
        };
        class EGVAR(Respawn,SpawnPosRespawn) {
            property = QEGVAR(Respawn,KillCam);
            displayName = "SpawnPos Respawn";
            tooltip = "Enabled respawning on the original spawn position if no eligible respawn modules found.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "(false)";
        };
        class EGVAR(Respawn,AreaRespawn) {
            property = QEGVAR(Respawn,AreaRespawn);
            displayName = "Respawn Radius";
            tooltip = "";
            control = QGVAR(0To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "5";
        };
    };
};

class EGVAR(JIP,Category) {
    displayName = "JiP Settings";
    collapsed = 0;
    class Attributes {
        class EGVAR(JIP,DENYTIME) {
            property = QEGVAR(JIP,DENYTIME);
            displayName = "Deny Time";
            tooltip = "After how many minutes should a player be considered JIP";
            control = QGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "5";
        };
        class EGVAR(JIP,EXPIRETIME) {
            property = QEGVAR(JIP,EXPIRETIME);
            displayName = "Expire Time";
            tooltip = "After how many minutes JiPs will no longer have teleport or transport actions.";
            control = QGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "5";
        };
        class EGVAR(JIP,EnemyDISTANCE) {
            property = QEGVAR(JIP,EnemyDISTANCE);
            displayName = "Nearby Enemy Distance";
            tooltip = "Denies teleport action if the distance between enemies and the intended teleport location is less than this value in metres";
            control = QGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "100";
        };
    };
};
