#define TEAMSMENUTEAM(TEAMNAMEVAR) class GVAR(DOUBLES(TeamType,TEAMNAMEVAR)) {\
    property = QGVAR(DOUBLES(TeamType,TEAMNAMEVAR));\
    displayName = QUOTE(TEAMNAMEVAR Type);\
    tooltip = "Set Team to either AI, Player Controlled, or Both";\
    control = QGVAR(TeamType_Select);\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = "0";\
};\
class GVAR(DOUBLES(TeamName,TEAMNAMEVAR)) {\
    property = QGVAR(DOUBLES(TeamName,TEAMNAMEVAR));\
    displayName = "Name";\
    tooltip = "Set Team name";\
    control = "EditShort";\
    expression = SCENARIO_EXPRESSION;\
    defaultValue = QUOTE(QN(TEAMNAMEVAR Team));\
}

class GVAR(TeamsSettings) {
    displayName = "Team Settings";
    collapsed = 0;
    class Attributes {
        TEAMSMENUTEAM(BLUFOR);
        TEAMSMENUTEAM(OPFOR);
        TEAMSMENUTEAM(INDFOR);
        TEAMSMENUTEAM(CIVILIAN);
    };
};
