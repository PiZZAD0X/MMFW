
class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_Init_EventHandlers {
    class StaticWeapon {
        class ADDON {
            init = QUOTE(_this call DFUNC(ObjectInitPost));
        };
    };
    class ThingX {
        class ADDON {
            init = QUOTE(_this call DFUNC(ObjectInitPost));
        };
    };
    class Land_PortableLight_single_F {
        class ADDON {
            init = QUOTE(_this call DFUNC(ObjectInitPost));
        };
    };
    class Land_Camping_Light_F {
        class ADDON {
            init = QUOTE(_this call DFUNC(ObjectInitPost));
        };
    };
};
