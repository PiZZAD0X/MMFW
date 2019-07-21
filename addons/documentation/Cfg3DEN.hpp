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
                #include "display3DEN\Menu3DEN.hpp"
                #include "display3DEN\MenuDoc.hpp"
                #include "display3DEN\MenuTools.hpp"
                class EGVAR(Core,Folder) {
                    items[] += {
                        QEGVAR(ExportImport,Folder),
                        QGVAR(Documentation),
                        QGVAR(VersionDisplay)
                    };
                };
            };
        };
    };
};
