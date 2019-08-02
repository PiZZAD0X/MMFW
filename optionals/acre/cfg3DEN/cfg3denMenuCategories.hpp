class GVAR(MainSettings) {
    displayName = "Main ACRE Settings";
    class AttributeCategories {
        #include "ACRE\MainSettings.hpp"
    };
};

class GVAR(Blufor) {
    displayName = "Blufor ACRE Configuration";
    class AttributeCategories {
        #include "ACRE\Blufor.hpp"
    };
};

class GVAR(Opfor) {
    displayName = "Opfor ACRE Configuration";
    class AttributeCategories {
        #include "ACRE\Opfor.hpp"
    };
};

class GVAR(Indfor) {
    displayName = "Indfor ACRE Configuration";
    class AttributeCategories {
        #include "ACRE\Indfor.hpp"
    };
};

class GVAR(Civilian) {
    displayName = "Civilian ACRE Configuration";
    class AttributeCategories {
        #include "ACRE\Civ.hpp"
    };
};
