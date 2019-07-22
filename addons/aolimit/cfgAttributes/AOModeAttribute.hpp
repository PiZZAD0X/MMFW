class GVAR(AOModeAttribute): Combo {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(AOModeAttribute_attr_load));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(AOModeAttribute_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLBSelChanged = QUOTE(_this call FUNC(AOModeAttribute_attr_onLBSelChanged));
        };
    };
};
