#define NEWTAB(NAME) _briefing set [count _briefing, ["Diary",[NAME

#define ENDTAB ]]]

#define DISPLAYBRIEFING() \
for "_i" from 0 to (count _briefing) step 1 do {\
    player createDiaryRecord (_briefing select ((count _briefing) - _i));\
};
