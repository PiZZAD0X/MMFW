class GVAR(UnitSettings) {
    displayName = "Cover Map Options";
    collapsed = 1;
    class Attributes {
        class GVAR(UnitDefaultAO) {
            property = QGVAR(UnitDefaultAO);
            displayName = "CoverMap Default AO";
            tooltip = "AO that the unit will be set to upon mission start.";
            control = QGVAR(AreaSelectAttributePlayerOnly);
            validate = "STRING";
            condition = "ObjectControllable";
            expression = ENTITY_EXPRESSION;
            defaultValue = "'Side Default AO'";
        };
        class GVAR(UnitAONameArray) {
            property = QGVAR(UnitAONameArray);
            displayName = "CoverMap AO List";
            tooltip = "List of AOs that this unit can access via ace interact on map if CoverMap setting is enabled. Leave all unselected to enforce side default settings.";
            control = QGVAR(MultipleAreaSelectAttribute);
            condition = "ObjectControllable";
            expression = ENTITY_EXPRESSION;
            defaultValue = "[]";
        };
    };
};
