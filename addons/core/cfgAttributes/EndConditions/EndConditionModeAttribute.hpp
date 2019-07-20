class EGVAR(EndConditions,ModeAttribute): Toolbox {
    attributeLoad = "\
        private _name = gettext (_config >> 'property');\
        missionNamespace setvariable [_name,_value];\
        private _control = (_this controlsGroupCtrl 100);\
        _control setvariable ['ParentCfg',_config];\
        _control lbsetcursel _value;\
    ";
    attributeSave = "\
        private _name = gettext (_config >> 'property');\
        private _value = missionNamespace getvariable [_name,''];\
        _value\
    ";
    h = "8 * (pixelH * pixelGrid * 0.50)";
    class Controls: Controls {
        class Title: Title {};
        class Value: ctrlToolbox {
            idc = 100;
            style = "0x02";
            x = "48 * (pixelW * pixelGrid * 0.50)";
            w = "82 * (pixelW * pixelGrid * 0.50)";
            h = "8 * (pixelH * pixelGrid * 0.50)";
            rows = 1;
            columns = 2;
            strings[] = {"All Conditions","Any Condition"};
            values[] = {0,1};
            onToolboxSelChanged = "\
                params ['_control','_value'];\
                private _config = _control getvariable ['ParentCfg',''];\
                private _name = gettext (_config >> 'property');\
                missionNamespace setvariable [_name,_value];\
            ";
        };
    };
};
