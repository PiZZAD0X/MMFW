class EGVAR(ExportImport,Folder) {
    text = "Import/Export Framework Settings";
    items[] = {QEGVAR(Export,Configure),QEGVAR(Import,Configure)};
    picture = "\a3\modules_f\data\portraitModule_ca.paa";
};

class EGVAR(Export,Configure) {
    text = "Export Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Export,Menu););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveFlying_ca.paa";
};

class EGVAR(Import,Configure) {
    text = "Import Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Import,Menu););
    picture = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveSurface_ca.paa";
};
