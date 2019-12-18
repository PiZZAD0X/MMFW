class GVAR(EH) {
    onTerrainNew = QUOTE([] call FUNC(setAllEntityGear_EH));
    onMissionLoad = QUOTE([] call FUNC(setAllEntityGear_EH));
    onMissionNew = QUOTE([] call FUNC(setAllEntityGear_EH));
    onMissionSave = QUOTE([] call FUNC(setAllEntityGear_EH));
    onMissionPreviewEnd = QUOTE([] call FUNC(setAllEntityGear_EH));
};
