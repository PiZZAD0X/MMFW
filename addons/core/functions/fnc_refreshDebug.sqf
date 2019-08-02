/*
 * Author: PiZZADOX
 *
 * Refreshes text in debug display
 *
 * Arguments:
 * N/A
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */


 #include "script_component.hpp"
 EXEC_CHECK(ALL);

private _text = "<br></br><br></br>";

{
    _text = _text + _x + "<br></br>";
} forEach GVAR(DebugMessages);

((uiNamespace getVariable QGVAR(DisplayID)) displayCtrl 4001) ctrlSetStructuredText (parsetext _text);
