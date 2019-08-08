
#include "script_component.hpp"
EDEN_CHECK;

LOG("GearComboLoadAttribute_onMouseClick started");

private _ctrlButton = _this select 0;
private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlCombo = _ctrlGroup controlsgroupctrl 100;
private _unit = ((get3denselected "object") select 0);
private _GearSystem = GETVAR(_unit,UnitGearType,"NONE");
private _UnitClass = GETVAR(_unit,UnitSystemType,"NONE");
if (!(_GearSystem isEqualto "NONE") || !(_UnitClass isEqualto "NONE")) then {
    [_unit,_GearSystem,_UnitClass] call FUNC(GearTypeLoad3DEN);
};
