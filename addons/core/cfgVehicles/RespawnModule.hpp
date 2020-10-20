class GVAR(RespawnModule): GVAR(BaseModule) {
    displayName = "Respawn Module";
    scope = 2;
    function = QFUNC(RespawnModule);
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
        class GVAR(HandleHeight) {
            displayName = "Handle Height";
            tooltip = "";
            property = QGVAR(HandleHeight);
            control = "CheckBox";
            expression = MODULE_EXPRESSION;
            defaultValue = "(false)";
        };
        class GVAR(Side) {
            displayName = "Side";
            tooltip = "";
            property = QGVAR(Side);
            control = QEGVAR(Respawn,Side_Combo);
            expression = MODULE_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(Cond) {
            displayName = "Custom Condition";
            tooltip = "Enter a custom condition that must be met for this zone to be captured. Default: true";
            property = QGVAR(Cond);
            control = "EditCode";
            expression = MODULE_EXPRESSION;
            defaultValue = "'true'";
        };
    };
};
