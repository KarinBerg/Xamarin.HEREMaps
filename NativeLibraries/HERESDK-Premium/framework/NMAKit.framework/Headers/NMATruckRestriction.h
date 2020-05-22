/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * Represents truck restriction type.
 */
typedef NS_ENUM(NSUInteger, NMATruckRestrictionType) {

    /**
     * General truck restriction.
     */
    NMATruckRestrictionTypeTruckRestriction = 0,

    /**
     * Weight restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeWeightRestriction = 1,

    /**
     * Height restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeHeightRestriction = 2,

    /**
     * Length restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeLengthRestriction = 3,

    /**
     * Width restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeWidthRestriction = 4,

    /**
     * Weight per axle restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeWeightPerAxelRestriction = 5,

    /**
     * Kingpin-to-rear-axle restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeKpraLengthRestriction = 6,

    /**
     * Preferred route restriction.
     */
    NMATruckRestrictionTypePreferredRoute = 7,

    /**
     * Hazardous materials permit restriction.
     */
    NMATruckRestrictionTypeHazMatPermitRequired = 8,

    /**
     * Speed limit restriction.
     *
     * See also `getValue`
     */
    NMATruckRestrictionTypeSpeedLimit = 9,

    /**
     * Toll restriction.
     */
    NMATruckRestrictionTypeToll = 10,

    /**
     * Unknown restriction.
     */
    NMATruckRestrictionTypeUnknown = 11
};

/**
 * Represents truck hazardous material type.
 */
typedef NS_ENUM(NSUInteger, NMATruckRestrictionHazMat) {
    /**
     * None.
     */
    NMATruckRestrictionHazMatNone = 0,

    /**
     * Explosives.
     */
    NMATruckRestrictionHazMatExplosives = 1,
    /**
     * Gas.
     */
    NMATruckRestrictionHazMatGas = 2,

    /**
     * Flammable.
     */
    NMATruckRestrictionHazMatFlammable = 3,

    /**
     * Flammable solid/combustible.
     */
    NMATruckRestrictionHazMatFlammableSolidCombustible = 4,

    /**
     * Organic.
     */
    NMATruckRestrictionHazMatOrganic = 5,

    /**
     * Poison.
     */
    NMATruckRestrictionHazMatPoison = 6,

    /**
     * Radioactive.
     */
    NMATruckRestrictionHazMatRadioactive = 7,

    /**
     * Corrosive.
     */
    NMATruckRestrictionHazMatCorrosive = 8,

    /**
     * Other.
     */
    NMATruckRestrictionHazMatOther = 9,

    /**
     * Any hazardous material.
     */
    NMATruckRestrictionHazMatAny = 10,

    /**
     * Pih.
     */
    NMATruckRestrictionHazMatPih = 11,

    /**
     * Harmful for water.
     */
    NMATruckRestrictionHazMatHarmfulForWater = 12,

    /**
     * Explosive flammable.
     */
    NMATruckRestrictionHazMatExplosiveFlammable = 13,

    /**
     * Tunnel category B.
     */
    NMATruckRestrictionHazMatTunnelCategoryB = 14,

    /**
     * Tunnel category C.
     */
    NMATruckRestrictionHazMatTunnelCategoryC = 15,

    /**
     * Tunnel category D.
     */
    NMATruckRestrictionHazMatTunnelCategoryD = 16,

    /**
     * Tunnel category E.
     */
    NMATruckRestrictionHazMatTunnelCategoryE = 17,

    /**
     * Unknown.
     */
    NMATruckRestrictionHazMatUnknown = 18
};

/**
 * Represents weather condition restriction.
 */
typedef NS_ENUM(NSUInteger, NMATruckRestrictionWeatherType) {

    /**
     * None.
     */
    NMATruckRestrictionWeatherTypeNone = 0,

    /**
     * Rain.
     */
    NMATruckRestrictionWeatherTypeRain = 1,

    /**
     * Snow.
     */
    NMATruckRestrictionWeatherTypeSnow = 2,

    /**
     * Fog.
     */
    NMATruckRestrictionWeatherTypeFog = 3,

    /**
     * Unknown.
     */
    NMATruckRestrictionWeatherTypeUnknown = 4
};

