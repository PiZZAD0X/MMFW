if (GETMVAR(File_BLUFOR,false)) exitwith {
    if !(GETMVAR(File_Path_BLUFOR,"") isEqualto "") then {
        "" call (compile preprocessFileLineNumbers (GETMVAR(File_Path_BLUFOR,"")));
    } else {
        ERROR("No briefing found for BLUFOR!");
    };
};

if (GETMVAR(NATO_BLUFOR,false)) then {
    //Situation
    private _situationStr = "";

    private _situationMain = GETMVAR(NATO_SIT_Main_BLUFOR,"");
    if !(_situationMain isEqualTo "") then {
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Situation:</h1></font color><br/>" + _situationMain + "<br/><br/>";
    };
    private _situationTerrain = GETMVAR(NATO_SIT_Terrain_BLUFOR,"");
    if !(_situationTerrain isEqualTo "") then {
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Terrain:</h1></font color><br/>" + _situationTerrain + "<br/><br/>";
    };
    private _situationKey = GETMVAR(NATO_SIT_KEYTerrain_BLUFOR,"");
    if !(_situationKey isEqualTo "") then {
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Key Terrain:</h1></font color><br/>" + _situationKey + "<br/><br/>";
    };
    private _situationWeather = GETMVAR(NATO_SIT_Weather_BLUFOR,"");
    if !(_situationWeather isEqualTo "") then {
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Weather:</h1></font color><br/>" + _situationWeather;
    };

    NEWTAB("I. Situation:"),
        _situationStr
    ENDTAB;

    //Enemy
    private _enemyStr = "";

    private _enemyDisposition = GETMVAR(NATO_Enemy_DIS_BLUFOR,"");
    if !(_enemyDisposition isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Disposition:</h1></font color><br/>" + _enemyDisposition + "<br/><br/>";
    };
    private _enemyStrength = GETMVAR(NATO_Enemy_STRENGTH_BLUFOR,"");
    if !(_enemyStrength isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Strength:</h1></font color><br/>" + _enemyStrength + "<br/><br/>";
    };
    private _enemyEquipment = GETMVAR(NATO_Enemy_EQUIPMENT_BLUFOR,"");
    if !(_enemyEquipment isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Equipment:</h1></font color><br/>" + _enemyEquipment + "<br/><br/>";
    };
    private _enemyAppearance = GETMVAR(NATO_Enemy_APPEARANCE_BLUFOR,"");
    if !(_enemyAppearance isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Appearance:</h1></font color><br/>" + _enemyAppearance + "<br/><br/>";
    };
    private _enemyMLCOA = GETMVAR(NATO_Enemy_MLCOA_BLUFOR,"");
    if !(_enemyMLCOA isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>MLCOA:</h1></font color><br/>" + _enemyMLCOA + "<br/><br/>";
    };
    private _enemyMDCOA = GETMVAR(NATO_Enemy_MDCOA_BLUFOR,"");
    if !(_enemyMDCOA isEqualTo "") then {
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>MDCOA:</h1></font color><br/>" + _enemyMDCOA;
    };

    if !(_enemyStr isEqualTo "") then {
        NEWTAB("   A. Enemy Forces:"),
            _enemyStr
        ENDTAB;
    };


    //Friendly
    private _friendlyStr = "";

    private _friendlyDisposition = GETMVAR(NATO_FRIENDLY_DIS_BLUFOR,"");
    if !(_friendlyDisposition isEqualTo "") then {
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Disposition:</h1></font color><br/>" + _friendlyDisposition + "<br/><br/>";
    };
    private _friendlyHigher = GETMVAR(NATO_FRIENDLY_Higher_BLUFOR,"");
    if !(_friendlyHigher isEqualTo "") then {
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Higher Units:</h1></font color><br/>" + _friendlyHigher + "<br/><br/>";
    };
    private _friendlyStrength = GETMVAR(NATO_FRIENDLY_STRENGTH_BLUFOR,"");
    if !(_friendlyStrength isEqualTo "") then {
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Strength:</h1></font color><br/>" + _friendlyStrength + "<br/><br/>";
    };
    private _friendlyEquipment = GETMVAR(NATO_FRIENDLY_EQUIPMENT_BLUFOR,"");
    if !(_friendlyEquipment isEqualTo "") then {
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Equipment:</h1></font color><br/>" + _friendlyEquipment + "<br/><br/>";
    };
    private _friendlyAppearance = GETMVAR(NATO_FRIENDLY_APPEARANCE_BLUFOR,"");
    if !(_friendlyAppearance isEqualTo "") then {
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Appearance:</h1></font color><br/>" + _friendlyAppearance;
    };

    if !(_friendlyStr isEqualTo "") then {
        NEWTAB("   B. Friendly Forces:"),
            _friendlyStr
        ENDTAB;
    };


    //Mission
    private _missionStr = "";

    private _missionNato = GETMVAR(NATO_Mission_BLUFOR,"");
    if !(_missionNato isEqualTo "") then {
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>Mission:</h1></font color><br/>" + _missionNato;
    };

    if !(_missionStr isEqualTo "") then {
        NEWTAB("II. Mission:"),
            _missionStr
        ENDTAB;
    };

    private _execStr = "";

    private _execCIntent = GETMVAR(NATO_EXECUTION_INTENT_BLUFOR,"");
    if !(_execCIntent isEqualTo "") then {
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Commanders Intent:</h1></font color><br/>" + _execCIntent + "<br/><br/>";
    };

    private _execManeuver = GETMVAR(NATO_EXECUTION_MANEUVER_BLUFOR,"");
    if !(_execManeuver isEqualTo "") then {
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Maneuver:</h1></font color><br/>" + _execManeuver + "<br/><br/>";
    };

    private _execTimings = GETMVAR(NATO_EXECUTION_Timings_BLUFOR,"");
    if !(_execTimings isEqualTo "") then {
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Timings:</h1></font color><br/>" + _execTimings + "<br/><br/>";
    };

    private _execTasks = GETMVAR(NATO_EXECUTION_Tasks_BLUFOR,"");
    if !(_execTasks isEqualTo "") then {
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Tasks:</h1></font color><br/>" + _execTasks;
    };

    if !(_execStr isEqualTo "") then {
        NEWTAB("III. Execution:"),
            _execStr
        ENDTAB;
    };


    NEWTAB("IV. Service Support:"),
    ""
    ENDTAB;

    private _supportStr = "";

    private _firesStr = GETMVAR(NATO_SANDS_SUPPORT_FIRES_BLUFOR,"");
    if !(_firesStr isEqualTo "") then {
        _supportStr = _supportStr + "<font color='#5BD527' size='14.0'><h1>Fires:</h1></font color><br/>" + _firesStr + "<br/><br/>";
    };

    private _ammoTasks = GETMVAR(NATO_SANDS_SUPPORT_AMMO_BLUFOR,"");
    if !(_ammoTasks isEqualTo "") then {
        _supportStr = _supportStr + "<font color='#5BD527' size='14.0'><h1>Ammo:</h1></font color><br/>" + _ammoTasks;
    };

    if !(_supportStr isEqualTo "") then {
        NEWTAB("   A. Support:"),
            _supportStr
        ENDTAB;
    };

    private _serviceStr = "";

    private _serviceGen = GETMVAR(NATO_SANDS_SERVICE_GENERAL_BLUFOR,"");
    if !(_serviceGen isEqualTo "") then {
        _serviceStr = _serviceStr + "<font color='#5BD527' size='14.0'><h1>General:</h1></font color><br/>" + _serviceGen;
    };

    if !(_serviceStr isEqualTo "") then {
        NEWTAB("   B. Service:"),
            _serviceStr
        ENDTAB;
    };

    NEWTAB("V. Command and Signal:"),
    ""
    ENDTAB;

    private _commandStr = "";

    private _commandGen = GETMVAR(NATO_CANDS_COMMAND_BLUFOR,"");
    if !(_commandGen isEqualTo "") then {
        _commandStr = _commandStr + "<font color='#5BD527' size='14.0'><h1>General:</h1></font color><br/>" + _commandGen;
    };

    if !(_commandStr isEqualTo "") then {
        NEWTAB("   A. Command:"),
            _commandStr
        ENDTAB;
    };

    private _signalStr = "";

    private _signalFreq = GETMVAR(NATO_CANDS_Signals_FREQ_BLUFOR,"");
    if !(_signalFreq isEqualTo "") then {
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Frequencies:</h1></font color><br/>" + _signalFreq + "<br/><br/>";
    };

    private _signalCode = GETMVAR(NATO_CANDS_Signals_CODEWORDS_BLUFOR,"");
    if !(_signalCode isEqualTo "") then {
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Codewords:</h1></font color><br/>" + _signalCode + "<br/><br/>";
    };

    private _signalSpec = GETMVAR(NATO_CANDS_Signals_SPECIAL_BLUFOR,"");
    if !(_signalSpec isEqualTo "") then {
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Special Signals:</h1></font color><br/>" + _signalSpec + "<br/><br/>";
    };

    private _signalCall = GETMVAR(NATO_CANDS_Signals_CALLSIGNS_BLUFOR,"");
    if !(_signalCall isEqualTo "") then {
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Callsigns:</h1></font color><br/>" + _signalCall + "<br/><br/>";
    };

    private _signalPass = GETMVAR(NATO_CANDS_Signals_PASSWORDS_BLUFOR,"");
    if !(_signalPass isEqualTo "") then {
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Passwords:</h1></font color><br/>" + _signalPass;
    };

    if !(_signalStr isEqualTo "") then {
        NEWTAB("   B. Signals:"),
            _signalStr
        ENDTAB;
    };
};

