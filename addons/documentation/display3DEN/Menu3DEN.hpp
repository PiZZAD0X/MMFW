class GVAR(ExportImportFolder) {
    text = "Import/Export Framework Settings";
    items[] = {QGVAR(ExportConfigure),QGVAR(ImportConfigure)};
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

class GVAR(ExportConfigure) {
    text = "Export Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(ExportMenu););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveFlying_ca.paa";
};

class GVAR(ImportConfigure) {
    text = "Import Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQGVAR(ImportMenu););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveSurface_ca.paa";
};
