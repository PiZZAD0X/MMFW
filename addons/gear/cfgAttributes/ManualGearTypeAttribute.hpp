class GVAR(AttributeManualGearEditShort): EditShort {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(ManualGearTypeAttribute_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(ManualGearTypeAttribute_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onKillFocus = QUOTE([ARR_2(_this,_config)] call FUNC(ManualGearTypeAttribute_onKillFocus));
        };
    };
};
