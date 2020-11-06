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

private _text = "<br></br><br></br>";

GVAR(DebugMessages) apply {
    _text = _text + _x + "<br></br>";
};

((uiNamespace getVariable QGVAR(DisplayID)) displayCtrl 4001) ctrlSetStructuredText (parsetext _text);
