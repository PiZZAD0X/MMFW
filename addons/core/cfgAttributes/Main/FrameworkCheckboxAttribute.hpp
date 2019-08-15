class GVAR(FrameworkCheckbox): Checkbox {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(FrameWorkCheckBox_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(FrameWorkCheckBox_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onCheckedChanged = QUOTE([] call FUNC(FrameWorkCheckBox_OnChecked));
        };
    };
};
