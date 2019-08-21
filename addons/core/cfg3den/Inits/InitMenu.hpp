class GVAR(GlobalInitSettings) {
    displayName = "Global Init Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(GlobalPreInit) {
            property = QGVAR(GlobalPreInit);
            displayName = "PreInit";
            tooltip = "PreInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(GlobalPostInit) {
            property = QGVAR(GlobalPostInit);
            displayName = "PostInit";
            tooltip = "PostInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};

class GVAR(ServerInitSettings) {
    displayName = "Server Init Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(ServerPreInit) {
            property = QGVAR(ServerPreInit);
            displayName = "PreInit";
            tooltip = "PreInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(ServerPostInit) {
            property = QGVAR(ServerPostInit);
            displayName = "PostInit";
            tooltip = "PostInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};

class GVAR(SideInitSettings) {
    displayName = "Side Init Settings";
    collapsed = 0;
    class Attributes {
        class GVAR(BluforPostInit) {
            property = QGVAR(BluforPostInit);
            displayName = "PostInit";
            tooltip = "PostInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(OpforPostInit) {
            property = QGVAR(OpforPostInit);
            displayName = "PostInit";
            tooltip = "PostInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(IndforPostInit) {
            property = QGVAR(IndforPostInit);
            displayName = "PostInit";
            tooltip = "PostInit";
            control = "EditCodeMulti5";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
