#include "script_component.hpp"
EXEC_CHECK(CLIENT);

[QEGVAR(Core,SettingsLoaded), {
    [{!isNull ace_player}, {
        private _briefing = [];
        switch (side player) do {
            case west: {
                BRIEFINGTEAMEXEC(Blufor);
            };
            case east: {
                BRIEFINGTEAMEXEC(Opfor);
            };
            case independent: {
                BRIEFINGTEAMEXEC(Indfor);
            };
            case civilian: {
                BRIEFINGTEAMEXEC(Civilian);
            };
        };
        if (GETMVAR(MissionNotes_Enable,false)) then {
            private _notesStr = "";
             private _notesAuthor = GETMVAR(MissionNotes_Author,"");
            if !(_notesAuthor isEqualTo "") then {
                _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Author:</h1></font color><br/>" + _notesAuthor + "<br/><br/>";
            };
            private _notesTesters = GETMVAR(MissionNotes_Testers,"");
            if !(_notesTesters isEqualTo "") then {
                _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Testers:</h1></font color><br/>" + _notesTesters + "<br/><br/>";
            };
            private _notesConditions = GETMVAR(MissionNotes_Conditions,"");
            if !(_notesConditions isEqualTo "") then {
                _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>End Conditions:</h1></font color><br/>" + _notesConditions + "<br/><br/>";
            };
            private _notesCustom = GETMVAR(MissionNotes_Custom,"");
            if !(_notesCustom isEqualTo "") then {
                _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Mission Specific Notes:</h1></font color><br/>" + _notesCustom + "<br/><br/>";
            };
            private _notesChange = GETMVAR(MissionNotes_Changelog,"");
            if !(_notesChange isEqualTo "") then {
                _notesStr = _notesStr + "<font color='#5BD527' size='14.0'><h1>Mission Changelog:</h1></font color><br/>" + _notesChange;
            };
            if !(_notesStr isEqualTo "") then {
                NEWTAB("Mission Notes:"),
                    _notesStr
                ENDTAB;
            };
            private _gamemastermsg = "<font color='#5BD527' size='14.0'><h1>Game Mastering:</h1></font color><br/>";
            if (GETMVAR(MissionNotes_GM,false)) then {
                _gamemastermsg = _gamemastermsg + "This mission is designed for game mastering and can be manipulated as per Mission Notes";
            } else {
                _gamemastermsg = _gamemastermsg + "This mission is not designed for game mastering and should only be manipulated for technical, administrative or diagnostic purposes.";
            };
            NEWTAB("Game Mastering"),
                _gamemastermsg
            ENDTAB;
        };
        DISPLAYBRIEFING();
    }] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;
