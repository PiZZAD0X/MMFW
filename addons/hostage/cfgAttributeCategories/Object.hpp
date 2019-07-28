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
        class GVAR(RescueLocation) {
            displayName = "Hostage Rescue Zone";
            tooltip = "Determines the rescue area for the hostage";
            property = QGVAR(RescueLocation);
            control = GVAR(HostageAreaSelectAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'No Area Selected'";
        };
         class GVAR(FreedJoinSquad) {
            displayName = "Hostage Joins Squad";
            tooltip = "Determine if the hostage will join the squad of the player who frees them.";
            property = QGVAR(FreedJoinSquad);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "true";
        };
        class GVAR(FreedBehaviorModifier) {
            displayName = "Hostage Freed Behavior Change";
            tooltip = "Enable modifiers for hostage's behavior when they are freed.";
            property = QGVAR(FreedBehaviorModifier);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
        class GVAR(FreedBehavior) {
            displayName = "Hostage Freed Behavior";
            tooltip = "Determine the hostages behavior when freed by the player.\nWill not function unless 'Hostage Freed Modifiers' is enabled.";
            property = QGVAR(FreedBehavior);
            control = QGVAR(FreedBehaviorAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'Careless'";
        };
    };
};
