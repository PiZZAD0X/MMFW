class Cfg3DEN {
    class EventHandlers {
        #include "cfg3denEH.hpp"
    };
    class Mission {
        #include "cfg3den\cfg3denMenuCategories.hpp"
    };
};

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                #include "display3DEN\Menu.hpp"
                class EGVAR(Core,Folder) {
                    items[] += {
                        QGVAR(Folder)
                    };
                };
            };
        };
    };
};
