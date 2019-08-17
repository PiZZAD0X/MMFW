class EGVAR(Respawn,DeathScreenTypeAttribute): Combo {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(DeathScreenTypeAttribute_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(DeathScreenTypeAttribute_AttrSave));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};
