#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"MMFW_main","MMFW_core"};
        authors[] = {"Olsen","PiZZADOX","Sacher"};
        author = "MMFW Team";
        authorUrl = "https://github.com/Global-Conflicts-ArmA";
        VERSION_CONFIG;
    };
};

#include "\z\MMFW\addons\main\RscTitles.hpp"
#include "CfgEventHandlers.hpp"
#include "Cfg3DEN.hpp"
