class GVAR(endScreen) {
    idd = 300;
    fadeout = 0;
    fadein = 0;
    duration = 30;
    onLoad = QUOTE(\
        uiNamespace setVariable [ARR_2(QN(GVAR(EndScreenDisplay)),_this select 0)];\
    );
    controlsBackground[] = {BACKGROUND};
    objects[] = {};
    controls[] = {TEXT_Title, TEXT_LEFT, TEXT_RIGHT, TEXT_BOTTOM_LEFT,TEXT_BOTTOM_MIDDLE_LEFT, TEXT_BOTTOM_MIDDLE_RIGHT, TEXT_BOTTOM_RIGHT};

    class BACKGROUND: GVAR(RscBackground) {
        idc = 3000;
        x = -1;
        y = -1;
        w = 4;
        h = 4;
    };
    class TEXT_Title:  GVAR(RscStructuredText) {
        idc = 3001;
        x = 0.2375 * safezoneW + safezoneX;
        y = 0.149922 * safezoneH + safezoneY;
        w = 0.525 * safezoneW;
        h = 0.140031 * safezoneH;
    };
    class TEXT_LEFT:  GVAR(RscStructuredText) {
        idc = 3002;
        x = 0.2375 * safezoneW + safezoneX;
        y = 0.289953 * safezoneH + safezoneY;
        w = 0.2625 * safezoneW;
        h = 0.560125 * safezoneH;
    };
    class TEXT_RIGHT:  GVAR(RscStructuredText) {
        idc = 3003;
        x = 0.5 * safezoneW + safezoneX;
        y = 0.289953 * safezoneH + safezoneY;
        w = 0.2625 * safezoneW;
        h = 0.560125 * safezoneH;
    };
    class TEXT_BOTTOM_LEFT:  GVAR(RscStructuredText) {
        idc = 3004;
        x = 0.1 * safezoneW + safezoneX;
        y = 0.6 * safezoneH + safezoneY;
        w = 0.8 * safezoneW;
        h = 0.5 * safezoneH;
    };
    class TEXT_BOTTOM_MIDDLE_LEFT:  GVAR(RscStructuredText) {
        idc = 3005;
        x = 0.3 * safezoneW + safezoneX;
        y = 0.6 * safezoneH + safezoneY;
        w = 0.8 * safezoneW;
        h = 0.5 * safezoneH;
    };
    class TEXT_BOTTOM_MIDDLE_RIGHT:  GVAR(RscStructuredText) {
        idc = 3006;
        x = 0.5 * safezoneW + safezoneX;
        y = 0.6 * safezoneH + safezoneY;
        w = 0.8 * safezoneW;
        h = 0.5 * safezoneH;
    };
    class TEXT_BOTTOM_RIGHT:  GVAR(RscStructuredText) {
        idc = 3007;
        x = 0.7 * safezoneW + safezoneX;
        y = 0.6 * safezoneH + safezoneY;
        w = 0.8 * safezoneW;
        h = 0.5 * safezoneH;
    };
};
