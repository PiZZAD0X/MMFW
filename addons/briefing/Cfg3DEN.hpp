class Cfg3DEN {
    class Mission {
        //Additional Core cfg3denMenu defines
        #include "cfg3den\cfg3denMenuCategories.hpp"
    };
};

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                #include "display3DEN\Menu.hpp"
                class EGVAR(Core,Folder) {
                    items[] + = {
                        QGVAR(Folder)
                    };
                };
            };
        };
    };
};
