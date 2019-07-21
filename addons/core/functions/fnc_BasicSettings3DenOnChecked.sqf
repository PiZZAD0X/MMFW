/*    Description: Main Framework Init. Declares needed vars, calls core functions
 *    Arguments:
 *         N/A
 *    Return Value:
 *         N/A
 *    Author
 *        Sacher & PiZZADOX
 */


#include "script_component.hpp"
EDEN_CHECK;

LOG("BasicSettings3Den called");

private _ctrlCheckbox = _this select 0;
private _state = cbChecked _ctrlCheckbox;
LOG_2("onCheckedChanged _control: %1 _state: %2",_control,_state);
if (_state) then {
    [] call FUNC(BasicSettings3Den);
};
