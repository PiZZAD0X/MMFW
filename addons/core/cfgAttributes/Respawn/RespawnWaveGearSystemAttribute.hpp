class EGVAR(Respawn,WaveGearSystemAttribute): Combo {
    //save the lbData from the selected entry upon exit
    attributeSave = "\
        private _attProperty = getText (_config >> 'property');\
        private _value = ((_this controlsGroupCtrl 100) lbData lbCurSel (_this controlsGroupCtrl 100));\
        missionNamespace setvariable [_attProperty,_value];\
        _value\
    ";
    //_this - config, _value - saved value
    attributeLoad="\
        private _control = (_this controlsGroupCtrl 100);\
        private _attProperty = getText (_config >> 'property');\
        _waveGearSystemArray = ['Loose','Preferential','Strict'];\
        {\
            _x params ['_name'];\
            private _index = _control lbadd _name;\
            _control lbsetdata [_index,_name];\
            _control lbsetValue [_index,_foreachIndex];\
            if (_value isEqualto (_control lbData _index)) then {\
                _control lbSetCurSel _index;\
            };\
        } foreach _waveGearSystemArray;\
    ";
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            idc=100;
            onLBSelChanged="\
                _ctrlCombo = _this select 0;\
                _cursel = _this select 1;\
                _value = _control lbData _cursel;\
                private _config = _ctrlCombo getvariable ['parentcontrolcfg',''];\
                private _attProperty = getText (_config >> 'property');\
                missionNamespace setvariable [_attProperty,_value];\
            ";
        };
    };
};
