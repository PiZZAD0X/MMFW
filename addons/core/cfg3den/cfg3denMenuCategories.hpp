class EGVAR(Respawn,Settings_BLUFOR) {
    displayName = "BLUFOR Respawn Settings";
    class AttributeCategories {
        #include "Respawn\BluforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_OPFOR) {
    displayName = "OPFOR Respawn Settings";
    class AttributeCategories {
        #include "Respawn\OpforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Indfor) {
    displayName = "Indfor Respawn Settings";
    class AttributeCategories {
        #include "Respawn\IndforRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Civ) {
    displayName = "Civilian Respawn Settings";
    class AttributeCategories {
        #include "Respawn\CivilianRespawn.hpp"
    };
};

class EGVAR(Respawn,Settings_Main) {
    displayName = "General Respawn Settings";
    class AttributeCategories {
        #include "Respawn\MainRespawn.hpp"
    };
};

class EGVAR(EndConditions,SettingsMenu) {
    displayName = "End Condition Settings";
    class AttributeCategories {
      #include "EndConditions\TimelimitMenu.hpp"
      #include "EndConditions\CustomFileMenu.hpp"
      #include "EndConditions\SleepMenu.hpp"
    };
};

class EGVAR(EndConditions,Category_1_Menu) {
    displayName = "Category 1 Settings";
    class AttributeCategories {
        #include "EndConditions\Category1Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_2_Menu) {
    displayName = "Category 2 Settings";
    class AttributeCategories {
        #include "EndConditions\Category2Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_3_Menu) {
    displayName = "Category 3 Settings";
    class AttributeCategories {
        #include "EndConditions\Category3Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_4_Menu) {
    displayName = "Category 4 Settings";
    class AttributeCategories {
        #include "EndConditions\Category4Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_5_Menu) {
    displayName = "Category 5 Settings";
    class AttributeCategories {
        #include "EndConditions\Category5Menu.hpp"
    };
};

class EGVAR(EndConditions,Category_6_Menu) {
    displayName = "Category 6 Settings";
    class AttributeCategories {
        #include "EndConditions\Category6Menu.hpp"
    };
};
