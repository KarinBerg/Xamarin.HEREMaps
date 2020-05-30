/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAVenue3dBaseLocation;
@class NMAVenue3dCombinedRoute;
@class NMAVenue3dRouteOptions;
@class NMAVenue3dRouteStyleOptions;
@class NMAVenue3dRoutingController;


/**
 * Represents a delegate to handle NMAVenue3dRoutingController route calculation completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAVenue3dRoutingControllerObserver <NSObject>

@required
/**
 *  Callback upon completion of route calculation.
 *
 * @param combinedRoute A NMAVenue3dCombined route object representing different
 *                   route sections including indoor part(s), possible outdoor part
 *                   and possible link section(s). The route can be shown on the map
 *                   using NMAVenue3dRoutingController::showRoute message.
 *                   A NMAVenue3dCombined route object contains 0 route sections
 *                   in case if route calculation fails.
 */
- (void)didCalculateRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(didCalculateRoute(_:));

@end


/**
 *
 * An NMAVenue3dRoutingController object encapsulates the routing functionality.
 *
 * With NMAVenue3dRoutingController one can set route parameters like start end end locations and display the route.
 * Either end of the route need to be some space in a venue.
 *
 * This class can not be instantiated directly, instead it is obtained from NMAVenueMapLayer for the given NMAVenue3dController object.
 *
 * See also `NMAVenue3dMapLayer`
 *
 * See also `NMAVenue3dController`
 */
@interface NMAVenue3dRoutingController : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Calculates route object from start to end location.
 * Route calculation is done in an asynchronous manner, and the calculated route is available
 * for listeners of NMAVenue3dRoutingControllerDelegate upon completion.
 * Parking locations are only taken into account if the transport mode is set to car
 * in NMARoutingMode.
 * If the transport mode is car and the starting location has an associated parking location,
 * the route segment from the starting point to the associated parking location
 * will be in pedestrian mode.
 * If the transport mode is car and the end point has an associated parking location,
 * the route segment from the parking location to the end point will be in pedestrian mode.
 *
 * @param startLocation
 *            A start location object.
 * @param endLocation
 *            An end ocation object.
 * @param options
 *            An options used for route calculataion.
 */
- (void)calculateRouteFrom:(nonnull NMAVenue3dBaseLocation *)startLocation
                        to:(nonnull NMAVenue3dBaseLocation *)endLocation
                withParams:(nonnull NMAVenue3dRouteOptions *)options
NS_SWIFT_NAME(calculateRoute(from:to:params:));

/**
 * Calculates route object with the given waypoints.
 * Route calculation is done in an asynchronous manner, and the calculated route is available
 * for listeners of NMAVenue3dRoutingControllerDelegate upon completion.
 * Parking locations are only taken into account for the start and end points of the route,
 * and only if the transport mode is set to car in NMARoutingMode.
 * Parking locations on intermediate waypoints are ignored.
 * If the transport mode is car and the starting point has an associated  parking location,
 * the route segment from the starting point to the associated parking location
 * will be in pedestrian mode.
 * If the transport mode is car and the end point has an associated  parking location,
 * the route segment from the parking location to the end point will be in pedestrian mode.
 *
 * @param points
 *            The points on the route as NMAVenue3dBaseLocation objects (start, waypoints, end).
 *            Maximum number of elements is 11 (9 waypoints).
 * @param options
 *            Options used for route calculataion.
 */
- (void)calculateRouteWithPoints:(nonnull NSArray<NMAVenue3dBaseLocation *> *)points
                      withParams:(nonnull NMAVenue3dRouteOptions *)options
NS_SWIFT_NAME(calculateRoute(points:params:));

/**
 * Add a NMAVenue3dRoutingControllerObserver
 *
 * @param observer to be added
 */
- (void)addObserver:(nonnull id<NMAVenue3dRoutingControllerObserver>)observer
NS_SWIFT_NAME(add(listener:));

/**
 * Remove a NMAVenue3dRoutingControllerObserver
 *
 * @param observer to be added
 */
- (void)removeObserver:(nonnull id<NMAVenue3dRoutingControllerObserver>)observer
NS_SWIFT_NAME(remove(listener:));

/**
 * Shows the route on the map with default route style options.
 * Only one route at a time can be shown.
 *
 * @param combinedRoute
 *            A route object. This object is obtained using the calculateRouteFrom message or
 *            the calculateRouteWithPoints message of this class.
 *            The route can be hidden using the hideRoute message of this class.
 */
- (void)showRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute;

/**
* Shows the route on the map with custom route style options.
* Only one route at a time can be shown.
*
* @param combinedRoute
*            A route object. This object is obtained using the calculateRouteFrom message or
*            the calculateRouteWithPoints message of this class.
*            The route can be hidden using the hideRoute message of this class.
* @param styleOptions
*            Route styles, which are used in order to customize the look of the route.
*/
- (void)showRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
     withStyleOptions:(nonnull NMAVenue3dRouteStyleOptions *)styleOptions
NS_SWIFT_NAME(show(combinedRoute:styleOptions:));

/**
 * Hides the currently shown route.
 */
- (void)hideRoute;

@end
