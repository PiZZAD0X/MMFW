#define CAPTUREZONETEAMLOOP(TEAMNAMEVAR,CAPMODEVAR,COLOURVAR,TIMEVAR,MESSAGEVAR) case #TEAMNAMEVAR: {\
    if (CAPMODEVAR isEqualTo 0) then {\
        if (_owner isEqualto _oldOwner) then {\
            _argNested set [5,(_ownerControlCount + 1)];\
            if ((_argNested select 5) > TIMEVAR) then {\
                if !(_hidden) then {\
                    _marker setMarkerColor COLOURVAR;\
                    _marker setMarkerAlpha 0.5;\
                };\
                if !(_silent) then {\
                    if (_automessages) then {\
                        private _msg = format ["%1 has captured %2!",EGVAR(Core,DOUBLES(TeamName,TEAMNAMEVAR)),_zoneName];\
                        _msg remoteExec ["hintsilent"];\
                    } else {\
                        (MESSAGEVAR select 1) remoteExec ["hintsilent"];\
                    };\
                };\
                missionNamespace setvariable [_varName,true];\
                missionNamespace setvariable [_teamControllingvarName,#TEAMNAMEVAR];\
                if (_mode isEqualto "ONCE") exitWith {\
                    if !(_hidden) then {\
                        _marker setMarkerAlpha 0.5;\
                        _marker setMarkerBrush "Border";\
                    };\
                    [_idPFH] call CBA_fnc_removePerFrameHandler;\
                };\
            };\
        } else {\
            _argNested set [4,_owner];\
            _argNested set [5,0];\
            if !(_hidden) then {\
                _marker setMarkerColor COLOURVAR;\
                _marker setMarkerAlpha 0.25;\
            };\
            if !(_silent) then {\
                if (_automessages) then {\
                    private _msg = format ["%1 is capturing %2!",EGVAR(Core,DOUBLES(TeamName,TEAMNAMEVAR)),_zoneName];\
                    _msg remoteExec ["hintsilent"];\
                } else {\
                    (MESSAGEVAR select 0) remoteExec ["hintsilent"];\
                };\
            };\
        };\
    } else {\
        _owner = "CONTESTED";\
        _argNested set [5,0];\
        if !(_owner isEqualto _oldOwner) then {\
            _argNested set [4,_owner];\
            if !(_hidden) then {\
                _marker setMarkerColor _contestedcolour;\
                _marker setMarkerAlpha 0.25;\
            };\
            if !(_silent) then {\
                if (_automessages) then {\
                    private _msg = format ["%1 is contested!",_zoneName];\
                    _msg remoteExec ["hintsilent"];\
                } else {\
                    _contestedmessage remoteExec ["hintsilent"];\
                };\
            };\
        };\
    };\
}
