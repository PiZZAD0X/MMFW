class GVAR(RadiusAttribute) : Edit {
     attributeLoad = QUOTE(\
        if !(_value isEqualType '') then {\
            _value = str _value;\
        };\
        (_this controlsGroupCtrl 100) ctrlSetText _value;\
    );
     attributeSave = QUOTE(\
        _value = ctrlText (_this controlsGroupCtrl 100);\
        if (gettext (_config >> 'typeName') == 'NUMBER') then {\
            _value = parsenumber _value;\
        };\
        _value\
    );
     class Controls: Controls {
         class Title: Title {};
         class Value: ctrlEdit {
             idc = 100;
             style = ST_LEFT;
             x = "48 * (pixelW * pixelGrid * 0.50)";
             w = "82 * (pixelW * pixelGrid * 0.50)";
             h = "5 * (pixelH * pixelGrid * 0.50)";
         };
     };
 };
