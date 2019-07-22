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
        icon = QPATHTOF(resources\aolimitmodule_ca.paa);

        class AttributeValues {
            size3[] = {100,100,-1};
            IsRectangle = 0;
        };

        class Attributes {
            class GVAR(AOMode) {
                displayName = "AO Mode";
                tooltip = "Set the AO as a Soft AO that gives players time to return to the area before killing them, or a hard AO which forces the player inside the AO.";
                property = QGVAR(AOMode);
                control = QGVAR(AOModeAttribute);
                typeName = "STRING";
                expression = MODULE_EXPRESSION;
                defaultValue = "'HARD'";
            };
            class GVAR(Blufor) {
                displayName = "Blufor";
                tooltip = "Restrict Blufor to this AO. Units that start outside of the AO will be not be restricted.";
                property = QGVAR(Blufor);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Opfor) {
                displayName = "Opfor";
                tooltip = "Restrict Opfor to this AO. Units that start outside of the AO will be not be restricted.";
                property = QGVAR(Opfor);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Indfor) {
                displayName = "Indfor";
                tooltip = "Restrict Indfor to this AO. Units that start outside of the AO will be not be restricted.";
                property = QGVAR(Indfor);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
                typeName = "BOOL";
                validate = "none";
            };
            class GVAR(Civilian) {
                displayName = "Civilian";
                tooltip = "Restrict Civilian to this AO. Units that start outside of the AO will be not be restricted.";
                property = QGVAR(CIV);
                control = "CheckBox";
                expression = MODULE_EXPRESSION;
                defaultValue = "true";
                typeName = "BOOL";
                validate = "none";
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
                control = QMGVAR(30To120Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "30";
                AOTypes[] = {"SOFT"};
                typeName = "number";
                validate = "number";
            };
            class GVAR(SoftTimeOutsideAir) {
                displayName = "Max time outside of AO";
                tooltip = "The amount of time in seconds an air based unit is allowed to stay outside the AO";
                property = QGVAR(SoftTimeOutsideAir);
                control = QMGVAR(120To360Step1_Slider);
                expression = MODULE_EXPRESSION;
                defaultValue = "120";
                AOTypes[] = {"SOFT"};
                typeName = "number";
                validate = "number";
            };
        };
    };

    class GVAR(AOLimitModule_R) : GVAR(AOLimitModule) {
        displayName = "AO Limit Module (Rectangle)"; // Name displayed in the menu
        class AttributeValues {
            size3[] = {100,100,-1};
            IsRectangle = 1;
        };
    };
};
