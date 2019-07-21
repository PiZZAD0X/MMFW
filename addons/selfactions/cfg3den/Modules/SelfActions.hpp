class GVAR(Settings) {
    displayName = "Self Action Settings";
    collapsed = 1;
    class Attributes {
        class GVAR(Enable) {
            property = QGVAR(Enable);
            displayName = "Self Actions Enable";
            tooltip = "Enable Self Actions";
            control = "CheckboxState";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(CheckColour_Enabled) {
            property = QGVAR(CheckColour_Enabled);
            displayName = "Team Colour Action";
            tooltip = "Enable Team Colour Action";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(CheckMap_Enabled) {
            property = QGVAR(CheckMap_Enabled);
            displayName = "View Map Action";
            tooltip = "Enable View Map Action";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(CutGrass_Enabled) {
            property = QGVAR(CutGrass_Enabled);
            displayName = "Cut Grass Action";
            tooltip = "Enable Cut Grass Action";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "true";
        };
        class GVAR(ParaFlares_Enabled) {
            property = QGVAR(ParaFlares_Enabled);
            displayName = "Launch ParaFlare Action";
            tooltip = "Enable Launch ParaFlare Action";
            control = "Checkbox";
            expression = SCENARIO_EXPRESSION;
            defaultValue = "false";
        };
        class GVAR(ParaFlare_Brightness) {
            property = QGVAR(ParaFlare_Brightness);
            displayName = "ParaFlare Brightness";
            tooltip = "Sets the brightness of paraflares";
            control = QMGVAR(15To40Step5_Slider);
            expression = SCENARIO_EXPRESSION;
            defaultValue = "15";
        };
    };
};
