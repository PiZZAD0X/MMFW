class GVAR(ColourCombo): Combo {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(ColourComboAttribute_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(ColourComboAttribute_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
            onLBSelChanged = QUOTE(_this call FUNC(ColourComboAttribute_onSelChange););
        };
    };
};
