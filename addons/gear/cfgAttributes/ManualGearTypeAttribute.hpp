class GVAR(AttributeManualGearEditShort): EditShort {
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(ManualGearTypeAttribute_AttrSave));
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(ManualGearTypeAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onKillFocus = QUOTE(_this call FUNC(ManualGearTypeAttribute_onKillFocus));
        };
    };
};
