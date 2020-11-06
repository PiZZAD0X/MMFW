#include "script_component.hpp"
EXEC_CHECK(CLIENT);

params ["_AONameCalled"];

private _index = GVAR(AOArray) findIf {_x select 0 == _AONameCalled};
if (_index isEqualTo -1) exitwith {
    ERROR_1("Live CoverMap area: %1 not found in array!",_AONameCalled);
};
GVAR(AOArray) select _index params ["_AOName", "_area", "_AOZoom", "_logic"];

if (isNil QGVAR(MarkerArray)) then {
    GVAR(MarkerArray) = [];
} else {
    GVAR(MarkerArray) apply {deletemarker _x};
    GVAR(MarkerArray) = [];
};
//for self interact options and logging
GVAR(currentAO) = _AOName;

_area params ["_pos","_radiusX","_radiusY","_dir"];

_pos params ["_posx","_posy"];
private _radiusXo = _radiusX;
private _radiusYo = _radiusY;
private _MainS = 20000;
private _MainBS = 50;

if ((_dir > 0 && {_dir <= 90}) || (_dir > 180 && {_dir <= 270})) then {
    private _temp = _radiusX;
    _radiusX = _radiusY;
    _radiusY = _temp;
};

private _colorForest = "colorKhaki";
private _colors = ["colorBlack","colorBlack",_colorForest,"colorGreen",_colorForest,/**/"colorBlack"/**/,_colorForest,_colorForest];

{
    _x params ["_dir"];
    private _i = _forEachIndex;

    _dir = _dir mod 360;
    if (_dir < 0) then {_dir = _dir + 360};

    private _s = _radiusX;
    private _w = 2 * _MainS +_radiusY;
    private _bw = _radiusY + _MainBS;
    if !((_dir > 0 && {_dir <= 90}) || (_dir > 180 && {_dir <= 270})) then {
        _s = _radiusY;
        _w = _radiusX + 2 * _MainBS;
        _bw = _radiusX + _MainBS;
    };
    private _posos_x = _posx + (sin _dir) * (_MainS + _s + _MainBS);
    private _posos_y = _posy + (cos _dir) * (_MainS + _s + _MainBS);

    {
        _x params ["_color"];

        private _markername1 = format ["##PREFIX##_CoverMap_Marker_C_%1_%2",_i,_forEachIndex];
        private _marker1 = createMarkerLocal [_markername1,[_posos_x, _posos_y]];
        GVAR(MarkerArray) pushBack _marker1;

        _marker1 setMarkerSizeLocal [_w,_MainS];
        _marker1 setMarkerDirLocal _dir;
        _marker1 setMarkerShapeLocal "rectangle";
        _marker1 setMarkerBrushLocal "solid";
        _marker1 setMarkerColorLocal _color;

        if (_forEachIndex isEqualto 5) then {
            _marker1 setMarkerBrushLocal "grid";
        };

    } forEach _colors;

    private _posos_x = _posx + (sin _dir) * (_MainBS / 2 + _s);
    private _posos_y = _posy + (cos _dir) * (_MainBS / 2 + _s);

    for "_m" from 0 to 7 do {
        private _markername2 = format ["##PREFIX##_CoverMap_Marker_W_%1_%2",_i,_m];
        private _marker2 = createMarkerLocal [_markername2,[_posos_x, _posos_y]];
        GVAR(MarkerArray) pushBack _marker2;

        _marker2 setMarkerSizeLocal [_bw, _MainBS / 2];
        _marker2 setMarkerDirLocal _dir;
        _marker2 setMarkerShapeLocal "rectangle";
        _marker2 setMarkerBrushLocal "solid";
        _marker2 setMarkerColorLocal "colorwhite";

    };

} forEach [_dir, (_dir + 90), (_dir + 180), (_dir + 270)];

private _markername3 = format ["##PREFIX##_CoverMap_Marker_b1_%1",_index];
private _marker3 = createMarkerLocal [_markername3,[_posx, _posy]];
GVAR(MarkerArray) pushBack _marker3;

_marker3 setMarkerSizeLocal [_radiusXo, _radiusYo];
_marker3 setMarkerDirLocal _dir;
_marker3 setMarkerShapeLocal "rectangle";
_marker3 setMarkerBrushLocal "border";
_marker3 setMarkerColorLocal "colorBlack";

private _markername4 = format ["##PREFIX##_CoverMap_Marker_b2_%1",_index];
private _marker4 = createMarkerLocal [_markername4,[_posx, _posy]];
GVAR(MarkerArray) pushBack _marker4;

_marker4 setMarkerSizeLocal [_radiusXo+_MainBS, _radiusYo+_MainBS];
_marker4 setMarkerDirLocal _dir;
_marker4 setMarkerShapeLocal "rectangle";
_marker4 setMarkerBrushLocal "border";
_marker4 setMarkerColorLocal "colorBlack";

[{(visibleMap)},{
    params ["_zoomlevel","_p"];
    MapAnimAdd [0, _zoomlevel, _p];
    MapAnimCommit;
},[_AOZoom,_pos]] call CBA_fnc_waitUntilAndExecute;
