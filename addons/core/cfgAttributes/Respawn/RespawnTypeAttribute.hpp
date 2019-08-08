#define RESPAWNCOMBO_ATTR_LOAD(VALUEVAR,CFGVAR) \
attributeLoad = QUOTE([ARR_5(_this,_value,_config,QN(CFGVAR),QN(VALUEVAR))] call FUNC(RespawnCombo_AttrLoad))

#define RESPAWNCOMBO_ATTR_SAVE(VALUEVAR,CFGVAR) \
attributeSave = QUOTE([ARR_4(_this,_config,QN(CFGVAR),QN(VALUEVAR))] call FUNC(RespawnCombo_AttrSave))

#define RESPAWNCOMBO_ONLOAD(VALUEVAR,CFGVAR) \
onLoad = QUOTE([ARR_3(_this,QN(CFGVAR),QN(VALUEVAR))] call FUNC(RespawnCombo_onLoad))

#define RESPAWNCOMBO_ONLBSELCHANGED(VALUEVAR,CFGVAR) \
onLBSelChanged = QUOTE([ARR_3(_this,QN(CFGVAR),QN(VALUEVAR))] call FUNC(RespawnCombo_onLBSelChanged))

#define RESPAWNTEMPLATES_ATTR_LOAD(VALUEVAR) \
attributeLoad = QUOTE([ARR_3(_this,_value,QN(VALUEVAR))] call FUNC(respawntemplates_attr_load))

#define RESPAWNTEMPLATES_ATTR_SAVE \
attributeSave = QUOTE(_this call FUNC(respawntemplates_attr_save))

#define RESPAWNTEMPLATES_ATTR_ONLBSELCHANGED \
onLBSelChanged = QUOTE(_this call FUNC(RespawnTemplates_onLBSelChanged))

#define RESPAWNTEMPLATES_ATTR_ONSETFOCUS(VALUEVAR) \
onSetFocus = QUOTE([ARR_2(_this,QN(VALUEVAR))] call FUNC(RespawnTemplates_onSetFocus))

#define RESPAWNCOMBO_ATTR_VALUES \
class Value1: Value0 { idc = 101; };\
class Value2: Value0 { idc = 102; };\
class Value3: Value0 { idc = 103; };\
class Value4: Value0 { idc = 104; };\
class Value5: Value0 { idc = 105; };\
class Value6: Value0 { idc = 106; };\
class Value7: Value0 { idc = 107; }

class EGVAR(Respawn,Combo_Blufor): Combo {
    RESPAWNCOMBO_ATTR_LOAD(EGVAR(Respawn,Value_Blufor),EGVAR(Respawn,ComboCfg_Blufor));
    RESPAWNCOMBO_ATTR_SAVE(EGVAR(Respawn,Value_Blufor),EGVAR(Respawn,ComboCfg_Blufor));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            RESPAWNCOMBO_ONLOAD(EGVAR(Respawn,Value_Blufor),EGVAR(Respawn,ComboCfg_Blufor));
            RESPAWNCOMBO_ONLBSELCHANGED(EGVAR(Respawn,Value_Blufor),EGVAR(Respawn,ComboCfg_Blufor));
        };
    };
};

