#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "MMFW_main",
            "MMFW_core",
            "MMFW_aidrivers",
            "MMFW_acre",
            "MMFW_antind",
            "MMFW_autotrack",
            "MMFW_briefing",
            "MMFW_capturezone",
            "MMFW_covermap",
            "MMFW_hostage",
            "MMFW_markercontrol",
            "MMFW_objectsettings",
            "MMFW_safestart",
            "MMFW_selfactions",
            "MMFW_setuptimer",
            "MMFW_shotcount",
            "MMFW_startinparachute",
            "MMFW_starttext",
            "MMFW_teamcolour"
        };
        authors[] = {"Olsen","PiZZADOX","Sacher"};
        author = "MMFW Team";
        authorUrl = "https://github.com/PiZZAD0X/MMFW";
        VERSION_CONFIG;
    };
};

#include "\z\MMFW\addons\main\RscTitles.hpp"
#include "CfgEventHandlers.hpp"
#include "Cfg3DEN.hpp"
