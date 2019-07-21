class EGVAR(Briefing,NATOStyle_BLUFOR) {
    displayName = "NATO Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,NATO_BLUFOR) {
            property = QEGVAR(Briefing,NATO_BLUFOR);
            displayName = "NATO style briefing";
            tooltip = "Enables NATO style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,NATO_Situation_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Situation_Title_BLUFOR);
            displayName = "Situation";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_SIT_Main_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Main_BLUFOR);
            displayName = "Situation";
            tooltip = "Situation";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Terrain_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Terrain_BLUFOR);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_KEYTerrain_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SIT_KEYTerrain_BLUFOR);
            displayName = "Key Terrain";
            tooltip = "Key Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Weather_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Weather_BLUFOR);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_Title_BLUFOR);
            displayName = "Enemy";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_Enemy_DIS_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_DIS_BLUFOR);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_STRENGTH_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_STRENGTH_BLUFOR);
            displayName = "Enemy Strength";
            tooltip = "Enemy Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_EQUIPMENT_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_EQUIPMENT_BLUFOR);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_APPEARANCE_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_APPEARANCE_BLUFOR);
            displayName = "Enemy Appearance";
            tooltip = "Enemy Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_MLCOA_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_MLCOA_BLUFOR);
            displayName = "Most Likely Course of Action";
            tooltip = "Most Likely Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_MDCOA_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_MDCOA_BLUFOR);
            displayName = "Most Dangerous Course of Action";
            tooltip = "Most Dangerous Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Title_BLUFOR);
            displayName = "Friendly";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_DIS_BLUFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_DIS_BLUFOR);
            displayName = "Friendly Disposition";
            tooltip = "Friendly Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_Higher_BLUFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Higher_BLUFOR);
            displayName = "Friendly Higher Units";
            tooltip = "Friendly Higher Units";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_STRENGTH_BLUFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_STRENGTH_BLUFOR);
            displayName = "Friendly Strength";
            tooltip = "Friendly Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_BLUFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_BLUFOR);
            displayName = "Friendly Appearance";
            tooltip = "Friendly Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Mission_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Mission_Title_BLUFOR);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_Mission_BLUFOR) {
            property = QEGVAR(Briefing,NATO_Mission_BLUFOR);
            displayName = "Mission";
            tooltip = "Mission";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Title_BLUFOR);
            displayName = "Execution";
            tooltip = "Execution";
            control = "CategoryTitle";
            validate = "STRING";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_INTENT_BLUFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_INTENT_BLUFOR);
            displayName = "Intent";
            tooltip = "Intent";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_MANEUVER_BLUFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_MANEUVER_BLUFOR);
            displayName = "Maneuver";
            tooltip = "Maneuver";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Timings_BLUFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Timings_BLUFOR);
            displayName = "Timings";
            tooltip = "Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_EXECUTION_Tasks_BLUFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Tasks_BLUFOR);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_Title_BLUFOR);
            displayName = "Service Support";
            tooltip = "Service Support";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_Title_BLUFOR);
            displayName = "Support";
            tooltip = "Support";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_BLUFOR);
            displayName = "Fires";
            tooltip = "Fires";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_BLUFOR);
            displayName = "Ammo";
            tooltip = "Ammo";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_Title_BLUFOR);
            displayName = "Service";
            tooltip = "Service";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_BLUFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_BLUFOR);
            displayName = "General";
            tooltip = "General";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Title_BLUFOR);
            displayName = "Command and Signals";
            tooltip = "Command and Signals";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_Title_BLUFOR);
            displayName = "Command";
            tooltip = "Command";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_BLUFOR);
            displayName = "Command";
            tooltip = "Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_Title_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_Title_BLUFOR);
            displayName = "Signals";
            tooltip = "Signals";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_FREQ_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_FREQ_BLUFOR);
            displayName = "Radio Frequencies";
            tooltip = "Radio Frequencies";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_BLUFOR);
            displayName = "Codewords";
            tooltip = "Codewords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_BLUFOR);
            displayName = "Special Signals";
            tooltip = "Special Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_BLUFOR);
            displayName = "Callsigns";
            tooltip = "Callsigns";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_BLUFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_BLUFOR);
            displayName = "Passwords";
            tooltip = "Passwords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,WPStyle_BLUFOR) {
    displayName = "Warsaw Pact Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Warsaw_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_BLUFOR);
            displayName = "Warsaw Pact style briefing";
            tooltip = "Enables Warsaw Pact style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Title_BLUFOR);
            displayName = "Preliminaries";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Weather_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Weather_BLUFOR);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Terrain_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Terrain_BLUFOR);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_Title_BLUFOR);
            displayName = "Reference Points";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Reference_DeploymentPoints_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_DeploymentPoints_BLUFOR);
            displayName = "Deployment Reference Points";
            tooltip = "Deployment Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_SubsequentPoints_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_SubsequentPoints_BLUFOR);
            displayName = "Subsequent Reference Points";
            tooltip = "Subsequent Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Title_BLUFOR);
            displayName = "Enemy";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Disp_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Disp_BLUFOR);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Equip_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Equip_BLUFOR);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_HQ_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_HQ_BLUFOR);
            displayName = "Probable Enemy HQ Location";
            tooltip = "Probable Enemy HQ Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Line_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Line_BLUFOR);
            displayName = "Probable Enemy Main Element Location";
            tooltip = "Probable Enemy Main Element Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_BLUFOR);
            displayName = "Probable Enemy Direction of Attack";
            tooltip = "Probable Enemy Direction of Attack";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Arty_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Arty_BLUFOR);
            displayName = "Probable Enemy Artillery Positions and Capability";
            tooltip = "Probable Enemy Artillery Positions and Capability";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Title_BLUFOR);
            displayName = "Higher and Adjacent Units";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Higher_Disp_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Disp_BLUFOR);
            displayName = "Description";
            tooltip = "Description";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Boundary_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Boundary_BLUFOR);
            displayName = "Boundaries";
            tooltip = "Boundaries";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Arty_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Arty_BLUFOR);
            displayName = "Location and Capability of Artillery";
            tooltip = "Location and Capability of Artillery";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_Title_BLUFOR);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Mission_Desc_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_Desc_BLUFOR);
            displayName = "Mission Statement";
            tooltip = "Mission Statement";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_DIR_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_DIR_BLUFOR);
            displayName = "End State Direction";
            tooltip = "End State Direction";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Title_BLUFOR);
            displayName = "Order";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_BLUFOR);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_Arty_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_Arty_BLUFOR);
            displayName = "Tasks for Artillery Elements";
            tooltip = "Tasks for Artillery Elements";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Timings_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Timings_BLUFOR);
            displayName = "Readiness Timings";
            tooltip = "Readiness Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Signals_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Signals_BLUFOR);
            displayName = "Signals";
            tooltip = "Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_COMM_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_COMM_Title_BLUFOR);
            displayName = "Location of the Commander";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_COMM_LOC_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_COMM_LOC_BLUFOR);
            displayName = "Location of the Commander";
            tooltip = "Location of the Commander";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_SUCC_Title_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_SUCC_Title_BLUFOR);
            displayName = "Succession of Command";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_SUCC_DESC_BLUFOR) {
            property = QEGVAR(Briefing,Warsaw_SUCC_DESC_BLUFOR);
            displayName = "Succession of Command";
            tooltip = "Succession of Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,Custom_File_BLUFOR) {
    displayName = "Briefing File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,File_BLUFOR) {
            property = QEGVAR(Briefing,File_BLUFOR);
            displayName = "Briefing File";
            tooltip = "Loads file as briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,File_Path_BLUFOR) {
            property = QEGVAR(Briefing,File_Path_BLUFOR);
            displayName = "Path to briefing file";
            tooltip = "Path to briefing file";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
class EGVAR(Briefing,Appendix_BLUFOR) {
    displayName = "Appendix Card File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Appendix_BLUFOR) {
            property = QEGVAR(Briefing,Appendix_BLUFOR);
            displayName = "Appendix File";
            tooltip = "Enables Appendix File";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,Appendix_Path_BLUFOR) {
            property = QEGVAR(Briefing,Appendix_Path_BLUFOR);
            displayName = "Path to Appendix file";
            tooltip = "Path to Appendix Briefing File";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};