class EGVAR(Respawn,Templates_Blufor): Title {
    RESPAWNTEMPLATES_ATTR_LOAD(EGVAR(Respawn,Value_Blufor));
    RESPAWNTEMPLATES_ATTR_SAVE;
    h="8 * 5 * (pixelH * pixelGrid * 0.50)";
    class Controls: Controls {
        class Title: Title {
            h="8 * 5 * (pixelH * pixelGrid * 0.50)";
        };
        class Value0: ctrlListbox {
            idc = 100;
            show=0;
            x="48 * (pixelW * pixelGrid * 0.50)";
            w="82 * (pixelW * pixelGrid * 0.50)";
            h="8 * 5 * (pixelH * pixelGrid * 0.50)";
            colorSelectBackground[]={0,0,0,0};
            colorSelectBackground2[]={0,0,0,0};
            RESPAWNTEMPLATES_ATTR_ONLBSELCHANGED;
            RESPAWNTEMPLATES_ATTR_ONSETFOCUS(EGVAR(Respawn,Value_Blufor));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Opfor): EGVAR(Respawn,Combo_Blufor) {
    RESPAWNCOMBO_ATTR_LOAD(EGVAR(Respawn,Value_Opfor),EGVAR(Respawn,ComboCfg_Opfor));
    RESPAWNCOMBO_ATTR_SAVE(EGVAR(Respawn,Value_Opfor),EGVAR(Respawn,ComboCfg_Opfor));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            RESPAWNCOMBO_ONLOAD(EGVAR(Respawn,Value_Opfor),EGVAR(Respawn,ComboCfg_Opfor));
            RESPAWNCOMBO_ONLBSELCHANGED(EGVAR(Respawn,Value_Opfor),EGVAR(Respawn,ComboCfg_Opfor));
        };
    };
};

class EGVAR(Respawn,Templates_Opfor): EGVAR(Respawn,Templates_Blufor) {
    RESPAWNTEMPLATES_ATTR_LOAD(EGVAR(Respawn,Value_Opfor));
    RESPAWNTEMPLATES_ATTR_SAVE;
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            RESPAWNTEMPLATES_ATTR_ONLBSELCHANGED;
            RESPAWNTEMPLATES_ATTR_ONSETFOCUS(EGVAR(Respawn,Value_Opfor));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Indfor): EGVAR(Respawn,Combo_Blufor) {
    RESPAWNCOMBO_ATTR_LOAD(EGVAR(Respawn,Value_Indfor),EGVAR(Respawn,ComboCfg_Indfor));
    RESPAWNCOMBO_ATTR_SAVE(EGVAR(Respawn,Value_Indfor),EGVAR(Respawn,ComboCfg_Indfor));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            RESPAWNCOMBO_ONLOAD(EGVAR(Respawn,Value_Indfor),EGVAR(Respawn,ComboCfg_Indfor));
            RESPAWNCOMBO_ONLBSELCHANGED(EGVAR(Respawn,Value_Indfor),EGVAR(Respawn,ComboCfg_Indfor));
        };
    };
};

class EGVAR(Respawn,Templates_Indfor): EGVAR(Respawn,Templates_Blufor) {
    RESPAWNTEMPLATES_ATTR_LOAD(EGVAR(Respawn,Value_Indfor));
    RESPAWNTEMPLATES_ATTR_SAVE;
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            RESPAWNTEMPLATES_ATTR_ONLBSELCHANGED;
            RESPAWNTEMPLATES_ATTR_ONSETFOCUS(EGVAR(Respawn,Value_Indfor));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Civ): EGVAR(Respawn,Combo_Blufor) {
    RESPAWNCOMBO_ATTR_LOAD(EGVAR(Respawn,Value_Civ),EGVAR(Respawn,ComboCfg_Civ));
    RESPAWNCOMBO_ATTR_SAVE(EGVAR(Respawn,Value_Civ),EGVAR(Respawn,ComboCfg_Civ));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            RESPAWNCOMBO_ONLOAD(EGVAR(Respawn,Value_Civ),EGVAR(Respawn,ComboCfg_Civ));
            RESPAWNCOMBO_ONLBSELCHANGED(EGVAR(Respawn,Value_Civ),EGVAR(Respawn,ComboCfg_Civ));
        };
    };
};

class EGVAR(Respawn,Templates_Civ): EGVAR(Respawn,Templates_Blufor) {
    RESPAWNTEMPLATES_ATTR_LOAD(EGVAR(Respawn,Value_Civ));
    RESPAWNTEMPLATES_ATTR_SAVE;
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            RESPAWNTEMPLATES_ATTR_ONLBSELCHANGED;
            RESPAWNTEMPLATES_ATTR_ONSETFOCUS(EGVAR(Respawn,Value_Civ));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};
