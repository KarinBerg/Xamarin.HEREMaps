/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARouter.h"
#import "NMAUrbanMobility.h"

@class NMAUrbanMobilityRouteResult;
@class NMARoutingMode;
@class NMAUrbanMobilityCalculateResult;
@class NMAWaypoint;


/**
 * The possible types of connectivity for route calculation
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityRouterConnectivity) {
    /**
     * Route is calculated based on the current online status [NMAApplicationContext isOnline], which depends
     * on the current network access and could be forced to offline using [NMAApplicationContext setNetworkAccessAllowed:NO]
     * If the SDK is online, then an online routing will be made.
     * If the SDK is offline, then an offline route calculation is performed.
     */
    NMAUrbanMobilityRouterConnectivityDefault,
    /**
     * Attempts offline routing regardless whether there is enough map
     * data on the device. If there is not enough map data the request might
     * fail. If it fails, it will not try online.
     */
    NMAUrbanMobilityRouterConnectivityOffline,
    /**
     * Attempts online routing regardless whether device is online or
     * whether the HERE SDK is allowed to access network. If the device is
     * offline, the request will fail. If it fails, it will not try offline.
     */
    NMAUrbanMobilityRouterConnectivityOnline
} DEPRECATED_ATTRIBUTE;


/**
 * Represents values for set direction used to looking for earlier/later routes
 * The possible values are F (Forward) and B (Backward).
 *
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMASubsequentRouteType) {
    /** uses F (Forward) value in request */
    NMASubsequentRouteTypeForward = 0,
    /** uses B (Backward) value in request */
    NMASubsequentRouteTypeBackward
} DEPRECATED_ATTRIBUTE;

/**
 * A completion block used to handle the result of an Urban Mobility route request.
 *
 * @param routeResult The result of the Urban Mobility routing calculation (can be nil if `NMARoutingError`
 * error param is not `NMARoutingErrorNone`)
 *
 * @param error A routing calculation error.
 * See `NMARoutingError` for possible error codes. If
 * `NMARoutingErrorRouteUseDisabledRoads` is returned then
 * violatedOptions is not empty (the returned NMARoute is valid
 * and can be used for navigation although it uses roads which were
 * disabled in the original NMARoutingMode::routingOptions options).
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
typedef void (^NMAUrbanMobilityCalculateResultBlock)(NMAUrbanMobilityRouteResult * _Nullable routeResult, NMAUrbanMobilityError error);


/**
 * Urban Mobility-specific route calculation executor. Defines Urban Mobility specific calculation
 * methods and response listener.
 * 
 * Urban Mobility provides Inter-modal and Multi-modal routes including Public Transit.
 * 
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityRouter : NMARouter

/**
 * Initializes an NMAUrbanMobilityRouter instance
 */
- (nonnull instancetype)init;

/**
 * Initializes an NMAUrbanMobilityRouter instance
 */
+ (nonnull instancetype)new;

/**
 * Starts a `NMAUrbanMobilityRoute` calculation with the given stop list.
 *
 * This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * 
 * NMARoutingErrorInvalidParameters is returned if new route is requested while the previous
 * one has not yet been completed.
 *
 * @param stops The array of stops used to calculate the route. Must contain exactly two items
 * of type `NMAWaypoint` otherwise this method returns nil and completes with an error of
 * NMARoutingErrorInvalidParameters.
 *
 * @param mode The `NMARoutingMode` to use for route calculation
 *
 * @return `NSProgress` if route calculation is successfully started, nil otherwise
 */

- (nullable NSProgress *)calculateRouteWithStops:(nonnull NSArray <NMAWaypoint *> *)stops
                                     routingMode:(nonnull NMARoutingMode *)mode
                                 completionBlock:(nonnull NMAUrbanMobilityCalculateResultBlock)completion
NS_SWIFT_NAME(calculateRoute(withStops:routingMode:_:));

/**
 * Starts an earlier\later route calculation, based on service parameters included in `NMAUrbanMobilityRouteResult`
 *
 * This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.
 *
 * @param routeResult of type `NMAUrbanMobilityRouteResult` contains parameters (serviceUrl and context) obtained from response of requested route
 *
 * @param subsequentRouteType The NMASubsequentRouteType parameter to force searching earlier or later routes
 *
 * @param routeCount Number of desired route. Given number is just suggestion and the number of
 * route returned is not guaranteed. Allowed range is [1, 6]. Using unsupported value will result error response in route calculation.
 *
 * @return NSProgress if route calculation is successfully started, nil otherwise
 */
- (nullable NSProgress *)calculateSubsequentRouteWithRouteResult:(nonnull NMAUrbanMobilityRouteResult *)routeResult
                                         withSubsequentRouteType:(NMASubsequentRouteType)subsequentRouteType
                                                  withRouteCount:(NSUInteger)routeCount
                                                 completionBlock:(nonnull NMAUrbanMobilityCalculateResultBlock)completion
NS_SWIFT_NAME(calculateSubsequentRoute(withRouteResult:subsequentRouteType:routeCount:_:));

/**
 * This determines whether route is calculated online or offline. Default is
 * `NMAUrbanMobilityRouterConnectivityDefault`. 
 * See NMAUrbanMobilityRouterConnectivity for full description of offline / online behaviour
 *
 * If this is changed after calling calculateRouteWithStops:routingMode:completionBlock,
 * the change will not take effect for the current route calculation.
 *
 * @note An example of the usage is as follows:
 * e.g. An app wishes to try online first and falls back to offline
 * if online fails. Such app will set connectivity to NMAUrbanMobilityRouterConnectivityOnline
 * before calculating a route, if this fails, it will change connectivity
 * to NMAUrbanMobilityRouterConnectivityOffline before another route calculation
 * attempt.
 */
@property (nonatomic) NMAUrbanMobilityRouterConnectivity connectivity;

@end

