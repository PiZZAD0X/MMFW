class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(Module): EGVAR(Core,BaseModule) {
        displayName = "Cover Map Module"; // Name displayed in the menu
        scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
        // Name of function triggered once conditions are met
        function = QFUNC(Module);
        // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 1;
        canSetArea = 1;

        class AttributeValues {
            size3[] = {100, 100, -1};
            IsRectangle = 1;
        };

        // Categories collapsible in "Edit Attributes" window
        // Category class, can be anything
        class Attributes {
            class GVAR(AOName) {
                displayName = "AO Name";
                tooltip = "AO name displayed in ace actions and referenced in module settings";
                control = "EditShort";
                typeName = "STRING";
                property = QGVAR(AOName);
                expression = MODULE_EXPRESSION;
                validate = "STRING";
                defaultValue = "'Area0'";
            };
            class GVAR(ZoomLevel) {
                displayName = "Zoomlevel";
                tooltip = "Map zoom level of the AO. Default: 0.2";
                property = QGVAR(ZoomLevel);
                control = "EditShort";
                expression = MODULE_EXPRESSION;
                defaultValue = "0.2";
                typeName = "NUMBER";
                validate = "number";
            };
        };
    };
};
