#define STARTTEXTTEAMATTR(TEAMNAMEVAR) class GVAR(DOUBLES(TitleQuote,TEAMNAMEVAR)) {\
    displayName = QUOTE(TEAMNAMEVAR Title Quote);\
    tooltip = QUOTE(Title Quote of the TEAMNAMEVAR Start Text. Empty for none);\
    control = "Edit";\
    property = QGVAR(DOUBLES(TitleQuote,TEAMNAMEVAR));\
    defaultValue = "''";\
    typeName = "STRING";\
    expression = SCENARIO_EXPRESSION;\
    validate = "none";\
};\
class GVAR(DOUBLES(Text,TEAMNAMEVAR)) {\
    displayName = QUOTE(TEAMNAMEVAR Text);\
    tooltip = QUOTE(Text of the TEAMNAMEVAR Start Text. Empty for none);\
    control = "Edit";\
    property = QGVAR(DOUBLES(Text,TEAMNAMEVAR));\
    defaultValue = "''";\
    typeName = "STRING";\
    expression = SCENARIO_EXPRESSION;\
    validate = "none";\
}

class GVAR(Category) {
    displayName = "Start Text Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
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
        STARTTEXTTEAMATTR(Blufor);
        STARTTEXTTEAMATTR(Opfor);
        STARTTEXTTEAMATTR(Indfor);
        STARTTEXTTEAMATTR(Civilian);
    };
};
