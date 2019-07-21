
class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
        initServer = QUOTE(call COMPILE_FILE(XEH_preServerInit));
    };
};

class Extended_InitPost_EventHandlers {
    class ADDON {
        init = QUOTE(_this call FUNC(AutoTrackInit));
    };
};
