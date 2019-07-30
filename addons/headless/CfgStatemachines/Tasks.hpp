class EGVAR(Tasks,StateMachine) {
    list = QUOTE(allGroups select {local _x && {_x getVariable [ARR_2(QQGVAR(enabled), false)]}});
    skipNull = 1;

    class Init {
        onStateEntered = QEFUNC(tasks,onInitEntered);
        class DoTask {
            targetState = "DoTask";
            condition = QUOTE(CBA_missionTime > 0);
        };
    };

    class DoTask {
        onStateEntered = QEFUNC(tasks,onDoTaskEntered);
        class TaskAttack {
            targetState = "TaskAttack";
            events[] = {QEGVAR(tasks,attack)};
        };
        class TaskDefend {
            targetState = "TaskDefend";
            events[] = {QEGVAR(tasks,defend)};
        };
        class TaskGarrison {
            targetState = "TaskGarrison";
            events[] = {QEGVAR(tasks,garrison)};
        };
        class TaskPatrol {
            targetState = "TaskPatrol";
            events[] = {QEGVAR(tasks,patrol)};
        };
        class TaskPatrolRandom {
            targetState = "TaskPatrolRandom";
            events[] = {QEGVAR(tasks,patrolRandom)};
        };
        class TaskTransport {
            targetState = "TaskTransport";
            events[] = {QEGVAR(tasks,transport)};
        };
        class DoNothing {
            targetState = "DoNothing";
            events[] = {QEGVAR(tasks,doNothing)};
        };
    };

    class TaskAttack {
        onStateEntered = QEFUNC(tasks,onAttackEntered);
        onState = QEFUNC(tasks,onAttack);

        class DoTask {
            targetState = "DoTask";
            condition = QEFUNC(tasks,checkDoTask);
        };

        class Flank {
            targetState = "Flank";
            events[] = {QEGVAR(tasks,flankManeuver)};
        };

        class Retreat {
            targetState = "Retreat";
            events[] = {QEGVAR(tasks,retreatManeuver)};
        };

        class TaskDefend {
            targetState = "TaskDefend";
            events[] = {QEGVAR(tasks,defend)};
        };

        class TaskGarrison {
            targetState = "TaskGarrison";
            events[] = {QEGVAR(tasks,garrison)};
        };
    };

    class Flank {
        onStateEntered = QEFUNC(tasks,onFlankEntered);
        onState = QEFUNC(tasks,onFlank);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };

        class TaskAttack {
            targetState = "TaskAttack";
            events[] = {QEGVAR(tasks,attack)};
        };

        class Retreat {
            targetState = "Retreat";
            events[] = {QEGVAR(tasks,retreatManeuver)};
        };

        class TaskDefend {
            targetState = "TaskDefend";
            events[] = {QEGVAR(tasks,defend)};
        };

        class TaskGarrison {
            targetState = "TaskGarrison";
            events[] = {QEGVAR(tasks,garrison)};
        };
    };

    class Retreat {
        onStateEntered = QEFUNC(tasks,onRetreatEntered);
        onState = QEFUNC(tasks,onRetreat);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };

        class TaskAttack {
            targetState = "TaskAttack";
            events[] = {QEGVAR(tasks,attack)};
        };

        class Flank {
            targetState = "Flank";
            events[] = {QEGVAR(tasks,flankManeuver)};
        };

        class TaskDefend {
            targetState = "TaskDefend";
            events[] = {QEGVAR(tasks,defend)};
        };

        class TaskGarrison {
            targetState = "TaskGarrison";
            events[] = {QEGVAR(tasks,garrison)};
        };
    };

    class TaskDefend {
        onStateEntered = QEFUNC(tasks,onDefendEntered);
        onState = QEFUNC(tasks,onDefend);
    };

    class TaskGarrison {
        onStateEntered = QEFUNC(tasks,onGarrisonEntered);
        onState = QEFUNC(tasks,onGarrison);

        class DoTask {
            targetState = "DoTask";
            condition = QEFUNC(tasks,checkDoTask);
        };

        class Flank {
            targetState = "Flank";
            events[] = {QEGVAR(tasks,flankManeuver)};
        };

        class Retreat {
            targetState = "Retreat";
            events[] = {QEGVAR(tasks,retreatManeuver)};
        };

        class TaskDefend {
            targetState = "TaskDefend";
            events[] = {QEGVAR(tasks,defend)};
        };

        class TaskAttack {
            targetState = "TaskAttack";
            events[] = {QEGVAR(tasks,attack)};
        };
    };

    class TaskPatrolRandom {
        onStateEntered = QEFUNC(tasks,onPatrolRandomEntered);
        onState = QEFUNC(tasks,onPatrolRandom);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };

        class PatrolBuildings {
            targetState = "PatrolBuildings";
            events[] = {QEGVAR(tasks,patrolBuildings)};
        };
        class SearchVehicles {
            targetState = "SearchVehciles";
            events[] = {QEGVAR(tasks,searchVehicles)};
        };
        class Disembark {
            targetState = "Disembark";
            events[] = {QEGVAR(tasks,disembark)};
        };
        class Wait {
            targetState = "Wait";
            events[] = {QEGVAR(tasks,wait)};
        };
    };

    class TaskPatrol {
        onStateEntered = QEFUNC(tasks,onPatrolEntered);
        onState = QEFUNC(tasks,onPatrolRandom);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };

        class PatrolBuildings {
            targetState = "PatrolBuildings";
            events[] = {QEGVAR(tasks,patrolBuildings)};
        };

        class Embark {
            targetState = "Embark";
            events[] = {QEGVAR(tasks,embark)};
        };

        class Disembark {
            targetState = "Disembark";
            events[] = {QEGVAR(tasks,disembark)};
        };

        class Wait {
            targetState = "Wait";
            events[] = {QEGVAR(tasks,wait)};
        };
    };

    class TaskTransport {
        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };

        class Transport {
            targetState = "Transport";
            condition = QUOTE(_this getVariable [ARR_2(QQEGVAR(tasks,inMission), false)]);
        };
    };

    class DoNothing {
        onStateEntered = "";
        class DoTask {
            targetState = "DoTask";
            condition = QEFUNC(tasks,checkDoTask);
        };
    };

    class PatrolBuildings {
        onStateEntered = QEFUNC(tasks,onPatrolBuildingEntered);
        onState = QEFUNC(tasks,onPatrolBuilding);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };
    };

    class SearchVehicles {

    };

    class Disembark {
        onStateEntered = QEFUNC(tasks,onDisembarkEntered);
        onState = QEFUNC(tasks,onDisembark);

        class PatrolBuildings {
            targetState = "PatrolBuildings";
            events[] = {QEGVAR(tasks,patrolBuildings)};
        };

        class TaskPatrol {
            targetState = "TaskPatrol";
            events[] = {QEGVAR(tasks,patrol)};
        };

        class Embark {
            targetState = "Embark";
            events[] = {QEGVAR(tasks,embark)};
        };

        class Wait {
            targetState = "Wait";
            events[] = {QEGVAR(tasks,wait)};
        };
    };

    class Embark {
        onStateEntered = QEFUNC(tasks,onEmbarkEntered);
        onState = QEFUNC(tasks,onEmbark);

        class DoTask {
            targetState = "DoTask";
            events[] = {QEGVAR(tasks,doTask)};
        };
    };

    class Transport {
        onStateEntered = QEFUNC(tasks,onTransportEntered);
    };

    class Wait {
        onStateEntered = QUOTE(_this setVariable [ARR_2(QQEGVAR(tasks,waitUntil), CBA_missionTime + 30 + random 30)]); // killing a ; // killing a unit also exits the state machine for this unit

        class DoTask {
            targetState = "DoTask";
            condition = QUOTE(CBA_missionTime >= _this getVariable [ARR_2(QQEGVAR(tasks,waitUntil), CBA_missionTime)]);
        };
    };
};
