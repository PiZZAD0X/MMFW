class GVAR(SettingsMenu) {
    text = "Framework Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(Settings););
    picture = "\a3\3DEN\Data\Cfg3DEN\History\changeAttributes_ca.paa";
};

class EGVAR(Module,SettingsMenu) {
    text = "Module Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Module,Settings););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
};
