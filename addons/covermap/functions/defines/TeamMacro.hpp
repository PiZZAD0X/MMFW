#define COVERMAPTEAMMACRO(TEAMNAMEVAR) _StartAO = GETMVAR(DOUBLES(DefaultAO,TEAMNAMEVAR),"No Area Selected");\
if (_StartAO isEqualto "") exitwith {\
    ERROR(QUOTE(No Default TEAMNAMEVAR Area defined for CoverMap!));\
};\
if ((GVAR(AOArray) findif {_StartAO == (_x select 0)}) isEqualto -1) exitwith {\
    ERROR_1(QUOTE(Default CoverMap TEAMNAMEVAR area: %1 does not exist!),_StartAO);\
}
