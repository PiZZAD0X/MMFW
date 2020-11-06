
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

class Extended_FiredMan_EventHandlers {
	class CAManBase {
        class ADDON {
            init = QUOTE(call FUNC(firedManEH));
        };
	};
};

class Extended_InitPost_EventHandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE(_this call FUNC(addEH));
        };
    };
};
