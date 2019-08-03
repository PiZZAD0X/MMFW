class GVAR(CheckBoxPlayerOnlyCategory): CheckBox {
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckBoxStatePlayerOnlyCategory): CheckBoxState {
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckboxNumberPlayerOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(CheckboxReversedPlayerOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(EditPlayerOnlyCategory): Edit {
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class EGVAR(3DEN,EditShortPlayerOnlyCategory): Edit
{
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};

class GVAR(EditArrayPlayerOnlyCategory): Edit
{
    onLoad = QUOTE([_this] call FUNC(PlayerOnlyOnLoad));
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};
