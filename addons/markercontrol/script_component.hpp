#define COMPONENT markercontrol
#define COMPONENT_BEAUTIFIED MarkerControl
#include "\z\MMFW\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MARKERCONTROL
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_CORE
    #define DEBUG_SETTINGS DEBUG_ENABLED_MARKERCONTROL
#endif

#define MARKERSTEAMCHECK(teamvar,markerVar,briefingVar) \
(GETMVAR(markerVar,[])) apply {\
    private _layerEntities = getMissionLayerEntities _x;\
    if !(_layerEntities isEqualTo []) then {\
        if !((_layerEntities select 1) isEqualto []) then {\
            (_layerEntities select 1) apply {_markers pushBackUnique [teamvar, _x]};\
        };\
    } else {\
        _markers pushBackUnique [teamvar, _x];\
    };\
};\
(GETMVAR(briefingVar,[])) apply {\
    private _layerEntities = getMissionLayerEntities _x;\
    if !(_layerEntities isEqualTo []) then {\
        if !((_layerEntities select 1) isEqualto []) then {\
            (_layerEntities select 1) apply {_markersBriefing pushBackUnique [teamvar, _x]};\
        };\
    } else {\
        _markersBriefing pushBackUnique [teamvar, _x];\
    };\
}

#include "\z\MMFW\addons\main\script_macros.hpp"
