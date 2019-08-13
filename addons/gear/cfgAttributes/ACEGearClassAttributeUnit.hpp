class GVAR(ACE_Arsenal_LoadoutClassComboUnit): Combo {
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(ACEGearClassAttributeUnit_AttrSave));
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(ACEGearClassAttributeUnit_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
            onLBSelChanged = QUOTE(_this call FUNC(ACEGearClassAttributeUnit_onSelChange));
        };
    };
};
