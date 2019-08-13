class GVAR(UnitCategory) {
    displayName = "Gear Options";
    collapsed = 1;
    class Attributes {
        class GVAR(UnitSystemType) {
            displayName = "Gear System Type";
            tooltip = "Set the gear system type for the unit.";
            control = QGVAR(AttributeSystemType);
            typeName = "STRING";
            property = QGVAR(UnitSystemType);
            expression = ENTITY_EXPRESSION;
            condition = "ObjectControllable";
            defaultValue = "'NONE'";
        };
        class GVAR(UnitGearType) {
            displayName = "Gear Type";
            tooltip = "Set the gear type for the unit that sets the class for respawn and other functions. If set to ACE or Olsen gear mode, this corresponds to the types defined in the gear team settings.";
            control = QGVAR(AttributeComboGearLoad);
            GearSystems[] = {"ACEAR","OLSEN"};
            property = QGVAR(UnitGearType);
            typeName = "STRING";
            expression = ENTITY_EXPRESSION;
            condition = "ObjectControllable";
            validate = "none";
            defaultValue = "'NONE'";
        };
        class GVAR(UnitGearManualType) {
            property = QGVAR(UnitGearManualType);
            displayName = "Custom Gear Type";
            GearSystems[] = {"ACEAR"};
            tooltip = "Defines a custom gear class for respawn and other functions.";
            control = QGVAR(ACE_Arsenal_LoadoutClassComboUnit);
            typeName = "STRING";
            expression = ENTITY_EXPRESSION;
            condition = "ObjectControllable";
            defaultValue = "'NONE'";
        };
        class GVAR(UnitGearManualTypeOlsen) {
            property = QGVAR(UnitGearManualTypeOlsen);
            displayName = "Custom Gear Type";
            GearSystems[] = {"OLSEN"};
            tooltip = "Defines a custom gear class for respawn and other functions. If set to ACE gear system, this corresponds to the name of an ACE mission loadout. If set to Olsen gear system, this corresponds to the name of gear type in the team olsen gear script. Leave blank to disable.";
            control = QGVAR(AttributeManualGearEditShort);
            typeName = "STRING";
            expression = ENTITY_EXPRESSION;
            condition = "ObjectControllable";
            defaultValue = "''";
        };
        class GVAR(VehicleSystemType) {
            displayName = "Gear System Type";
            tooltip = "Set the gear system type for the vehicle.";
            control = QGVAR(AttributeSystemTypeVehicle);
            typeName = "STRING";
            property = QGVAR(VehicleSystemType);
            expression = ENTITY_EXPRESSION;
            condition = "objectVehicle";
            validate = "none";
            defaultValue = "'NONE'";
        };
        class GVAR(VehicleGearManualType) {
            property = QGVAR(VehicleGearManualType);
            displayName = "Custom Gear Type";
            GearSystems[] = {"OLSEN"};
            tooltip = "Defines a custom gear class for respawn and other functions. If set to ACE gear system, this corresponds to the name of an ACE mission loadout. If set to Olsen gear system, this corresponds to the name of gear type in the team olsen gear script. Leave blank to disable.";
            control = QGVAR(AttributeManualGearEditShort);
            typeName = "STRING";
            expression = ENTITY_EXPRESSION;
            condition = "objectVehicle";
            defaultValue = "''";
        };
    };
};
