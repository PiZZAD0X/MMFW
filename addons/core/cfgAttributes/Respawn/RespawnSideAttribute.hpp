class EGVAR(Respawn,Side_Combo): Combo {
    //save the lbData from the selected entry upon exit
    attributeSave = "\
        private _value = ((_this controlsGroupCtrl 100) lbValue lbCurSel (_this controlsGroupCtrl 100));\
        private _name = gettext (_config >> 'property');\
        missionNamespace setvariable [_name,_value];\
        _value\
    ";
    //_this - config, _value - saved value
    attributeLoad="\
        private _control = (_this controlsGroupCtrl 100);\
        private _name = gettext (_config >> 'property');\
        _respawnSideArray = [['BLUFOR','a3\ui_f\data\map\diary\icons\playerwest_ca.paa'],['OPFOR','a3\ui_f\data\map\diary\icons\playereast_ca.paa'],['Indfor','a3\ui_f\data\map\diary\icons\playerguer_ca.paa'],['Civilian','a3\ui_f\data\map\diary\icons\playerciv_ca.paa']];\
        {\
            _x params ['_sidename','_picture'];\
            private _index = _control lbadd _sidename;\
            _control lbsetdata [_index,_sidename];\
            _control lbsetValue [_index,_foreachIndex];\
            _control lbsetpicture [_index,_picture];\
            _control lbsetpicturecolor [_index,[1,1,1,0.8]];\
            _control lbsetpicturecolorselected [_index,[1,1,1,1]];\
            if (_value isEqualto (_control lbValue _index)) then {\
                _control lbSetCurSel _index;\
            };\
        } foreach _respawnSideArray;\
    ";
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {};
    };
};
