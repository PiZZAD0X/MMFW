class GVAR(Attributes) {
    displayName = "Hostage Options";
    collapsed = 1;
    class Attributes {
        class GVAR(State) {
            displayName = "Hostage";
            tooltip = "Makes this unit a hostage that starts bound/captive and must be rescued via player action.";
            property = QGVAR(State);
            control = "CheckboxState";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
        class GVAR(Rescue_Location) {
            displayName = "Hostage Rescue Zone";
            tooltip = "Marker that determines the hostage rescue zone. (Default: 'hostage_rescue' marker)";
            property = QGVAR(Rescue_Location);
            control = GVAR(HostageAreaSelectAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'No Area Selected'";
        };
         class GVAR(Freed_JoinSquad) {
            displayName = "Hostage Joins Squad";
            tooltip = "Determine if the hostage will join the squad of the player who frees them. (Default: true)";
            property = QGVAR(Freed_JoinSquad);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "true";
        };
        class GVAR(Freed_Behavior_Modifier) {
            displayName = "Hostage Freed Behavior Change";
            tooltip = "Enable modifiers for hostage's behavior when they are freed. (False by default.)";
            property = QGVAR(Freed_Behavior_Modifier);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
        class GVAR(Freed_Behavior) {
            displayName = "Hostage Freed Behavior";
            tooltip = "Determine the hostages behavior when freed by the player.\nWill not function unless 'Hostage Freed Modifiers' is enabled. (Default: CARELESS)";
            property = QGVAR(Freed_Behavior);
            control = QGVAR(FreedBehaviorAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'Careless'";
        };
    };
};
