/*    Description: Checks for duplicate config type entries in all3DENentities and deletes placed entity if duplicate found
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */


#include "script_component.hpp"
EXEC_CHECK(ALL);
EDEN_CHECK;

params ["_logic"];

LOG_2("_logic:%1 class:%2",_logic,typeof _logic);
{
    LOG_2("_logic:%1 class:%2",_x,typeof _x);
    if (!(_logic isEqualto _x)) then {
        if (x isEqualType _logic) exitwith {
            LOG_2("MATCH DUPLICATE! _object class:%1 _logic class:%2",typeof _x,typeof _logic);
            private _printname = getText (configFile >> "cfgVehicles" >> typeof _logic >> "displayName");
            ERROR_1("You can only have one %1 module. Duplicate module deleted.",_printname);
            delete3DENEntities [_logic];
        };
    };
} foreach (all3DENentities select 3);
