class GVAR(DragAttribute): GVAR(CarryAttribute) {
    class Controls: Controls {
        class Title: Title {};
        class Value: ctrlToolbox {
            idc = 100;
            style = "0x02";
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "6 * (pixelH * pixelGrid * 0.50)";
            rows = 1;
            columns = 3;
            strings[] = {"Cant Drag","Can Drag","Ignore Weight"};
            values[] = {0,1,2};
            onToolboxSelChanged = QUOTE([_this] call FUNC(CarryAttribute_ToolboxSel));
        };
    };
};
