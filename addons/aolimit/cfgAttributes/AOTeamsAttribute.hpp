class GVAR(TeamsAttribute): Title {
    attributeLoad = QUOTE([ARR_3(_this,_value,_config)] call FUNC(AOTeamsAttribute_AttrLoad));
    attributeSave = QUOTE([ARR_2(_this,_config)] call FUNC(AOTeamsAttribute_AttrSave));
    h = "4 * 5 * (pixelH * pixelGrid * 0.50)";
    class Controls: Controls {
        class Title: Title {
            h = "4 * 5 * (pixelH * pixelGrid * 0.50)";
        };
        class Value0: ctrlListbox {
            idc = 100;
            show = 1;
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "4 * 5 * (pixelH * pixelGrid * 0.50)";
            colorSelectBackground[] = {0,0,0,0};
            colorSelectBackground2[] = {0,0,0,0};
            onLBSelChanged = QUOTE(_this call FUNC(AOTeamsAttribute_onLBSelChanged));
        };
    };
};
