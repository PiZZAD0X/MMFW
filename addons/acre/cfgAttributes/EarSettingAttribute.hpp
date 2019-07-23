class GVAR(EarSetting): Title {
    attributeLoad = "\
        private _unit = ((get3denselected 'object') select 0);\
        private _name = gettext (_config >> 'property');\
        _unit setvariable [_name,_value];\
        private _control = (_this controlsGroupCtrl 100);\
        _control setvariable ['ParentCfg',_config];\
        _control lbsetcursel _value\
    ";
    attributeSave = "\
        private _unit = ((get3denselected 'object') select 0);\
        private _name = gettext (_config >> 'property');\
        private _value = _unit getvariable [_name,0];\
        _value\
    ";
    h = "7 * (pixelH * pixelGrid * 0.50)";
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
            strings[] = {"Left","Center","Right"};
            values[] = {1,0,2};
            onToolboxSelChanged ="\
                params ['_control','_value'];\
                private _unit = ((get3denselected 'object') select 0);\
                private _config = _control getvariable ['ParentCfg',''];\
                private _name = gettext (_config >> 'property');\
                _unit setvariable [_name,_value];\
            ";
        };
    };
};
