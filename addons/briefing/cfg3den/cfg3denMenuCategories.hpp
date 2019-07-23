class GVAR(Blufor) {
    displayName = "Blufor Briefing";
    class AttributeCategories {
        #include "Briefing\BluforMenu.hpp"
    };
};

class GVAR(Opfor) {
    displayName = "Opfor Briefing";
    class AttributeCategories {
        #include "Briefing\OpforMenu.hpp"
    };
};

class GVAR(Indfor) {
    displayName = "Indfor Briefing";
    class AttributeCategories {
        #include "Briefing\IndforMenu.hpp"
    };
};

class GVAR(Civilian) {
    displayName = "Civilian Briefing";
    class AttributeCategories {
        #include "Briefing\CivMenu.hpp"
    };
};

class GVAR(MissionNotes) {
    displayName = "Mission Notes";
    class AttributeCategories {
        #include "Briefing\MissionNotesMenu.hpp"
    };
};
