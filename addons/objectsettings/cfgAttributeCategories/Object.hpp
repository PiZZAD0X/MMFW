class GVAR(Attributes) {
    displayName = "Drag and Carry Options";
    collapsed = 1;
    class Attributes {
        class GVAR(Carryable) {
            displayName = "ACE Carryable";
            tooltip = "Set the ability for players to use ACE carry actions on this object";
            property = QGVAR(Carryable);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "(1 - objectBrain) * (1 - objectVehicle)";
            defaultValue = "1";
        };
        class GVAR(Draggable) {
            displayName = "ACE Draggable";
            tooltip = "Set the ability for players to use ACE drag actions on this object";
            property = QGVAR(Draggable);
            control = "Checkbox";
            expression = ENTITY_EXPRESSION;
            condition = "(1 - objectBrain) * (1 - objectVehicle)";
            defaultValue = "1";
        };
    };
};
