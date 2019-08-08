class GVAR(ColourCombo): Combo {
    attributeSave = QUOTE(_this call FUNC(ColourComboAttribute_AttrSave););
    attributeLoad = QUOTE([ARR_2(_this,_config)] call FUNC(ColourComboAttribute_AttrLoad););
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
            onLBSelChanged = QUOTE(_this call FUNC(ColourComboAttribute_onSelChange););
        };
    };
};
