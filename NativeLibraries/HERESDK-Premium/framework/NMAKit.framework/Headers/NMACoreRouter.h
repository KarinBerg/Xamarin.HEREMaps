/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARouter.h"
#import "NMARoutingError.h"

@class NMARouteResult;
@class NMARoutingMode;
@class NMADynamicPenalty;
@class NMAGeoCoordinates;

/**
 * The possible types of connectivity for route calculation
 */
typedef NS_ENUM(NSUInteger, NMACoreRouterConnectivity) {
    /**
     * Route is calculated based on the current online status [NMAApplicationContext isOnline], which depends
     * on the current network access and could be forced to offline using [NMAApplicationContext setNetworkAccessAllowed:NO]
     * If the SDK is online, then an online routing will be made.
     * If the SDK is offline, then an offline route calculation is performed.
     */
    NMACoreRouterConnectivityDefault,
    /**
     * Attempts offline routing regardless whether there is enough map
     * data on the device. If there is not enough map data the request might
     * fail. If it fails, it will not try online.
     */
    NMACoreRouterConnectivityOffline,
    /**
     * Attempts online routing regardless whether device is online or
     * whether the HERE SDK is allowed to access network. If the device is
     * offline, the request will fail. If it fails, it will not try offline.
     */
    NMACoreRouterConnectivityOnline
};

/**
 * A completion block used to handle the result of a route request.
 *
 * @param routeResult The result of the routing calculation (can be nil if `NMARoutingError`
 * error param is not `NMARoutingErrorNone`)
 *
 * @param error A routing calculation error.
 * See `NMARoutingError` for possible error codes. If
 * `NMARoutingErrorRouteUseDisabledRoads` is returned then
 * violatedOptions is not empty (the returned NMARoute is valid
 * and can be used for navigation although it uses roads which were
 * disabled in the original NMARoutingMode::routingOptions options).
 */
typedef void(^NMACalculateResultBlock)(NMARouteResult * _Nullable routeResult, NMARoutingError error);


/**
 */

/**
 * Route calculation executor handling core routing types (Car, Truck, Pedestrian, Bike). Defines
 * concrete calculation method and response listener for core routing types.
 *
 * NMACoreRouter requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.
 *
 * Routing within China is supported, but routes may not cross the Chinese border.
 * Thus, any route calculation which begins, ends, or passes through China and involves
 * one or more other countries will fail.
 *
 * @note It is possible for an NMACoreRouter request to return a route that can't be
 * followed; for example, a route that is blocked by a traffic accident or construction
 * work. These conditions will likely be reported if the traffic feature is available
 * and enabled for routing, but they may not be in all cases. Appropriate caution should
 * always be exercised when using routes provided by NMACoreRouter.
 */
@interface NMACoreRouter : NMARouter

/**
 * Default initializer that initializes a `NMACoreRouter` instance with `NMACoreRouterConnectivityDefault`
 * for route calculation.
 *
 * @return The `NMACoreRouter`
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Default initializer that initializes a `NMACoreRouter` instance with `NMACoreRouterConnectivityDefault`
 * for route calculation.
 *
 * @return The `NMACoreRouter`
 */
+ (nonnull instancetype)new;

/**
 * Starts a route calculation with the given stop list and `NMARoutingMode`.
 *
 * This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * The array of stops used to calculate the route must have at least two items. Any of
 * the following may be included in any combination:
 *
 * 1. `NMAGeoCoordinates`
 *
 * 2. `NMAPlace`
 *
 * 3. `NMAPlaceLocation`
 *
 * 4. `NMAWaypoint`
 *
 * @param stops A list of stops to route between. If the first stop or
 * the last stop is of `NMAWaypoint`, their waypointType must be of `NMAStopWaypoint` type.
 * While there is no maximum limit imposed on how many waypoints is allowed for a route,
 * increasing the # of waypoints increases the probability that the route request will fail
 * and a safe upper limit of 128 is recommended.
 *
 * @param mode The `NMARoutingMode` to use for route calculation.
 *
 * @return `NSProgress` if route calculation is successfully started, nil otherwise.
 *
 * @note Note: If the SDK/device becomes offline and you do not have offline permission
 * for the transport mode being requested, this operation will be denied.
 *
 * @note As of 3.2.2, This method returns nil, completes with NMARoutingErrorInvalidParameters,
 * and a route will not be calculated if calculating a route with NMARoutingModeTrack
 * since calculating a route in track mode is no longer supported.
 *
 * @note This method returns nil, completes with NMARoutingErrorInvalidParameters,
 * and a route will not be calculated if calculating a route with
 * NMATransportModePublicTransport that contains more than 2 stops.
 */
- (nullable NSProgress *)calculateRouteWithStops:(nonnull NSArray *)stops
                                     routingMode:(nonnull NMARoutingMode *)mode
                                 completionBlock:(nullable NMACalculateResultBlock)completion
NS_SWIFT_NAME(calculateRoute(withStops:routingMode:_:));

/**
 * Starts a route calculation with the given list of points and `NMARoutingMode`.
 *
 * This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * @param points A list of `NMAGeoCoordinates` that is used to calculate a route.
 * The list must have at least two items.
 *
 * @param mode The `NMARoutingMode` is used for route calculation between points and for route
 * recalculation during navigation mode.
 *
 * @return `NSProgress` if route calculation is successfully started, nil otherwise.
 *
 * @note If the SDK/device becomes offline and you do not have offline permission
 * for the transport mode being requested, this operation will be denied.
 *
 * @note This method returns nil, completes with NMARoutingErrorInvalidParameters,
 * and a route will not be calculated if calculating a route with
 * NMATransportModePublicTransport.
 */
- (nullable NSProgress *)calculateRouteWithPoints:(nonnull NSArray<NMAGeoCoordinates *> *)points
                                      routingMode:(nonnull NMARoutingMode *)mode
                                  completionBlock:(nullable NMACalculateResultBlock)completion
NS_SWIFT_NAME(calculateRoute(withPoints:routingMode:_:));

/**
 * Indicate the dynamic penalty that should be applied to route calculations. Penalties can be
 * applied in the form of restricting roads, areas and setting different traffic modes.
 *
 * @note For the route calculation to consider traffic you must set an `NMADynamicPenalty` that
 * specifies an `NMATrafficPenaltyMode`. Traffic-based routing requires an internet connection.
 */
@property (nonatomic, nullable) NMADynamicPenalty *dynamicPenalty;

/**
 * This determines whether route is calculated online or offline. Default is
 * `NMACoreRouterConnectivityDefault`.
 *
 * If set to offline, it will attempt to calculate the route offline
 * regardless of the routing type and regardless of whether there is
 * enough map data for the route calculation, if fails, it will not
 * make another attempt online.
 *
 * If set to online, it will attempt to calculate the route
 * online regardless of the routing type and regardless of the current
 * device connectivity. If it fails, it will not make another attempt
 * offline.
 *
 * If this is changed after calling calculateRouteWithStops:routingMode:completionBlock,
 * the change will not take effect for the current route calculation.
 *
 * @note An example of the usage is as follows:
 * e.g. An app wishes to try online first and falls back to offline
 * if online fails. Such app will set connectivity to NMACoreRouterConnectivityOnline
 * before calculating a route, if this fails, it will change connectivity
 * to NMACoreRouterConnectivityOffline before another route calculation
 * attempt.
 */
@property (nonatomic) NMACoreRouterConnectivity connectivity;

@end
