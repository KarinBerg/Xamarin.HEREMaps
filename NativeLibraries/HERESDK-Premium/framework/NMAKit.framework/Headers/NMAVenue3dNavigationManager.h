/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAVenue3dCombinedRoute;
@class NMAVenue3dLinkRouteSection;
@class NMAVenue3dMapLayer;
@class NMAVenue3dVenue;
@class NMAVenue3dNavigationManager;
@class NMAVenue3dRouteManeuver;
@class NMAVenue3dVenueRouteSection;

/**
 * Indicates failure of a distance-related statistics computation as a float value.
 */
FOUNDATION_EXPORT float const NMAVenue3dNavigationManagerInvalidValue;

/**
 * Indicates incorrect time interval value.
 */
FOUNDATION_EXPORT NSTimeInterval const NMAVenue3dNavigationManagerInvalidTimeInterval;

/**
 * The possible states of NMAVenue3dNavigationManager.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dNavigationState) {
    /** No navigation is in progress */
    NMAVenue3dNavigationStateIdle = 0,
    /** Navigation is in progress and active */
    NMAVenue3dNavigationStateRunning,
    /** Navigation is in progress but not currently active */
    NMAVenue3dNavigationStatePaused
};

/**
 * The tilt that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dTrackingTilt) {
    /** The map will be automatically tilted to a 2D perspective */
    NMAVenue3dTrackingTilt2D,
    /** The map will be automatically tilted to a 3D perspective */
    NMAVenue3dTrackingTilt3D,
    /** The map tilt will not be changed */
    NMAVenue3dTrackingTiltCustom
};

/**
 * The tracking mode that is used when map tracking is enabled.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dTrackingMode) {
    /** The map will be automatically pan and rotate as the object moves.*/
    NMAVenue3dTrackingModeFollow,
    /** The map will be automatically pan and rotation is fixed up to north.*/
    NMAVenue3dTrackingModeNorthUp,
    /** The map will be automatically pan and the user can rotate the view.*/
    NMAVenue3dTrackingModeFreeRotation
};

/**
 * An interface for responding to navigation events sent by the
 * NMAVenue3dNavigationManager.
 */
@protocol NMAVenue3dNavigationListener<NSObject>
@optional


/**
 * Called when the destination of turn-by-turn navigation is reached.
 *
 * When the destination is reached, NMAVenue3dNavigationManager -stop is automatically
 * called. When this callback is received, the navigation manager state will be
 * NMAVenue3dNavigationStateIdle.
 *
 */
- (void)navigationManagerDidReachDestination:(nonnull NMAVenue3dNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerDidReachDestination(_:));

/**
 * Called when the current (upcoming) maneuver is updated.
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 * @param maneuver The current (upcoming) maneuver to be made.
 * @param nextManeuver The maneuver to be made AFTER THE CURRENT MANEUVER.
 *
 * @note The "current" maneuver is the upcoming, or next, maneuver to be taken. The "next"
 * maneuver is actually the maneuver to be taken after the current maneuver.
 */
- (void)navigationManager:(nonnull NMAVenue3dNavigationManager *)navigationManager
       hasCurrentManeuver:(nullable NMAVenue3dRouteManeuver *)maneuver
             nextManeuver:(nullable NMAVenue3dRouteManeuver *)nextManeuver
NS_SWIFT_NAME(navigationManager(_:hasCurrentManeuver:nextManeuver:));

/**
 * Called when the navigation manager loses its indoor position.
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 */
- (void)navigationManagerDidLosePosition:(nonnull NMAVenue3dNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerDidLosePosition(_:));

/**
 * Called when the navigation manager finds its indoor position.
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 */
- (void)navigationManagerDidFindPosition:(nonnull NMAVenue3dNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerDidFindPosition(_:));

/**
 * Called when a change is made to the route section being navigated.
 *
 * This can occur after successful rerouting due to the user leaving the current route (see
 * NMAVenue3dNavigationListener::navigationManagerWillReroute: ).
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 * @param routeSection NMAVenue3dVenueRouteSection representing the route section that was set.
 * @param combinedRoute NMAVenue3dCombinedRoute representing the current route.
 */
- (void)navigationManager:(nonnull NMAVenue3dNavigationManager *)navigationManager
    didUpdateRouteSection:(nonnull NMAVenue3dVenueRouteSection *)routeSection
          inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(navigationManager(_:didUpdate:in:));

/**
 * Called when rerouting is triggered due to the user leaving the current route section.
 *
 * If a new route section is successfully calculated, it is immediately applied to
 * the current navigation session and navigationManager:didUpdateRouteSection: is called.
 * After rerouting, the navigationManager:didUpdateRouteSection: is called.
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 */
- (void)navigationManagerWillReroute:(nonnull NMAVenue3dNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerWillReroute(_:));

/**
 * Called when rerouting, due to the user leaving the current route section, has finished.
 *
 * This method just means an attempt to reroute finished and does not guarantee that
 * a new route was successfully created.
 *
 * @param navigationManager The NMAVenue3dNavigationManager object.
 */
