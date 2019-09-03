#define COVERMAPTEAMATTR(TEAMNAMEVAR) class GVAR(DOUBLES(DefaultAO,TEAMNAMEVAR)) {\
    property = QGVAR(DOUBLES(DefaultAO,TEAMNAMEVAR));\
    displayName = QUOTE(TEAMNAMEVAR Starting AO);\
    tooltip = QUOTE(Set the TEAMNAMEVAR Map area to corresponding CoverMap AO name.);\
    control = GVAR(AreaSelectAttribute);\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = "'No Area Selected'";\
    validate = "STRING";\
};\
class GVAR(DOUBLES(DefaultAOList,TEAMNAMEVAR)) {\
    property = QGVAR(DOUBLES(DefaultAOList,TEAMNAMEVAR));\
    displayName = QUOTE(TEAMNAMEVAR Default AOs);\
    tooltip = "Determines the default AOs units can switch between";\
    control = GVAR(MultipleAreaSelectAttribute);\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = "[]";\
}

class GVAR(Category) {
    displayName = "Cover Map Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Enable Cover Map Module";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(AllowSwitching) {
            property = QGVAR(AllowSwitching);
            displayName = "Allow Map AO Switching";
            tooltip = "Allow players to switch AOs their character has defined via ace interaction in the map";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        COVERMAPTEAMATTR(Blufor);
        COVERMAPTEAMATTR(Opfor);
        COVERMAPTEAMATTR(Indfor);
        COVERMAPTEAMATTR(Civilian);
    };
};
