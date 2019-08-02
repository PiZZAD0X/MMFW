#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Data_F_Tank_Loadorder",
            // CBA
            "cba_main",
            "cba_xeh",
            // ACE
            "ace_main"
        };
        author = ECSTRING(core,MMFWTeam);
        url = CSTRING(URL);
        VERSION_CONFIG;
    };
};

class CfgMods {
    class PREFIX {
        dir = "@MMFW";
        name = "Mission Maker Framework";
        picture = "A3\Ui_f\data\Logos\arma3_expansion_alpha_ca";
        hidePicture = "true";
        hideName = "true";
        actionName = "Website";
        action = CSTRING(URL);
        description = "Issue Tracker: https://github.com/PiZZAD0X/MMFW/issues";
    };
};

#include "CfgSettings.hpp"
