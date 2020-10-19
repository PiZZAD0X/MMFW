class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(SetupTimerModule): EGVAR(Core,BaseModule) {
        displayName = "Setup Timer Module"; // Name displayed in the menu
        scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
        // Name of function triggered once conditions are met
        function = QFUNC(Module);
        // Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 1;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        icon = QPATHTOF(resources\setuptimermodule_ca.paa);

        class AttributeValues {
            size3[] = {100, 100, -1};
            IsRectangle = 0;
        };

        // Categories collapsible in "Edit Attributes" window
        // Category class, can be anything
        class Attributes {
            class GVAR(SideSelect) {
                displayName = "Side";
                tooltip = "Side restricted to the setup area.";
                control = "Combo";
                typeName = "NUMBER";
                property = QGVAR(SideSelect);
                expression = MODULE_EXPRESSION;
                validate = "none";
                class values {
                    class West {name = "West"; value = 0; default = 0;};
                    class East {name = "East"; value = 1;};
                    class Ind {name = "Independent"; value = 2;};
                    class Civ {name = "Civilian"; value = 3;};
                };
                defaultValue = "0";
            };
            class GVAR(Time) {
                // Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
                displayName = "Time"; // Attribute label
                tooltip = "Time in seconds";
                control = QEGVAR(Core,30To900Step1_Slider);
                property = QGVAR(Time);
                defaultValue = "30"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
                typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
                expression = MODULE_EXPRESSION;
                validate = "number";
            };
        };
    };

    class GVAR(SetupTimerModule_R): GVAR(SetupTimerModule) {
        scope = 0;
        displayName = "Setup Timer Module (Rectangle)"; // Name displayed in the menu
        class AttributeValues {
            IsRectangle = 1;
        };
    };
};
