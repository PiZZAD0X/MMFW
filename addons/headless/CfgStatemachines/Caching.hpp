class EGVAR(Caching,StateMachine) {
    list = QUOTE(allGroups select {local _x && {!(_x getVariable [ARR_2(QQEGVAR(core,enabled), false)])}});
    skipNull = 1;

    class Init {
        onStateEntered = QEFUNC(Caching,onCacheInit);
        class Cache {
            targetState = "Cache";
            events[] = {QEGVAR(Caching,cache)};
        };

        class Uncache {
            targetState = "Uncache";
            events[] = {QEGVAR(Caching,uncache)};
        };
    };

    class Cache {
        onStateEntered = QEFUNC(Caching,cacheGroup);
        onState = QEFUNC(Caching,handleCache);

        class LeaderChanged {
            targetState = "LeaderChanged";
            events[] = {QEGVAR(Caching,leaderChanged)};
        };

        class MoveUnits {
            targetState = "MoveUnits";
            events[] = {QEGVAR(Caching,moveUnits)};
        };

        class Uncache {
            targetState = "Uncache";
            events[] = {QEGVAR(Caching,uncache)};
        };
    };

    class LeaderChanged {
        onStateEntered = QEFUNC(Caching,changeLeader);

        class Cache {
            targetState = "Cache";
            events[] = {QEGVAR(Caching,cache)};
        };
    };

    class MoveUnits {
        onStateEntered = QEFUNC(Caching,moveCachedUnits);

        class Cache {
            targetState = "Cache";
            events[] = {QEGVAR(Caching,cache)};
        };
    };

    class Uncache {
        onStateEntered = QEFUNC(Caching,uncacheGroup);
        onState = QEFUNC(Caching,handleUncache);

        class Cache {
            targetState = "Cache";
            events[] = {QEGVAR(Caching,cache)};
        };
    };
};
