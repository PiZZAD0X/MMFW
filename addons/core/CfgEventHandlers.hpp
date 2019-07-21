
class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
        Clientinit = QUOTE(call COMPILE_FILE(XEH_preClientInit));
        Serverinit = QUOTE(call COMPILE_FILE(XEH_preServerInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
        Clientinit = QUOTE(call COMPILE_FILE(XEH_postClientInit));
        Serverinit = QUOTE(call COMPILE_FILE(XEH_postServerInit));
    };
};

class Extended_InitPost_Eventhandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE(_this call FUNC(CAManBaseInitPost));
        };
    };
};

class Extended_Killed_Eventhandlers {
    class CAManBase {
        class EGVAR(Core,Killed) {
            killed = QUOTE(_this call FUNC(CAManBaseKilled));
        };
    };
};

class Extended_Respawn_Eventhandlers {
    class CAManBase {
        class EGVAR(Core,Respawn) {
            respawn = QUOTE(_this call FUNC(CAManBaseRespawn));
        };
    };
};
