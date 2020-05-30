/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMANavigationManager;
@class NMAVenue3dCombinedNavigation;
@class NMAVenue3dCombinedRoute;
@class NMAVenue3dLinkRouteSection;
@class NMAVenue3dMapLayer;
@class NMAVenue3dNavigationManager;
@class NMAVenue3dOutdoorRouteSection;
@class NMAVenue3dVenueRouteSection;

/**
 * The possible states of NMAVenue3dCombinedNavigationState.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dCombinedNavigationState) {
    /** No navigation is in progress */
    NMAVenue3dCombinedNavigationStateIdle = 0,
    /** Navigation is in progress and active */
    NMAVenue3dCombinedNavigationStateRunning,
    /** Simulation of the navigation is in progress and active */
    NMAVenue3dCombinedNavigationStateSimulating,
    /** Navigation is in progress but not currently active */
    NMAVenue3dCombinedNavigationStatePaused
};

/**
 * Specifies the possible types of navigation.
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dCombinedNavigationType) {
    /** None navigation is currently active */
    NMAVenue3dCombinedNavigationTypeNone = 0,
    /** Currently indoor navigation is active */
    NMAVenue3dCombinedNavigationTypeIndoor,
    /** Currently link section navigation is active */
    NMAVenue3dCombinedNavigationTypeLink,
    /** Currently outdoor navigation is active */
    NMAVenue3dCombinedNavigationTypeOutdoor
};

/**
 * Indicates failure of a distance-related statistics computation as a double value.
 */
FOUNDATION_EXPORT double const NMAVenue3dCombinedNavigationManagerInvalidValue;

/**
 * An interface for responding to navigation events sent by the
 * NMAVenue3dCombinedNavigationManager.
 */
@protocol NMAVenue3dCombinedNavigationListener<NSObject>
@optional


/**
 * Called when the destination of turn-by-turn navigation is reached.
 *
 * When the destination is reached, NMAVenue3dCombinedNavigation -stop is automatically
 * called.
 */
- (void)navigationManagerDidReachDestination:(nonnull NMAVenue3dCombinedNavigation *)navigationManager
NS_SWIFT_NAME(navigationManagerDidReachDestination(_:));

/**
 * Called when a change is made to the combined route being navigated.
 *
 * This can occur after successful rerouting due to the user leaving the current route (see
 * navigationManager:navigationManagerWillReroute).
 *
 * @param navigationManager The NMAVenue3dCombinedNavigation object.
 * @param combinedRoute NMAVenue3dCombinedRoute representing the current route.
 */
- (void)navigationManager:(nonnull NMAVenue3dCombinedNavigation *)navigationManager
   didUpdateCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(navigationManager(_:didUpdate:));

/**
 * Called when an indoor section of the combined route will be started.
 *
 * @param navigationManager The NMAVenue3dCombinedNavigation object.
 * @param indoorSection NMAVenue3dVenueRouteSection representing the next indoor section.
 * @param combinedRoute NMAVenue3dCombinedRoute representing the current route.
 */
- (void)navigationManager:(nonnull NMAVenue3dCombinedNavigation *)navigationManager
   willStartIndoorSection:(nonnull NMAVenue3dVenueRouteSection *)indoorSection
          inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(navigationManager(_:willStart:in:));

/**
 * Called when an link section of the combined route will be started.
 *
 * @param navigationManager The NMAVenue3dCombinedNavigation object.
 * @param linkingSection NMAVenue3dLinkRouteSection representing the next link section.
 * @param combinedRoute NMAVenue3dCombinedRoute representing the current route.
 */
- (void)navigationManager:(nonnull NMAVenue3dCombinedNavigation *)navigationManager
  willStartLinkingSection:(nonnull NMAVenue3dLinkRouteSection *)linkingSection
          inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(navigationManager(_:willStart:in:));

/**
 * Called when an outdoor section of the combined route will be started.
 *
 * @param navigationManager The NMAVenue3dCombinedNavigation object.
 * @param outdoorSection NMAVenue3dOutdoorRouteSection representing the next outdoor section.
 * @param combinedRoute NMAVenue3dCombinedRoute representing the current route.
 */
