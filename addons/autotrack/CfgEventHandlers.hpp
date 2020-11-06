
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
    class LandVehicle {
        class ADDON {
            init = QUOTE(call FUNC(AutoTrackInit));
        };
    };
    class Helicopter {
        class ADDON {
            init = QUOTE(call FUNC(AutoTrackInit));
        };
    };
    class Plane {
        class ADDON {
            init = QUOTE(call FUNC(AutoTrackInit));
        };
    };
    class Ship_F {
        class ADDON {
            init = QUOTE(call FUNC(AutoTrackInit));
        };
    };
};
