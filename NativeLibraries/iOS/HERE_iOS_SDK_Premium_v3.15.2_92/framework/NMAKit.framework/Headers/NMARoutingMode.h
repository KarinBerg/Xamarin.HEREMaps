/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * Defines the value used to indicate routing may start in any direction
 */
FOUNDATION_EXPORT const float NMARoutingModeStartDirectionAny;

/**
 * Represents values describing different routing types.
 *
 * @note a NMARoutingType has no effect on
 * NMATransportModePedestrian, NMATransportModePublicTransport, NMATransportModeTruck
 * or NMATransportModeScooter transport modes, since they always use NMARoutingTypeFastest
 * (if NMARoutingTypeShortest is set as the NMARoutingType when one of these
 * `NMATransportMode` types is selected, it will
 * be reset to NMARoutingTypeFastest when a route is calculated).
 */
typedef NS_ENUM(NSUInteger, NMARoutingType) {
    /**
     * Search for the shortest route, taking road conditions and restrictions into account (minimizes travel distance).
     * Car mode only.
     *
     * @note In some cases, the route returned by the fastest mode
     * may not be the route with the shortest possible travel time. For example,
     * it may favor a route that remains on a highway, even if a shorter travel time
     * can be achieved by taking a detour or shortcut through a side road.
     */
    NMARoutingTypeShortest = 0,
    /**
     * Search for the fastest route, taking road conditions and restrictions into account (minimizes travel time).
     *
     * @note In this mode, the distance of the route
     * is minimized, while keeping the route sensible. This includes, for example,
     * penalizing turns. Because of that, the resulting route will not necessarily be
     * the one with minimal distance.
     */
    NMARoutingTypeFastest = 1,
    /** Search for balanced route, some travel time may be sacrificed in order to reduce the distance traveled. It calculates the optimal route based on time and distance combination. Car mode only. */
    NMARoutingTypeBalanced = 3
};

/**
 * Represents values describing different transport modes, the mode of
 * transportation a person will be using to travel a route (e.g. a car).
 */
typedef NS_ENUM(NSUInteger, NMATransportMode) {
    /** A car is being used as the mode of transportation. */
    NMATransportModeCar = 0,
    /**
     * Walking is being used as the mode of transportation.
     *
     *  @note When calculating a route using NMATransportModePedestrian,
     *  NMARoutingType will be reset to NMARoutingTypeFastest.
     *
     *  See also `NMARoutingTypeFastest`
     */
    NMATransportModePedestrian = 1,
    /**
     * Public transport is being used as the mode of transportation.
     *
     *  @note When calculating a route using NMATransportModePublicTransport,
     *  NMARoutingType will be reset to NMARoutingTypeFastest.
     *
     *  See also `NMARoutingTypeFastest`
     */
    NMATransportModePublicTransport = 2,
    /**
     * A truck is being used as the mode of transportation.
     *
     *  @note When calculating a route using NMATransportModeTruck,
     *  NMARoutingType will be reset to NMARoutingTypeFastest.
     *
     *  See also `NMARoutingTypeFastest`
     */
    NMATransportModeTruck = 5,
    /** Urban Mobility includes ways to get around the city: transit, taxi, shared car/bikes. */
    NMATransportModeUrbanMobility = 6,
    /**
     * A bike is being used as the mode of transportation.
     *
     * IMPORTANT: This is a Beta API, and is subject to change without notice
     */
    NMATransportModeBike = 7,
    /**
     * A scooter is being used as the mode of transportation.
     *
     *  When calculating a route using NMATransportModeScooter,
     *  NMARoutingType will be reset to NMARoutingTypeFastest.
     */
    NMATransportModeScooter = 8
};

/**
 * Represents values describing routing options that can be used to enforce
 * special conditions on a calculated route.
 */
typedef NS_OPTIONS(NSUInteger, NMARoutingOption) {
    /**
     * The routing engine will avoid links that are part of a boat ferry passage.
     */
    NMARoutingOptionAvoidBoatFerry          = 1 << 0,

    /**
     * The routing engine will avoid links that are part of a dirt road.
     */
    NMARoutingOptionAvoidDirtRoad           = 1 << 1,

    /**
     * The routing engine will avoid links that are part of a highway.
     *
     * @note Effective only when used with ::NMATransportModeCar. Is ignored with ::NMATransportModeScooter
     */
    NMARoutingOptionAvoidHighway            = 1 << 2,

    /**
     * The routing engine will avoid links that go through a park.
     *
     * @note Effective only when used with ::NMATransportModePedestrian.
     */
    NMARoutingOptionAvoidPark               = 1 << 3,

    /**
     * The routing engine will avoid links that are part of a toll road.
     *
     * @note Effective only when used with ::NMATransportModeCar.
     */
    NMARoutingOptionAvoidTollRoad           = 1 << 4,

    /**
     * The routing engine will avoid links that are part of a tunnel.
     *
     * @note Effective only when used with ::NMATransportModeCar.
     */
    NMARoutingOptionAvoidTunnel             = 1 << 5,

    /**
     * The routing engine will avoid links that are part of a motorail train or car shuttle train passage.
     */
    NMARoutingOptionAvoidCarShuttleTrain    = 1 << 6,

    /**
     * The routing engine will avoid HOV/Carpool roads.
     */
    NMARoutingOptionAvoidCarpool            = 1 << 7
};

