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
    defaultValue = QUOTE(QN(NONE));\
}

#define GEAR3DENTEAMENTRY(TEAMNAME) class GVAR(DOUBLES(Menu,TEAMNAME)) {\
    displayName = QUOTE(TEAMNAME Gear Settings);\
    class AttributeCategories {\
        class GVAR(DOUBLES(Presets,TEAMNAME)) {\
            displayName = QUOTE(TEAMNAME Gear Presets);\
            collapsed = 1;\
            class Attributes {\
                class GVAR(DOUBLES(ACE_Arsenal_GearPresets,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(ACE_Arsenal_GearPresets,TEAMNAME));\
                    displayName = "Gear Presets";\
                    tooltip = "";\
                    control = QGVAR(DOUBLES(PresetsCombo,TEAMNAME));\
                    typeName = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "'None'";\
                };\
            };\
        };\
        class GVAR(DOUBLES(ACE_Arsenal,TEAMNAME)) {\
            displayName = QUOTE(TEAMNAME ACE Gear Settings);\
            collapsed = 1;\
            class Attributes {\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,SQL);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,TL);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,RFL);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,RFLAT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,AR);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,GRN);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,VCRW);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,VCMD);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,OFF);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,TWOIC);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,MED);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,AT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,AAT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,MG);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,AMG);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,MKS);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,RTO);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,FAC);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,FO);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,ENG);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,EOD);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,HAT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,AHAT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,MORTL);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,MOR);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,APLT);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,ACRW);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,CUS1);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,CUS2);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,CUS3);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,CUS4);\
                GEAR_TYPECONFIG_ACEAR(TEAMNAME,CUS5);\
            };\
        };\
        class GVAR(DOUBLES(Olsen,TEAMNAME)) {\
            displayName = QUOTE(TEAMNAME Olsen Gear Settings);\
            collapsed = 1;\
            class Attributes {\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,SQL);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,TL);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,RFL);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,RFLAT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,AR);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,GRN);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,VCRW);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,VCMD);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,OFF);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,TWOIC);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,MED);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,AT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,AAT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,MG);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,AMG);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,MKS);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,RTO);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,FAC);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,FO);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,ENG);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,EOD);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,HAT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,AHAT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,MORTL);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,MOR);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,APLT);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,ACRW);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,CUS1);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,CUS2);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,CUS3);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,CUS4);\
                GEAR_TYPECONFIG_OLSEN(TEAMNAME,CUS5);\
            };\
        };\
    };\
}

GEAR3DENTEAMENTRY(Blufor);
GEAR3DENTEAMENTRY(Opfor);
GEAR3DENTEAMENTRY(Indfor);
GEAR3DENTEAMENTRY(Civilian);
