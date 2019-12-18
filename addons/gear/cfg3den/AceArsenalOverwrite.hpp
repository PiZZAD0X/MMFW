class ace_arsenal_DummyCategory {
    displayName = "Dummy attribute, should never show up";
    class AttributeCategories {
        class ACE3_Arsenal {
            class Attributes {
                class ace_arsenal_DefaultLoadoutsListAttribute {
                    property = "ace_arsenal_DefaultLoadoutsListAttribute";
                    value = 0;
                    expression = "missionNamespace setvariable ['ace_arsenal_defaultLoadoutsList', _value, true];";
                    defaultValue = "[]";
                    validate = "none";
                    wikiType = "[[Array]]";
                };
            };
        };
    };
};
