class cfgMagazines {
    class ACE_HandFlare_Base;
    class GVAR(ParaFlare_White): ACE_HandFlare_Base {
        displayname = "White Para Flare";
        displayNameShort = "White Para Flare";
        model = "\A3\weapons_f\ammo\flare_white";
        picture = "\A3\Weapons_F\Data\UI\gear_flare_white_ca.paa";
        ammo = QGVAR(ParaFlare_Shot_White);
        mass = 2;
    };
    class GVAR(ParaFlare_Green): GVAR(ParaFlare_White) {
        displayname = "Green Para Flare";
        displayNameShort = "Green Para Flare";
        model = "\A3\weapons_f\ammo\flare_green";
        picture = "\A3\Weapons_F\Data\UI\gear_flare_green_ca.paa";
        ammo = QGVAR(ParaFlare_Shot_Green);
    };
    class GVAR(ParaFlare_Red): GVAR(ParaFlare_White) {
        displayname = "Red Para Flare";
        displayNameShort = "Red Para Flare";
        model = "\A3\weapons_f\ammo\flare_red";
        picture = "\A3\Weapons_F\Data\UI\gear_flare_red_ca.paa";
        ammo = QGVAR(ParaFlare_Shot_Red);
    };
    class GVAR(ParaFlare_Yellow): GVAR(ParaFlare_White) {
        displayname = "Yellow Para Flare";
        displayNameShort = "Yellow Para Flare";
        model = "\A3\weapons_f\ammo\flare_yellow";
        picture = "\A3\Weapons_F\Data\UI\gear_flare_yellow_ca.paa";
        ammo = QGVAR(ParaFlare_Shot_Yellow);
    };
};
