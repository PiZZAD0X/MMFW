class Cfg3DEN {
    class Attributes {
        #include "CfgAttributes.hpp"
    };
    class Mission {
        class EGVAR(Module,Settings) {
            class AttributeCategories {
                #include "cfg3den\Modules\CoverMap.hpp"
            };
        };
    };
    class Object {
        class AttributeCategories {
            #include "cfgAttributeCategories\Object.hpp"
        };
    };
};
