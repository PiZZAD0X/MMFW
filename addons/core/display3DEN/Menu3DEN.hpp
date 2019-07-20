class EGVAR(ExportImport,Folder) {
    text = "Import/Export Framework Settings";
    items[] = {QEGVAR(Export,Configure),QEGVAR(Import,Configure)};
    picture = "";
};

class EGVAR(Export,Configure) {
    text = "Export Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Export,Menu)););
};

class EGVAR(Import,Configure) {
    text = "Import Mission Settings";
    action = QUOTE(edit3DENMissionAttributes QN(EGVAR(Import,Menu)););
};
