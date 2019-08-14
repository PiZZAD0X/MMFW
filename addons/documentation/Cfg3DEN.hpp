class Cfg3DEN {
    class Attributes {
        #include "CfgAttributes.hpp"
    };
    class Mission {
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
                        QGVAR(ExportImportFolder),
                        QGVAR(Documentation),
                        QGVAR(VersionDisplay)
                    };
                };
            };
        };
    };
};