/**
 * Represents restriction on a link or lane related to trucks with a specified number of
 * trailers.
 */
typedef NS_ENUM(NSUInteger, NMATruckRestrictionTrailerType) {
    /** None. */
    NMATruckRestrictionTrailerTypeNone = 0,
    /** Truck with one or more trailers. */
    NMATruckRestrictionTrailerTypeValue1 = 1,
    /** Truck with two or more trailers. */
    NMATruckRestrictionTrailerTypeValue2 = 2,
    /** Truck with three or more trailers. */
    NMATruckRestrictionTrailerTypeValue3 = 3,
    /** Semi or tractor with 1 or more trailers. */
    NMATruckRestrictionTrailerTypeValue4 = 4,
    /**  Unknown. */
    NMATruckRestrictionTrailerTypeUnknown = 5
};


/**
 * Gives information about the truck restriction, e.g. its type, restriction value etc.
 */
@interface NMATruckRestriction : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets truck restrictoin type.
 */
@property (nonatomic, readonly) NMATruckRestrictionType truckRestrictionType;

/**
 * Gets truck hazardous materials restriction. Use `hasHazMatRestriction`
 * to check if there is any restriction of this type.
 */
@property (nonatomic, readonly) NMATruckRestrictionHazMat truckHazMatType;

/**
 * Gets truck trailer type restriction. Use `hasTrailerRestriction` to check if there is any
 * restriction of this type.
 */
@property (nonatomic, readonly) NMATruckRestrictionTrailerType truckTrailerType;

/**
 * Gets truck weather type restriction. Use `hasWeatherRestriction` to check if there is any
 * restriction of this type.
 */
@property (nonatomic, readonly) NMATruckRestrictionWeatherType truckWeatherType;

/**
 * Gets the value of `truckRestrictionType`. Use `hasValue` to check whether current
 * type has any value associated with it.
 * Value for each `truckRestrictionType` represents certain thing:
 * `NMATruckRestrictionTypeWeightRestriction` - maximum weight for truck in kg.
 * `NMATruckRestrictionTypeHeightRestriction` - maximum height for truck in cm.
 * `NMATruckRestrictionTypeLengthRestriction` - maximum length for truck in cm.
 * `NMATruckRestrictionTypeWidthRestriction` - maximum width for truck in cm.
 * `NMATruckRestrictionTypeWeightPerAxelRestriction` - maximum kg per axel.
 * `NMATruckRestrictionTypeKpraLengthRestriction` - kingpin to rear axle limit in cm.
 * `NMATruckRestrictionTypeSpeedLimit` - maximum speed in meters per second.
 *
 * Types below does not have any values associated with it:
 * `NMATruckRestrictionTypeTruckRestriction`
 * `NMATruckRestrictionTypeToll`
 * `NMATruckRestrictionTypePreferredRoute`
 * `NMATruckRestrictionTypeHazMatPermitRequired`
 */
@property (nonatomic, readonly) NSUInteger value;

/**
 * Checks whether `truckRestrictionType` has any value associated with it. Types such as
 * `NMATruckRestrictionTypeTruckRestriction`, `NMATruckRestrictionTypeToll`,
 * `NMATruckRestrictionTypePreferredRoute` or `NMATruckRestrictionTypeHazMatPermitRequired` do not
 * have value. All the other types should have value.
 */
-(BOOL)hasValue;

/**
 * Checks whether this truck restriction has additional hazardous materials restriction.
 * Use `truckHazMatType` to get type of hazmat restriction.
 */
-(BOOL)hasHazMatRestriction;

/**
 * Checks whether this truck restriction has additional trailer restriction.
 * Use `truckTrailerType` to get type of truck trailer restriction.
 */
-(BOOL)hasTrailerRestriction;

/**
 * Checks whether this truck restriction has additional weather restriction.
 * Use `truckWeatherType` to get type of truck weather restriction.
 */
-(BOOL)hasWeatherRestriction;

@end
