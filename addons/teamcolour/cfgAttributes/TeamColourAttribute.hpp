class GVAR(ColourAttribute): Combo {
    onLoad = QUOTE(_this call FUNC(PlayerOnlyOnLoad));
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(TeamColourAttribute_attr_load));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(TeamColourAttribute_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};
