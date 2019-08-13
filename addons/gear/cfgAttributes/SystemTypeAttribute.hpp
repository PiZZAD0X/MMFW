class GVAR(AttributeSystemType): Combo {
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(SystemTypeAttribute_AttrSave));
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(SystemTypeAttribute_AttrLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onLBSelChanged = QUOTE(_this call FUNC(SystemTypeAttribute_onLBSelChanged));
        };
    };
};

class GVAR(AttributeSystemTypeVehicle): GVAR(AttributeSystemType) {
    attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(SystemTypeVehicleAttribute_AttrLoad));
};
