class GVAR(Category)  {
    displayName = "Start in Parachute Options";
    collapsed = 1;
    class Attributes  {
        class GVAR(Type) {
            displayName = "Start in Parachute";
            tooltip = "Set Parachute Type of a unit";
            property = QGVAR(Type);
            control = QGVAR(TypeAttribute);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "0";
        };
        class GVAR(Altitude) {
            displayName = "Parachute Altitude";
            tooltip = "Altitude at which unit is parachuted";
            property = QGVAR(Altitude);
            control = QMGVAR(100To1000Step100_Slider);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            validate = "number";
            defaultValue = "300";
        };
        class GVAR(RandomAltitude) {
            displayName = "Parachute Randomized Altitude";
            tooltip = "Adds a random height to the normal parachute altitude";
            property = QGVAR(RandomAltitude);
            control = QMGVAR(100To500Step100_Slider);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            validate = "number";
            defaultValue = "100";
        };
    };
};
