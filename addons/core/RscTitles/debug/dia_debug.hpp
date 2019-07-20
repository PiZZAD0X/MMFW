class EGVAR(Debug,Display) {
    idd = 400;
    fadeout = 0;
    fadein = 0;
    duration = 360;
    onLoad = QUOTE(\
        uiNamespace setVariable [ARR_2(QN(EGVAR(Debug,DisplayID)),_this select 0)];\
    );
    class controlsBackground {
        class SOME_TEXT:  MGVAR(RscStructuredText) {
            idc = 4001;
            x = 0 * safezoneW + safezoneX;
            y = 0 * safezoneH + safezoneY;
            w = 0.5 * safezoneW;
            h = 1 * safezoneH;
        };
    };
};
