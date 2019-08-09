if (GETMVAR(Enabled_2,false)) then {
    if ((isNil QGVAR(Message_2)) || {!(GETMVAR(Message_2,"") isEqualType "STRING")}) then {
        ERROR("invalid message for End Condition Category 2");
    } else {
        LOG("Valid message for End Condition Category 2, executing");

        private _conditionsCountCategory_2 = 0;
        if (GETMVAR(CasualtyCount_Enabled_BLUFOR_2,false)) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (GETMVAR(CasualtyCount_Enabled_OPFOR_2,false)) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (GETMVAR(CasualtyCount_Enabled_Indfor_2,false)) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (GETMVAR(CasualtyCount_Enabled_Civ_2,false)) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};

        if (!(GETMVAR(EntitiesAlive_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (!(GETMVAR(EntitiesDead_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (!(GETMVAR(EntitiesDamaged_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (!(GETMVAR(HostageRescued_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (!(GETMVAR(CustomVariables_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};
        if (!(GETMVAR(CaptureZoneCaptured_Array_2,[]) isEqualto [])) then {_conditionsCountCategory_2 = _conditionsCountCategory_2 + 2;};

        if ((_conditionsCountCategory_2) > 0  || ((GETMVAR(ExtractionEnabled_2,false)) && {(GETMVAR(ExtractionForced_2,false))})) then {
            LOG_2("Starting Category 2 Condition Count:%1",_conditionsCountCategory_2);
            GVAR(Category_2_PFH) = [{
                params ["_argNested", "_idPFH"];
                if (GVAR(MissionEnded)) exitwith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };
                private _ConditionCheckList = [];

                //Casualty Checks
                private _CasConditionCheck_Blufor = false;

                if (GETMVAR(CasualtyCount_Enabled_BLUFOR_2,false)) then {
                    private _westCasualty = GVAR(TeamName_Blufor) call FUNC(CasualtyPercentage);
                    if (_westCasualty >= GETMVAR(CasualtyCount_Percentage_BLUFOR_2,75)) then {_CasConditionCheck_Blufor = true;} else {_CasConditionCheck_Blufor = false;};
                    _ConditionCheckList pushback ["BLUFOR Cas Check",_CasConditionCheck_Blufor];
                };

                private _CasConditionCheck_Opfor = false;

                if (GETMVAR(CasualtyCount_Enabled_OPFOR_2,false)) then {
                    private _eastCasualty = GVAR(TeamName_Opfor) call FUNC(CasualtyPercentage);
                    if (_eastCasualty >= GETMVAR(CasualtyCount_Percentage_OPFOR_2,75)) then {_CasConditionCheck_Opfor = true;} else {_CasConditionCheck_Opfor = false;};
                    _ConditionCheckList pushback ["OPFOR Cas Check",_CasConditionCheck_Opfor];
                };

                private _CasConditionCheck_Indfor = false;

                if (GETMVAR(CasualtyCount_Enabled_Indfor_2,false)) then {
                    private _resCasualty = GVAR(TeamName_Indfor) call FUNC(CasualtyPercentage);
                    if (_resCasualty >= GETMVAR(CasualtyCount_Percentage_Indfor_2,75)) then {_CasConditionCheck_Indfor = true;} else {_CasConditionCheck_Indfor = false;};
                    _ConditionCheckList pushback ["Indfor Cas Check",_CasConditionCheck_Indfor];
                };

                private _CasConditionCheck_Civ = false;

                if (GETMVAR(CasualtyCount_Enabled_Civ_2,false)) then {
                    private _civCasualty = GVAR(TeamName_Civ) call FUNC(CasualtyPercentage);
                    if (_civCasualty >= GETMVAR(CasualtyCount_Percentage_Civ_2,75)) then {_CasConditionCheck_Civ = true;} else {_CasConditionCheck_Civ = false;};
                    _ConditionCheckList pushback ["CIVILIAN Cas Check",_CasConditionCheck_Civ];
                };

                //alive entity block
                private _aliveUnitArray = GETMVAR(EntitiesAlive_Array_2,[]);
                if (!(_aliveUnitArray isEqualto [])) then {
                    LOG_2("Alive Array 2:%1",_aliveUnitArray);
                    private _alive = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {
                            _alive = _alive && (_unit call FUNC(alive));
                        } else {
                            _alive = false;
                            LOG_2("Unit %1 not found!",_x);
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);
                        };
                    } forEach _aliveUnitArray;
                    _ConditionCheckList pushback ["Alive Check",_alive];
                };

                //dead entity block
                private _deadUnitArray = GETMVAR(EntitiesDead_Array_2,[]);
                if (!(_deadUnitArray isEqualto [])) then {
                    LOG_2("Dead Array 2:%1",_deadUnitArray);
                    private _dead = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if (isNull _unit) then {
                            _dead = false;
                           LOG_2("Unit %1 not found!",_x);
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);
                        } else {
                            private _unitDeadCheck = (!(_unit call FUNC(alive)));
                            LOG_2("Unit %1 check: %2",_unit,_unitDeadCheck);
                            _dead = _dead && _unitDeadCheck;
                        };
                    } forEach _deadUnitArray;
                    _ConditionCheckList pushback ["Dead Check",_dead];
                };

                //damaged & immobilized entity block
                private _damagedUnitArray = GETMVAR(EntitiesDamaged_Array_2,[]);
                if (!(_damagedUnitArray isEqualto [])) then {
                    LOG_2("Damaged Array 2:%1",_damagedUnitArray);
                    private _damaged = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {
                            _damaged = _damaged && ((damage _unit > 0.5) || ((_unit isKindOf LandVehicle) && (!canMove _unit)));
                        } else {
                            _damaged = false;
                           LOG_2("Unit %1 not found!",_x);
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);
                        };
                    } forEach _damagedUnitArray;
                    _ConditionCheckList pushback ["Damaged Check",_damaged];
                };

                //rescued hostage block
                private _hostageRescuedArray = GETMVAR(HostageRescued_Array_2,[]);
                if (!(_hostageRescuedArray isEqualto [])) then {
                    LOG_2("Rescued Array 2:%1",_hostageRescuedArray);
                    private _rescued = true;
                    {
                        private _unit = missionNamespace getVariable [_x,objNull];
                        if (!(_unit isEqualto objNull) && {(_unit call FUNC(alive))}) then {
                            _rescued = _rescued && (EGETVAR(_unit,Hostage,IsRescued,false));
                        } else {
                            _rescued = false;
                            LOG_2("Unit %1 not found!",_x);
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);
                        };
                    } forEach _hostageRescuedArray;
                    _ConditionCheckList pushback ["Rescued Check",_rescued];
                };

                //custom variables block
                private _customVariablesArray = GETMVAR(CustomVariables_Array_2,[]);
                if (!(_customVariablesArray isEqualto [])) then {
                    LOG_2("Var Array 2:%1",_customVariablesArray);
                    private _custom = true;
                    {
                        private _VarCheck = missionNamespace getVariable [_x,false];
                        _custom = _custom && _VarCheck;
                        private _checklisttext = format ["Custom Var Check: %1", _x];
                        _ConditionCheckList pushback [_checklisttext,_custom];
                    } forEach _customVariablesArray;
                };

                private _captureZones_Array_2 = GETMVAR(CaptureZoneCaptured_Array_2,[]);
                if (!(_captureZones_Array_2 isEqualto [])) then {
                    private _captureZones_TeamSetting_2 = GETMVAR(CaptureZoneCaptured_Team_2,1);
                    {
                        private _CaptureZoneConditionCheck = false;
                        if !((call compile _x) in (EGETMVAR(CaptureZone,ListArray,[]))) then {
                            LOG_2("CaptureZone %1 does not exist!",_x);
                            ["CaptureZone " + _x + " does not exist!","CaptureZone " + _x + " does not exist!"] call FUNC(DebugMessageDetailed);
                            _CaptureZoneConditionCheck = false;
                        } else {
                            private _varName = format ["%1_var",_x];
                            private _teamControllingvarName = format ["%1_teamControlling",_x];

                            switch (_captureZones_TeamSetting_2) do {
                                case 0: {
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "UNCONTESTED") then {
                                        _CaptureZoneConditionCheck = true;
                                    } else {
                                        _CaptureZoneConditionCheck = false;
                                    };
                                };
                                case 2: {
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
                    } foreach _captureZones_Array_2;
                };

                LOG_2("Category 2 _ConditionCheckList:%1",_ConditionCheckList);

                private _ExtractionCheck = false;

                //check block
                if (GETMVAR(ExtractionEnabled_2,false)) then {
                    private _team = ([GVAR(TeamName_Blufor),GVAR(TeamName_Opfor),GVAR(TeamName_Indfor),GVAR(TeamName_Civ)] select GVAR(ExtractionTeam_2));
                    if (GVAR(ExtractionMarker_2) isEqualto "") exitwith {["","No marker entered for extract zone for Category 2!"] call FUNC(DebugMessageDetailed);};
                    if ((getMarkerColor GVAR(ExtractionMarker_2)) isEqualto "") exitwith {["","Invalid extract marker for Category 2!"] call FUNC(DebugMessageDetailed);};
                        if ([_team,GVAR(ExtractionMarker_2),GVAR(ExtractionRatio_2)] call FUNC(hasExtracted)) then {
                            _ExtractionCheck = true;
                        } else {
                            _ExtractionCheck = false;
                        };
                        TRACE_2("Extraction Check Category 2",_ExtractionCheck);
                } else {
                    _ExtractionCheck = true;
                };

                if (_ExtractionCheck) then {
                    if ((GETMVAR(ExtractionEnabled_2,false)) && {(GETMVAR(ExtractionForced_2,false))}) then
                    {
                        LOG_2("Category 2 Ending due to forced Extraction!");
                        [GVAR(Message_2)] call FUNC(EndMission);
                        [_idPFH] call CBA_fnc_removePerFrameHandler;
                    } else {
                        if (GVAR(Mode_2) isEqualto 2) then {
                            {
                                _x params ["_name","_value"];
                                if (_value) exitwith {
                                    LOG_2("Category 2 Ending due to :%1",_value);
                                    [GVAR(Message_2)] call FUNC(EndMission);
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                                };
                            } foreach _ConditionCheckList;
                        } else {
                            private _fullcheck = true;
                            {
                                _x params ["_name","_value"];
                                _fullcheck = _fullcheck && _value;
                                LOG_2("Category 2 checking var:%1 result:%2",_name,_value);
                            } foreach _ConditionCheckList;
                            if (_fullcheck) then {
                                LOG("Category 2 Ending due to all conditions met!");
                                [GVAR(Message_2)] call FUNC(EndMission);
                                [_idPFH] call CBA_fnc_removePerFrameHandler;
                            };
                        };
                    };
                };
            }, (GETMVAR(ConditionSleep,30))] call CBA_fnc_addPerFrameHandler;
        } else {
            ERROR("No Conditions for Category 2");
        };
    };
};
