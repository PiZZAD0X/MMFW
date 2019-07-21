class EGVAR(Briefing,NATOStyle_Indfor) {
    displayName = "NATO Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,NATO_Indfor) {
            property = QEGVAR(Briefing,NATO_Indfor);
            displayName = "NATO style briefing";
            tooltip = "Enables NATO style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,NATO_Situation_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_Situation_Title_Indfor);
            displayName = "Situation";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_SIT_Main_Indfor) {
            property = QEGVAR(Briefing,NATO_SIT_Main_Indfor);
            displayName = "Situation";
            tooltip = "Situation";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Terrain_Indfor) {
            property = QEGVAR(Briefing,NATO_SIT_Terrain_Indfor);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_KEYTerrain_Indfor) {
            property = QEGVAR(Briefing,NATO_SIT_KEYTerrain_Indfor);
            displayName = "Key Terrain";
            tooltip = "Key Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Weather_Indfor) {
            property = QEGVAR(Briefing,NATO_SIT_Weather_Indfor);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_Title_Indfor);
            displayName = "Enemy";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_Enemy_DIS_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_DIS_Indfor);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_STRENGTH_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_STRENGTH_Indfor);
            displayName = "Enemy Strength";
            tooltip = "Enemy Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_EQUIPMENT_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_EQUIPMENT_Indfor);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_APPEARANCE_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_APPEARANCE_Indfor);
            displayName = "Enemy Appearance";
            tooltip = "Enemy Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_MLCOA_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_MLCOA_Indfor);
            displayName = "Most Likely Course of Action";
            tooltip = "Most Likely Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_MDCOA_Indfor) {
            property = QEGVAR(Briefing,NATO_Enemy_MDCOA_Indfor);
            displayName = "Most Dangerous Course of Action";
            tooltip = "Most Dangerous Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Title_Indfor);
            displayName = "Friendly";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_DIS_Indfor) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_DIS_Indfor);
            displayName = "Friendly Disposition";
            tooltip = "Friendly Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_Higher_Indfor) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Higher_Indfor);
            displayName = "Friendly Higher Units";
            tooltip = "Friendly Higher Units";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_STRENGTH_Indfor) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_STRENGTH_Indfor);
            displayName = "Friendly Strength";
            tooltip = "Friendly Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_Indfor) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_Indfor);
            displayName = "Friendly Appearance";
            tooltip = "Friendly Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Mission_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_Mission_Title_Indfor);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_Mission_Indfor) {
            property = QEGVAR(Briefing,NATO_Mission_Indfor);
            displayName = "Mission";
            tooltip = "Mission";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Title_Indfor);
            displayName = "Execution";
            tooltip = "Execution";
            control = "CategoryTitle";
            validate = "STRING";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_INTENT_Indfor) {
            property = QEGVAR(Briefing,NATO_EXECUTION_INTENT_Indfor);
            displayName = "Intent";
            tooltip = "Intent";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_MANEUVER_Indfor) {
            property = QEGVAR(Briefing,NATO_EXECUTION_MANEUVER_Indfor);
            displayName = "Maneuver";
            tooltip = "Maneuver";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Timings_Indfor) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Timings_Indfor);
            displayName = "Timings";
            tooltip = "Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Tasks_Indfor) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Tasks_Indfor);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_Title_Indfor);
            displayName = "Service Support";
            tooltip = "Service Support";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_Title_Indfor);
            displayName = "Support";
            tooltip = "Support";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_Indfor);
            displayName = "Fires";
            tooltip = "Fires";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_Indfor);
            displayName = "Ammo";
            tooltip = "Ammo";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_Title_Indfor);
            displayName = "Service";
            tooltip = "Service";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_Indfor) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_Indfor);
            displayName = "General";
            tooltip = "General";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Title_Indfor);
            displayName = "Command and Signals";
            tooltip = "Command and Signals";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_Title_Indfor);
            displayName = "Command";
            tooltip = "Command";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_Indfor);
            displayName = "Command";
            tooltip = "Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_Title_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_Title_Indfor);
            displayName = "Signals";
            tooltip = "Signals";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_FREQ_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_FREQ_Indfor);
            displayName = "Radio Frequencies";
            tooltip = "Radio Frequencies";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_Indfor);
            displayName = "Codewords";
            tooltip = "Codewords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_Indfor);
            displayName = "Special Signals";
            tooltip = "Special Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_Indfor);
            displayName = "Callsigns";
            tooltip = "Callsigns";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_Indfor) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_Indfor);
            displayName = "Passwords";
            tooltip = "Passwords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,WPStyle_Indfor) {
    displayName = "Warsaw Pact Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Warsaw_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Indfor);
            displayName = "Warsaw Pact style briefing";
            tooltip = "Enables Warsaw Pact style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Title_Indfor);
            displayName = "Preliminaries";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Weather_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Weather_Indfor);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Terrain_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Terrain_Indfor);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Reference_Title_Indfor);
            displayName = "Reference Points";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Reference_DeploymentPoints_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Reference_DeploymentPoints_Indfor);
            displayName = "Deployment Reference Points";
            tooltip = "Deployment Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_SubsequentPoints_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Reference_SubsequentPoints_Indfor);
            displayName = "Subsequent Reference Points";
            tooltip = "Subsequent Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Title_Indfor);
            displayName = "Enemy";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Disp_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Disp_Indfor);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Equip_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Equip_Indfor);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_HQ_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_HQ_Indfor);
            displayName = "Probable Enemy HQ Location";
            tooltip = "Probable Enemy HQ Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Line_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Line_Indfor);
            displayName = "Probable Enemy Main Element Location";
            tooltip = "Probable Enemy Main Element Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_Indfor);
            displayName = "Probable Enemy Direction of Attack";
            tooltip = "Probable Enemy Direction of Attack";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Arty_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Arty_Indfor);
            displayName = "Probable Enemy Artillery Positions and Capability";
            tooltip = "Probable Enemy Artillery Positions and Capability";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Higher_Title_Indfor);
            displayName = "Higher and Adjacent Units";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Higher_Disp_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Higher_Disp_Indfor);
            displayName = "Description";
            tooltip = "Description";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Boundary_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Higher_Boundary_Indfor);
            displayName = "Boundaries";
            tooltip = "Boundaries";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Arty_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Higher_Arty_Indfor);
            displayName = "Location and Capability of Artillery";
            tooltip = "Location and Capability of Artillery";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Mission_Title_Indfor);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Mission_Desc_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Mission_Desc_Indfor);
            displayName = "Mission Statement";
            tooltip = "Mission Statement";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_DIR_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Mission_DIR_Indfor);
            displayName = "End State Direction";
            tooltip = "End State Direction";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Order_Title_Indfor);
            displayName = "Order";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_Indfor);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_Arty_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_Arty_Indfor);
            displayName = "Tasks for Artillery Elements";
            tooltip = "Tasks for Artillery Elements";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Timings_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Order_Timings_Indfor);
            displayName = "Readiness Timings";
            tooltip = "Readiness Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Signals_Indfor) {
            property = QEGVAR(Briefing,Warsaw_Order_Signals_Indfor);
            displayName = "Signals";
            tooltip = "Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_COMM_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_COMM_Title_Indfor);
            displayName = "Location of the Commander";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_COMM_LOC_Indfor) {
            property = QEGVAR(Briefing,Warsaw_COMM_LOC_Indfor);
            displayName = "Location of the Commander";
            tooltip = "Location of the Commander";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_SUCC_Title_Indfor) {
            property = QEGVAR(Briefing,Warsaw_SUCC_Title_Indfor);
            displayName = "Succession of Command";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_SUCC_DESC_Indfor) {
            property = QEGVAR(Briefing,Warsaw_SUCC_DESC_Indfor);
            displayName = "Succession of Command";
            tooltip = "Succession of Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,Custom_File_Indfor) {
    displayName = "Briefing File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,File_Indfor) {
            property = QEGVAR(Briefing,File_Indfor);
            displayName = "Briefing File";
            tooltip = "Loads file as briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,File_Path_Indfor) {
            property = QEGVAR(Briefing,File_Path_Indfor);
            displayName = "Path to briefing file";
            tooltip = "Path to briefing file";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,Appendix_Indfor) {
    displayName = "Appendix Card File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Appendix_Indfor) {
            property = QEGVAR(Briefing,Appendix_Indfor);
            displayName = "Appendix File";
            tooltip = "Enables Appendix File";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,Appendix_Path_Indfor) {
            property = QEGVAR(Briefing,Appendix_Path_Indfor);
            displayName = "Path to Appendix file";
            tooltip = "Path to Appendix Briefing File";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
