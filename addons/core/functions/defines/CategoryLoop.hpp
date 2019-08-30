#define CATEGORYLOOP(LOOPNUM) if (EGETMVAR(EndConditions,DOUBLES(Enabled,LOOPNUM),false)) then {\
    if ((EGETMVAR(EndConditions,DOUBLES(Message,LOOPNUM),"") isEqualTo "") || {!(EGETMVAR(EndConditions,DOUBLES(Message,LOOPNUM),"") isEqualType "STRING")}) then {\
        ERROR_1("Invalid message for End Condition Category %1",LOOPNUM);\
    } else {\
        LOG_1("Valid message for End Condition Category %1, executing",LOOPNUM);\
\
        private _conditionsCountCategory = 0;\
        if (EGETMVAR(EndConditions,CasualtyCount_Enabled_BLUFOR,false)) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (EGETMVAR(EndConditions,CasualtyCount_Enabled_OPFOR,false)) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (EGETMVAR(EndConditions,CasualtyCount_Enabled_Indfor,false)) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (EGETMVAR(EndConditions,CasualtyCount_Enabled_Civ,false)) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
\
        if (!(EGETMVAR(EndConditions,EntitiesAlive_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (!(EGETMVAR(EndConditions,EntitiesDead_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (!(EGETMVAR(EndConditions,EntitiesDamaged_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (!(EGETMVAR(EndConditions,HostageRescued_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (!(EGETMVAR(EndConditions,CustomVariables_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
        if (!(EGETMVAR(EndConditions,CaptureZoneCaptured_Array,[]) isEqualto [])) then {_conditionsCountCategory = _conditionsCountCategory + 1;};\
\
        if ((_conditionsCountCategory) > 0  || ((EGETMVAR(EndConditions,DOUBLES(ExtractionEnabled,LOOPNUM),false)) && {(EGETMVAR(EndConditions,DOUBLES(ExtractionForced,LOOPNUM),false))})) then {\
            LOG_2("Starting Category %2 Condition Count:%1",_conditionsCountCategory,LOOPNUM);\
            EGVAR(EndConditions,TRIPLES(Category,LOOPNUM,PFH)) = [{\
                params ["_argNested", "_idPFH"];\
                if (GETMVAR(MissionEnded,false)) exitwith {\
                    [_idPFH] call CBA_fnc_removePerFrameHandler;\
                };\
                private _ConditionCheckList = [];\
\
                private _CasConditionCheck_Blufor = false;\
\
                if (EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_BLUFOR,LOOPNUM),false)) then {\
                    private _westCasualty = GVAR(TeamName_Blufor) call FUNC(CasualtyPercentage);\
                    if (_westCasualty >= EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_BLUFOR,LOOPNUM),75)) then {_CasConditionCheck_Blufor = true;} else {_CasConditionCheck_Blufor = false;};\
                    _ConditionCheckList pushback ["BLUFOR Cas Check",_CasConditionCheck_Blufor];\
                };\
\
                private _CasConditionCheck_Opfor = false;\
\
                if (EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_OPFOR,LOOPNUM),false)) then {\
                    private _eastCasualty = GVAR(TeamName_Opfor) call FUNC(CasualtyPercentage);\
                    if (_eastCasualty >= EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_OPFOR,LOOPNUM),75)) then {_CasConditionCheck_Opfor = true;} else {_CasConditionCheck_Opfor = false;};\
                    _ConditionCheckList pushback ["OPFOR Cas Check",_CasConditionCheck_Opfor];\
                };\
\
                private _CasConditionCheck_Indfor = false;\
\
                if (EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_Indfor,LOOPNUM),false)) then {\
                    private _resCasualty = GVAR(TeamName_Indfor) call FUNC(CasualtyPercentage);\
                    if (_resCasualty >= EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_Indfor,LOOPNUM),75)) then {_CasConditionCheck_Indfor = true;} else {_CasConditionCheck_Indfor = false;};\
                    _ConditionCheckList pushback ["INDFOR Cas Check",_CasConditionCheck_Indfor];\
                };\
\
                private _CasConditionCheck_Civ = false;\
\
                if (EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Enabled_Civ,LOOPNUM),false)) then {\
                    private _civCasualty = GVAR(TeamName_Civ) call FUNC(CasualtyPercentage);\
                    if (_civCasualty >= EGETMVAR(EndConditions,DOUBLES(CasualtyCount_Percentage_Civ,LOOPNUM),75)) then {_CasConditionCheck_Civ = true;} else {_CasConditionCheck_Civ = false;};\
                    _ConditionCheckList pushback ["CIVILIAN Cas Check",_CasConditionCheck_Civ];\
                };\
\
                private _aliveUnitArray = EGETMVAR(EndConditions,DOUBLES(EntitiesAlive_Array,LOOPNUM),[]);\
                if (!(_aliveUnitArray isEqualto [])) then {\
                    LOG_2("Alive Array %2:%1",_aliveUnitArray,LOOPNUM);\
                    private _alive = true;\
                    {\
                        private _unit = missionNamespace getVariable [_x,objNull];\
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {\
                            _alive = _alive && (_unit call FUNC(alive));\
                        } else {\
                            _alive = false;\
                            ERROR_1("Unit %1 not found!",_x);\
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);\
                        };\
                    } forEach _aliveUnitArray;\
                    _ConditionCheckList pushback ["Alive Check",_alive];\
                };\
\
                private _deadUnitArray = EGETMVAR(EndConditions,DOUBLES(EntitiesDead_Array,LOOPNUM),[]);\
                if (!(_deadUnitArray isEqualto [])) then {\
                    LOG_2("Dead Array %2:%1",_deadUnitArray,LOOPNUM);\
                    private _dead = true;\
                    {\
                        private _unit = missionNamespace getVariable [_x,objNull];\
                        if (isNull _unit) then {\
                            _dead = false;\
                           ERROR_1("Unit %1 not found!",_x);\
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);\
                        } else {\
                            private _unitDeadCheck = (!(_unit call FUNC(alive)));\
                            LOG_2("Unit %1 check: %2",_unit,_unitDeadCheck);\
                            _dead = _dead && _unitDeadCheck;\
                        };\
                    } forEach _deadUnitArray;\
                    _ConditionCheckList pushback ["Dead Check",_dead];\
                };\
\
                private _damagedUnitArray = EGETMVAR(EndConditions,DOUBLES(EntitiesDamaged_Array,LOOPNUM),[]);\
                if (!(_damagedUnitArray isEqualto [])) then {\
                    LOG_2("Damaged Array %2:%1",_damagedUnitArray,LOOPNUM);\
                    private _damaged = true;\
                    {\
                        private _unit = missionNamespace getVariable [_x,objNull];\
                        if ((_unit isEqualType "OBJECT") && {!(_unit isEqualto objNull)}) then {\
                            _damaged = _damaged && ((damage _unit > 0.5) || ((_unit isKindOf LandVehicle) && (!canMove _unit)));\
                        } else {\
                            _damaged = false;\
                           ERROR_1("Unit %1 not found!",_x);\
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);\
                        };\
                    } forEach _damagedUnitArray;\
                    _ConditionCheckList pushback ["Damaged Check",_damaged];\
                };\
\
                private _hostageRescuedArray = EGETMVAR(EndConditions,DOUBLES(HostageRescued_Array,LOOPNUM),[]);\
                if (!(_hostageRescuedArray isEqualto [])) then {\
                    LOG_2("Rescued Array %2:%1",_hostageRescuedArray,LOOPNUM);\
                    private _rescued = true;\
                    {\
                        private _unit = missionNamespace getVariable [_x,objNull];\
                        if (!(_unit isEqualto objNull) && {(_unit call FUNC(alive))}) then {\
                            _rescued = _rescued && (EGETVAR(_unit,Hostage,IsRescued,false));\
                        } else {\
                            _rescued = false;\
                            ERROR_1("Unit %1 not found!",_x);\
                            ["Unit " + _x + " not found!","Unit " + _x + " not found!"] call FUNC(DebugMessageDetailed);\
                        };\
                    } forEach _hostageRescuedArray;\
                    _ConditionCheckList pushback ["Rescued Check",_rescued];\
                };\
\
                private _customVariablesArray = EGETMVAR(EndConditions,DOUBLES(CustomVariables_Array,LOOPNUM),[]);\
                if (!(_customVariablesArray isEqualto [])) then {\
                    LOG_2("Var Array %2:%1",_customVariablesArray,LOOPNUM);\
                    private _custom = true;\
                    {\
                        private _VarCheck = missionNamespace getVariable [_x,false];\
                        _custom = _custom && _VarCheck;\
                        private _checklisttext = format ["Custom Var Check: %1", _x];\
                        _ConditionCheckList pushback [_checklisttext,_custom];\
                    } forEach _customVariablesArray;\
                };\
\
                private _captureZones_Array = EGETMVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Array,LOOPNUM),[]);\
                if (!(_captureZones_Array isEqualto [])) then {\
                    private _captureZones_TeamSetting = EGETMVAR(EndConditions,DOUBLES(CaptureZoneCaptured_Team,LOOPNUM),1);\
                    {\
                        private _CaptureZoneConditionCheck = false;\
                        if !((call compile _x) in (EGETMVAR(EndConditions,DOUBLES(CaptureZone_ListArray,LOOPNUM),[]))) then {\
                            ERROR_1("CaptureZone %1 does not exist!",_x);\
                            ["CaptureZone " + _x + " does not exist!","CaptureZone " + _x + " does not exist!"] call FUNC(DebugMessageDetailed);\
                            _CaptureZoneConditionCheck = false;\
                        } else {\
                            private _varName = format ["%1_var",_x];\
                            private _teamControllingvarName = format ["%1_teamControlling",_x];\
\
                            switch (_captureZones_TeamSetting) do {\
                                case 0: {\
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "UNCONTESTED") then {\
                                        _CaptureZoneConditionCheck = true;\
                                    } else {\
                                        _CaptureZoneConditionCheck = false;\
                                    };\
                                };\
                                case 1: {\
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "BLUFOR") then {\
                                        _CaptureZoneConditionCheck = true;\
                                    } else {\
                                        _CaptureZoneConditionCheck = false;\
                                    };\
                                };\
                                case 2: {\
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "OPFOR") then {\
                                        _CaptureZoneConditionCheck = true;\
                                    } else {\
                                        _CaptureZoneConditionCheck = false;\
                                    };\
                                };\
                                case 3: {\
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "INDFOR") then {\
                                        _CaptureZoneConditionCheck = true;\
                                    } else {\
                                        _CaptureZoneConditionCheck = false;\
                                    };\
                                };\
                                case 4: {\
                                    if ((missionNamespace getVariable [_teamControllingvarName,false]) isEqualto "CIVILIAN") then {\
                                        _CaptureZoneConditionCheck = true;\
                                    } else {\
                                        _CaptureZoneConditionCheck = false;\
                                    };\
                                };\
                                default {_CaptureZoneConditionCheck = false;};\
                            };\
