class EGVAR(EndConditions,ExtractModule): GVAR(BaseModule) {
    displayName = "Extraction Area";
    scope = 2;
    function = QFUNC(ExtractAreaModule);
    isGlobal = 1;
    isTriggerActivated = 0;
    isDisposable = 0;
    is3DEN = 1;
    canSetArea = 1;
    canSetAreaShape = 1;
    class AttributeValues {
        size3[] = {100, 100, -1};
        IsRectangle = 0;
    };

    class Attributes {
        class EGVAR(EndConditions,AreaName) {
            displayName = "Area Name";
            tooltip = "Area displayed in referenced in End Conditions settings";
            control = "EditShort";
            typeName = "STRING";
            unique = 1;
            property = QEGVAR(EndConditions,AreaName);
            expression = MODULE_EXPRESSION;
            validate = "STRING";
            defaultValue = "'ExtractArea0'";
        };
    };
};

class EGVAR(EndConditions,ExtractModule_R): EGVAR(EndConditions,ExtractModule) {
    scope = 0;
    displayName = "Extraction Area (Rectangle)";
    class AttributeValues {
        IsRectangle = 1;
    };
};