- (void)navigationManagerDidReroute:(nonnull NMAVenue3dNavigationManager *)navigationManager
NS_SWIFT_NAME(navigationManagerDidReroute(_:));

@end

/**
 */


/**
 *
 * `NMAVenue3dNavigationManager` is a navigation manager class that provides guidance
 * advice and information along an indoor route.
 *
 * IMPORTANT: Venue3D Navigation Manager is a Beta feature. The related classes are subject to
 * change without notice.
 */
@interface NMAVenue3dNavigationManager : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Returns the current state of the navigation related to the tracked route.
 */
@property (nonatomic, readonly) NMAVenue3dNavigationState navigationState;

/**
 * When set to YES, the current navigation will be paused (if any). When set
 * to NO, the current navigation will resume if previously paused. This has no
 * effect if there is no navigation currently in progress.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

/**
 * Allows the NMANavigationManager to automatically update map position as
 * navigation progresses.
 *
 * @note The default value is YES.
 */
@property (nonatomic, getter = isMapTrackingEnabled) BOOL mapTrackingEnabled;

/**
 * Controls how the map is tilted when map tracking is enabled.
 *
 * In 2D and 3D modes, the map will automatically be tilted back appropriately when
 * the tilt value is changed. In Custom mode, the tilt will not be changed. Use custom
 * mode to allow the map to be manually tilted during navigation or to set the tilt to
 * a fixed custom value.
 *
 * @note The default value is NMAVenue3dTrackingTilt3D.
 */
@property (nonatomic) NMAVenue3dTrackingTilt mapTrackingTilt;

/**
 * Controls how the map is moved and rotated when map tracking is enabled.
 *
 * @note The default value is NMAVenue3dTrackingModeFollow.
 */
@property (nonatomic) NMAVenue3dTrackingMode mapTrackingMode;

/**
 * The `NMAVenue3dMapLayer` object for navigation manager.
 */
@property (nonatomic, readonly, weak, nullable) NMAVenue3dMapLayer * venueMapLayer;

/**
 * The `NMAVenue3dVenue` object where the navigation is taking place.
 *
 * @note If the navigation is started with 'NMAVenue3dLinkRouteSection' route section,
 * then this property will return nil.
 */
@property (nonatomic, readonly, weak, nullable) NMAVenue3dVenue * venue;

/**
 * Returns current (upcoming) maneuver on the route, or nil, if this information
 * is not available because the navigation hasn't been started, or there are no
 * maneuvers on the route.
 *
 * @note The currentManeuver property represents the upcoming, or next, maneuver to be taken. The
 * nextManeuver property is actually the maneuver to be taken after the current maneuver.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dRouteManeuver * currentManeuver;

/**
 * Returns the next maneuver on the route AFTER THE CURRENT MANEUVER , or nil if there is none.
 *
 * @note The nextManeuver property represents the maneuver, which comes after current maneuver.
 * The current maneuver represents the upcoming, or next maneuver to be taken.
 */
@property (nonatomic, readonly, nullable) NMAVenue3dRouteManeuver * nextManeuver;

/**
 * Returns the distance from current position to the current (upcoming) maneuver in meters,
 * or NMAVenue3dNavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) float distanceToCurrentManeuver;

/**
 * Returns the distance from current position to the next maneuver AFTER THE CURRENT MANEUVER
 * in meters, or NMAVenue3dNavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) float distanceToNextManeuver;

/**
 * Returns the distance from current position to the end of route in meters,
 * or NMAVenue3dNavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) float distanceToDestination;

/**
 * Returns the distance from route start to the current position in meters,
 * or NMAVenue3dNavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) float distanceFromStart;

/**
 * Returns the average speed of distance travelled in meters/sec or 0 if it
 * cannot be calculated.
 */
@property (nonatomic, readonly) float averageSpeed;

/**
 * Returns the number of seconds that remain to travel to the destination,
 * or NMAVenue3dNavigationManagerInvalidTimeInterval on error.
 */
@property (nonatomic, readonly) NSTimeInterval timeToArrival;

/**
 * Returns the time interval in seconds, after which the route will be recalculated in case the
 * user moves far away from the current route.
 *
 * When the user significantly deviates from the specified route, he is given exactly
 * reroutingTimeout secs return to the route. When the user fails to do so within this timeout, the
 * rerouting process is started and a new route will be constructed based on the user's
 * current position.
 *
 * See also `NMAVenue3dNavigationListener::navigationManagerWillReroute:`
 */
@property (nonatomic) NSTimeInterval reroutingTimeout;

/**
 * Enables/disables device vibration during navigation. If enabled, it will happen on specific
 * navigation events, like maneuver change, rerouting, reaching destination, etc.
 *
 * @note vibration is enabled by default.
 */
@property (nonatomic) bool vibrationEnabled;

/**
 * Enables/disables device beep sounds during navigation. If enabled, it will happen on specific
 * navigation events, like maneuver change, rerouting, reaching destination, etc.
 *
 * @note beeps are enabled by default.
 */
@property (nonatomic) bool beepsEnabled;

