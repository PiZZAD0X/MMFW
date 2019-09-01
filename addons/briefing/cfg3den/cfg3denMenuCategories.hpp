#define BRIEFINGTEAMMENU(TEAMNAME) class GVAR(DOUBLES(Menu,TEAMNAME)) {\
    displayName = QUOTE(TEAMNAME Briefing);\
    class AttributeCategories {\
        class GVAR(DOUBLES(NATOStyle,TEAMNAME)) {\
            displayName = "NATO Style Briefing";\
            collapsed = 1;\
            class Attributes {\
                class GVAR(DOUBLES(NATO,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO,TEAMNAME));\
                    displayName = "NATO style briefing";\
                    tooltip = "Enables NATO style briefing";\
                    control = "CheckboxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class GVAR(DOUBLES(NATO_Situation_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Situation_Title,TEAMNAME));\
                    displayName = "Situation";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(NATO_SIT_Main,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SIT_Main,TEAMNAME));\
                    displayName = "Situation";\
                    tooltip = "Situation";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SIT_Terrain,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SIT_Terrain,TEAMNAME));\
                    displayName = "Terrain";\
                    tooltip = "Terrain";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SIT_KEYTerrain,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SIT_KEYTerrain,TEAMNAME));\
                    displayName = "Key Terrain";\
                    tooltip = "Key Terrain";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SIT_Weather,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SIT_Weather,TEAMNAME));\
                    displayName = "Weather";\
                    tooltip = "Weather";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_Title,TEAMNAME));\
                    displayName = "Enemy";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_DIS,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_DIS,TEAMNAME));\
                    displayName = "Enemy Disposition";\
                    tooltip = "Enemy Disposition";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_STRENGTH,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_STRENGTH,TEAMNAME));\
                    displayName = "Enemy Strength";\
                    tooltip = "Enemy Strength";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_EQUIPMENT,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_EQUIPMENT,TEAMNAME));\
                    displayName = "Enemy Equipment";\
                    tooltip = "Enemy Equipment";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_APPEARANCE,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_APPEARANCE,TEAMNAME));\
                    displayName = "Enemy Appearance";\
                    tooltip = "Enemy Appearance";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_MLCOA,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_MLCOA,TEAMNAME));\
                    displayName = "Most Likely Course of Action";\
                    tooltip = "Most Likely Course of Action";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Enemy_MDCOA,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Enemy_MDCOA,TEAMNAME));\
                    displayName = "Most Dangerous Course of Action";\
                    tooltip = "Most Dangerous Course of Action";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_FRIENDLY_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_FRIENDLY_Title,TEAMNAME));\
                    displayName = "Friendly";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(NATO_FRIENDLY_DIS,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_FRIENDLY_DIS,TEAMNAME));\
                    displayName = "Friendly Disposition";\
                    tooltip = "Friendly Disposition";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_FRIENDLY_Higher,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_FRIENDLY_Higher,TEAMNAME));\
                    displayName = "Friendly Higher Units";\
                    tooltip = "Friendly Higher Units";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_FRIENDLY_STRENGTH,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_FRIENDLY_STRENGTH,TEAMNAME));\
                    displayName = "Friendly Strength";\
                    tooltip = "Friendly Strength";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_FRIENDLY_APPEARANCE,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_FRIENDLY_APPEARANCE,TEAMNAME));\
                    displayName = "Friendly Appearance";\
                    tooltip = "Friendly Appearance";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_Mission_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Mission_Title,TEAMNAME));\
                    displayName = "Mission";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(NATO_Mission,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_Mission,TEAMNAME));\
                    displayName = "Mission";\
                    tooltip = "Mission";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_EXECUTION_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_EXECUTION_Title,TEAMNAME));\
                    displayName = "Execution";\
                    tooltip = "Execution";\
                    control = "CategoryTitle";\
                    validate = "STRING";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_EXECUTION_INTENT,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_EXECUTION_INTENT,TEAMNAME));\
                    displayName = "Intent";\
                    tooltip = "Intent";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_EXECUTION_MANEUVER,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_EXECUTION_MANEUVER,TEAMNAME));\
                    displayName = "Maneuver";\
                    tooltip = "Maneuver";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_EXECUTION_Timings,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_EXECUTION_Timings,TEAMNAME));\
                    displayName = "Timings";\
                    tooltip = "Timings";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_EXECUTION_Tasks,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_EXECUTION_Tasks,TEAMNAME));\
                    displayName = "Tasks";\
                    tooltip = "Tasks";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_Title,TEAMNAME));\
                    displayName = "Service Support";\
                    tooltip = "Service Support";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_SUPPORT_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_SUPPORT_Title,TEAMNAME));\
                    displayName = "Support";\
                    tooltip = "Support";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_SUPPORT_FIRES,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_SUPPORT_FIRES,TEAMNAME));\
                    displayName = "Fires";\
                    tooltip = "Fires";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_SUPPORT_AMMO,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_SUPPORT_AMMO,TEAMNAME));\
                    displayName = "Ammo";\
                    tooltip = "Ammo";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_SERVICE_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_SERVICE_Title,TEAMNAME));\
                    displayName = "Service";\
                    tooltip = "Service";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_SANDS_SERVICE_GENERAL,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_SANDS_SERVICE_GENERAL,TEAMNAME));\
                    displayName = "General";\
                    tooltip = "General";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Title,TEAMNAME));\
                    displayName = "Command and Signals";\
                    tooltip = "Command and Signals";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_COMMAND_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_COMMAND_Title,TEAMNAME));\
                    displayName = "Command";\
                    tooltip = "Command";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_COMMAND,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_COMMAND,TEAMNAME));\
                    displayName = "Command";\
                    tooltip = "Command";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_Title,TEAMNAME));\
                    displayName = "Signals";\
                    tooltip = "Signals";\
                    control = "SubTitle";\
                    expression = "true";\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_FREQ,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_FREQ,TEAMNAME));\
                    displayName = "Radio Frequencies";\
                    tooltip = "Radio Frequencies";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_CODEWORDS,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_CODEWORDS,TEAMNAME));\
                    displayName = "Codewords";\
                    tooltip = "Codewords";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_SPECIAL,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_SPECIAL,TEAMNAME));\
                    displayName = "Special Signals";\
                    tooltip = "Special Signals";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_CALLSIGNS,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_CALLSIGNS,TEAMNAME));\
                    displayName = "Callsigns";\
                    tooltip = "Callsigns";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(NATO_CANDS_Signals_PASSWORDS,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(NATO_CANDS_Signals_PASSWORDS,TEAMNAME));\
                    displayName = "Passwords";\
                    tooltip = "Passwords";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
            };\
        };\
        class GVAR(DOUBLES(WPStyle,TEAMNAME)) {\
            displayName = "Warsaw Pact Style Briefing";\
            collapsed = 1;\
            class Attributes {\
                class GVAR(DOUBLES(Warsaw,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw,TEAMNAME));\
                    displayName = "Warsaw Pact style briefing";\
                    tooltip = "Enables Warsaw Pact style briefing";\
                    control = "CheckboxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class GVAR(DOUBLES(Warsaw_Preliminaries_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Preliminaries_Title,TEAMNAME));\
                    displayName = "Preliminaries";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Preliminaries_Weather,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Preliminaries_Weather,TEAMNAME));\
                    displayName = "Weather";\
                    tooltip = "Weather";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Preliminaries_Terrain,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Preliminaries_Terrain,TEAMNAME));\
                    displayName = "Terrain";\
                    tooltip = "Terrain";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Reference_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Reference_Title,TEAMNAME));\
                    displayName = "Reference Points";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Reference_DeploymentPoints,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Reference_DeploymentPoints,TEAMNAME));\
                    displayName = "Deployment Reference Points";\
                    tooltip = "Deployment Reference Points";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Reference_SubsequentPoints,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Reference_SubsequentPoints,TEAMNAME));\
                    displayName = "Subsequent Reference Points";\
                    tooltip = "Subsequent Reference Points";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Title,TEAMNAME));\
                    displayName = "Enemy";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Disp,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Disp,TEAMNAME));\
                    displayName = "Enemy Disposition";\
                    tooltip = "Enemy Disposition";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Equip,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Equip,TEAMNAME));\
                    displayName = "Enemy Equipment";\
                    tooltip = "Enemy Equipment";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Prob_HQ,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Prob_HQ,TEAMNAME));\
                    displayName = "Probable Enemy HQ Location";\
                    tooltip = "Probable Enemy HQ Location";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Prob_Line,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Prob_Line,TEAMNAME));\
                    displayName = "Probable Enemy Main Element Location";\
                    tooltip = "Probable Enemy Main Element Location";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Prob_Dir_Attack,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Prob_Dir_Attack,TEAMNAME));\
                    displayName = "Probable Enemy Direction of Attack";\
                    tooltip = "Probable Enemy Direction of Attack";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Enemy_Prob_Arty,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Enemy_Prob_Arty,TEAMNAME));\
                    displayName = "Probable Enemy Artillery Positions and Capability";\
                    tooltip = "Probable Enemy Artillery Positions and Capability";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Higher_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Higher_Title,TEAMNAME));\
                    displayName = "Higher and Adjacent Units";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Higher_Disp,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Higher_Disp,TEAMNAME));\
                    displayName = "Description";\
                    tooltip = "Description";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Higher_Boundary,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Higher_Boundary,TEAMNAME));\
                    displayName = "Boundaries";\
                    tooltip = "Boundaries";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Higher_Arty,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Higher_Arty,TEAMNAME));\
                    displayName = "Location and Capability of Artillery";\
                    tooltip = "Location and Capability of Artillery";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Mission_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Mission_Title,TEAMNAME));\
                    displayName = "Mission";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Mission_Desc,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Mission_Desc,TEAMNAME));\
                    displayName = "Mission Statement";\
                    tooltip = "Mission Statement";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Mission_DIR,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Mission_DIR,TEAMNAME));\
                    displayName = "End State Direction";\
                    tooltip = "End State Direction";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Order_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Order_Title,TEAMNAME));\
                    displayName = "Order";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_Order_Tasks,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Order_Tasks,TEAMNAME));\
                    displayName = "Tasks";\
                    tooltip = "Tasks";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Order_Tasks_Arty,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Order_Tasks_Arty,TEAMNAME));\
                    displayName = "Tasks for Artillery Elements";\
                    tooltip = "Tasks for Artillery Elements";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Order_Timings,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Order_Timings,TEAMNAME));\
                    displayName = "Readiness Timings";\
                    tooltip = "Readiness Timings";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_Order_Signals,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_Order_Signals,TEAMNAME));\
                    displayName = "Signals";\
                    tooltip = "Signals";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_COMM_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_COMM_Title,TEAMNAME));\
                    displayName = "Location of the Commander";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_COMM_LOC,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_COMM_LOC,TEAMNAME));\
                    displayName = "Location of the Commander";\
                    tooltip = "Location of the Commander";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
                class GVAR(DOUBLES(Warsaw_SUCC_Title,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_SUCC_Title,TEAMNAME));\
                    displayName = "Succession of Command";\
                    control = "CategoryTitle";\
                    expression = "true";\
                    defaultValue = "";\
                };\
                class GVAR(DOUBLES(Warsaw_SUCC_DESC,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Warsaw_SUCC_DESC,TEAMNAME));\
                    displayName = "Succession of Command";\
                    tooltip = "Succession of Command";\
                    control = "EditMulti5";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
            };\
        };\
        class GVAR(DOUBLES(Custom_File,TEAMNAME)) {\
            displayName = "Briefing File";\
            collapsed = 1;\
            class Attributes {\
                class GVAR(DOUBLES(File,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(File,TEAMNAME));\
                    displayName = "Briefing File";\
                    tooltip = "Loads file as briefing";\
                    control = "CheckboxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class GVAR(DOUBLES(File_Path,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(File_Path,TEAMNAME));\
                    displayName = "Path to briefing file";\
                    tooltip = "Path to briefing file";\
                    control = "Edit";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
            };\
        };\
        class GVAR(DOUBLES(Appendix,TEAMNAME)) {\
            displayName = "Appendix Card File";\
            collapsed = 1;\
            class Attributes {\
                class GVAR(DOUBLES(Appendix,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Appendix,TEAMNAME));\
                    displayName = "Appendix File";\
                    tooltip = "Enables Appendix File";\
                    control = "CheckboxState";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "false";\
                };\
                class GVAR(DOUBLES(Appendix_Path,TEAMNAME)) {\
                    property = QGVAR(DOUBLES(Appendix_Path,TEAMNAME));\
                    displayName = "Path to Appendix file";\
                    tooltip = "Path to Appendix Briefing File";\
                    control = "Edit";\
                    validate = "STRING";\
                    expression = SCENARIO_EXPRESSION;\
                    defaultValue = "''";\
                };\
            };\
        };\
    };\
}

BRIEFINGTEAMMENU(Blufor);
BRIEFINGTEAMMENU(Opfor);
BRIEFINGTEAMMENU(Indfor);
BRIEFINGTEAMMENU(Civilian);

class GVAR(MissionNotes) {
    displayName = "Mission Notes";
    class AttributeCategories {
        #include "Briefing\MissionNotesMenu.hpp"
    };
};
