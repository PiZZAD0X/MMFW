class EGVAR(Briefing,Blufor) {
    displayName = "Blufor Briefing";
    class AttributeCategories {
        #include "Briefing\BluforMenu.hpp"
    };
};

class EGVAR(Briefing,Opfor) {
    displayName = "Opfor Briefing";
    class AttributeCategories {
        #include "Briefing\OpforMenu.hpp"
    };
};

class EGVAR(Briefing,Indfor) {
    displayName = "Indfor Briefing";
    class AttributeCategories {
        #include "Briefing\IndforMenu.hpp"
    };
};

class EGVAR(Briefing,Civilian) {
    displayName = "Civilian Briefing";
    class AttributeCategories {
        #include "Briefing\CivMenu.hpp"
    };
};

class EGVAR(Briefing,MissionNotes) {
    displayName = "Mission Notes";
    class AttributeCategories {
        #include "Briefing\MissionNotesMenu.hpp"
    };
};
