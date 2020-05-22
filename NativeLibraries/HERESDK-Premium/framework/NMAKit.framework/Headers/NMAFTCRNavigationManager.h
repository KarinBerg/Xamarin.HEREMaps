/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAFTCRRoute;
@class NMAFTCRManeuver;
@class NMAFTCRNavigationManager;
@class NMAMapView;
@class NMAGeoPosition;

/**
 * The tilt that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAFTCRTrackingTilt) {
    /** The map will be automatically tilted to a 2D perspective */
    NMAFTCRTrackingTilt2D,
    /** The map will be automatically tilted to a 3D perspective */
    NMAFTCRTrackingTilt3D,
    /** The map tilt will not be changed */
    NMAFTCRTrackingTiltCustom
};

/**
 * The tracking mode that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAFTCRTrackingMode) {
    /** The map will not be automatically pan.*/
    NMAFTCRTrackingModeNone,
    /** The map will be automatically pan and rotate as the object moves.*/
    NMAFTCRTrackingModeFollow,
    /** The map will be automatically pan and rotation is fixed up to north.*/
    NMAFTCRTrackingModeNorthUp,
    /** The map will be automatically pan and the user can rotate the view.*/
    NMAFTCRTrackingModeFreeRotation
};


/**
 * An interface for responding to navigation events sent by the `NMAFTCRNavigationManager`.
 */
@protocol NMAFTCRNavigationManagerDelegate<NSObject>
@optional

/**
 * Called when the current (upcoming) maneuver is updated.
 *
 * @param navigationManager The NMAFTCRNavigationManager object.
 * @param maneuver The current (upcoming) maneuver to be made.
 * @param nextManeuver The maneuver to be made AFTER THE CURRENT MANEUVER.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next"
 * maneuver is actually the maneuver to be taken after the current maneuver.
 */
- (void)navigationManager:(nonnull NMAFTCRNavigationManager *)navigationManager
       hasCurrentManeuver:(nullable NMAFTCRManeuver *)maneuver
             nextManeuver:(nullable NMAFTCRManeuver *)nextManeuver
NS_SWIFT_NAME(navigationManager(_:hasCurrentManeuver:nextManeuver:));

/**
 * Called when the destination of navigation is reached.
 *
 * When the destination is reached, `[NMAFTCRNavigationManager stop]` is automatically called.
 *
 * @param navigationManager The `NMAFTCRNavigationManager` object.
 */
- (void)navigationManagerDidReachDestination:(nonnull NMAFTCRNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerDidReachDestination(_:));

/**
 * Called when a route stopover has been reached.
 *
 * @note Note that, in addition to this,
 * `[NMAFTCRNavigationManager navigationManager:hasCurrentManeuver:nextManeuver:]`
 *  will also be called.
 *
 * @param navigationManager The NMANavigationManager singleton.
 * @param stopoverIndex The index of stopover reached.
*/
- (void)navigationManager:(nonnull NMAFTCRNavigationManager *)navigationManager
         didReachStopover:(NSInteger)stopoverIndex
NS_SWIFT_NAME(navigationManager(_:didReachStopover:));

/**
 * Called when rerouting is triggered due to the user leaving the current route section.
 *
 * If a new route is successfully calculated, it is immediately applied to
 * the current navigation session. After rerouting,
 * `[NMAFTCRNavigationManager navigationManager:didRerouteWithRoute:error:]` is called.
 *
 * @param navigationManager The NMAFTCRNavigationManager object.
 */
- (void)navigationManagerWillReroute:(nonnull NMAFTCRNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerWillReroute(_:));

/**
 * Called when rerouting, due to the user leaving the current route section, has finished.
 *
 * This method just means an attempt to reroute finished and does not guarantee that
 * a new route was successfully created.
 *
 * @note In order to see new route on the map, old `NMAMapFTCRRoute` should be removed from
 * the map and new mapRoute added to the map.
 *
 * @param navigationManager The `NMAFTCRNavigationManager` object.
 * @param reroute The new recalculated `NMAFTCRRoute` object.
 * @param error The error if rerouting was not successful or nil otherwise.
 */
- (void)navigationManager:(nonnull NMAFTCRNavigationManager *)navigationManager
      didRerouteWithRoute:(nullable NMAFTCRRoute *)reroute
                    error:(NSError* _Nullable)error
NS_SWIFT_NAME(navigationManager(_:didReroute:error:));

@end


/**
 * A navigation manager class that provides guidance advice and information along the FTCR routes.
 * IMPORTANT: `NMAFTCRNavigationManager` is a Beta feature. The related classes are subject to
 * change without notice.
 */
@interface NMAFTCRNavigationManager : NSObject

/**
 * Returns the `NMAFTCRNavigationManager` singleton instance.
 *
 * @note Use this method to obtain a `NMAFTCRNavigationManager` instance.
 *
 * @return shared `NMAFTCRNavigationManager` instance.
 */
+ (nonnull instancetype)sharedNavigationManager
NS_SWIFT_NAME(sharedInstance());

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The NMAMapView used for the current navigation.
 *
 * If a map view is specified when navigation is started, that map view will be used
 * to track the current position.
 *
 * @note Will be nil if no map was specified for the current navigation session.
 *
 * @note Changes made to this property while navigation is active will not be reflected
 * until the next navigation session is started.
 */
