#define SPECTATETEAMS_ATTR_LOAD \
attributeLoad = "\
    private _pictureChecked = gettext (configfile >> 'ctrlCheckbox' >> 'textureChecked');\
    private _pictureUnchecked = gettext (configfile >> 'ctrlCheckbox' >> 'textureUnchecked');\
    private _ctrlListbox = _this controlsGroupCtrl 100;\
    {\
        _x params ['_name'];\
        private _lbAdd = _ctrlListbox lbadd _name;\
        _ctrlListbox lbsetdata [_lbAdd,_name];\
        private _active = _name in _value;\
        _ctrlListbox lbsetvalue [_lbAdd,[0,1] select _active];\
        _ctrlListbox lbsetpicture [_lbAdd,[_pictureUnchecked,_pictureChecked] select _active];\
    } foreach ['BLUFOR','OPFOR','Indfor','CIVILIAN'];\
"

#define SPECTATETEAMS_ATTR_SAVE \
attributeSave = "\
    _value = [];\
    _ctrlListbox = _this controlsGroupCtrl 100;\
    if (ctrlshown _ctrlListbox) exitwith {\
        for '_i' from 0 to (lbsize _ctrlListbox - 1) do {\
            if (_ctrlListbox lbvalue _i > 0) then {_value pushback (_ctrlListbox lbdata _i);};\
        };\
    };\
    _value\
"

#define SPECTATETEAMS_ATTR_ONLOAD \
onLBSelChanged = "\
    _ctrlListbox = _this select 0;\
    _cursel = _this select 1;\
    _active = _ctrlListbox lbvalue _cursel;\
    _active = (_active + 1) % 2;\
    _pictureChecked = gettext (configfile >> 'ctrlCheckbox' >> 'textureChecked');\
    _pictureUnchecked = gettext (configfile >> 'ctrlCheckbox' >> 'textureUnchecked');\
    _ctrlListbox lbsetvalue [_cursel,_active];\
    _ctrlListbox lbsetpicture [_cursel,[_pictureUnchecked,_pictureChecked] select _active];\
"

class EGVAR(Spectator,Teams_Attribute): Title {
    SPECTATETEAMS_ATTR_LOAD;
    SPECTATETEAMS_ATTR_SAVE;
    h="4 * 5 * (pixelH * pixelGrid * 0.50)";
    class Controls: Controls {
        class Title: Title {
            h="4 * 5 * (pixelH * pixelGrid * 0.50)";
        };
        class Value0: ctrlListbox {
            idc=100;
            show=1;
            x="48 * (pixelW * pixelGrid * 0.50)";
            w="82 * (pixelW * pixelGrid * 0.50)";
            h="4 * 5 * (pixelH * pixelGrid * 0.50)";
            colorSelectBackground[]={0,0,0,0};
            colorSelectBackground2[]={0,0,0,0};
            SPECTATETEAMS_ATTR_ONLOAD;
        };
    };
};
