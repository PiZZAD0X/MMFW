class GVAR(AttributeComboGearLoad): ComboPreview {
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(GearComboLoadAttribute_AttrSave));
    attributeLoad = QUOTE(ARR_3(_this,_value,_config)] call FUNC(GearComboLoadAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 100;
            onLBSelChanged = QUOTE(_this call FUNC(GearComboLoadAttribute_onSelChange));
        };
        class Preview: Preview {
            idc = 101;
            onMouseButtonClick = QUOTE(_this call FUNC(GearComboLoadAttribute_onMouseClick));
        };
    };
};
