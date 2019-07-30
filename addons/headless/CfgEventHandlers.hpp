
class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
        clientinit = QUOTE(call COMPILE_FILE(XEH_preClientInit));
        serverinit = QUOTE(call COMPILE_FILE(XEH_preServerInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
        serverinit = QUOTE(call COMPILE_FILE(XEH_postServerInit));
    };
};
