#define NEWTAB(NAME) _briefing set [count _briefing, ["Diary",[NAME

#define ENDTAB ]]]

#define DISPLAYBRIEFING() \
for "_i" from 0 to (count _briefing) step 1 do {\
    player createDiaryRecord (_briefing select ((count _briefing) - _i));\
}

#define BRIEFINGTEAMEXEC(TEAMNAME) if (GETMVAR(DOUBLES(File,TEAMNAME),false)) exitwith {\
    if !(GETMVAR(DOUBLES(File_Path,TEAMNAME),"") isEqualto "") then {\
        "" call (compile preprocessFileLineNumbers (GETMVAR(DOUBLES(File_Path,TEAMNAME),"")));\
    } else {\
        ERROR_1("No briefing found for %1!",TEAMNAME);\
    };\
};\
if (GETMVAR(DOUBLES(NATO,TEAMNAME),false)) then {\
    private _situationStr = "";\
    private _situationMain = GETMVAR(DOUBLES(NATO_SIT_Main,TEAMNAME),"");\
    if !(_situationMain isEqualTo "") then {\
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Situation:</h1></font color><br/>" + _situationMain + "<br/><br/>";\
    };\
    private _situationTerrain = GETMVAR(DOUBLES(NATO_SIT_Terrain,TEAMNAME),"");\
    if !(_situationTerrain isEqualTo "") then {\
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Terrain:</h1></font color><br/>" + _situationTerrain + "<br/><br/>";\
    };\
    private _situationKey = GETMVAR(DOUBLES(NATO_SIT_KEYTerrain,TEAMNAME),"");\
    if !(_situationKey isEqualTo "") then {\
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Key Terrain:</h1></font color><br/>" + _situationKey + "<br/><br/>";\
    };\
    private _situationWeather = GETMVAR(DOUBLES(NATO_SIT_Weather,TEAMNAME),"");\
    if !(_situationWeather isEqualTo "") then {\
        _situationStr = _situationStr + "<font color='#5BD527' size='14.0'><h1>Weather:</h1></font color><br/>" + _situationWeather;\
    };\
    NEWTAB("I. Situation:"),\
        _situationStr\
    ENDTAB;\
    private _enemyStr = "";\
    private _enemyDisposition = GETMVAR(DOUBLES(NATO_Enemy_DIS,TEAMNAME),"");\
    if !(_enemyDisposition isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Disposition:</h1></font color><br/>" + _enemyDisposition + "<br/><br/>";\
    };\
    private _enemyStrength = GETMVAR(DOUBLES(NATO_Enemy_STRENGTH,TEAMNAME),"");\
    if !(_enemyStrength isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Strength:</h1></font color><br/>" + _enemyStrength + "<br/><br/>";\
    };\
    private _enemyEquipment = GETMVAR(DOUBLES(NATO_Enemy_EQUIPMENT,TEAMNAME),"");\
    if !(_enemyEquipment isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Equipment:</h1></font color><br/>" + _enemyEquipment + "<br/><br/>";\
    };\
    private _enemyAppearance = GETMVAR(DOUBLES(NATO_Enemy_APPEARANCE,TEAMNAME),"");\
    if !(_enemyAppearance isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>Appearance:</h1></font color><br/>" + _enemyAppearance + "<br/><br/>";\
    };\
    private _enemyMLCOA = GETMVAR(DOUBLES(NATO_Enemy_MLCOA,TEAMNAME),"");\
    if !(_enemyMLCOA isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>MLCOA:</h1></font color><br/>" + _enemyMLCOA + "<br/><br/>";\
    };\
    private _enemyMDCOA = GETMVAR(DOUBLES(NATO_Enemy_MDCOA,TEAMNAME),"");\
    if !(_enemyMDCOA isEqualTo "") then {\
        _enemyStr = _enemyStr + "<font color='#5BD527' size='14.0'><h1>MDCOA:</h1></font color><br/>" + _enemyMDCOA;\
    };\
    if !(_enemyStr isEqualTo "") then {\
        NEWTAB("   A. Enemy Forces:"),\
            _enemyStr\
        ENDTAB;\
    };\
    private _friendlyStr = "";\
    private _friendlyDisposition = GETMVAR(DOUBLES(NATO_FRIENDLY_DIS,TEAMNAME),"");\
    if !(_friendlyDisposition isEqualTo "") then {\
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Disposition:</h1></font color><br/>" + _friendlyDisposition + "<br/><br/>";\
    };\
    private _friendlyHigher = GETMVAR(DOUBLES(NATO_FRIENDLY_Higher,TEAMNAME),"");\
    if !(_friendlyHigher isEqualTo "") then {\
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Higher Units:</h1></font color><br/>" + _friendlyHigher + "<br/><br/>";\
    };\
    private _friendlyStrength = GETMVAR(DOUBLES(NATO_FRIENDLY_STRENGTH,TEAMNAME),"");\
    if !(_friendlyStrength isEqualTo "") then {\
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Strength:</h1></font color><br/>" + _friendlyStrength + "<br/><br/>";\
    };\
    private _friendlyEquipment = GETMVAR(DOUBLES(NATO_FRIENDLY_EQUIPMENT,TEAMNAME),"");\
    if !(_friendlyEquipment isEqualTo "") then {\
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Equipment:</h1></font color><br/>" + _friendlyEquipment + "<br/><br/>";\
    };\
    private _friendlyAppearance = GETMVAR(DOUBLES(NATO_FRIENDLY_APPEARANCE,TEAMNAME),"");\
    if !(_friendlyAppearance isEqualTo "") then {\
        _friendlyStr = _friendlyStr + "<font color='#5BD527' size='14.0'><h1>Appearance:</h1></font color><br/>" + _friendlyAppearance;\
    };\
    if !(_friendlyStr isEqualTo "") then {\
        NEWTAB("   B. Friendly Forces:"),\
            _friendlyStr\
        ENDTAB;\
    };\
    private _missionStr = "";\
    private _missionNato = GETMVAR(DOUBLES(NATO_Mission,TEAMNAME),"");\
    if !(_missionNato isEqualTo "") then {\
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>Mission:</h1></font color><br/>" + _missionNato;\
    };\
    if !(_missionStr isEqualTo "") then {\
        NEWTAB("II. Mission:"),\
            _missionStr\
        ENDTAB;\
    };\
    private _execStr = "";\
    private _execCIntent = GETMVAR(DOUBLES(NATO_EXECUTION_INTENT,TEAMNAME),"");\
    if !(_execCIntent isEqualTo "") then {\
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Commanders Intent:</h1></font color><br/>" + _execCIntent + "<br/><br/>";\
    };\
    private _execManeuver = GETMVAR(DOUBLES(NATO_EXECUTION_MANEUVER,TEAMNAME),"");\
    if !(_execManeuver isEqualTo "") then {\
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Maneuver:</h1></font color><br/>" + _execManeuver + "<br/><br/>";\
    };\
    private _execTimings = GETMVAR(DOUBLES(NATO_EXECUTION_Timings,TEAMNAME),"");\
    if !(_execTimings isEqualTo "") then {\
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Timings:</h1></font color><br/>" + _execTimings + "<br/><br/>";\
    };\
    private _execTasks = GETMVAR(DOUBLES(NATO_EXECUTION_Tasks,TEAMNAME),"");\
    if !(_execTasks isEqualTo "") then {\
        _execStr = _execStr + "<font color='#5BD527' size='14.0'><h1>Tasks:</h1></font color><br/>" + _execTasks;\
    };\
    if !(_execStr isEqualTo "") then {\
        NEWTAB("III. Execution:"),\
            _execStr\
        ENDTAB;\
    };\
    NEWTAB("IV. Service Support:"),\
    ""\
    ENDTAB;\
    private _supportStr = "";\
    private _firesStr = GETMVAR(DOUBLES(NATO_SANDS_SUPPORT_FIRES,TEAMNAME),"");\
    if !(_firesStr isEqualTo "") then {\
        _supportStr = _supportStr + "<font color='#5BD527' size='14.0'><h1>Fires:</h1></font color><br/>" + _firesStr + "<br/><br/>";\
    };\
    private _ammoTasks = GETMVAR(DOUBLES(NATO_SANDS_SUPPORT_AMMO,TEAMNAME),"");\
    if !(_ammoTasks isEqualTo "") then {\
        _supportStr = _supportStr + "<font color='#5BD527' size='14.0'><h1>Ammo:</h1></font color><br/>" + _ammoTasks;\
    };\
    if !(_supportStr isEqualTo "") then {\
        NEWTAB("   A. Support:"),\
            _supportStr\
        ENDTAB;\
    };\
    private _serviceStr = "";\
    private _serviceGen = GETMVAR(DOUBLES(NATO_SANDS_SERVICE_GENERAL,TEAMNAME),"");\
    if !(_serviceGen isEqualTo "") then {\
        _serviceStr = _serviceStr + "<font color='#5BD527' size='14.0'><h1>General:</h1></font color><br/>" + _serviceGen;\
    };\
    if !(_serviceStr isEqualTo "") then {\
        NEWTAB("   B. Service:"),\
            _serviceStr\
        ENDTAB;\
    };\
    NEWTAB("V. Command and Signal:"),\
    ""\
    ENDTAB;\
    private _commandStr = "";\
    private _commandGen = GETMVAR(DOUBLES(NATO_CANDS_COMMAND,TEAMNAME),"");\
    if !(_commandGen isEqualTo "") then {\
        _commandStr = _commandStr + "<font color='#5BD527' size='14.0'><h1>General:</h1></font color><br/>" + _commandGen;\
    };\
    if !(_commandStr isEqualTo "") then {\
        NEWTAB("   A. Command:"),\
            _commandStr\
        ENDTAB;\
    };\
    private _signalStr = "";\
    private _signalFreq = GETMVAR(DOUBLES(NATO_CANDS_Signals_FREQ,TEAMNAME),"");\
    if !(_signalFreq isEqualTo "") then {\
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Frequencies:</h1></font color><br/>" + _signalFreq + "<br/><br/>";\
    };\
    private _signalCode = GETMVAR(DOUBLES(NATO_CANDS_Signals_CODEWORDS,TEAMNAME),"");\
    if !(_signalCode isEqualTo "") then {\
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Codewords:</h1></font color><br/>" + _signalCode + "<br/><br/>";\
    };\
    private _signalSpec = GETMVAR(DOUBLES(NATO_CANDS_Signals_SPECIAL,TEAMNAME),"");\
    if !(_signalSpec isEqualTo "") then {\
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Special Signals:</h1></font color><br/>" + _signalSpec + "<br/><br/>";\
    };\
    private _signalCall = GETMVAR(DOUBLES(NATO_CANDS_Signals_CALLSIGNS,TEAMNAME),"");\
    if !(_signalCall isEqualTo "") then {\
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Callsigns:</h1></font color><br/>" + _signalCall + "<br/><br/>";\
    };\
    private _signalPass = GETMVAR(DOUBLES(NATO_CANDS_Signals_PASSWORDS,TEAMNAME),"");\
    if !(_signalPass isEqualTo "") then {\
        _signalStr = _signalStr + "<font color='#5BD527' size='14.0'><h1>Passwords:</h1></font color><br/>" + _signalPass;\
    };\
    if !(_signalStr isEqualTo "") then {\
        NEWTAB("   B. Signals:"),\
            _signalStr\
        ENDTAB;\
    };\
};\
if (GETMVAR(DOUBLES(Warsaw,TEAMNAME),false)) then {\
    private _preStr = "";\
    private _preWeather = GETMVAR(DOUBLES(Warsaw_Preliminaries_Weather,TEAMNAME),"");\
    if !(_preWeather isEqualTo "") then {\
        _preStr = _preStr + "<font color='#5BD527' size='14.0'><h1>Weather:</h1></font color><br/>" + _preWeather + "<br/><br/>";\
    };\
    private _preTerrain = GETMVAR(DOUBLES(Warsaw_Preliminaries_Terrain,TEAMNAME),"");\
    if !(_preTerrain isEqualTo "") then {\
        _preStr = _preStr + "<font color='#5BD527' size='14.0'><h1>Terrain:</h1></font color><br/>" + _preTerrain;\
    };\
    if !(_preStr isEqualTo "") then {\
        NEWTAB("I. Preliminaries:"),\
            _preStr\
        ENDTAB;\
    };\
    private _refpointsStr = "";\
    private _refpointsDep = GETMVAR(DOUBLES(Warsaw_Reference_DeploymentPoints,TEAMNAME),"");\
    if !(_refpointsDep isEqualTo "") then {\
        _refpointsStr = _refpointsStr + "<font color='#5BD527' size='14.0'><h1>Deployment Reference Points:</h1></font color><br/>" + _refpointsDep + "<br/><br/>";\
    };\
    private _refpointsSub = GETMVAR(DOUBLES(Warsaw_Reference_SubsequentPoints,TEAMNAME),"");\
    if !(_refpointsSub isEqualTo "") then {\
        _refpointsStr = _refpointsStr + "<font color='#5BD527' size='14.0'><h1>Subsequent Reference Points:</h1></font color><br/>" + _refpointsSub;\
    };\
    if !(_refpointsStr isEqualTo "") then {\
        NEWTAB("II. Reference Points:"),\
            _refpointsStr\
        ENDTAB;\
    };\
    private _enStr = "";\
    private _enDesc = GETMVAR(DOUBLES(Warsaw_Enemy_Disp,TEAMNAME),"");\
    if !(_enDesc isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Enemy Disposition:</h1></font color><br/>" + _enDesc + "<br/><br/>";\
    };\
    private _enEquip = GETMVAR(DOUBLES(Warsaw_Enemy_Equip,TEAMNAME),"");\
    if !(_enEquip isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Enemy Equipment:</h1></font color><br/>" + _enEquip + "<br/><br/>";\
    };\
    private _enHQ = GETMVAR(DOUBLES(Warsaw_Enemy_Prob_HQ,TEAMNAME),"");\
    if !(_enHQ isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy HQ Location:</h1></font color><br/>" + _enHQ + "<br/><br/>";\
    };\
    private _enLoc = GETMVAR(DOUBLES(Warsaw_Enemy_Prob_Line,TEAMNAME),"");\
    if !(_enLoc isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Main Element Location:</h1></font color><br/>" + _enLoc + "<br/><br/>";\
    };\
    private _enDir = GETMVAR(DOUBLES(Warsaw_Enemy_Prob_Dir_Attack,TEAMNAME),"");\
    if !(_enDir isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Direction of Attack:</h1></font color><br/>" + _enDir + "<br/><br/>";\
    };\
    private _enArty = GETMVAR(DOUBLES(Warsaw_Enemy_Prob_Arty,TEAMNAME),"");\
    if !(_enArty isEqualTo "") then {\
        _enStr = _enStr + "<font color='#5BD527' size='14.0'><h1>Probable Enemy Artillery Positions and Capability:</h1></font color><br/>" + _enArty;\
    };\
    if !(_enStr isEqualTo "") then {\
        NEWTAB("III. Enemy:"),\
            _enStr\
        ENDTAB;\
    };\
    private _higherStr = "";\
    private _higherDesc = GETMVAR(DOUBLES(Warsaw_Higher_Disp,TEAMNAME),"");\
    if !(_higherDesc isEqualTo "") then {\
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Description:</h1></font color><br/>" + _higherDesc + "<br/><br/>";\
    };\
    private _higherBound = GETMVAR(DOUBLES(Warsaw_Higher_Boundary,TEAMNAME),"");\
    if !(_higherBound isEqualTo "") then {\
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Boundaries:</h1></font color><br/>" + _higherBound + "<br/><br/>";\
    };\
    private _higherLocArty = GETMVAR(DOUBLES(Warsaw_Higher_Arty,TEAMNAME),"");\
    if !(_higherLocArty isEqualTo "") then {\
        _higherStr = _higherStr + "<font color='#5BD527' size='14.0'><h1>Location and Capability of Artillery:</h1></font color><br/>" + _higherLocArty;\
    };\
    if !(_higherStr isEqualTo "") then {\
        NEWTAB("IV. Higher and Adjacent Units:"),\
            _higherStr\
        ENDTAB;\
    };\
    private _missionStr = "";\
    private _missionStat = GETMVAR(DOUBLES(Warsaw_Mission_Desc,TEAMNAME),"");\
    if !(_missionStat isEqualTo "") then {\
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>Statement:</h1></font color><br/>" + _missionStat + "<br/><br/>";\
    };\
    private _missionDir = GETMVAR(DOUBLES(Warsaw_Mission_DIR,TEAMNAME),"");\
    if !(_missionDir isEqualTo "") then {\
        _missionStr = _missionStr + "<font color='#5BD527' size='14.0'><h1>End State Direction:</h1></font color><br/>" + _missionDir;\
    };\
    if !(_missionStr isEqualTo "") then {\
        NEWTAB("V. Mission:"),\
            _missionStr\
        ENDTAB;\
    };\
    private _orderStr = "";\
    private _orderTasks = GETMVAR(DOUBLES(Warsaw_Order_Tasks,TEAMNAME),"");\
    if !(_orderTasks isEqualTo "") then {\
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Tasks:</h1></font color><br/>" + _orderTasks + "<br/><br/>";\
    };\
    private _orderArty = GETMVAR(DOUBLES(Warsaw_Order_Tasks_Arty,TEAMNAME),"");\
    if !(_orderArty isEqualTo "") then {\
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Tasks for Artillery Elements:</h1></font color><br/>" + _orderArty + "<br/><br/>";\
    };\
    private _orderTimings = GETMVAR(DOUBLES(Warsaw_Order_Timings,TEAMNAME),"");\
    if !(_orderTimings isEqualTo "") then {\
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Readiness Timings:</h1></font color><br/>" + _orderTimings + "<br/><br/>";\
    };\
    private _orderSignals = GETMVAR(DOUBLES(Warsaw_Order_Signals,TEAMNAME),"");\
    if !(_orderSignals isEqualTo "") then {\
        _orderStr = _orderStr + "<font color='#5BD527' size='14.0'><h1>Signals:</h1></font color><br/>" + _orderSignals;\
    };\
    if !(_orderStr isEqualTo "") then {\
        NEWTAB("VI. Order:"),\
            _orderStr\
        ENDTAB;\
    };\
    private _cmdlocStr = "";\
    private _cmdlocDesc = GETMVAR(DOUBLES(Warsaw_COMM_LOC,TEAMNAME),"");\
    if !(_cmdlocDesc isEqualTo "") then {\
        _cmdlocStr = _cmdlocStr + "<font color='#5BD527' size='14.0'><h1>Location of Command:</h1></font color><br/>" + _cmdlocDesc;\
    };\
    if !(_cmdlocStr isEqualTo "") then {\
        NEWTAB("VII. Location of the Commander:"),\
            _cmdlocStr\
        ENDTAB;\
    };\
    private _succStr = "";\
    private _succDesc = GETMVAR(DOUBLES(Warsaw_SUCC_DESC,TEAMNAME),"");\
    if !(_succDesc isEqualTo "") then {\
        _succStr = _succStr + "<font color='#5BD527' size='14.0'><h1>Succession of Command:</h1></font color><br/>" + _succDesc;\
    };\
    if !(_succStr isEqualTo "") then {\
        NEWTAB("VIII. Succession of Command:"),\
            _succStr\
        ENDTAB;\
    };\
};\
if (GETMVAR(DOUBLES(Appendix,TEAMNAME),false)) then {\
    if !(GETMVAR(DOUBLES(Appendix_Path,TEAMNAME),"") isEqualto "") then {\
        "" call (compile preprocessFileLineNumbers (GETMVAR(DOUBLES(Appendix_Path,TEAMNAME),"")));\
    } else {\
        ERROR("No appendix found for BLUFOR!");\
    };\
}
