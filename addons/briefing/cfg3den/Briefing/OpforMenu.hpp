class EGVAR(Briefing,NATOStyle_OPFOR) {
    displayName = "NATO Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,NATO_OPFOR) {
            property = QEGVAR(Briefing,NATO_OPFOR);
            displayName = "NATO style briefing";
            tooltip = "Enables NATO style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,NATO_Situation_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_Situation_Title_OPFOR);
            displayName = "Situation";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_SIT_Main_OPFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Main_OPFOR);
            displayName = "Situation";
            tooltip = "Situation";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Terrain_OPFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Terrain_OPFOR);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_KEYTerrain_OPFOR) {
            property = QEGVAR(Briefing,NATO_SIT_KEYTerrain_OPFOR);
            displayName = "Key Terrain";
            tooltip = "Key Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_SIT_Weather_OPFOR) {
            property = QEGVAR(Briefing,NATO_SIT_Weather_OPFOR);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_Title_OPFOR);
            displayName = "Enemy";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,NATO_Enemy_DIS_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_DIS_OPFOR);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_STRENGTH_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_STRENGTH_OPFOR);
            displayName = "Enemy Strength";
            tooltip = "Enemy Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_EQUIPMENT_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_EQUIPMENT_OPFOR);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_APPEARANCE_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_APPEARANCE_OPFOR);
            displayName = "Enemy Appearance";
            tooltip = "Enemy Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,NATO_Enemy_MLCOA_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_MLCOA_OPFOR);
            displayName = "Most Likely Course of Action";
            tooltip = "Most Likely Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_Enemy_MDCOA_OPFOR) {
            property = QEGVAR(Briefing,NATO_Enemy_MDCOA_OPFOR);
            displayName = "Most Dangerous Course of Action";
            tooltip = "Most Dangerous Course of Action";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_FRIENDLY_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Title_OPFOR);
            displayName = "Friendly";
            control = "SubTitle";
            expression = "true";
            defaultValue = "";

        };
        class EGVAR(Briefing,NATO_FRIENDLY_DIS_OPFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_DIS_OPFOR);
            displayName = "Friendly Disposition";
            tooltip = "Friendly Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_FRIENDLY_Higher_OPFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_Higher_OPFOR);
            displayName = "Friendly Higher Units";
            tooltip = "Friendly Higher Units";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_FRIENDLY_STRENGTH_OPFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_STRENGTH_OPFOR);
            displayName = "Friendly Strength";
            tooltip = "Friendly Strength";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_OPFOR) {
            property = QEGVAR(Briefing,NATO_FRIENDLY_APPEARANCE_OPFOR);
            displayName = "Friendly Appearance";
            tooltip = "Friendly Appearance";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_Mission_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_Mission_Title_OPFOR);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";

        };
        class EGVAR(Briefing,NATO_Mission_OPFOR) {
            property = QEGVAR(Briefing,NATO_Mission_OPFOR);
            displayName = "Mission";
            tooltip = "Mission";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_EXECUTION_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Title_OPFOR);
            displayName = "Execution";
            tooltip = "Execution";
            control = "CategoryTitle";
            validate = "STRING";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_EXECUTION_INTENT_OPFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_INTENT_OPFOR);
            displayName = "Intent";
            tooltip = "Intent";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_EXECUTION_MANEUVER_OPFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_MANEUVER_OPFOR);
            displayName = "Maneuver";
            tooltip = "Maneuver";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_EXECUTION_Timings_OPFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Timings_OPFOR);
            displayName = "Timings";
            tooltip = "Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_EXECUTION_Tasks_OPFOR) {
            property = QEGVAR(Briefing,NATO_EXECUTION_Tasks_OPFOR);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_Title_OPFOR);
            displayName = "Service Support";
            tooltip = "Service Support";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_Title_OPFOR);
            displayName = "Support";
            tooltip = "Support";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_FIRES_OPFOR);
            displayName = "Fires";
            tooltip = "Fires";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SUPPORT_AMMO_OPFOR);
            displayName = "Ammo";
            tooltip = "Ammo";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_Title_OPFOR);
            displayName = "Service";
            tooltip = "Service";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_OPFOR) {
            property = QEGVAR(Briefing,NATO_SANDS_SERVICE_GENERAL_OPFOR);
            displayName = "General";
            tooltip = "General";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Title_OPFOR);
            displayName = "Command and Signals";
            tooltip = "Command and Signals";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_Title_OPFOR);
            displayName = "Command";
            tooltip = "Command";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_COMMAND_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_COMMAND_OPFOR);
            displayName = "Command";
            tooltip = "Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_Title_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_Title_OPFOR);
            displayName = "Signals";
            tooltip = "Signals";
            control = "SubTitle";
            expression = "true";
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_FREQ_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_FREQ_OPFOR);
            displayName = "Radio Frequencies";
            tooltip = "Radio Frequencies";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CODEWORDS_OPFOR);
            displayName = "Codewords";
            tooltip = "Codewords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_SPECIAL_OPFOR);
            displayName = "Special Signals";
            tooltip = "Special Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_CALLSIGNS_OPFOR);
            displayName = "Callsigns";
            tooltip = "Callsigns";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
        class EGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_OPFOR) {
            property = QEGVAR(Briefing,NATO_CANDS_Signals_PASSWORDS_OPFOR);
            displayName = "Passwords";
            tooltip = "Passwords";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};

