#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"MMFW_main","MMFW_core"};
        authors[] = {"Olsen","PiZZADOX"};
        author = "MMFW Team";
        authorUrl = "https://github.com/unitedoperations";
        VERSION_CONFIG;
    };
};

#include "\z\MMFW\addons\core\RscTitles.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgAttributes.hpp"
#include "Cfg3DEN.hpp"
