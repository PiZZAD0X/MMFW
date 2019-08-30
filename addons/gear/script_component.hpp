#define COMPONENT gear
#define COMPONENT_BEAUTIFIED Gear
#include "\z\MMFW\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_GEAR
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_GEAR
    #define DEBUG_SETTINGS DEBUG_SETTINGS_GEAR
#endif

#include "\z\MMFW\addons\main\script_macros.hpp"
