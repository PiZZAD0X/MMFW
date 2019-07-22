class Cfg3DEN {
    class Object {
        class AttributeCategories {
            #include "cfgAttributeCategories\Object.hpp"
        };
    };
    class Mission {
        class EGVAR(Module,Settings) {
            class AttributeCategories {
                #include "cfg3den\Modules\AIDrivers.hpp"
            };
        };
    };
};
