#define NEWTAB(NAME) _briefing set [count _briefing, ["Diary",[NAME

#define ENDTAB ]]]

#define DISPLAYBRIEFING() \
{\
    player createDiaryRecord _x;\
} foreach _briefing;
