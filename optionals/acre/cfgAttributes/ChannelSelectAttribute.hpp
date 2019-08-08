class GVAR(ChannelSelect): Title {
    attributeLoad = "\
        private _valuestr = str _value;\
        (_this controlsGroupCtrl 100) ctrlSetText _valuestr;\
    ";
    attributeSave = "\
        private _attProperty = getText (_config >> 'property');\
        private _value = (parsenumber (ctrlText (_this controlsGroupCtrl 100)));\
        private _unit = ((get3denselected 'object') select 0);\
        _unit setvariable [_attProperty,_value];\
        _value\
    ";
    class Controls: Controls {
        class Title: Title {};
        class TitleZ: ctrlStatic {
            text = "Channel";
            style = 2;
            shadow = 0;
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "14 * (pixelW * pixelGrid * 0.50)";
            h = "5 * (pixelH * pixelGrid * 0.50)";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.5,0.5,0.5,1};
        };
        class ValueZ: ctrlEdit {
            idc = 100;
            x = "(48 + 14) * (pixelW * pixelGrid * 0.50)";
            w = "(82 / 3 - 14) * (pixelW * pixelGrid * 0.50)";
            h = "5 * (pixelH * pixelGrid * 0.50)";
            font = "EtelkaMonospacePro";
            sizeEx = "3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
        };
    };
};
