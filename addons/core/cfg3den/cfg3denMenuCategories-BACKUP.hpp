#define RESPAWNMENUTEAM(TEAMNAMEVAR) class EGVAR(Respawn,DOUBLES(Settings,TEAMNAMEVAR)) {\
    displayName = QUOTE(TEAMNAMEVAR Respawn Settings);\
    class AttributeCategories {\
        class EGVAR(Respawn,DOUBLES(TeamSettings,TEAMNAMEVAR)) {\
            displayName = QUOTE(TEAMNAMEVAR Respawn Settings);\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(Respawn,DOUBLES(Type,TEAMNAMEVAR)) {\
                    displayName = "Respawn System";\
                    tooltip = QUOTE(Type of respawn system for TEAMNAMEVAR. Place down a GameLogic object with name GVAR(DOUBLES(RESPAWN,TEAMNAMEVAR)) to define respawn location.);\
                    control = QEGVAR(Respawn,DOUBLES(Combo,TEAMNAMEVAR));\
                    defaultValue = "0";\
                    property = QEGVAR(Respawn,DOUBLES(Type,TEAMNAMEVAR));\
                    expression = SCENARIO_EXPRESSION;\
                };\
                class EGVAR(Respawn,DOUBLES(Templates,TEAMNAMEVAR)) {\
                    property = QEGVAR(Respawn,DOUBLES(Templates,TEAMNAMEVAR));\
                    displayName = "Respawn System Settings";\
                    tooltip = "";\
                    control = QEGVAR(Respawn,DOUBLES(Templates,TEAMNAMEVAR));\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "['']";\
                };\
                class EGVAR(Respawn,DOUBLES(NewTeam,TEAMNAMEVAR)) {\
                    property = QEGVAR(Respawn,DOUBLES(NewTeam,TEAMNAMEVAR));\
                    displayName = "Respawn Side";\
                    tooltip = QUOTE(Determines what side the originally TEAMNAMEVAR players will spawn on. Enabling this setting requires respawned players to join a new group.);\
                    respawnTypes[] = {1,2,3};\
                    control = QEGVAR(Respawn,Side_Combo);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "3";\
                };\
                class EGVAR(Respawn,DOUBLES(Delay,TEAMNAMEVAR)) {\
                    property = QEGVAR(Respawn,DOUBLES(Delay,TEAMNAMEVAR));\
                    displayName = "Respawn Delay";\
                    tooltip = "Delay in seconds between a player being killed and respawning. Must be more than 5 seconds.";\
                    respawnTypes[] = {1,2,3,4,5};\
                    control = QGVAR(5To20Step1_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "5";\
                    validate = "number";\
                };\
                class EGVAR(Respawn,DOUBLES(IndTickets,TEAMNAMEVAR)) {\
                    property = QEGVAR(Respawn,DOUBLES(IndTickets,TEAMNAMEVAR));\
                    displayName = "Individual Respawn Tickets";\
                    tooltip = "Number of individual respawns.";\
                    respawnTypes[] = {2};\
                    control = QGVAR(1To10Step1_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "2";\
                    validate = "number";\
                };\
                class EGVAR(Respawn,DOUBLES(TeamTickets,TEAMNAMEVAR)) {\
                    property = QEGVAR(Respawn,DOUBLES(TeamTickets,TEAMNAMEVAR));\
                    displayName = "Team Respawn Tickets";\
                    tooltip = "Number of team respawns.";\
                    respawnTypes[] = {3};\
                    control = QGVAR(10To100Step1_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "30";\
                    validate = "number";\
                };\
            };\
        };\
        \
        class EGVAR(Spectator,TEAMNAMEVAR) {\
            displayName = QUOTE(TEAMNAMEVAR Spectate Settings);\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(Spectator,DOUBLES(EnabledTeams,TEAMNAMEVAR)) {\
                    property = QEGVAR(Spectate,DOUBLES(EnabledTeams,TEAMNAMEVAR));\
                    displayName = "Spectate Teams";\
                    tooltip = "Teams that this team can spectate.";\
                    control = QEGVAR(Spectator,Teams_Attribute);\
                    defaultValue = "['BLUFOR','OPFOR','INDFOR','CIVILIAN']";\
                    expression = SCENARIO_EXPRESSION;\
                };\
                class EGVAR(Spectator,DOUBLES(KillCam,TEAMNAMEVAR)) {\
                    property = QEGVAR(Spectate,DOUBLES(KillCam,TEAMNAMEVAR));\
                    displayName = "Killcam";\
                    tooltip = "This setting enables the specator killcam functionality.";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "true";\
                };\
                class EGVAR(Spectator,DOUBLES(AIEnabled,TEAMNAMEVAR)) {\
                    property = QEGVAR(Spectate,DOUBLES(AIEnabled,TEAMNAMEVAR));\
                    displayName = "Spectate AI";\
                    tooltip = "Enable Spectating AI Entities.";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "true";\
                };\
                class EGVAR(Spectator,DOUBLES(FreeCam,TEAMNAMEVAR)) {\
                    property = QEGVAR(Spectate,DOUBLES(FreeCam,TEAMNAMEVAR));\
                    displayName = "Spectator Freecam";\
                    tooltip = "Enable Freecam Ability in Spectator.";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "true";\
                };\
                class EGVAR(Spectator,DOUBLES(3rdPerson,TEAMNAMEVAR)) {\
                    property = QEGVAR(Spectate,DOUBLES(3rdPerson,TEAMNAMEVAR));\
                    displayName = "Spectator Third Person";\
                    tooltip = "Enable Third Person Ability in Spectator.";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "true";\
                };\
            };\
        };\
        class EGVAR(TeamJIPSettings,TEAMNAMEVAR) {\
            displayName = QUOTE(TEAMNAMEVAR JiP Settings);\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(JIP,DOUBLES(Type,TEAMNAMEVAR)) {\
                    property = QEGVAR(JIP,DOUBLES(Type,TEAMNAMEVAR));\
                    displayName = "JiP Type";\
                    tooltip = "TELEPORT: Player can teleport to his squad. TRANSPORT: Player can send a hint to all group leaders requesting transport. DENY: Player is killed and put in spectator.";\
                    control = QEGVAR(JIP,TypeAtt);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "0";\
                };\
                class EGVAR(JIP,DOUBLES(Distance,TEAMNAMEVAR)) {\
                    property = QEGVAR(JIP,DOUBLES(Distance,TEAMNAMEVAR));\
                    displayName = "JiP Distance";\
                    tooltip = "If distance to group members upon spawn is greater than this you will be granted the defined JiP action";\
                    control = QGVAR(50To200Step50_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "200";\
                };\
                class EGVAR(JIP,DOUBLES(SpawnDistance,TEAMNAMEVAR)) {\
                    property = QEGVAR(JIP,DOUBLES(SpawnDistance,TEAMNAMEVAR));\
                    displayName = "Spawn Radius";\
                    tooltip = "Exiting this radius will remove the JiP actions from the player.";\
                    control = QGVAR(50To200Step50_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "50";\
                };\
            };\
        };\
    };\
}


class EGVAR(Respawn,Settings_Main) {
    displayName = "General Respawn Settings";
    class AttributeCategories {
        #include "Respawn\MainRespawn.hpp"
    };
};

RESPAWNMENUTEAM(Blufor);
RESPAWNMENUTEAM(Opfor);
RESPAWNMENUTEAM(Indfor);
RESPAWNMENUTEAM(Civilian);

class EGVAR(EndConditions,SettingsMenu) {
    displayName = "End Condition Settings";
    class AttributeCategories {
      #include "EndConditions\TimelimitMenu.hpp"
      #include "EndConditions\CustomFileMenu.hpp"
      #include "EndConditions\SleepMenu.hpp"
    };
};

#define CATEGORYMAINMENU(MENUNUM) class EGVAR(EndConditions,TRIPLES(Category,MENUNUM,Menu)) {\
    displayName = QUOTE(Category MENUNUM Settings);\
    class AttributeCategories {\
        class EGVAR(EndConditions,DOUBLES(MainSettings_Category,MENUNUM)) {\
            displayName = "Category Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(Enabled,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(Enabled,MENUNUM));\
                    displayName = "Enable Category";\
                    tooltip = "Toggle Activation of the End Condition Category";\
                    control = "CheckBoxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(Mode,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(Mode,MENUNUM));\
                    displayName = "Category Mode";\
                    tooltip = "Whether or not the condition fires if any condition is true, or if all conditions are true. Extract condition must be true in both cases.";\
                    control = QEGVAR(EndConditions,ModeAttribute);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "0";\
                };\
                class EGVAR(EndConditions,DOUBLES(Message,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(Message,MENUNUM));\
                    displayName = "Category Message";\
                    tooltip = "Message displayed when end condition category is triggered";\
                    control = "Edit";\
                    validate = "string";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = QUOTE(QN(End condition MENUNUM fired!));\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(CasualtySettings_Category,MENUNUM)) {\
            displayName = "Casualty Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_BLUFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_BLUFOR,MENUNUM));\
                    displayName = "BLUFOR Casualty";\
                    tooltip = "Enables casualty limit for this team";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_BLUFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_BLUFOR,MENUNUM));\
                    displayName = "Casualty Percentage";\
                    tooltip = "End condition fires when team casualty percentage is over this number";\
                    control = QGVAR(5To100Step5_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "75";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_OPFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_OPFOR,MENUNUM));\
                    displayName = "OPFOR Casualty";\
                    tooltip = "Enables casualty limit for this team";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_OPFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_OPFOR,MENUNUM));\
                    displayName = "Casualty Percentage";\
                    tooltip = "End condition fires when team casualty percentage is over this number";\
                    control = QGVAR(5To100Step5_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "75";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_INDFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_INDFOR,MENUNUM));\
                    displayName = "Indfor Casualty";\
                    tooltip = "Enables casualty limit for this team";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_INDFOR,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_INDFOR,MENUNUM));\
                    displayName = "Casualty Percentage";\
                    tooltip = "End condition fires when team casualty percentage is over this number";\
                    control = QGVAR(5To100Step5_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "75";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_CIV,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_CIV,MENUNUM));\
                    displayName = "CIVILIAN Casualty";\
                    tooltip = "Enables casualty limit for this team";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_CIV,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_CIV,MENUNUM));\
                    displayName = "Casualty Percentage";\
                    tooltip = "End condition fires when team casualty percentage is over this number";\
                    control = QGVAR(5To100Step5_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "75";\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(EntitySettings_Category,MENUNUM)) {\
            displayName = "Entity Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(EntitiesAlive_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(EntitiesAlive_Array,MENUNUM));\
                    displayName = "Alive Entities";\
                    tooltip = "Array of entities checked for alive status. Leave blank to disable";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
                class EGVAR(EndConditions,DOUBLES(EntitiesDead_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(EntitiesDead_Array,MENUNUM));\
                    displayName = "Dead Entities";\
                    tooltip = "Array of entities checked for dead status. Leave blank to disable";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
                class EGVAR(EndConditions,DOUBLES(EntitiesDamaged_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(EntitiesDamaged_Array,MENUNUM));\
                    displayName = "Damaged Entities";\
                    tooltip = "Array of entities checked for over 50 percent damage or immobilized status. Includes dead state. Leave blank to disable";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(HostageSettings_Category,MENUNUM)) {\
            displayName = "Hostage Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(HostageRescued_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(HostageRescued_Array,MENUNUM));\
                    displayName = "Hostage(s) Rescued";\
                    tooltip = "Array of hostages that must be rescued for the end condition to fire. leave blank to disable.";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(VariableSettings_Category,MENUNUM)) {\
            displayName = "Custom Variable Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(CustomVariables_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CustomVariables_Array,MENUNUM));\
                    displayName = "Custom Variables";\
                    tooltip = "Array of variables to check for true status. Leave blank to disable";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(CaptureZoneSettings_Category,MENUNUM)) {\
            displayName = "CaptureZone Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Array,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Array,MENUNUM));\
                    displayName = "CaptureZone Names";\
                    tooltip = "List of CaptureZones names that must be captured for the end condition to fire. Leave empty to disable.";\
                    control = "EditArray";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "[]";\
                };\
                class EGVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Team,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Team,MENUNUM));\
                    displayName = "CaptureZone Team";\
                    tooltip = "Team that must activate the CaptureZones for the condition to fire.";\
                    control = QEGVAR(EndConditions,CaptureZoneTeam);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "0";\
                };\
            };\
        };\
        \
        class EGVAR(EndConditions,DOUBLES(ExtractionSettings_Category,MENUNUM)) {\
            displayName = "Extraction Settings";\
            collapsed = 0;\
            class Attributes {\
                class EGVAR(EndConditions,DOUBLES(ExtractionEnabled,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(ExtractionEnabled,MENUNUM));\
                    displayName = "Require Extraction";\
                    tooltip = "Require Extraction in addition to end conditions for this category. This is a secondary end-condition which requires a primary end-condition (all conditions above). Ratio/Players need to leave the marked area first before the condition is triggered.";\
                    control = "CheckBoxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                 class EGVAR(EndConditions,DOUBLES(ExtractionForced,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(ExtractionForced,MENUNUM));\
                    displayName = "Force Extraction End";\
                    tooltip = "If enabled then the mission will end regardless of any other conditions above and the extraction is met!";\
                    control = "CheckBox";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class EGVAR(EndConditions,DOUBLES(ExtractionTeam,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(ExtractionTeam,MENUNUM));\
                    displayName = "Team";\
                    tooltip = "Team required to be in extract area.";\
                    control = QEGVAR(EndConditions,ExtractTeam);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "0";\
                };\
                class EGVAR(EndConditions,DOUBLES(ExtractionMarker,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(ExtractionMarker,MENUNUM));\
                    displayName = "Extraction Area";\
                    tooltip = "Extraction Area.";\
                    control = QEGVAR(EndConditions,ExtractionAreaSelectAttribute);\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "'No Area Selected'";\
                };\
                class EGVAR(EndConditions,DOUBLES(ExtractionRatio,MENUNUM)) {\
                    property = QEGVAR(EndConditions,DOUBLES(ExtractionRatio,MENUNUM));\
                    displayName = "Ratio";\
                    tooltip = "Percentage of alive personnel inside the marker to be considered extracted. Default 75";\
                    control = QGVAR(5To100Step5_Slider);\
                    expression = SCENARIO_EXPRESSION;\
                    validate = "number";\
                    defaultValue = "75";\
                };\
            };\
        };\
    };\
}

CATEGORYMAINMENU(1);
CATEGORYMAINMENU(2);
CATEGORYMAINMENU(3);
CATEGORYMAINMENU(4);
CATEGORYMAINMENU(5);
CATEGORYMAINMENU(6);
