class GVAR(EH) {
    onTerrainNew = QUOTE([] call FUNC(GearHandleEH));
    onMissionLoad = QUOTE([] call FUNC(GearHandleEH));
    onMissionNew = QUOTE([] call FUNC(GearHandleEH));
    onMissionSave = QUOTE([] call FUNC(GearHandleEH));
    onMissionPreviewEnd = QUOTE([] call FUNC(GearHandleEH));
};
