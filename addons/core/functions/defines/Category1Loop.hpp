if (GETMVAR(Enabled_1,false)) then {
    if ((isNil QGVAR(Message_1)) || {!(GETMVAR(Message_1,"") isEqualType "STRING")}) then {
        ERROR("invalid message for End Condition Category 1");
    } else {
        LOG("Valid message for End Condition Category 1, executing");

        private _conditionsCountCategory1 = 0;
        if (GETMVAR(CasualtyCount_Enabled_BLUFOR_1,false)) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (GETMVAR(CasualtyCount_Enabled_OPFOR_1,false)) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (GETMVAR(CasualtyCount_Enabled_Indfor_1,false)) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (GETMVAR(CasualtyCount_Enabled_Civ_1,false)) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};

        if (!(GETMVAR(EntitiesAlive_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (!(GETMVAR(EntitiesDead_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (!(GETMVAR(EntitiesDamaged_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (!(GETMVAR(HostageRescued_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (!(GETMVAR(CustomVariables_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};
        if (!(GETMVAR(CaptureZoneCaptured_Array_1,[]) isEqualto [])) then {_conditionsCountCategory1 = _conditionsCountCategory1 + 1;};

        if ((_conditionsCountCategory1) > 0) then {
            LOG_1("Starting Category 1 Condition Count:%1",_conditionsCountCategory1);
            private _endConditionsCategory1PFHhandle = [{
                params ["_argNested", "_idPFH"];
                _argNested params ["_checkFrequency","_lastCheckedTime"];
                if (EGVAR(core,MissionEnded)) exitwith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
                private _timeDifference = (CBA_missionTime - _lastCheckedTime);
                if (_timeDifference <= _checkFrequency) exitwith {
                };
                LOG_1("Category Check with _lastCheckedTime: %1",_lastCheckedTime);
                _argNested set [1,CBA_missionTime];
                private _ConditionCheckList = [];

                //Casualty Checks
                private _CasConditionCheck_Blufor = false;

                if (GETMVAR(CasualtyCount_Enabled_BLUFOR_1,false)) then {
                    private _westCasualty = EGVAR(Core,TeamName_Blufor) call EFUNC(Core,CasualtyPercentage);
                    if (_westCasualty >= GETMVAR(CasualtyCount_Percentage_BLUFOR_1,75)) then {_CasConditionCheck_Blufor = true;} else {_CasConditionCheck_Blufor = false;};
                    _ConditionCheckList pushback ["BLUFOR Cas Check",_CasConditionCheck_Blufor];
                };

                private _CasConditionCheck_Opfor = false;

                if (GETMVAR(CasualtyCount_Enabled_OPFOR_1,false)) then {
                    private _eastCasualty = EGVAR(Core,TeamName_Opfor) call EFUNC(Core,CasualtyPercentage);
                    if (_eastCasualty >= GETMVAR(CasualtyCount_Percentage_OPFOR_1,75)) then {_CasConditionCheck_Opfor = true;} else {_CasConditionCheck_Opfor = false;};
                    _ConditionCheckList pushback ["OPFOR Cas Check",_CasConditionCheck_Opfor];
                };

                private _CasConditionCheck_Indfor = false;

                if (GETMVAR(CasualtyCount_Enabled_Indfor_1,false)) then {
                    private _resCasualty = EGVAR(Core,TeamName_Indfor) call EFUNC(Core,CasualtyPercentage);
                    if (_resCasualty >= GETMVAR(CasualtyCount_Percentage_Indfor_1,75)) then {_CasConditionCheck_Indfor = true;} else {_CasConditionCheck_Indfor = false;};
                    _ConditionCheckList pushback ["Indfor Cas Check",_CasConditionCheck_Indfor];
                };

                private _CasConditionCheck_Civ = false;

                if (GETMVAR(CasualtyCount_Enabled_Civ_1,false)) then {
                    private _civCasualty = EGVAR(Core,TeamName_Civ) call EFUNC(Core,CasualtyPercentage);
                    if (_civCasualty >= GETMVAR(CasualtyCount_Percentage_Civ_1,75)) then {_CasConditionCheck_Civ = true;} else {_CasConditionCheck_Civ = false;};
                    _ConditionCheckList pushback ["CIVILIAN Cas Check",_CasConditionCheck_Civ];
                };

                //alive entity block
                private _aliveUnitArray = GETMVAR(EntitiesAlive_Array_1,[]);
                if (!(_aliveUnitArray isEqualto [])) then {
                    LOG_1("Alive Array 1:%1",_aliveUnitArray);
                    private _alive = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {
                            _alive = _alive && (_unit call EFUNC(Core,alive));
                        } else {
                            _alive = false;
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call EFUNC(Debug,DebugMessageDetailed);
                        };
                    } forEach _aliveUnitArray;
                    _ConditionCheckList pushback ["Alive Check",_alive];
                };

                //dead entity block
                private _deadUnitArray = GETMVAR(EntitiesDead_Array_1,[]);
                if (!(_deadUnitArray isEqualto [])) then {
                    LOG_1("Dead Array 1:%1",_deadUnitArray);
                    private _dead = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if (isNull _unit) then {
                            _dead = false;
                            LOG_1("Unit %1 not found!",_unit);
                        } else {
                            private _unitDeadCheck = (!(_unit call EFUNC(Core,alive)));
                            LOG_2("Unit %1 check: %2",_unit,_unitDeadCheck);
                            _dead = _dead && _unitDeadCheck;
                        };
                    } forEach _deadUnitArray;
                    _ConditionCheckList pushback ["Dead Check",_dead];
                };

                //damaged & immobilized entity block
                private _damagedUnitArray = GETMVAR(EntitiesDamaged_Array_1,[]);
                if (!(_damagedUnitArray isEqualto [])) then {
                    LOG_1("Damaged Array 1:%1",_damagedUnitArray);
                    private _damaged = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {
                            _damaged = _damaged && ((damage _unit > 0.5) || ((_unit isKindOf LandVehicle) && (!canMove _unit)));
                        } else {
                            _damaged = false;
                            LOG_1("Unit %1 not found!",_x);
                        };
                    } forEach _damagedUnitArray;
                    _ConditionCheckList pushback ["Damaged Check",_damaged];
                };

                //rescued hostage block
                private _hostageRescuedArray = GETMVAR(HostageRescued_Array_1,[]);
                if (!(_hostageRescuedArray isEqualto [])) then {
                    LOG_1("Rescued Array 1:%1",_hostageRescuedArray);
                    private _rescued = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if (!(_unit isEqualto objNull) && {(_unit call EFUNC(Core,alive))}) then {
                            _rescued = _rescued && (EGETVAR(_unit,Hostage,IsRescued,false));
                        } else {
                            _rescued = false;
                            LOG_1("Unit %1 not found!",_x);
                        };
                    } forEach _hostageRescuedArray;
                    _ConditionCheckList pushback ["Rescued Check",_rescued];
                };

                //custom variables block
                private _customVariablesArray = GETMVAR(CustomVariables_Array_1,[]);
                if (!(_customVariablesArray isEqualto [])) then {
                    LOG_1("Var Array 1:%1",_customVariablesArray);
                    private _custom = true;
                    {
                        private _VarCheck = missionNamespace getVariable [_x,false];
                        _custom = _custom && _VarCheck;
                        private _checklisttext = format ["Custom Var Check: %1", _x];
                        _ConditionCheckList pushback [_checklisttext,_custom];
                    } forEach _customVariablesArray;
                };

                private _captureZones_Array_1 = GETMVAR(CaptureZoneCaptured_Array_1,[]);
                if (!(_captureZones_Array_1 isEqualto [])) then {
                    private _captureZones_TeamSetting_1 = GETMVAR(CaptureZoneCaptured_Team_1,1);
                    {
                        private _CaptureZoneConditionCheck = false;
                        if !((call compile _x) in (EGETMVAR(CaptureZone,ListArray,[]))) then {
                            LOG_1("CaptureZone %1 does not exist!",_x);
                            _CaptureZoneConditionCheck = false;
                        } else {
                            private _varName = format ["%1_var",_x];
                            private _teamControllingvarName = format ["%1_teamControlling",_x];

                            switch (_captureZones_TeamSetting_1) do {
                                case 0: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "UNCONTESTED") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                case 1: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "BLUFOR") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                case 2: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "OPFOR") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                case 3: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "INDFOR") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                case 4: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "CIVILIAN") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                default {_CaptureZoneConditionCheck = false;};
                            };

                            _CaptureZoneConditionCheck = _CaptureZoneConditionCheck && {(missionNamespace getVariable [_varName,false])};
                            private _checklisttext = format ["CaptureZoneCheck Check: %1 _var: %2 _team: %3", _x,(missionNamespace getVariable [_varName,false]),(missionNamespace getVariable [_teamControllingvarName,false])];
                            _ConditionCheckList pushback [_checklisttext,_CaptureZoneConditionCheck];
                        };
                    } foreach _captureZones_Array_1;
                };

                LOG_1("Category 1 _ConditionCheckList:%1",_ConditionCheckList);

                private _ExtractionCheck = false;

                //check block
                if (GETMVAR(ExtractionEnabled_1,false)) then {
                    private _team = ([EGVAR(Core,TeamName_Blufor),EGVAR(Core,TeamName_Opfor),EGVAR(Core,TeamName_Indfor),EGVAR(Core,TeamName_Civ)] select GVAR(ExtractionTeam_1));
                    if (GVAR(ExtractionMarker_1) isEqualto "") exitwith {["","No marker entered for extract zone for Category 1!"] call EFUNC(Debug,DebugMessageDetailed);};
                    if ((getMarkerColor GVAR(ExtractionMarker_1)) isEqualto "") exitwith {["","Invalid extract marker for Category 1!"] call EFUNC(Debug,DebugMessageDetailed);};
                        if ([_team,GVAR(ExtractionMarker_1),GVAR(ExtractionRatio_1)] call FUNC(hasExtracted)) then {
                            _ExtractionCheck = true;
                        } else {
                            _ExtractionCheck = false;
                        };
                } else {
                    _ExtractionCheck = true;
                };

                if (_ExtractionCheck) then {
                    if (GVAR(Mode_1) isEqualto 1) then {
                        {
                            _x params ["_name","_value"];
                            if (_value) exitwith {
                                LOG_1("Category 1 Ending due to :%1",_value);
                                [GVAR(Message_1)] call EFUNC(Core,EndMission);
                                [_idPFH] call CBA_fnc_removePerFrameHandler;
                            };
                        } foreach _ConditionCheckList;
                    } else {
                        private _fullcheck = true;
                        {
                            _x params ["_name","_value"];
                            _fullcheck = _fullcheck && _value;
                            LOG_2("Category 1 checking var:%1 result:%2",_name,_value);
                        } foreach _ConditionCheckList;
                        if (_fullcheck) then {
                            LOG("Category 1 Ending due to all conditions met!");
                            [GVAR(Message_1)] call EFUNC(Core,EndMission);
                            [_idPFH] call CBA_fnc_removePerFrameHandler;
                        };
                    };
                };
            }, 1, [(GETMVAR(ConditionSleep,30)),CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
        } else {
            ERROR("No Conditions for Category 1");
        };
    };
};
