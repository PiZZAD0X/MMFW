#define RESPAWNCOMBO_ATTR_VALUES \
class Value1: Value0 { idc = 101; };\
class Value2: Value0 { idc = 102; };\
class Value3: Value0 { idc = 103; };\
class Value4: Value0 { idc = 104; };\
class Value5: Value0 { idc = 105; };\
class Value6: Value0 { idc = 106; };\
class Value7: Value0 { idc = 107; }

class EGVAR(Respawn,Combo_Blufor): Combo {
    attributeLoad = QUOTE([ARR_5(_this,_value,_config,QQEGVAR(Respawn,Value_Blufor),QQEGVAR(Respawn,ComboCfg_Blufor))] call FUNC(RespawnCombo_AttrLoad));
    attributeSave = QUOTE([ARR_4(_this,_config,QQEGVAR(Respawn,Value_Blufor),QQEGVAR(Respawn,ComboCfg_Blufor))] call FUNC(RespawnCombo_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLoad = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Blufor),QQEGVAR(Respawn,ComboCfg_Blufor))] call FUNC(RespawnCombo_onLoad));
            onLBSelChanged = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Blufor),QQEGVAR(Respawn,ComboCfg_Blufor))] call FUNC(RespawnCombo_onLBSelChanged));
        };
    };
};

class EGVAR(Respawn,Templates_Blufor): Title {
    attributeLoad = QUOTE([ARR_3(_this,_value,QQEGVAR(Respawn,Value_Blufor))] call FUNC(respawntemplates_attr_load));
    attributeSave = QUOTE(_this call FUNC(respawntemplates_attr_save));
    h = "8 * 5 * (pixelH * pixelGrid * 0.50)";
    class Controls: Controls {
        class Title: Title {
            h = "8 * 5 * (pixelH * pixelGrid * 0.50)";
        };
        class Value0: ctrlListbox {
            idc = 100;
            show = 0;
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "8 * 5 * (pixelH * pixelGrid * 0.50)";
            colorSelectBackground[] = {0,0,0,0};
            colorSelectBackground2[] = {0,0,0,0};
            onLBSelChanged = QUOTE(_this call FUNC(RespawnTemplates_onLBSelChanged));
            onSetFocus = QUOTE([ARR_2(_this,QQEGVAR(Respawn,Value_Blufor))] call FUNC(RespawnTemplates_onSetFocus));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Opfor): EGVAR(Respawn,Combo_Blufor) {
    attributeLoad = QUOTE([ARR_5(_this,_value,_config,QQEGVAR(Respawn,Value_Opfor),QQEGVAR(Respawn,ComboCfg_Opfor))] call FUNC(RespawnCombo_AttrLoad));
    attributeSave = QUOTE([ARR_4(_this,_config,QQEGVAR(Respawn,Value_Opfor),QQEGVAR(Respawn,ComboCfg_Opfor))] call FUNC(RespawnCombo_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLoad = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Opfor),QQEGVAR(Respawn,ComboCfg_Opfor))] call FUNC(RespawnCombo_onLoad));
            onLBSelChanged = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Opfor),QQEGVAR(Respawn,ComboCfg_Opfor))] call FUNC(RespawnCombo_onLBSelChanged));
        };
    };
};

class EGVAR(Respawn,Templates_Opfor): EGVAR(Respawn,Templates_Blufor) {
    attributeLoad = QUOTE([ARR_3(_this,_value,QQEGVAR(Respawn,Value_Opfor))] call FUNC(respawntemplates_attr_load));
    attributeSave = QUOTE(_this call FUNC(respawntemplates_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            onLBSelChanged = QUOTE(_this call FUNC(RespawnTemplates_onLBSelChanged));
            onSetFocus = QUOTE([ARR_2(_this,QQEGVAR(Respawn,Value_Opfor))] call FUNC(RespawnTemplates_onSetFocus));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Indfor): EGVAR(Respawn,Combo_Blufor) {
    attributeLoad = QUOTE([ARR_5(_this,_value,_config,QQEGVAR(Respawn,Value_Indfor),QQEGVAR(Respawn,ComboCfg_Indfor))] call FUNC(RespawnCombo_AttrLoad));
    attributeSave = QUOTE([ARR_4(_this,_config,QQEGVAR(Respawn,Value_Indfor),QQEGVAR(Respawn,ComboCfg_Indfor))] call FUNC(RespawnCombo_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLoad = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Indfor),QQEGVAR(Respawn,ComboCfg_Indfor))] call FUNC(RespawnCombo_onLoad));
            onLBSelChanged = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Indfor),QQEGVAR(Respawn,ComboCfg_Indfor))] call FUNC(RespawnCombo_onLBSelChanged));
        };
    };
};

class EGVAR(Respawn,Templates_Indfor): EGVAR(Respawn,Templates_Blufor) {
    attributeLoad = QUOTE([ARR_3(_this,_value,QQEGVAR(Respawn,Value_Indfor))] call FUNC(respawntemplates_attr_load));
    attributeSave = QUOTE(_this call FUNC(respawntemplates_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            onLBSelChanged = QUOTE(_this call FUNC(RespawnTemplates_onLBSelChanged));
            onSetFocus = QUOTE([ARR_2(_this,QQEGVAR(Respawn,Value_Indfor))] call FUNC(RespawnTemplates_onSetFocus));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};

class EGVAR(Respawn,Combo_Civ): EGVAR(Respawn,Combo_Blufor) {
    attributeLoad = QUOTE([ARR_5(_this,_value,_config,QQEGVAR(Respawn,Value_Civ),QQEGVAR(Respawn,ComboCfg_Civ))] call FUNC(RespawnCombo_AttrLoad));
    attributeSave = QUOTE([ARR_4(_this,_config,QQEGVAR(Respawn,Value_Civ),QQEGVAR(Respawn,ComboCfg_Civ))] call FUNC(RespawnCombo_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLoad = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Civ),QQEGVAR(Respawn,ComboCfg_Civ))] call FUNC(RespawnCombo_onLoad));
            onLBSelChanged = QUOTE([ARR_3(_this,QQEGVAR(Respawn,Value_Civ),QQEGVAR(Respawn,ComboCfg_Civ))] call FUNC(RespawnCombo_onLBSelChanged));
        };
    };
};

class EGVAR(Respawn,Templates_Civ): EGVAR(Respawn,Templates_Blufor) {
    attributeLoad = QUOTE([ARR_3(_this,_value,QQEGVAR(Respawn,Value_Civ))] call FUNC(respawntemplates_attr_load));
    attributeSave = QUOTE(_this call FUNC(respawntemplates_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value0: Value0 {
            onLBSelChanged = QUOTE(_this call FUNC(RespawnTemplates_onLBSelChanged));
            onSetFocus = QUOTE([ARR_2(_this,QQEGVAR(Respawn,Value_Civ))] call FUNC(RespawnTemplates_onSetFocus));
        };
        RESPAWNCOMBO_ATTR_VALUES;
    };
};
