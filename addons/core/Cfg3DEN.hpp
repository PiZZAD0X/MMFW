class Cfg3DEN {

    class EventHandlers {
        #include "cfg3denEH.hpp"
    };

    class Mission {
        class GVAR(Settings) {
            displayName = "Mission Settings";
            class AttributeCategories {
                //add Main mission settings here
                #include "cfg3den\Mission\MainMenu.hpp"
                #include "cfg3den\Mission\TeamsMenu.hpp"
                #include "cfg3den\Mission\VisionMenu.hpp"
                //debug at bottom
                #include "cfg3den\Mission\DebugMenu.hpp"
            };
        };

        class GVAR(InitSettings) {
            displayName = "Init Settings";
            class AttributeCategories {
                //add Main mission settings here
                #include "cfg3den\Inits\InitMenu.hpp"
            };
        };

        //Additional Core cfg3denMenu defines
        #include "cfg3den\cfg3denMenuCategories.hpp"

        class EGVAR(Module,Settings) {
            displayName = "Module Settings";
            class AttributeCategories {
                //add module settings here
            };
        };
    };

    //Add Custom Base 3DEN Options & Categories
    class Group {};

    class Object {};

    class Logic {
        class Draw {
            class 3D {
                textureBackgroundModule = QPATHTOF(Resources\UI\textureBackgroundModuleSquareInv_ca.paa);
                sizeModule = "(32 + 14) * pixelW";
                sizeBackgroundModule = "(48 + 14) * pixelW";
                colorModule[] = {0,0,0};
                colorModuleBackground[] = {1,1,1};
                colorModulePreview[] = {1,1,1};
                colorModulePreviewBackground[] = {1,1,1};
                alphaNormal = 1;
                alphaNormalBackground = 0.75;
                alphaSelected = 1;
                alphaSelectedBackground = 1;
                alphaHover = 1;
                alphaHoverBackground = 1;
                fadeDistance = 2500;
            };
            class 2D {
                textureBackgroundModule = QPATHTOF(Resources\UI\textureBackgroundModuleSquareInv_ca.paa);
                sizeModule = "(32 + 6) * pixelW";
                sizeBackgroundModule = "(48 + 6) * pixelW";
                presenceBorder = 2;
                areaBorder = 1;
                colorModule[] = {0,0,0};
                colorModuleBackground[] = {1,1,1};
                colorModulePreview[] = {0,0,0};
                colorModulePreviewBackground[] = {1,1,1};
                alphaNormal = 1;
                alphaNormalBackground = 0.75;
                alphaSelected = 1;
                alphaSelectedBackground = 1;
                alphaHover = 1;
                alphaHoverBackground = 1;
            };
        };
    };

    //Add Custom Configs & Controls for 3DEN and Modules
    class Attributes {
        #include "CfgAttributes.hpp"
    };
};

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                //Menus Define
                #include "display3DEN\Menu.hpp"
                #include "display3DEN\MenuEndConditions.hpp"
                #include "display3DEN\MenuRespawn.hpp"
                class GVAR(Folder) {
                    text = "Mission Framework";
                    items[] = {
                        QGVAR(SettingsMenu),
                        QGVAR(InitSettingsMenu),
                        QEGVAR(Module,SettingsMenu),
                        QEGVAR(Respawn,Folder),
                        QEGVAR(EndConditions,Folder)
                    };
                };
                //Compile Main Menu
                items[] += {QGVAR(Folder)};
            };
        };
    };
};
