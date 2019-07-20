#define EH_3DENBASICSETTINGS QUOTE(\
    if !((getMissionConfigValue [ARR_2('GVAR(Enabled)','')]) isEqualTo '') then {\
        if ((getMissionConfigValue [ARR_2('GVAR(Enabled)','false')])) then {\
            [] call (FUNC(BasicSettings3DEN));\
        };\
    };\
)

class EGVAR(3DEN,EH) {
    onTerrainNew = EH_3DENBASICSETTINGS;
    onMissionLoad = EH_3DENBASICSETTINGS;
    onMissionNew = EH_3DENBASICSETTINGS;
    onMissionSave = EH_3DENBASICSETTINGS;
    onMissionPreviewEnd = EH_3DENBASICSETTINGS;
};
