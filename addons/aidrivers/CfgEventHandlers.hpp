
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

class Extended_InitPost_EventHandlers {
    class LandVehicle {
        class ADDON {
            init = QUOTE(call FUNC(initPost));
        };
    };
    class Helicopter {
        class ADDON {
            init = QUOTE(call FUNC(initPost));
        };
    };
    class Plane {
        class ADDON {
            init = QUOTE(call FUNC(initPost));
        };
    };
    class Ship_F {
        class ADDON {
            init = QUOTE(call FUNC(initPost));
        };
    };
};
