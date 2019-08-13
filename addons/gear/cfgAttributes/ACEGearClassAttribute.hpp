class GVAR(ACE_Arsenal_LoadoutClassCombo): Combo {
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(ACEGearClassAttribute_AttrSave));
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(ACEGearClassAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
            onLBSelChanged = QUOTE(_this call FUNC(ACEGearClassAttribute_onSelChange));
        };
    };
};
