class EGVAR(3DEN,EH) {
    onTerrainNew = QUOTE([] call FUNC(BasicSettings3DEN));
    onMissionLoad = QUOTE([] call FUNC(BasicSettings3DEN));
    onMissionNew = QUOTE([] call FUNC(BasicSettings3DEN));
    onMissionSave = QUOTE([] call FUNC(BasicSettings3DEN));
    onMissionPreviewEnd = QUOTE([] call FUNC(BasicSettings3DEN));
};