@property (nonatomic, weak, nullable) NMAMapView *map;

/**
 * Controls how the map is tilted when map tracking is enabled.
 *
 * In 2D and 3D modes, the map will automatically be tilted back appropriately when
 * the tilt value is changed. In Custom mode, the tilt will not be changed. Use custom
 * mode to allow the map to be manually tilted during navigation or to set the tilt to
 * a fixed custom value.
 *
 * @note Setting this property will have no effect if `map` was not set beforehand.
 *
 * @note The default value is NMAFTCRTrackingTilt3D.
 */
@property (nonatomic) NMAFTCRTrackingTilt mapTrackingTilt;

/**
 * Controls how the map is moved and rotated when map tracking is enabled.
 *
 * @note Setting this property will have no effect if `map` was not set beforehand.
 *
 * @note The default value is NMAFTCRTrackingModeFollow.
 */
@property (nonatomic) NMAFTCRTrackingMode mapTrackingMode;

/**
 * Returns current (upcoming) maneuver on the route, or nil, if this information
 * is not available because the navigation hasn't been started, or there are no
 * maneuvers on the route.
 *
 * @note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly, nullable) NMAFTCRManeuver *currentManeuver;

/**
 * Returns the next maneuver on the route AFTER THE CURRENT MANEUVER , or nil if there is none.
 *
 * @note The nextManeuver property represents the maneuver, which comes after current maneuver.
 * The current maneuver represents the upcoming, or next maneuver to be taken.
 */
@property (nonatomic, readonly, nullable) NMAFTCRManeuver *nextManeuver;

/**
 * Returns the distance from current position to the current (upcoming) maneuver in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceToCurrentManeuver;

/**
 * Returns the distance from current position to the next maneuver AFTER THE CURRENT MANEUVER
 * in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceToNextManeuver;

/**
 * Returns the distance from current position to the end of route in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceToDestination;

/**
 * Returns the distance from route start to the current position in meters.
 */
@property (nonatomic, readonly) NSUInteger distanceFromStart;

/**
 * Returns the average speed of distance travelled in meters/sec or 0 if it
 * cannot be calculated.
 */
@property (nonatomic, readonly) NSInteger averageSpeed;

/**
 * Returns the number of seconds that remain to travel to the destination.
 */
@property (nonatomic, readonly) NSTimeInterval timeToArrival;

/**
 * Returns matched route position for current navigation session, can be nil if current gps
 * position can not be matched.
 */
@property (nonatomic, readonly, nullable) NMAGeoPosition *routePosition;

/**
 * Adds a listener to the navigation manager. The listener must implement
 * the `NMAFTCRNavigationManagerDelegate` protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the `NMAFTCRNavigationManagerDelegate` object to be added.
 *
 * See also `NMAFTCRNavigationManagerDelegate`
 */
- (void)addListener:(nonnull id<NMAFTCRNavigationManagerDelegate>)listener
NS_SWIFT_NAME(add(listener:));

/**
 * Removes a listener from the navigation manager. The listener must implement
 * the NMAFTCRNavigationManagerDelegate protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the `NMAFTCRNavigationManagerDelegate` object to be removed.
 *
 * See also `NMAFTCRNavigationManagerDelegate`
 */
- (void)removeListener:(nonnull id<NMAFTCRNavigationManagerDelegate>)listener
NS_SWIFT_NAME(remove(listener:));

/**
 * Starts a navigation session using the specified `NMAFTCRRoute` route.
 *
 * If there already is an active navigation, calling this method will have no effect.
 *
 * @note In case of reroute, old `NMAMapFTCRRoute` should be removed from the map and new
 * mapRoute added to the map.
 * @note If navigation has to be done by simulating location,
 * use `NMAFTCRRoutePositionSource` as datasource for `NMAPositioningManager::dataSource`.
 *
 * @param route The route to navigate.
 */
- (void)startWithRoute:(nonnull NMAFTCRRoute *)route
NS_SWIFT_NAME(start(_:));

/**
 * Stops the current navigation session.
 */
- (void)stop;

/**
 * Returns the remaining distance to the end of route or of route subleg.
 *
 * @param subleg The subleg number to use or `NMAFTCRRouteSublegWhole` for the whole route.
 *
 * @return the distance in meters. Returns NSUIntegerMax if an error occured
 * or if the end of given route leg has been already reached.
 */
- (NSUInteger)remainingDistanceToSubleg:(NSUInteger)subleg
NS_SWIFT_NAME(remainingDistance(toSubleg:));

/**
 * Returns the Time To Arrival (TTA) in seconds to the end of the specific leg of the route.

 * @param subleg The subleg number to use or `NMAFTCRRouteSublegWhole` for the whole route.
 *
 * @return the time in seconds. Returns -DBL_MAX if an error occured
 * or if the end of given route leg has been already reached.
 */
- (NSTimeInterval)timeToArrivalForSubleg:(NSUInteger)subleg
NS_SWIFT_NAME(timeToArrival(forSubleg:));

@end
