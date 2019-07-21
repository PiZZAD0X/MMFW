class GVAR(Category) {
    displayName = "Start Text Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Start Text";
            tooltip = "Enables Start Text";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(TimeSelect) {
            displayName = "Time display";
            tooltip = "What kind of Time should be displayed. Default Date and Time";
            control = "Combo";
            typeName = "NUMBER";
            property = QGVAR(TimeSelect);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            class values {
                class Date {name = "Date"; value = 0;};
                class Time {name = "Time"; value = 1;};
                class DateTime {name = "Date and Time"; value = 2; default = 2;};
            };
            defaultValue = "2";
        };
        class GVAR(TitleQuote_Blufor) {
            displayName = "Blufor Title Quote";
            tooltip = "Title Quote of the Blufor Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(TitleQuote_Blufor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(Text_Blufor) {
            displayName = "Blufor Text";
            tooltip = "Text of the Blufor Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(Text_Blufor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(TitleQuote_Opfor) {
            displayName = "Opfor Title Quote";
            tooltip = "Title Quote of the Opfor Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(TitleQuote_Opfor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(Text_Opfor) {
            displayName = "Opfor Text";
            tooltip = "Text of the Opfor Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(Text_Opfor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(TitleQuote_Indfor) {
            displayName = "Independent Title Quote";
            tooltip = "Title Quote of the Independent Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(TitleQuote_Indfor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(Text_Indfor) {
            displayName = "Independent Text";
            tooltip = "Text of the Independent Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(Text_Indfor);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(TitleQuote_Civ) {
            displayName = "Civilian Title Quote";
            tooltip = "Title Quote of the Civilian Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(TitleQuote_Civ);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
        class GVAR(Text_Civ) {
            displayName = "Civilian Text";
            tooltip = "Text of the Civilian Start Text. Empty for none";
            control = "Edit";
            property = QGVAR(Text_Civ);
            defaultValue = "''";
            typeName = "STRING";
            expression = SCENARIO_EXPRESSION;
            validate = "none";
        };
    };
};
