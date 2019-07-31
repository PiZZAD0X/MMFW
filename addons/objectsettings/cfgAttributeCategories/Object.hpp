class GVAR(Attributes) {
    displayName = "Drag and Carry Options";
    collapsed = 1;
    class Attributes {
        class GVAR(Carryable) {
            displayName = "ACE Carryable";
            tooltip = "Set the ability for players to use ACE carry actions on this object";
            property = QGVAR(Carryable);
            control = QGVAR(CarryAttribute);
            expression = QUOTE([ARR_2(_this, _value)] call FUNC(InitPostCarryable));
            condition = "(1 - objectBrain) * (1 - objectVehicle)";
            defaultValue = "(1)";
        };
        class GVAR(Draggable) {
            displayName = "ACE Draggable";
            tooltip = "Set the ability for players to use ACE drag actions on this object";
            property = QGVAR(Draggable);
            control = QGVAR(DragAttribute);
            expression = QUOTE([ARR_2(_this, _value)] call FUNC(InitPostDraggable));
            condition = "(1 - objectBrain) * (1 - objectVehicle)";
            defaultValue = "(1)";
        };
    };
};
