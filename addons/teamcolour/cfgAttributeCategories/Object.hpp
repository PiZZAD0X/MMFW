class GVAR(Category) {
    displayName = "Team Colour Options";
    collapsed = 1;
    class Attributes {
        class GVAR(Colour) {
            displayName = "Team Colour";
            tooltip = "Set Player Colour";
            property = QGVAR(Colour);
            control = QGVAR(ColourAttribute);
            typeName = "STRING";
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "'None'";
        };
    };
};