if (GETMVAR(Warsaw_BLUFOR,false)) then {

    private _preStr = "";

    private _preWeather = GETMVAR(Warsaw_Preliminaries_Weather_BLUFOR,"");
    if !(_preWeather isEqualTo "") then {
        _preStr = _preStr + "<font color='#5BD527' size='14.0'><h1>Weather:</h1></font color><br/>" + _preWeather + "<br/><br/>";
    };

    private _preTerrain = GETMVAR(Warsaw_Preliminaries_Terrain_BLUFOR,"");
    if !(_preTerrain isEqualTo "") then {
        _preStr = _preStr + "<font color='#5BD527' size='14.0'><h1>Terrain:</h1></font color><br/>" + _preTerrain;
    };

    if !(_preStr isEqualTo "") then {
        NEWTAB("I. Preliminaries:"),
            _preStr
        ENDTAB;
    };

    private _refpointsStr = "";

    private _refpointsDep = GETMVAR(Warsaw_Reference_DeploymentPoints_BLUFOR,"");
    if !(_refpointsDep isEqualTo "") then {
        _refpointsStr = _refpointsStr + "<font color='#5BD527' size='14.0'><h1>Deployment Reference Points:</h1></font color><br/>" + _refpointsDep + "<br/><br/>";
    };

    private _refpointsSub = GETMVAR(Warsaw_Reference_SubsequentPoints_BLUFOR,"");
    if !(_refpointsSub isEqualTo "") then {
        _refpointsStr = _refpointsStr + "<font color='#5BD527' size='14.0'><h1>Subsequent Reference Points:</h1></font color><br/>" + _refpointsSub;
    };

    if !(_refpointsStr isEqualTo "") then {
        NEWTAB("II. Reference Points:"),
            _refpointsStr
        ENDTAB;
    };

    private _enStr = "";

    private _enDesc = GETMVAR(Warsaw_Enemy_Disp_BLUFOR,"");
    if !(_enDesc isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Enemy Disposition:</h1></font color><br/>" + _enDesc + "<br/><br/>";
    };

    private _enEquip = GETMVAR(Warsaw_Enemy_Equip_BLUFOR,"");
    if !(_enEquip isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Enemy Equipment:</h1></font color><br/>" + _enEquip + "<br/><br/>";
    };

    private _enHQ = GETMVAR(Warsaw_Enemy_Prob_HQ_BLUFOR,"");
    if !(_enHQ isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy HQ Location:</h1></font color><br/>" + _enHQ + "<br/><br/>";
    };

    private _enLoc = GETMVAR(Warsaw_Enemy_Prob_Line_BLUFOR,"");
    if !(_enLoc isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Main Element Location:</h1></font color><br/>" + _enLoc + "<br/><br/>";
    };

    private _enDir = GETMVAR(Warsaw_Enemy_Prob_Dir_Attack_BLUFOR,"");
    if !(_enDir isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Direction of Attack:</h1></font color><br/>" + _enDir + "<br/><br/>";
    };

    private _enArty = GETMVAR(Warsaw_Enemy_Prob_Arty_BLUFOR,"");
    if !(_enArty isEqualTo "") then {
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Artillery Positions and Capability:</h1></font color><br/>" + _enArty;
    };

    if !(_enStr isEqualTo "") then {
        NEWTAB("III. Enemy:"),
            _enStr
        ENDTAB;
    };

    private _higherStr = "";

    private _higherDesc = GETMVAR(Warsaw_Higher_Disp_BLUFOR,"");
    if !(_higherDesc isEqualTo "") then {
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Description:</h1></font color><br/>" + _higherDesc + "<br/><br/>";
    };

    private _higherBound = GETMVAR(Warsaw_Higher_Boundary_BLUFOR,"");
    if !(_higherBound isEqualTo "") then {
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Boundaries:</h1></font color><br/>" + _higherBound + "<br/><br/>";
    };

    private _higherLocArty = GETMVAR(Warsaw_Higher_Arty_BLUFOR,"");
    if !(_higherLocArty isEqualTo "") then {
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Location and Capability of Artillery:</h1></font color><br/>" + _higherLocArty;
    };

    if !(_higherStr isEqualTo "") then {
        NEWTAB("IV. Higher and Adjacent Units:"),
            _higherStr
        ENDTAB;
    };

    private _missionStr = "";

    private _missionStat = GETMVAR(Warsaw_Mission_Desc_BLUFOR,"");
    if !(_missionStat isEqualTo "") then {
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>Statement:</h1></font color><br/>" + _missionStat + "<br/><br/>";
    };

    private _missionDir = GETMVAR(Warsaw_Mission_DIR_BLUFOR,"");
    if !(_missionDir isEqualTo "") then {
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>End State Direction:</h1></font color><br/>" + _missionDir;
    };

    if !(_missionStr isEqualTo "") then {
        NEWTAB("V. Mission:"),
            _missionStr
        ENDTAB;
    };

    private _orderStr = "";

    private _orderTasks = GETMVAR(Warsaw_Order_Tasks_BLUFOR,"");
    if !(_orderTasks isEqualTo "") then {
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Tasks:</h1></font color><br/>" + _orderTasks + "<br/><br/>";
    };

    private _orderArty = GETMVAR(Warsaw_Order_Tasks_Arty_BLUFOR,"");
    if !(_orderArty isEqualTo "") then {
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Tasks for Artillery Elements:</h1></font color><br/>" + _orderArty + "<br/><br/>";
    };

    private _orderTimings = GETMVAR(Warsaw_Order_Timings_BLUFOR,"");
    if !(_orderTimings isEqualTo "") then {
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Readiness Timings:</h1></font color><br/>" + _orderTimings + "<br/><br/>";
    };

    private _orderSignals = GETMVAR(Warsaw_Order_Signals_BLUFOR,"");
    if !(_orderSignals isEqualTo "") then {
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Signals:</h1></font color><br/>" + _orderSignals;
    };

    if !(_orderStr isEqualTo "") then {
        NEWTAB("VI. Order:"),
            _orderStr
        ENDTAB;
    };

    private _cmdlocStr = "";

    private _cmdlocDesc = GETMVAR(Warsaw_COMM_LOC_BLUFOR,"");
    if !(_cmdlocDesc isEqualTo "") then {
        _cmdlocStr = _cmdlocStr + "<font color='#5BD527' size='14.0'><h1>Location of Command:</h1></font color><br/>" + _cmdlocDesc;
    };

    if !(_cmdlocStr isEqualTo "") then {
        NEWTAB("VII. Location of the Commander:"),
            _cmdlocStr
        ENDTAB;
    };

    private _succStr = "";

    private _succDesc = GETMVAR(Warsaw_SUCC_DESC_BLUFOR,"");
    if !(_succDesc isEqualTo "") then {
        _succStr = _succStr + "<font color='#5BD527' size='14.0'><h1>Succession of Command:</h1></font color><br/>" + _succDesc;
    };

    if !(_succStr isEqualTo "") then {
        NEWTAB("VIII. Succession of Command:"),
            _succStr
        ENDTAB;
    };
};

