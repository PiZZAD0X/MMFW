#define COMPONENT antind
#define COMPONENT_BEAUTIFIED AntiND
#include "\z\MMFW\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ANTIND
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_CORE
    #define DEBUG_SETTINGS DEBUG_ENABLED_ANTIND
#endif

#include "\z\MMFW\addons\main\script_macros.hpp"
