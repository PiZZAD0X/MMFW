class GVAR(Category) {
    displayName = "Marker Control Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enabled) {
            property = QGVAR(Enabled);
            displayName = "Enable";
            tooltip = "Enables Marker Control";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
            typeName = "BOOL";
        };
        class GVAR(BluforMarkers) {
            displayName = "Blufor Markers";
            tooltip = "Markers which are only visible by Blufor. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(BluforMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(BluforBriefingMarkers) {
            displayName = "Blufor briefing Markers";
            tooltip = "Markers which are only visible by Blufor during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(BluforBriefingMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(OpforMarkers) {
            displayName = "Opfor Markers";
            tooltip = "Markers which are only visible by Opfor. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(OpforMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(OpforBriefingMarkers) {
            displayName = "Opfor briefing Markers";
            tooltip = "Markers which are only visible by Opfor during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(OpforBriefingMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(IndforMarkers) {
            displayName = "Independent Markers";
            tooltip = "Markers which are only visible by Independent. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(IndforMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(IndforBriefingMarkers) {
            displayName = "Independent briefing Markers";
            tooltip = "Markers which are only visible by Independent during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(IndforBriefingMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(CivilianMarkers) {
            displayName = "Civilian Markers";
            tooltip = "Markers which are only visible by Civilian. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(CivilianMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(CivilianBriefingMarkers) {
            displayName = "Civilian briefing Markers";
            tooltip = "Markers which are only visible by Civilian during the briefing. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(CivilianBriefingMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
        class GVAR(SystemMarkers) {
            displayName = "System Markers";
            tooltip = "Markers which are not visible. Marker names or 3DEN layer names without quotes and seperated by ,";
            control = "EditArray";
            typeName = "STRING";
            property = QGVAR(SystemMarkers);
            expression = SCENARIO_EXPRESSION;
            validate = "none";
            defaultValue = "[]";
        };
    };
};
