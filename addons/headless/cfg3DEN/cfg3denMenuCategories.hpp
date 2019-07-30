class GVAR(MainSettings) {
    displayName = "Main AI Settings";
    class AttributeCategories {
        #include "AI\MainSettings.hpp"
        #include "AI\TimeAndVisibilitySettings.hpp"
    };
};

class GVAR(CommanderSettings) {
    displayName = "Commander Settings";
    class AttributeCategories {
        #include "AI\CommanderSettings.hpp"
    };
};
