class GVAR(PresetsCombo_BLUFOR): ComboPreview {
    attributeSave = QUOTE(ARR_2(_this,_config)] call FUNC(GearPresetAttribute_AttrSave));
    attributeLoad = QUOTE(ARR_3(_this,_value,_config)] call FUNC(GearPresetAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
        };
        class Preview: Preview {
            idc = 101;
            onMouseButtonClick= QUOTE([ARR_2(_this,'BLUFOR')] call FUNC(GearPresetAttribute_onMouseClick));
        };
    };
};

class GVAR(PresetsCombo_OPFOR): GVAR(PresetsCombo_BLUFOR) {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
        class Preview: Preview {
            onMouseButtonClick= QUOTE([ARR_2(_this,'OPFOR')] call FUNC(GearPresetAttribute_onMouseClick));
        };
    };
};

class GVAR(PresetsCombo_Indfor): GVAR(PresetsCombo_BLUFOR) {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
        class Preview: Preview {
            onMouseButtonClick= QUOTE([ARR_2(_this,'INDFOR')] call FUNC(GearPresetAttribute_onMouseClick));
        };
    };
};

class GVAR(PresetsCombo_Civ): GVAR(PresetsCombo_BLUFOR) {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
        class Preview: Preview {
            onMouseButtonClick= QUOTE([ARR_2(_this,'CIVILIAN')] call FUNC(GearPresetAttribute_onMouseClick));
        };
    };
};
