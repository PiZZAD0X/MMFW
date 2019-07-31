#define SCENARIO_EXPRESSION QUOTE(missionNamespace setVariable [ARR_2('%s',_value)];)

#define ENTITY_EXPRESSION QUOTE(private _propertyName = '%s'; _this setVariable [ARR_2(_propertyName,_value)];)

#define OBJECT_FNC_EXPRESSION(var1,var2) QUOTE(\
private _propertyname = '%s';\
_this setVariable [ARR_2(_propertyName,_value)];\
[ARR_2(_this,_value)] call EFUNC(var1,var2);\
)

#define MODULE_EXPRESSION QUOTE(private _propertyName = '%s'; [ARR_3(_this,_propertyName,_value)] call EFUNC(core,ModuleExpression);)