class EGVAR(Briefing,WPStyle_OPFOR) {
    displayName = "Warsaw Pact Style Briefing";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Warsaw_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_OPFOR);
            displayName = "Warsaw Pact style briefing";
            tooltip = "Enables Warsaw Pact style briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Title_OPFOR);
            displayName = "Preliminaries";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Weather_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Weather_OPFOR);
            displayName = "Weather";
            tooltip = "Weather";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Preliminaries_Terrain_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Preliminaries_Terrain_OPFOR);
            displayName = "Terrain";
            tooltip = "Terrain";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_Title_OPFOR);
            displayName = "Reference Points";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Reference_DeploymentPoints_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_DeploymentPoints_OPFOR);
            displayName = "Deployment Reference Points";
            tooltip = "Deployment Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Reference_SubsequentPoints_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Reference_SubsequentPoints_OPFOR);
            displayName = "Subsequent Reference Points";
            tooltip = "Subsequent Reference Points";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Title_OPFOR);
            displayName = "Enemy";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Disp_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Disp_OPFOR);
            displayName = "Enemy Disposition";
            tooltip = "Enemy Disposition";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Equip_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Equip_OPFOR);
            displayName = "Enemy Equipment";
            tooltip = "Enemy Equipment";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_HQ_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_HQ_OPFOR);
            displayName = "Probable Enemy HQ Location";
            tooltip = "Probable Enemy HQ Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Line_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Line_OPFOR);
            displayName = "Probable Enemy Main Element Location";
            tooltip = "Probable Enemy Main Element Location";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Dir_Attack_OPFOR);
            displayName = "Probable Enemy Direction of Attack";
            tooltip = "Probable Enemy Direction of Attack";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Enemy_Prob_Arty_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Enemy_Prob_Arty_OPFOR);
            displayName = "Probable Enemy Artillery Positions and Capability";
            tooltip = "Probable Enemy Artillery Positions and Capability";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Title_OPFOR);
            displayName = "Higher and Adjacent Units";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Higher_Disp_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Disp_OPFOR);
            displayName = "Description";
            tooltip = "Description";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Boundary_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Boundary_OPFOR);
            displayName = "Boundaries";
            tooltip = "Boundaries";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Higher_Arty_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Higher_Arty_OPFOR);
            displayName = "Location and Capability of Artillery";
            tooltip = "Location and Capability of Artillery";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_Title_OPFOR);
            displayName = "Mission";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Mission_Desc_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_Desc_OPFOR);
            displayName = "Mission Statement";
            tooltip = "Mission Statement";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Mission_DIR_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Mission_DIR_OPFOR);
            displayName = "End State Direction";
            tooltip = "End State Direction";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Title_OPFOR);
            displayName = "Order";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_OPFOR);
            displayName = "Tasks";
            tooltip = "Tasks";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Tasks_Arty_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Tasks_Arty_OPFOR);
            displayName = "Tasks for Artillery Elements";
            tooltip = "Tasks for Artillery Elements";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Timings_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Timings_OPFOR);
            displayName = "Readiness Timings";
            tooltip = "Readiness Timings";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_Order_Signals_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_Order_Signals_OPFOR);
            displayName = "Signals";
            tooltip = "Signals";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_COMM_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_COMM_Title_OPFOR);
            displayName = "Location of the Commander";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_COMM_LOC_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_COMM_LOC_OPFOR);
            displayName = "Location of the Commander";
            tooltip = "Location of the Commander";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
        class EGVAR(Briefing,Warsaw_SUCC_Title_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_SUCC_Title_OPFOR);
            displayName = "Succession of Command";
            control = "CategoryTitle";
            expression = "true";
            defaultValue = "";
        };
        class EGVAR(Briefing,Warsaw_SUCC_DESC_OPFOR) {
            property = QEGVAR(Briefing,Warsaw_SUCC_DESC_OPFOR);
            displayName = "Succession of Command";
            tooltip = "Succession of Command";
            control = "EditMulti5";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};

class EGVAR(Briefing,Custom_File_OPFOR) {
    displayName = "Briefing File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,File_OPFOR) {
            property = QEGVAR(Briefing,File_OPFOR);
            displayName = "Briefing File";
            tooltip = "Loads file as briefing";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class EGVAR(Briefing,File_Path_OPFOR) {
            property = QEGVAR(Briefing,File_Path_OPFOR);
            displayName = "Path to briefing file";
            tooltip = "Path to briefing file";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";
        };
    };
};

class EGVAR(Briefing,Appendix_OPFOR) {
    displayName = "Appendix Card File";
    collapsed = 1;
    class Attributes {
        class EGVAR(Briefing,Appendix_OPFOR) {
            property = QEGVAR(Briefing,Appendix_OPFOR);
            displayName = "Appendix File";
            tooltip = "Enables Appendix File";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";

        };
        class EGVAR(Briefing,Appendix_Path_OPFOR) {
            property = QEGVAR(Briefing,Appendix_Path_OPFOR);
            displayName = "Path to Appendix file";
            tooltip = "Path to Appendix Briefing File";
            control = "Edit";
            validate = "STRING";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "''";

        };
    };
};
