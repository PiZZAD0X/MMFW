/*
    Author: Bohemia Interactive, edited by Revo

    Description:
    Saves the values of the combo box when pressing OK. Additionally a 3DEN history is created

    Parameter(s):
    -
    Returns:
    _value
*/


#include "script_component.hpp"
EDEN_CHECK;

params ["_ctrl", "_config"];
private _value = _ctrl lbData lbCurSel _ctrl;
_value
