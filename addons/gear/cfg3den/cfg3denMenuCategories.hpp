class GVAR(Settings) {
    displayName = "Gear Settings";
    class AttributeCategories {
        #include "Gear\MainMenu.hpp"
    };
};

#define GEAR_TYPECONFIG_OLSEN(TEAMNAME,SHORTNAME)  \
class MMFW_Gear_Olsen_LoadoutType_##TEAMNAME##_##SHORTNAME {\
    property = QUOTE(TRIPLES(GVAR(Olsen_LoadoutType),TEAMNAME,SHORTNAME));\
    displayName = CSTRING_2(Gear_DisplayName,SHORTNAME);\
    tooltip = CSTRING_2(Gear_ToolTip_Olsen,SHORTNAME);\
    control = QUOTE(Edit);\
    typeName = QUOTE(STRING);\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = QUOTE('');\
}

#define GEAR_TYPECONFIG_ACEAR(TEAMNAME,SHORTNAME) \
class MMFW_Gear_ACE_Arsenal_LoadoutType_##TEAMNAME##_##SHORTNAME {\
    property = QUOTE(TRIPLES(GVAR(ACE_Arsenal_LoadoutType),TEAMNAME,SHORTNAME));\
    displayName = CSTRING_2(Gear_DisplayName,SHORTNAME);\
    tooltip = CSTRING_2(Gear_ToolTip_ACEAR,SHORTNAME);\
    control = QUOTE(TRIPLES(PREFIX,Gear,ACE_Arsenal_LoadoutClassCombo));\
    typeName = QUOTE(STRING);\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = QUOTE('NONE');\
}

class GVAR(Menu_Blufor) {
    displayName = "Blufor Gear Settings";
    class AttributeCategories {
        #include "Gear\BluforMenu.hpp"
    };
};

class GVAR(Menu_Opfor) {
    displayName = "Opfor Gear Settings";
    class AttributeCategories {
        #include "Gear\OpforMenu.hpp"
    };
};

class GVAR(Menu_Indfor) {
    displayName = "Indfor Gear Settings";
    class AttributeCategories {
        #include "Gear\IndforMenu.hpp"
    };
};

class GVAR(Menu_Civ) {
    displayName = "Civilian Gear Settings";
    class AttributeCategories {
        #include "Gear\CivilianMenu.hpp"
    };
};

class ace_arsenal_DummyCategory {
    displayName = "Dummy attribute, should never show up";
    class AttributeCategories {
        class ACE3_Arsenal {
            class Attributes {
                class ace_arsenal_DefaultLoadoutsListAttribute {
                    property = "ace_arsenal_DefaultLoadoutsListAttribute";
                    value = 0;
                    expression = "missionNamespace setvariable ['ace_arsenal_defaultLoadoutsList', _value, true];";
                    defaultValue = "[]";
                    validate = "none";
                    wikiType = "[[Array]]";
                };
            };
        };
    };
};
