class EGVAR(Hostage,Attributes) {
    displayName = "Hostage Options";
    collapsed = 1;
    class Attributes {
        class EGVAR(Hostage,State) {
            displayName = "Hostage";
            tooltip = "Makes this unit a hostage that starts bound/captive and must be rescued via player action.";
            property = QEGVAR(Hostage,State);
            control = "CheckboxState";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
        class EGVAR(Hostage,Rescue_Location) {
            displayName = "Hostage Rescue Zone";
            tooltip = "Marker that determines the hostage rescue zone. (Default: 'hostage_rescue' marker)";
            property = QEGVAR(Hostage,Rescue_Location);
            control = "EditShort";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'hostage_rescue'";
        };
         class EGVAR(Hostage,Freed_JoinSquad) {
            displayName = "Hostage Joins Squad";
            tooltip = "Determine if the hostage will join the squad of the player who frees them. (Default: true)";
            property = QEGVAR(Hostage,Freed_JoinSquad);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "true";
        };
        class EGVAR(Hostage,Freed_Behavior_Modifier) {
            displayName = "Hostage Freed Behavior Change";
            tooltip = "Enable modifiers for hostage's behavior when they are freed. (False by default.)";
            property = QEGVAR(Hostage,Freed_Behavior_Modifier);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
        class EGVAR(Hostage,Freed_Behavior) {
            displayName = "Hostage Freed Behavior";
            tooltip = "Determine the hostages behavior when freed by the player.\nWill not function unless 'Hostage Freed Modifiers' is enabled. (Default: CARELESS)";
            property = QEGVAR(Hostage,Freed_Behavior);
            control = QEGVAR(Hostage,FreedBehaviorAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'Careless'";
        };
    };
};
