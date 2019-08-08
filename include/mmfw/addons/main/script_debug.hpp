/**
FAST RECOMPILING
**/
#define DISABLE_COMPILE_CACHE
// To Use: [] call MMFW_PREP_RECOMPILE;

#ifdef DISABLE_COMPILE_CACHE
    #define LINKFUNC(x) {_this call FUNC(x)}
    #define PREP_RECOMPILE_START    if (isNil "MMFW_PREP_RECOMPILE") then {MMFW_RECOMPILES = []; MMFW_PREP_RECOMPILE = {{call _x} forEach MMFW_RECOMPILES;}}; private _recomp = {
    #define PREP_RECOMPILE_END      }; call _recomp; MMFW_RECOMPILES pushBack _recomp;
#else
    #define LINKFUNC(x) FUNC(x)
    #define PREP_RECOMPILE_START /* disabled */
    #define PREP_RECOMPILE_END /* disabled */
#endif


/**
STACK TRACING
**/
//#define ENABLE_CALLSTACK
//#define ENABLE_PERFORMANCE_COUNTERS
//#define DEBUG_EVENTS

#ifdef ENABLE_CALLSTACK
    #define CALLSTACK(function) {private ['_ret']; if (MMFW_IS_ERRORED) then { ['AUTO','AUTO'] call MMFW_DUMPSTACK_FNC; MMFW_IS_ERRORED = false; }; MMFW_IS_ERRORED = true; MMFW_STACK_TRACE set [MMFW_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, MMFW_CURRENT_FUNCTION, 'ANON', _this]]; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH + 1; MMFW_CURRENT_FUNCTION = 'ANON'; _ret = _this call ##function; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH - 1; MMFW_IS_ERRORED = false; _ret;}
    #define CALLSTACK_NAMED(function, functionName) {private ['_ret']; if (MMFW_IS_ERRORED) then { ['AUTO','AUTO'] call MMFW_DUMPSTACK_FNC; MMFW_IS_ERRORED = false; }; MMFW_IS_ERRORED = true; MMFW_STACK_TRACE set [MMFW_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, MMFW_CURRENT_FUNCTION, functionName, _this]]; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH + 1; MMFW_CURRENT_FUNCTION = functionName; _ret = _this call ##function; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH - 1; MMFW_IS_ERRORED = false; _ret;}
    #define DUMPSTACK ([__FILE__, __LINE__] call MMFW_DUMPSTACK_FNC)

    #define FUNC(var1) {private ['_ret']; if (MMFW_IS_ERRORED) then { ['AUTO','AUTO'] call MMFW_DUMPSTACK_FNC; MMFW_IS_ERRORED = false; }; MMFW_IS_ERRORED = true; MMFW_STACK_TRACE set [MMFW_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, MMFW_CURRENT_FUNCTION, 'TRIPLES(ADDON,fnc,var1)', _this]]; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH + 1; MMFW_CURRENT_FUNCTION = 'TRIPLES(ADDON,fnc,var1)'; _ret = _this call TRIPLES(ADDON,fnc,var1); MMFW_STACK_DEPTH = MMFW_STACK_DEPTH - 1; MMFW_IS_ERRORED = false; _ret;}
    #define EFUNC(var1,var2) {private ['_ret']; if (MMFW_IS_ERRORED) then { ['AUTO','AUTO'] call MMFW_DUMPSTACK_FNC; MMFW_IS_ERRORED = false; }; MMFW_IS_ERRORED = true; MMFW_STACK_TRACE set [MMFW_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, MMFW_CURRENT_FUNCTION, 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)', _this]]; MMFW_STACK_DEPTH = MMFW_STACK_DEPTH + 1; MMFW_CURRENT_FUNCTION = 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)'; _ret = _this call TRIPLES(DOUBLES(PREFIX,var1),fnc,var2); MMFW_STACK_DEPTH = MMFW_STACK_DEPTH - 1; MMFW_IS_ERRORED = false; _ret;}
#else
    #define CALLSTACK(function) function /* disabled */
    #define CALLSTACK_NAMED(function, functionName) function /* disabled */
    #define DUMPSTACK /* disabled */
#endif


/**
PERFORMANCE COUNTERS
**/
//#define ENABLE_PERFORMANCE_COUNTERS

#ifdef ENABLE_PERFORMANCE_COUNTERS
    #define ADDPFH(function, timing, args) call { _ret = [function, timing, args] call CBA_fnc_addPerFrameHandler; if (isNil "MMFW_PFH" ) then { MMFW_PFH = []; }; MMFW_PFH pushBack [[_ret, __FILE__, __LINE__], [function, timing, args]];  _ret }

    #define CREATE_COUNTER(x) if (isNil "MMFW_COUNTERS" ) then { MMFW_COUNTERS = []; }; GVAR(DOUBLES(x,counter)) = []; GVAR(DOUBLES(x,counter)) set[0, QGVAR(DOUBLES(x,counter))];  GVAR(DOUBLES(x,counter)) set[1, diag_tickTime]; MMFW_COUNTERS pushBack GVAR(DOUBLES(x,counter));
    #define BEGIN_COUNTER(x) if (isNil QGVAR(DOUBLES(x,counter))) then { CREATE_COUNTER(x) }; GVAR(DOUBLES(x,counter)) set[2, diag_tickTime];
    #define END_COUNTER(x) GVAR(DOUBLES(x,counter)) pushBack [(GVAR(DOUBLES(x,counter)) select 2), diag_tickTime];

    #define DUMP_COUNTERS ([__FILE__, __LINE__] call MMFW_DUMPCOUNTERS_FNC)
#else
    #define ADDPFH(function, timing, args) [function, timing, args] call CBA_fnc_addPerFrameHandler

    #define CREATE_COUNTER(x) /* disabled */
    #define BEGIN_COUNTER(x) /* disabled */
    #define END_COUNTER(x) /* disabled */
    #define DUMP_COUNTERS  /* disabled */
#endif
