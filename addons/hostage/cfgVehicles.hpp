class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(Module): EGVAR(Core,BaseModule) {
        displayName = "Hostage Rescue Area";
        scope = 2;
        function = QFUNC(Module);
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
            class GVAR(AreaName) {
                displayName = "Area Name";
                tooltip = "Area name displayed in referenced in module select";
                control = "EditShort";
                typeName = "STRING";
                unique = 1;
                property = QGVAR(AreaName);
                expression = MODULE_EXPRESSION;
                validate = "STRING";
                defaultValue = "'Area0'";
            };
        };
    };
    class GVAR(Module_R): GVAR(Module) {
        scope = 0;
        displayName = "Hostage Rescue Area (Rectangle)";
        class AttributeValues {
            size3[] = {100, 100, -1};
            IsRectangle = 1;
        };
    };
};
