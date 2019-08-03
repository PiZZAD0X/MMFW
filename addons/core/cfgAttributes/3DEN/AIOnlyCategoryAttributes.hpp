class GVAR(CheckBoxAIOnlyCategory): CheckBox {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckBoxStateAIOnlyCategory): CheckBoxState {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckboxNumberAIOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckboxReversedAIOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(EditAIOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(EditShortAIOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(EditArrayAIOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(AIOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};
