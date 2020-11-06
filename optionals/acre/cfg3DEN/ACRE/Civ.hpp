class GVAR(RadioTypes_CAT_Civ) {
    displayName = "Radio Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(SR_type_Civ) {
            property = QGVAR(SR_type_Civ);
            displayName = "Short Range Radio Type";
            tooltip = "Sets the short range radio type for the side";
            control = QGVAR(SR_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(LR_type_Civ) {
            property = QGVAR(LR_type_Civ);
            displayName = "Long Range Radio Type";
            tooltip = "Sets the long range radio type for the side";
            control = QGVAR(LR_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(PK_type_Civ) {
            property = QGVAR(PK_type_Civ);
            displayName = "Long Range Pack Radio Type";
            tooltip = "Sets the long range pack radio type for the side";
            control = QGVAR(PK_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};

class GVAR(RADIONET_CAT_Civ) {
    displayName = "Radio Net Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(RADIONET_Enabled_Civ) {
            property = QGVAR(RADIONET_Enabled_Civ);
            displayName = "Enable Radio Net Channel Names";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(RADIONET_NAME1_Civ) {
            property = QGVAR(RADIONET_NAME1_Civ);
            displayName = "Channel 1 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 1'";
        };
        class GVAR(RADIONET_NAME2_Civ) {
            property = QGVAR(RADIONET_NAME2_Civ);
            displayName = "Channel 2 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 2'";
        };
        class GVAR(RADIONET_NAME3_Civ) {
            property = QGVAR(RADIONET_NAME3_Civ);
            displayName = "Channel 3 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 3'";
        };
        class GVAR(RADIONET_NAME4_Civ) {
            property = QGVAR(RADIONET_NAME4_Civ);
            displayName = "Channel 4 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 4'";
        };
        class GVAR(RADIONET_NAME5_Civ) {
            property = QGVAR(RADIONET_NAME5_Civ);
            displayName = "Channel 5 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'COY'";
        };
        class GVAR(RADIONET_NAME6_Civ) {
            property = QGVAR(RADIONET_NAME6_Civ);
            displayName = "Channel 6 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'CAS'";
        };
        class GVAR(RADIONET_NAME7_Civ) {
            property = QGVAR(RADIONET_NAME7_Civ);
            displayName = "Channel 7 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'FIRES'";
        };
    };
};

class GVAR(BABEL_CAT_Civ) {
    displayName = "Babel Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(BABEL_Enabled_Civ) {
            property = QGVAR(Babel_Enabled_Civ);
            displayName = "Enable Babel Languages";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_EN_Civ) {
            property = QGVAR(Babel_EN_Civ);
            displayName = "English";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(BABEL_RU_Civ) {
            property = QGVAR(Babel_RU_Civ);
            displayName = "Russian";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_FR_Civ) {
            property = QGVAR(Babel_FR_Civ);
            displayName = "French";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_AR_Civ) {
            property = QGVAR(Babel_AR_Civ);
            displayName = "Arabic";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_GK_Civ) {
            property = QGVAR(Babel_GK_Civ);
            displayName = "Greek";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_Custom_Civ) {
            property = QGVAR(Babel_Custom_Civ);
            displayName = "Custom Language";
            tooltip = "Define a custom language for this side";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(BABEL_Custom2_Civ) {
            property = QGVAR(Babel_Custom2_Civ);
            displayName = "Custom Language 2";
            tooltip = "Define a custom language for this side";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