if (GETMVAR(Appendix_BLUFOR,false)) then {
    if !(GETMVAR(Appendix_Path_BLUFOR,"") isEqualto "") then {
        "" call (compile preprocessFileLineNumbers (GETMVAR(Appendix_Path_BLUFOR,"")));
    } else {
        ERROR("No appendix found for BLUFOR!");
    };
};

if (GETMVAR(MissionNotes_Enable,false)) then {
    //Mission Notes
    private _notesStr = "";

     private _notesAuthor = GETMVAR(MissionNotes_Author,"");
    if !(_notesAuthor isEqualTo "") then {
        _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Author:</h1></font color><br/>" + _notesAuthor + "<br/><br/>";
    };

    private _notesTesters = GETMVAR(MissionNotes_Testers,"");
    if !(_notesTesters isEqualTo "") then {
        _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Testers:</h1></font color><br/>" + _notesTesters + "<br/><br/>";
    };

    private _notesConditions = GETMVAR(MissionNotes_Conditions,"");
    if !(_notesConditions isEqualTo "") then {
        _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>End Conditions:</h1></font color><br/>" + _notesConditions + "<br/><br/>";
    };

    private _notesCustom = GETMVAR(MissionNotes_Custom,"");
    if !(_notesCustom isEqualTo "") then {
        _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Mission Specific Notes:</h1></font color><br/>" + _notesCustom + "<br/><br/>";
    };

    private _notesChange = GETMVAR(MissionNotes_Changelog,"");
    if !(_notesChange isEqualTo "") then {
        _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Mission Changelog:</h1></font color><br/>" + _notesChange;
    };

    if !(_notesStr isEqualTo "") then {
        NEWTAB("Mission Notes:"),
            _notesStr
        ENDTAB;
    };
    private _gamemastermsg = "";

    if (GETMVAR(MissionNotes_GM,false)) then {
        _gamemastermsg = "This mission is designed for game mastering and can be manipulated as per Mission Notes";
    } else {
        _gamemastermsg = "This mission is not designed for game mastering and should only be manipulated for technical, administrative or diagnostic purposes.";
    };

    //Game Mastering
    NEWTAB("Game Mastering"),
        "<font color='#5BD527' size='14.0'><h1>Game Mastering:</h1></font color><br/>" + _gamemastermsg
    ENDTAB;
};



DISPLAYBRIEFING();
