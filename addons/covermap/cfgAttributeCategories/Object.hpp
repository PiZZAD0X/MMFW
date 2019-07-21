class GVAR(UnitSettings) {
    displayName = "Cover Map Options";
    collapsed = 1;
    class Attributes {
        class GVAR(UnitAONameArray) {
            property = QGVAR(UnitAONameArray);
            displayName = "CoverMap AO List";
            tooltip = "List of AO Names that this unit can access via ace interact on map if CoverMap setting is enabled. Leave blank to disable.";
            control = "EditStringArray";
            condition = "ObjectControllable";
            expression = ENTITY_EXPRESSION;
            defaultValue = "[]";
        };
        class GVAR(UnitDefaultAO) {
            property = QGVAR(UnitDefaultAO);
            displayName = "CoverMap Default AO";
            tooltip = "AO that the unit will be set to upon mission start. Leave blank to set AO to side default set in the module settings.";
            control = QEGVAR(3DEN,EditShortPlayerOnlyCategory);
            validate = "STRING";
            condition = "ObjectControllable";
            expression = ENTITY_EXPRESSION;
            defaultValue = "''";
        };
    };
};
