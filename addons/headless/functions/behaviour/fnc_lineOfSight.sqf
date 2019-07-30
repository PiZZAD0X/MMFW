/*
 * Author: Soldia
 *
 * Main loop for handling if AI can see a player unit
 *
 * Argument:
 * 0: AI Unit (OBJECT)
 *
 * Return value:
 * None
 *
 * Examples:
 * AIUnit call mmfw_behaviour_fnc_lineOfSight
 *
 * Public: No
 */
#include "script_component.hpp"
EXEC_CHECK(SERVERHC);

params ["_unit"];

// Initially, this is 0
private _updatetime = 0;
private _timesseen = 0;
// Maximal Viewdistance is 1000m default
private _maxviewdistance = 1000;

private _interval = 2;
#ifdef SOL_DEBUG
    _interval = 0;
#endif

[{
    params ["_data", "_pfhID"];
    _data params ["_unit","_updatetime","_maxviewdistance","_timesseen"];
    //TRACE_1("Data",_data);

    // If the unit is dead, remove PFH
    if !(alive _unit) exitWith {
        [_pfhID] call CBA_fnc_removePerFrameHandler;
    };

    // Every 60 seconds, we update the max Viewdistance
    if (time > _updatetime + 60) then {
        private _currentVD = _maxviewdistance;
        TRACE_1("Old VDistance", _currentVD);

        _currentVD = (_currentVD max EGVAR(behaviour,maxDistance));

        // According to the sunOrMoon-Status, we reduce the viewdistance
        if (sunOrMoon < 0.7) then {
            _currentVD = ((EGVAR(behaviour,maxDistance) - 200) min _currentVD);
            if (sunOrMoon < 0.5) then {
                _currentVD = ((EGVAR(behaviour,maxDistance) - 400) min _currentVD);
                if (sunOrMoon < 0.3) then {
                    if (hmd _unit == "") then {
                        _currentVD = ((EGVAR(behaviour,maxDistance) - 600) min _currentVD);
                        if (sunOrMoon < 0.1) then {
                            _currentVD = ((EGVAR(behaviour,maxDistance) - 900) min _currentVD);
                        };
                    };
                };
            };
        };

        // If it is rainy and windy, we reduce the viewdistance as well
        private _bestplaces = selectBestPlaces [_unit, 2, "(rain + windy)", 1, 1];
        if !(_bestplaces isEqualTo []) then {
            if (((_bestplaces select 0) select 1) >= 1) then {
                _currentVD = ((_currentVD / 1.4) min _currentVD);
            };
        };

        // The minimum Viewdistance is 100 meter
        _currentVD = _currentVD max 100;
        _maxviewdistance = _currentVD;
        TRACE_1("New VDistance",_currentVD);

        //Update Time
        _data set [1, time];
        _data set [2, _currentVD];
    };

    #ifdef SOL_DEBUG
        // Display additonal information as 3D Marker
        // Information to display
        // - QEGVAR(behaviour,hasKnowledge)
        // - QEGVAR(behaviour,supporting)
        // - QEGVAR(behaviour,calledSupport)
        private _knowledge = _unit getVariable [QEGVAR(behaviour,hasKnowledge), 0];
        private _supporting = (group _unit) getVariable [QEGVAR(behaviour,supporting), false];
        private _calledSupport = (group _unit) getVariable [QEGVAR(behaviour,calledSupport), false];
        drawIcon3D ["", [1,1,1,1], getPosASL _unit, 0, 0, 0, format ["Knowledge: %1\nSupporting: %2\n Called Support: %3", _knowledge, _supporting, _calledSupport]];
    #endif

    // No need to check if distance is < (minDistance + 5) or >MaxDistance meters
    private _distancePlayerUnit = player distance _unit;
    if (_distancePlayerUnit > _maxviewdistance) exitWith {};
    if (_distancePlayerUnit < 105) exitWith {};

    private _eyePosPlayer = eyePos player;
    private _eyePosUnit = eyePos _unit;
    if ((_unit getVariable [QEGVAR(behaviour,hasKnowledge), 0]) >= 1) exitWith {
        #ifdef SOL_DEBUG
            drawLine3D [ASLtoAGL (_eyePosPlayer vectorAdd [0,0,-0.3]), ASLToAGL _eyePosUnit, [0,0,0,1]];
            TRACE_2("",_unit,_distancePlayerUnit);
        #endif
    };

    // The "detection point" of the player is 30cm below the eyePos
    private _posPlayer = _eyePosPlayer vectorAdd [0, 0, -0.3];

    #ifdef SOL_DEBUG
        private _color = [0,0,0,0];
    #endif

    // If the angle between AI's eyedirection and playerpos is >25, we consider that the AI can't see the player
    if ((acos (([_eyePosPlayer select 0, _eyePosPlayer select 1, 0] vectorDiff [_eyePosUnit select 0, _eyePosUnit select 1, 0]) vectorCos (eyeDirection _unit))) > 25) then {

        // Lost vision? Decrese number but not lower than 0
        DEC(_timesseen);
        _timesseen = _timesseen max 0;

        #ifdef SOL_DEBUG
            _color = [1,0,0,1];
        #endif
    } else {
        // If the player is within the +-25 degree limits
        #ifdef SOL_DEBUG
            _color = [0,0,1,1];
        #endif
        // Check if there is a terrain intersect
        if!(terrainIntersect [ASLtoAGL _posPlayer, ASLToAGL _eyePosUnit]) then {
            //TRACE_1("Only Intersect left!",_unit);
            #ifdef SOL_DEBUG
                _color = [1,1,1,1];
            #endif
            // If no terrain intersect, is there a lineintersect with objects?
            if!(lineIntersects [_posPlayer, _eyePosUnit, vehicle player, _unit]) then {
                private _mintimesseen = 1;
                #ifdef SOL_DEBUG
                    // If Debug is on, we need 100 Frames
                    _mintimesseen = 100;
                #endif
                TRACE_1("Reveal!",_unit);
                // If we got direct LOS, reveal that specific player to the AI unit
                //_unit reveal [player,2];
                ["reveal", [_unit, player, 2]] call CBA_fnc_globalEvent;

                INC(_timesseen);

                if (_timesseen > _mintimesseen) then {
                    TRACE_1("Reveal side!",_unit);
                    //_unit reveal [player,4];
                    ["reveal", [_unit, player, 4]] call CBA_fnc_globalEvent;
                    _timesseen = 0;
                };

                #ifdef SOL_DEBUG
                    _color = [0,1,0,1];
                #endif
            };
        };
    };

    // Set the current number how often the AI has seen the player to PFH
    _data set [3, _timesseen];

    #ifdef SOL_DEBUG
        drawLine3D [ASLtoAGL _posPlayer, ASLToAGL _eyePosUnit, _color];
    #endif
}, _interval, [_unit, _updatetime, _maxviewdistance, _timesseen]] call cba_fnc_addPerFrameHandler;
