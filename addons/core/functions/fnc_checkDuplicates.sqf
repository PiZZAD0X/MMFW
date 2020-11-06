/*    Description: Checks for duplicate config type entries in all3DENentities and deletes placed entity if duplicate found
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */


#include "script_component.hpp"
EDEN_CHECK;

params ["_logic"];

TRACE_2("", _logic, typeof _logic);
private _index = (all3DENentities select 3) findIf {
    !(_x isEqualto _logic)
    && {_x isEqualType _logic}
};
if !(_index isEqualto -1) then {
    TRACE_2("MATCH DUPLICATE!", typeof _logic, _logic);
    private _printname = getText (configFile >> "cfgVehicles" >> typeof _logic >> "displayName");
    ERROR_1("You can only have one %1 module. Duplicate module deleted.", _printname);
    delete3DENEntities [_logic];
};
