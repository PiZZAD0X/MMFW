class EGVAR(Respawn,Category) {
    displayName = "General Respawn Settings";
    collapsed = 0; //_respawnTypeArray = [['1 Life','ONELIFE'],['Unlimited','UNLIMITED'],['Individual Tickets','INDTICKETS'],['Team Tickets','TEAMTICKETS'],['Wave','WAVE'],['Triggered','TRIGGERED']];\
    class Attributes {
        class EGVAR(Respawn,InstantDeath) {
            property = QEGVAR(Respawn,InstantDeath);
            displayName = "Instant Death Screen";
            tooltip = "This setting enables the 'YOU ARE DEAD' screen that shows immediately following a player's death. Disable to enable VR fadeout effect.";
            control = "CheckBox";
            defaultValue = "true";
            expression = SCENARIO_EXPRESSION;
        };
        class EGVAR(Respawn,KillCam) {
            property = QEGVAR(Respawn,KillCam);
            displayName = "Killcam";
            tooltip = "This setting enables the specator killcam functionality.";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
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
            control = QMGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "5";
        };
        class EGVAR(JIP,EXPIRETIME) {
            property = QEGVAR(JIP,EXPIRETIME);
            displayName = "Expire Time";
            tooltip = "After how many minutes JiPs will no longer have teleport or transport actions.";
            control = QMGVAR(5To20Step1_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "5";
        };
        class EGVAR(JIP,EnemyDISTANCE) {
            property = QEGVAR(JIP,EnemyDISTANCE);
            displayName = "Nearby Enemy Distance";
            tooltip = "Denies teleport action if the distance between enemies and the intended teleport location is less than this value in metres";
            control = QMGVAR(50To200Step50_Slider);
            expression = SCENARIO_EXPRESSION;
            validate = "number";
            defaultValue = "100";
        };
    };
};