- (void)navigationManager:(nonnull NMAVenue3dCombinedNavigation *)navigationManager
  willStartOutdoorSection:(nonnull NMAVenue3dOutdoorRouteSection *)outdoorSection
          inCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(navigationManager(_:willStart:in:));

@end

/**
 */


/**
 *
 * `NMAVenue3dCombinedNavigation` is a navigation manager class that provides guidance
 * advice and information along a combined route.
 *
 * IMPORTANT: Venue3D Combined Navigation is a Beta feature. The related classes are subject to
 * change without notice.
 */
@interface NMAVenue3dCombinedNavigation : NSObject

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
@property (nonatomic, readonly) NMAVenue3dCombinedNavigationState navigationState;

/**
 * When set to YES, the current navigation will be paused (if any). When set
 * to NO, the current navigation will resume if previously paused. This has no
 * effect if there is no navigation currently in progress.
 */
@property (nonatomic, getter = isPaused) BOOL paused;

/**
 * The `NMAVenue3dMapLayer` object for navigation manager.
 */
@property (nonatomic, readonly, weak, nullable) NMAVenue3dMapLayer* venueMapLayer;

/**
 * Returns the type of currently active navigation.
 */
@property (nonatomic, readonly) NMAVenue3dCombinedNavigationType currentNavigationType;

/**
* Returns the distance from current position to the end of route in meters,
* or NMAVenue3dCombinedNavigationManagerInvalidValue on error.
*/
@property (nonatomic, readonly) double distanceToDestination;

/**
 * Returns the distance from route start to the current position in meters,
 * or NMAVenue3dCombinedNavigationManagerInvalidValue on error.
 */
@property (nonatomic, readonly) double distanceFromStart;

/**
 * Adds a listener to the navigation manager. The listener must implement
 * the NMAVenue3dCombinedNavigationListener protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the NMAVenue3dCombinedNavigationListener object to be added.
 *
 * See also `NMAVenue3dCombinedNavigationListener`
 */
- (void)addListener:(nonnull id<NMAVenue3dCombinedNavigationListener>)listener
NS_SWIFT_NAME(add(listener:));

/**
 * Removes a listener from the navigation manager. The listener must implement
 * the NMAVenue3dCombinedNavigationListener protocol. The listener receives event
 * callbacks containing information about the current navigation session.
 *
 * @param listener the NMAVenue3dCombinedNavigationListener object to be removed.
 *
 * See also `NMAVenue3dCombinedNavigationListener`
 */
- (void)removeListener:(nonnull id<NMAVenue3dCombinedNavigationListener>)listener
NS_SWIFT_NAME(remove(listener:));

/**
 * Starts a turn-by-turn navigation session using the specified combined route.
 *
 * @param combinedRoute The combined route to navigate.
 *
 * @return YES if started successfully and NO otherwise, indicating that one of the
 * route sections is invalid or the navigation is already running.
 */
- (BOOL)startForCombinedRoute:(nonnull NMAVenue3dCombinedRoute *)combinedRoute
NS_SWIFT_NAME(start(combinedRoute:));

/**
 * Start simulation of a turn-by-turn navigation session using the specified combined route.
 *
 * @param combinedRoute The combined route to navigate.
 * @param speed The speed in meters per second (m/s).
 * @param distortionEnabled Specifies whether position will be distorted with some random factor.
 * @param updateInterval Specifies how often the new position will be updated. I.e. it controls
 * smoothness of the navigation simulation.
 *
 * @return YES if simulation started successfully and NO otherwise, indicating that one of the
 * route sections is invalid or the navigation is already running.
 */
- (BOOL)simulateForCombinedRoute:(nonnull NMAVenue3dCombinedRoute*)combinedRoute
                           speed:(double)speed
               distortionEnabled:(BOOL)distortionEnabled
                  updateInterval:(NSTimeInterval)updateInterval
NS_SWIFT_NAME(simulate(combinedRoute:speed:distortionEnabled:updateInterval:));

/**
 * Stops the current navigation started via start.
 */
- (void)stop;

@end
