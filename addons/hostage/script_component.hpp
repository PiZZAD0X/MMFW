#define COMPONENT hostage
#define COMPONENT_BEAUTIFIED Hostage
#include "\z\MMFW\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_HOSTAGE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_CORE
    #define DEBUG_SETTINGS DEBUG_ENABLED_HOSTAGE
#endif

#include "\z\MMFW\addons\main\script_macros.hpp"
