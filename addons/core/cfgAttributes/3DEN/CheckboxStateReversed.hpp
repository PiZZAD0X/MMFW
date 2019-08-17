class GVAR(CheckboxStateReversed): CheckboxState {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(CheckboxStateReversed_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(CheckboxStateReversed_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc = 101;
            onCheckedChanged = QUOTE(_this call FUNC(CheckboxStateReversed_onCheckedChanged));
        };
    };
};
