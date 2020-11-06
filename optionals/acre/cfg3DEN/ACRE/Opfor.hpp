class GVAR(RadioTypes_CAT_OPFOR) {
    displayName = "Radio Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(SR_type_OPFOR) {
            property = QGVAR(SR_type_OPFOR);
            displayName = "Short Range Radio Type";
            tooltip = "Sets the short range radio type for the side";
            control = QGVAR(SR_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(LR_type_OPFOR) {
            property = QGVAR(LR_type_OPFOR);
            displayName = "Long Range Radio Type";
            tooltip = "Sets the long range radio type for the side";
            control = QGVAR(LR_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
        class GVAR(PK_type_OPFOR) {
            property = QGVAR(PK_type_OPFOR);
            displayName = "Long Range Pack Radio Type";
            tooltip = "Sets the long range pack radio type for the side";
            control = QGVAR(PK_SELECT);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "0";
        };
    };
};

class GVAR(RADIONET_CAT_OPFOR) {
    displayName = "Radio Net Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(RADIONET_Enabled_OPFOR) {
            property = QGVAR(RADIONET_Enabled_OPFOR);
            displayName = "Enable Radio Net Channel Names";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(RADIONET_NAME1_OPFOR) {
            property = QGVAR(RADIONET_NAME1_OPFOR);
            displayName = "Channel 1 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 1'";
        };
        class GVAR(RADIONET_NAME2_OPFOR) {
            property = QGVAR(RADIONET_NAME2_OPFOR);
            displayName = "Channel 2 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 2'";
        };
        class GVAR(RADIONET_NAME3_OPFOR) {
            property = QGVAR(RADIONET_NAME3_OPFOR);
            displayName = "Channel 3 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 3'";
        };
        class GVAR(RADIONET_NAME4_OPFOR) {
            property = QGVAR(RADIONET_NAME4_OPFOR);
            displayName = "Channel 4 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'PLTNET 4'";
        };
        class GVAR(RADIONET_NAME5_OPFOR) {
            property = QGVAR(RADIONET_NAME5_OPFOR);
            displayName = "Channel 5 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'COY'";
        };
        class GVAR(RADIONET_NAME6_OPFOR) {
            property = QGVAR(RADIONET_NAME6_OPFOR);
            displayName = "Channel 6 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'CAS'";
        };
        class GVAR(RADIONET_NAME7_OPFOR) {
            property = QGVAR(RADIONET_NAME7_OPFOR);
            displayName = "Channel 7 Name";
            tooltip = "Sets the name of the channel";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "'FIRES'";
        };
    };
};

class GVAR(BABEL_CAT_OPFOR) {
    displayName = "Babel Configuration";
    collapsed = 0;
    class Attributes {
        class GVAR(BABEL_Enabled_OPFOR) {
            property = QGVAR(Babel_Enabled_OPFOR);
            displayName = "Enable Babel Languages";
            control = "CheckBoxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_EN_OPFOR) {
            property = QGVAR(Babel_EN_OPFOR);
            displayName = "English";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(BABEL_RU_OPFOR) {
            property = QGVAR(Babel_RU_OPFOR);
            displayName = "Russian";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_FR_OPFOR) {
            property = QGVAR(Babel_FR_OPFOR);
            displayName = "French";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_AR_OPFOR) {
            property = QGVAR(Babel_AR_OPFOR);
            displayName = "Arabic";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_GK_OPFOR) {
            property = QGVAR(Babel_GK_OPFOR);
            displayName = "Greek";
            tooltip = "Enables the language for this side";
            control = "CheckBox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(BABEL_Custom_OPFOR) {
            property = QGVAR(Babel_Custom_OPFOR);
            displayName = "Custom Language";
            tooltip = "Define a custom language for this side";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class GVAR(BABEL_Custom2_OPFOR) {
            property = QGVAR(Babel_Custom2_OPFOR);
            displayName = "Custom Language 2";
            tooltip = "Define a custom language for this side";
            control = "EditShort";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
