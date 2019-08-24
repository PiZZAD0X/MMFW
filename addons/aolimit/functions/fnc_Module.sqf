#include "script_component.hpp"

params [["_mode","",[""]],["_input",[],[[]]]];
switch _mode do {
    case "init": {
        EXEC_CHECK(ALL);
        if !(is3DEN) then {
            _input params ["_logic",["_isActivated",true,[true]]];
            if !(_isActivated) exitWith {};
            private _selectedSides = GETVAR(_logic,TeamsEnabled,["BLUFOR","OPFOR","INDFOR","CIVILIAN"]);
            if ("BLUFOR" in _selectedSides) then {_selectedSides pushBackUnique BLUFOR};
            if ("OPFOR" in _selectedSides) then {_selectedSides pushBackUnique OPFOR};
            if ("INDFOR" in _selectedSides) then {_selectedSides pushBackUnique INDEPENDENT};
            if ("CIVILIAN" in _selectedSides) then {_selectedSides pushBackUnique CIVILIAN};
            if (_selectedSides isEqualTo []) exitwith {
                LOG("No sides defined for AO limit!");
            };
            private _entryMode = GETVAR(_logic,EntryMode,false);
            private _airsetting = GETVAR(_logic,AirUnits,true);
            private _AOMode = GETVAR(_logic,AOMode,"HARD");
            private _softAOtime = GETVAR(_logic,SoftTimeOutside,30);
            private _softAOtimeAir = GETVAR(_logic,SoftTimeOutsideAir,120);
            private _loc = getPosATL _logic;
            private _size = _logic getVariable ["objectArea", [100, 100]];
            _size params ["_radiusX","_radiusY"];
            private _direction = getdir _logic;
            private _isRectangle = if ((typeof _logic) isEqualTo QGVAR(AOLimitModule_R)) then {true} else {false};
            private _area = [_loc,_radiusX,_radiusY,_direction,_isRectangle];
            //TRACE_5("",_logic,_AOMode,_selectedSides,_entryMode);

            [_logic,_area,_selectedSides,_entryMode,_airsetting,_AOMode,_softAOtime,_softAOtimeAir] call FUNC(Init);
        };
    };
    case "attributesChanged3DEN": {};
    default {};
};
true