\
                            _CaptureZoneConditionCheck = _CaptureZoneConditionCheck && {(missionNamespace getVariable [_varName,false])};\
                            private _checklisttext = format ["CaptureZoneCheck Check: %1 _var: %2 _team: %3", _x,(missionNamespace getVariable [_varName,false]),(missionNamespace getVariable [_teamControllingvarName,false])];\
                            _ConditionCheckList pushback [_checklisttext,_CaptureZoneConditionCheck];\
                        };\
                    } foreach _captureZones_Array;\
                };\
\
                LOG_2("Category %2 _ConditionCheckList:%1",_ConditionCheckList,LOOPNUM);\
\
                private _ExtractionCheck = false;\
\
                if (EGETMVAR(EndConditions,DOUBLES(ExtractionEnabled,LOOPNUM),false)) then {\
                    private _team = ([GVAR(TeamName_Blufor),GVAR(TeamName_Opfor),GVAR(TeamName_Indfor),GVAR(TeamName_Civ)] select EGETMVAR(EndConditions,DOUBLES(ExtractionTeam,LOOPNUM),0));\
                    private _moduleName = EGETMVAR(EndConditions,DOUBLES(ExtractionMarker,LOOPNUM),"No Area Defined");\
                    if (_moduleName isEqualTo "No Area Defined") exitwith {\
                        ERROR_1("Extraction Module for Category %1 Not Defined",LOOPNUM);\
                    };\
                    private _moduleArea = [];\
                    {\
                        _x params ["_AreaName","_area","_logic"];\
                        if (_moduleName isEqualTo _AreaName) exitwith {\
                            _moduleArea = _area;\
                        };\
                    } foreach EGVAR(EndConditions,ExtractAreaArray);\
                    if (_moduleArea isEqualto []) exitwith {\
                        ERROR_2("Extraction Module %2 for Category %1 Not Found!",LOOPNUM,_moduleName);\
                    };\
                    if ([_team,_moduleArea,GVAR(DOUBLES(ExtractionRatio,LOOPNUM))] call FUNC(hasExtracted)) then {\
                        _ExtractionCheck = true;\
                    } else {\
                        _ExtractionCheck = false;\
                    };\
                    LOG_2("Category %2 Extraction Check: %1",_ExtractionCheck,LOOPNUM);\
                } else {\
                    _ExtractionCheck = true;\
                };\
