
class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
        clientinit = QUOTE(call COMPILE_FILE(XEH_preClientInit));
    };
};

class Extended_InitPost_Eventhandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE(call FUNC(initPost));
        };
    };
};
