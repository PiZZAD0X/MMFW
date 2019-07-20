class GVAR(PreInit) {
    Init = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\GlobalPreInit.sqf';";
    serverInit = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\ServerPreInit.sqf';";
    clientInit = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\ClientPreInit.sqf';";
};
