class EGVAR(ExportImport,Folder) {
    text = "Import/Export Framework Settings";
    items[] = {QEGVAR(Export,Configure),QEGVAR(Import,Configure)};
    picture = "";
};

class EGVAR(Export,Configure) {
    text = "Export Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Export,Menu););
};

class EGVAR(Import,Configure) {
    text = "Import Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QQEGVAR(Import,Menu););
};