/**
 * Controls whether indoor navigation is paused when the application is sent to the background.
 * Default value is NO (Background indoor navigation is disabled).
 *
 * This property must be set whilst the app is in the foreground and has at least a
 * CLAuthorizationStatus of kCLAuthorizationStatusAuthorizedWhenInUse.
 * Changing the property whilst the app is in the background will have undefined behaviour and
 * may not reliably enable the background position updates required by navigation.
 *
 * @note The current NMAPositioningManager::dataSource must support background position updates in
 * order to navigate in the background. All position data sources supplied with the Here SDK support
 * background position updates. If the current position data source does not support background
 * position updates then background navigation will not work even though this property may be set
 * to YES.
 *
 * @note If navigation is stopped in the background, it will not restart automatically.
 *
 * @note This property can conflict with NMANavigationManager::backgroundNavigationEnabled, because
 * they both rely on <code>NNMAPositioningManager.dataSource.backgroundUpdatesEnabled</code> property.
 *
 * See also `NMAPositionDataSource::setBackgroundUpdatesEnabled:`
 *
 * See also `NMANavigationManager::backgroundNavigationEnabled`
 */
@property (nonatomic) BOOL backgroundNavigationEnabled;

/**
 * Controls whether indoor navigation may be started when the app is in the background. Default
 * value is NO (Navigation can not be started in the background and calls to
 * startForRouteSection: will return an error (NO/false return type)).
 *
 * This property must be set whilst the app is in the foreground and has at least a
 * CLAuthorizationStatus of kCLAuthorizationStatusAuthorizedWhenInUse. Changing the property whilst
 * the app is in the background will have undefined behaviour and may not reliably enable the
 * background position updates required by navigation.
 *
 * IMPORTANT: Even with this property set to YES if your app enters the background and then enters
 * the suspended state you may not be able to reliably start navigation in the background if the app
 * resumes background execution without returning to the foreground first (e.g. background execution
 * resumes to "silently" handle a push notification or a file download completing).
 * To guarantee navigation can be started after background suspension you must also call
 * [NMAPositioningManager startPositioning] in the foreground. This will mean your app will be
 * constantly waking to handle position updates in the background which will have a side effect of
 * consuming more power. Only the combination of explicitly starting NMAPositioningManager,
 * setting backgroundNavigationEnabled to YES and setting backgroundNavigationStartEnabled to YES
 * in the foreground will allow navigation to be reliably started in the background.
 *
 * @note The current NMAPositioningManager::dataSource must support background position updates in
 * order to navigate in the background. All position data sources supplied with the Here SDK support
 * background position updates. If the current position data source does not support background
 * position updates then background navigation will not work even though this property may be set
 * to YES.
 *
 * See also `backgroundNavigationEnabled`
 *
 * See also `NMANavigationManager::backgroundNavigationStartEnabled`
 */
@property (nonatomic) BOOL backgroundNavigationStartEnabled;

/**
 * Adds a listener to the navigation manager. The listener must implement
 * the NMAVenue3dNavigationListener protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the NMAVenue3dNavigationListener object to be added.
 *
 * See also `NMAVenue3dNavigationListener`
 */
- (void)addListener:(nonnull id<NMAVenue3dNavigationListener>)listener
NS_SWIFT_NAME(add(listener:));

/**
 * Removes a listener from the navigation manager. The listener must implement
 * the NMAVenue3dNavigationListener protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the NMAVenue3dNavigationListener object to be removed.
 *
 * See also `NMAVenue3dNavigationListener`
 */
- (void)removeListener:(nonnull id<NMAVenue3dNavigationListener>)listener
NS_SWIFT_NAME(remove(listener:));

/**
 * Starts a turn-by-turn navigation session  using the specified venue route section
 * in combined route.
 *
 * @param routeSection The venue route section to navigate.
 * @param combinedRoute The combined route which contains the venue route section.
 *
 * @return YES if started successfully and NO otherwise, indicating that the venue
 * route section is invalid, the combined route doesn't contain that route section
 * or the navigation is already running.
 */
- (BOOL)startForRouteSection:(nonnull NMAVenue3dVenueRouteSection *)routeSection
             inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(start(routeSection:inCombinedRoute:));

/**
 * Starts a tracking session  using the specified link route section
 * in combined route.
 *
 * @param linkSection The link route section to track.
 * @param combinedRoute The combined route which contains the link route section.
 *
 * @return YES if started successfully and NO otherwise, indicating that the link
 * route section is invalid, the combined route doesn't contain that route section
 * or the navigation is already running.
 */
- (BOOL)startForLinkSection:(nonnull NMAVenue3dLinkRouteSection *)linkSection
            inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(start(linkSection:inCombinedRoute:));

/**
 * Stops the current navigation started via start.
 */
- (void)stop;

/**
 * Flag indicating wether maneuver zoom is enabled.
 */
@property (nonatomic, readwrite) BOOL maneuverZoomEnabled;

/**
 * Distance in meters at which a maneuver is zoomed in if maneuver zoom is enabled.
 */
@property (nonatomic, readwrite) float maneuverZoomDistance;

/**
 * Zoom level to which a maneuver is zoomed in if maneuver zoom is enabled.
 */
@property (nonatomic, readwrite) float maneuverZoomLevel;

@end