/**
 * Route calculation vehicle speed profile.
 */
typedef NS_ENUM(NSUInteger, NMASpeedProfile) {
    /**
     * Remains route calculation unchanged.
     */
    NMASpeedProfileDefault = 0,

    /**
     * Intended to use in case of `NMARouteTta::duration` overestimation.
     */
    NMASpeedProfileFast
};


/**
 *
 * Represents a model of the parameters required for one route
 * calculation, encapsulating parameters such as:
 *
 * - The `NMARoutingType`
 * - The `NMATransportMode`
 * - The `NMARoutingOption` (specify 0 for none)
 */
@interface NMARoutingMode : NSObject

/**
 * Initializes a `NMARoutingMode` instance with default values.
 */
- (nonnull instancetype)init;

/**
 * Initializes a `NMARoutingMode` instance with the specified routing
 * parameters.
 *
 * @param routingType - A routing type (see `NMARoutingType`)
 * @param transportMode - A transport mode (see `NMATransportMode`)
 * @param routingOptions - An OR-ed combination of routing options (see `NMARoutingOption`).
 * @return The `NMARoutingMode` object, or nil if initialization failed
 */
- (nonnull instancetype)initWithRoutingType:(NMARoutingType)routingType transportMode:(NMATransportMode)transportMode routingOptions:(NMARoutingOption)routingOptions;

/**
 * The `NMARoutingType` for the `NMARoutingMode`.
 *
 * @note The default value is NMARoutingTypeShortest.
 */
@property (nonatomic) NMARoutingType routingType;

/**
 * The `NMATransportMode` for the `NMARoutingMode`.
 *
 * @note The default value is NMATransportModeCar.
 */
@property (nonatomic) NMATransportMode transportMode;

/**
 * Alternate route calculation speed profile.
 *
 * @note Сurrently supported only in `NMATransportModeTruck`. Route calculation may fail if used
 * in other modes.
 */
@property (nonatomic) NMASpeedProfile speedProfile;

/**
 * The OR-ed `NMARoutingOption` values for the `NMARoutingMode`.
 *
 * @note The default value is 0 (no options selected).
 */
@property (nonatomic) NMARoutingOption routingOptions;

/**
 * The desired departure time.
 */
@property (nonatomic, strong, nullable) NSDate *departureTime;

/**
 * The maximum number of alternative routes to calculate. The actual
 * number calculated may be less. The default value is 1.
 *
 * @note Only one result will be returned for routes with more than two waypoints.
 */
@property (nonatomic) NSUInteger resultLimit;

/**
 * The direction, in degrees, that routing should start in. Use values in range 0..359. If a value
 * greater than 359 is specified, the modulus of 360 is used. Values will be rounded to the nearest
 * integral value.
 *
 * Defaults to NMARoutingModeStartDirectionAny which means route in any direction in order to obtain
 * the shortest/fastest possible route.
 *
 * @note To route in the current direction of travel set this property to
 * [NMAPositioningManager sharedPositioningManager].currentPosition.course
 */
@property (nonatomic) float startDirection;

/**
 * The deviation distance in meters to pedestrian reroute. Default distance is 50 m.
 * It is only used as a trigger for guidance re-routing. It is not used by route calculation itself.
 * Attempting to set this property to 0 will be ignored.
 */
@property (nonatomic) NSUInteger deviationDistanceToPedestrianReroute;

/**
 * Prevents route from using specified routing zones. All other routing zones will be used if
 * necessary.
 *
 * @note Use `NMARoute.routingZones` to get routing zones used in the route.
 *
 * @note Use `NMARoutingZone.identifier` to get zone identifier.
 */
@property (nonatomic, nonnull) NSArray <NSString *> *excludeRoutingZones;

/**
 * Prevents creating a route through specified countries.
 *
 * @note Country code must be in ISO 3166-1 alpha-3 format otherwise routing might fail.
 * The exclusion of the countries from the route is supported only for
 * `NMATransportModeCar` and `NMATransportModeTruck` transport modes.
 *
 * @note IMPORTANT: this is a BETA feature, and is subject to change without notice.
*/
@property (nonatomic, nonnull, copy) NSArray <NSString *> *excludedCountries;

/**
 * The last character of the vehicle's license plate.
 *
 * Enables route computation with respect to restrictions based on last digit rule on license plate
 * number.
 *
 * @note Restrictions are supported only for `NMATransportModeCar`, `NMATransportModeTruck`
 * and `NMATransportModeScooter` transport modes.
 */
@property (nonatomic, nullable) NSString *licensePlateLastCharacter;

/**
 * NSString representing the preferred language for request responses.
 *
 * Default Value: [[NSLocale preferredLanguages] objectAtIndex:0].
 *
 * @note languagePreference should be a valid code according to the IETF BCP-47 standard
 * (see http://tools.ietf.org/html/bcp47 ).
 */
@property (nullable, nonatomic) NSString *languagePreference;


@end
