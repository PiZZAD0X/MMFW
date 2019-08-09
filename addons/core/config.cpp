#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"MMFW_main"};
        authors[] = {"Olsen","PiZZADOX","Sacher","TheMagnetar","TrainDoc","TinfoilHate"};
        author = "MMFW Team";
        authorUrl = "https://github.com/unitedoperations";
        VERSION_CONFIG;
    };
};

class CfgFactionClasses {
    class NO_CATEGORY;
    class GVAR(FrameworkCategory): NO_CATEGORY {
        displayName = " Mission Maker Framework";
    };
};

#include "\z\MMFW\addons\main\RscTitles.hpp"
#include "CfgEventHandlers.hpp"
#include "RscTitles.hpp"
#include "CfgVehicles.hpp"
#include "Cfg3DEN.hpp"
#include "CfgCustom\RespawnTemplates.hpp"
#include "cfgDebriefingSections.hpp"
