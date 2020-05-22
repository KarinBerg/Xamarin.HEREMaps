/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"


/**
 * The tunnel categories to avoid in truck routing.
 */
typedef NS_ENUM(NSUInteger, NMATunnelCategory) {
    /**
     * Tunnel category not defined.
     */
    NMATunnelCategoryNone,
    /**
     * Tunnel category B.
     */
    NMATunnelCategoryB NS_SWIFT_NAME(b),
    /**
     * Tunnel category C.
     */
    NMATunnelCategoryC NS_SWIFT_NAME(c),
    /**
     * Tunnel category D.
     */
    NMATunnelCategoryD NS_SWIFT_NAME(d),
    /**
     * Tunnel category E.
     */
    NMATunnelCategoryE NS_SWIFT_NAME(e)
};

/**
 * Hazardous goods types for use with truck routing.
 */
typedef NS_OPTIONS(NSUInteger, NMAHazardousGoodsType) {
    /**
     * Explosive goods.
     */
    NMAHazardousGoodsTypeExplosive              = 1 << 0,
    /**
     * Gas.
     */
    NMAHazardousGoodsTypeGas                    = 1 << 1,
    /**
     * Flammable material.
     */
    NMAHazardousGoodsTypeFlammable              = 1 << 2,
    /**
     * Combustible material.
     */
    NMAHazardousGoodsTypeCombustible            = 1 << 3,
    /**
     * Organic material.
     */
    NMAHazardousGoodsTypeOrganic                = 1 << 4,
    /**
     * Poison.
     */
    NMAHazardousGoodsTypePoison                 = 1 << 5,
    /**
     * Radio-active material.
     */
    NMAHazardousGoodsTypeRadioActive            = 1 << 6,
    /**
     * Corrosive material.
     */
    NMAHazardousGoodsTypeCorrosive              = 1 << 7,
    /**
     * Goods which are poisonous upon inhalation.
     */
    NMAHazardousGoodsTypePoisonousInhalation    = 1 << 8,
    /**
     * Goods which are harmful to water.
     */
    NMAHazardousGoodsTypeHarmfulToWater         = 1 << 9,
    /**
     * Other types of hazardous goods.
     */
    NMAHazardousGoodsTypeOther                  = 1 << 10
};

/**
 * The truck type of the routed truck.
 */
typedef NS_ENUM(NSUInteger, NMATruckType) {
    /**
     * Truck type not defined.
     */
    NMATruckTypeNone,
    /**
     * Regular truck type.
     */
    NMATruckTypeTruck,
    /**
     * Tractor truck type.
     *
     * @note Relevant for restrictions that apply exclusively to tractors with semi-trailers
     * (observed in North America). Such restrictions are taken into account only in case of
     * the trailers count greater than 0 (for example &truckType=tractorTruck&trailersCount=1).
     * The truck type is irrelevant in case of restrictions common for all types of trucks.
     */
    NMATruckTypeTractorTruck
};

/**
 * Defines way of handling road segments on which violated static truck restriction
 * applies.
 *
 * When mode is set to NMATruckRestrictionsNoViolations then such segments will not be part of the route.
 *
 * NMATruckRestrictionsPenalizeViolations is relaxed way of handling restrictions. Streets where truck restrictions
 * are violated will be avoided, but if there is no way around route will go through restricted
 * streets.
 *
 * WARNING: Route calculated with this option cannot be used for navigation.
 *
 * Typical use case is route calculation with imprecise start/destination for planning purpose
 * when user wants to know some statistics data like estimated length, countries crossed. With
 * this option route will be calculated even if it starts/ends in restricted areas.
 *
 * When no mode is explicitly set NMATruckRestrictionsNoViolations mode is used for route calculation.
 *
 * @note This option does not affect time dependent truck restrictions.
 */
typedef NS_ENUM(NSUInteger, NMATruckRestrictionsMode) {
    /**
     * In those mode violating road segments will not be part of the route.
     */
    NMATruckRestrictionsModeNoViolations,
    /**
     * In those mode violating road segments can be part of the route, if no other route can be calculated.
     */
    NMATruckRestrictionsModePenalizeViolations
};

/**
 * Contains options used when calculating a truck route.
 */
@interface NMARoutingMode (NMATruckRoutingMode)

/**
 * The tunnel category to which the truck route should be restricted.
 *
 * @note The default value is NMATunnelCategoryNone.
 *
 * @note Truck routing only.
 */
@property (nonatomic) NMATunnelCategory tunnelCategory;

/**
 * An OR combination of NMAHazardousGoodsType values that apply
 * to the cargo for the truck route.
 *
 * @note The default value is 0 (no hazardous goods).
 *
 * @note Truck routing only.
 */
@property (nonatomic) NMAHazardousGoodsType hazardousGoods;

/**
 * The limited vehicle weight in metric tons.
 *
 * @note The default value is 0 (no vehicle weight limit).
 *
 * @note Truck routing only.
 */
@property (nonatomic) float limitedVehicleWeight;

/**
 * The vehicle weight per axle in metric tons.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) float weightPerAxle;

/**
 * The vehicle height in meters.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) float vehicleHeight;

/**
 * The vehicle width in meters.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) float vehicleWidth;

/**
 * The vehicle length in meters.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) float vehicleLength;

/**
 * Number of the trailers.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) NSUInteger trailersCount;

/**
 * The routing engine will avoid difficult turns.
 *
 * @note The default value is NO.
 *
 * @note Truck routing only.
 */
@property (nonatomic) BOOL avoidDifficultTurns;

/**
 * Truck type of the routed truck.
 *
 * @note The default value is 0 (unspecified).
 *
 * @note Truck routing only.
 */
@property (nonatomic) NMATruckType truckType;

/**
 * Sets truck restrictions handling mode. If no mode is explicitly set then NMATruckRestrictionsNoViolations
 * option will be used.
 */
@property (nonatomic) NMATruckRestrictionsMode truckRestrictionsMode;

@end
