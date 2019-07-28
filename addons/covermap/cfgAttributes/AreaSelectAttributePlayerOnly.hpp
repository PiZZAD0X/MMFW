class GVAR(AreaSelectAttributePlayerOnly): Combo {
    attributeLoad = QUOTE([ARR_4(_this,_value,_config,true)] call FUNC(AreaSelectAttribute_attr_load));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(AreaSelectAttribute_attr_save));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLoad = QUOTE([_this] call FUNC(AreaSelectAttribute_onLoad));
        };
    };
};
