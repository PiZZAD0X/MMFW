/*    Description: Compiles global arrays from 3DEN mission property values and default settings
 *    Arguments:
 *         N/A
 *    Return Value:
 *         ARRAY
 *    Author
 *        PiZZADOX
 */

#include "script_component.hpp"

//LOG("setDefaultsCalled");

private _sections = QUOTE(!(((str(configname _x)) find QN(PREFIX)) isEqualto -1)) configClasses (Configfile >> "Cfg3DEN" >> "Mission");
{
    private _section = configName _x;
    //LOG_1("foreach _section: %1",_section);
    private _children = [configfile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories",2,false] call BIS_fnc_returnChildren;
    //LOG_1("_children: %1",_children);
    {
        private _propertyname = getText (_x >> "property");
        //LOG_1("_propertyname: %1",_propertyname);
        if !(_propertyname isEqualTo "") then {
            private _missionvalue = getMissionConfigValue [_propertyname,"NONE"];
            if (_missionvalue isEqualTo "NONE") then {
                if ((missionNamespace getvariable [_propertyname,"NOTSET"]) isEqualto "NOTSET") then {
                    if (isText(_x >> "defaultValue")) then {
                        private _valuetext = getText(_x >> "defaultValue");
                        missionNamespace setvariable [_propertyname, (call compile _valuetext), true];
                        private _value = missionNamespace getvariable [_propertyname,""];
                        //LOG_2("_propertyname: %1 no value in mission, default value %2! set!",str _propertyname,_value);
                    } else {
                        ERROR_1("_propertyname: %1 null default value! not set!",_propertyname);
                    };
                } else {
                    private _value = missionNamespace getvariable [_propertyname,""];
                    //LOG_2("_propertyname: %1 already defined with value of %2! not set!",str _propertyname,_value);
                };
            } else {
                //LOG_1("_propertyname: %1 has mission value!",_propertyname);
                missionNamespace setvariable [_propertyname, _missionvalue];
                //LOG_2("_propertyname: %1 set with value: %2",str _propertyname,_missionvalue);
            };
        } else {
            //LOG_1("_propertyname is null! config: %1!",_x);
        };
    } foreach _children;
} foreach _sections;

SETMVAR(Initialized,true);
[QGVAR(SettingsLoaded), []] call CBA_fnc_localEvent;
