class GVAR(PostInit) {
    Init = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\GlobalPostInit.sqf';";
    serverInit = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\ServerPostInit.sqf';";
    clientInit = "call compile preProcessFileLineNumbers '\x\UO_FW\addons\Main\Core\cfgXEH\init\ClientPostInit.sqf';";
};