\
                if (_ExtractionCheck) then {\
                    if ((EGETMVAR(EndConditions,DOUBLES(ExtractionEnabled,LOOPNUM),false)) && {(EGETMVAR(EndConditions,DOUBLES(ExtractionForced,LOOPNUM),false))}) then {\
                        LOG_1("Category %1 Ending due to forced Extraction!",LOOPNUM);\
                        [EGETMVAR(EndConditions,DOUBLES(Message,LOOPNUM),"")] call FUNC(EndMission);\
                        [_idPFH] call CBA_fnc_removePerFrameHandler;\
                    } else {\
                        if (GVAR(Mode_1) isEqualto 1) then {\
                            {\
                                _x params ["_name","_value"];\
                                if (_value) exitwith {\
                                    LOG_2("Category %2 Ending due to :%1",_value,LOOPNUM);\
                                    [EGETMVAR(EndConditions,DOUBLES(Message,LOOPNUM),"")] call FUNC(EndMission);\
                                    [_idPFH] call CBA_fnc_removePerFrameHandler;\
                                };\
                            } foreach _ConditionCheckList;\
                        } else {\
                            private _fullcheck = true;\
                            {\
                                _x params ["_name","_value"];\
                                _fullcheck = _fullcheck && _value;\
                                LOG_3("Category %3 checking var:%1 result:%2",_name,_value,LOOPNUM);\
                            } foreach _ConditionCheckList;\
                            if (_fullcheck) then {\
                                LOG_1("Category %1 Ending due to all conditions met!",LOOPNUM);\
                                [EGETMVAR(EndConditions,DOUBLES(Message,LOOPNUM),"")] call FUNC(EndMission);\
                                [_idPFH] call CBA_fnc_removePerFrameHandler;\
                            };\
                        };\
                    };\
                };\
            }, (EGETMVAR(EndConditions,ConditionSleep,30))] call CBA_fnc_addPerFrameHandler;\
        } else {\
            ERROR_1("No Conditions for Category %1",LOOPNUM);\
        };\
    };\
}
