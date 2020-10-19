class CfgVehicles {
    class EGVAR(Core,BaseModule);
    class GVAR(AOLimitModule): EGVAR(Core,BaseModule) {
        displayName = "AO Limit Module";
        scope = 2;
        function = QFUNC(Module);
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 1;
        canSetArea = 1;
        canSetAreaShape = 1;
        icon = QPATHTOF(resources\aolimitmodule_ca.paa);

        class AttributeValues {
            size3[] = {100,100,-1};
            IsRectangle = 0;
        };

        class Attributes {
            class GVAR(Description) {
                description = "AO Limit modules prevent players from leaving the module area if their team is enabled.";
                control = "StructuredText1";
            };
            class GVAR(AOMode) {
                displayName = "AO Mode";
                tooltip = "Set the AO as a Soft AO that gives players time to return to the area before killing them, or a hard AO which forces the player inside the AO.";
                property = QGVAR(AOMode);
                control = QGVAR(AOModeAttribute);
                typeName = "STRING";
                expression = MODULE_EXPRESSION;
                defaultValue = "'HARD'";
            };
            class GVAR(TeamsEnabled) {
                displayName = "Teams";
                tooltip = "Teams restricted by the AO Limit.";
                property = QGVAR(TeamsEnabled);
                control = QGVAR(TeamsAttribute);
                expression = MODULE_EXPRESSION;
                defaultValue = "['BLUFOR','OPFOR','INDFOR','CIVILIAN']";
            };
            class GVAR(EntryMode) {
                displayName = "Entry Restriction";
                tooltip = "Enable to restrict players within AO if they spawned outside the area but entered it.";
                property = QGVAR(EntryMode);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "false";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(AirUnits) {
                displayName = "Air unit exemption";
                tooltip = "Enable to exempt air units from AO restriction. Default: true";
                property = QGVAR(AirUnits);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(SoftTimeOutside) {
                displayName = "Max time outside of AO";
                tooltip = "The amount of time in seconds a land based unit is allowed to stay outside the AO";
                property = QGVAR(SoftTimeOutside);
                control = QEGVAR(Core,30To120Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                AOTypes[] = {"SOFT"};
                typeName = "number";
                validate = "number";
            };
            class GVAR(SoftTimeOutsideAir) {
                displayName = "Max air time outside of AO";
                tooltip = "The amount of time in seconds an air based unit is allowed to stay outside the AO";
                property = QGVAR(SoftTimeOutsideAir);
                control = QEGVAR(Core,120To360Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "120";
                AOTypes[] = {"SOFT"};
                typeName = "number";
                validate = "number";
            };
        };
    };

    class GVAR(AOLimitModule_R) : GVAR(AOLimitModule) {
        scope = 0;
        displayName = "AO Limit Module (Rectangle)"; // Name displayed in the menu
        class AttributeValues {
            size3[] = {100,100,-1};
            IsRectangle = 1;
        };
    };
};
