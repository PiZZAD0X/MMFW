class GVAR(UnitOptions) {
    displayName = "AI Options";
    collapsed = 1;
    class Attributes {
        class GVAR(UNITSETTINGS_Enable) {
            property = QGVAR(UNITSETTINGS_Enable);
            displayName = "Enable AI Unit Settings";
            tooltip = "Enables Framework AI Settings on this unit";
            control = QEGVAR(Core,CheckBoxStateAIOnlyCategory);
            expression = ENTITY_EXPRESSION;
            condition = "objectControllable";
            defaultValue = "false";
        };
    };
};
