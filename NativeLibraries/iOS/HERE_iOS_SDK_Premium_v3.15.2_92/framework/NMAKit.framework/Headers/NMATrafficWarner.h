/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATrafficNotification;
@class NMATrafficWarner;
@class NMARoute;


/**
 * NMATrafficWarner delegate providing traffic warnings relevant to the current navigation
 * session.
 */
@protocol NMATrafficWarnerDelegate<NSObject>
@optional

/**
 * Traffic warning notification for the current navigation session.
 *
 * This method will only be called when NMANavigationManager is navigating a route
 * (mode NMANavigationModeTurnByTurn) using a transport mode of NMATransportModeCar.
 *
 * @param trafficWarner NMATrafficWarner singleton instance.
 * @param trafficNotification NMATrafficNotification representing traffic ahead of the current
 * GPS position on the route being navigated.
 */
- (void)trafficWarner:(nonnull NMATrafficWarner *)trafficWarner didDetectTraffic:(nonnull NMATrafficNotification *)trafficNotification;

@end

#pragma mark -


/**
 * Provides traffic warning information for the current navigation session.
 *
 * IMPORTANT: In order to obtain traffic warning information and receieve NMATrafficWarnerDelegate
 * callbacks traffic data must be downloaded using [NMATrafficManager requestTrafficOnRoute:] or by
 * enabling traffic visualization on an NMAMapView using the trafficVisible property. In the latter
 * case you will only be warned of traffic that is, or was recently, visible on the map.
 *
 * @note This class should not be initialized directly. An instance should be obtained via
 * [NMANavigationManager trafficWarner]. Navigation Manager should be in NMANavigationStateRunning
 * state for the warner to work correctly.
 */
@interface NMATrafficWarner : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Delegate for notification of traffic events relevant to the current navigation session
 */
@property (nonatomic, weak, nullable) id<NMATrafficWarnerDelegate> delegate;

/**
 * Start the traffic warner delegate callbacks.
 *
 * It will be started by default if there is an active navigation session
 * (`[NMANavigationManager navigationState]` is `NMANavigationStateRunning`).
 */
- (void)start;

/**
 * Stop the traffic warner delegate callbacks.
 */
- (void)stop;

/**
 * Clears the traffic warner.
 *
 * This will permanently disable traffic warner until the a new navigation session is started using
 * [NMANavigationManager startTurnByTurnNavigationWithRoute:]
 */
- (void)clear;

/**
 * Traffic notification for the route currently being navigated by NMANavigationManager.
 *
 * This returns traffic that is ahead of the current GPS position.
 *
 * @return NMATrafficNotification for the current navigation session or nil if NMANavigationManager is
 * not navigating a route (mode NMANavigationModeTurnByTurn) using a transport mode of
 * NMATransportModeCar.
 *
 * @note To ensure the traffic notification contains all traffic for the route you must explicitly
 * download traffic data using NMATrafficManager for the NMARoute in question.
 */
- (nullable NMATrafficNotification *)trafficNotificationOnCurrentRoute;

/**
 * Traffic notification for all traffic on a given NMARoute.
 *
 * If the route is currently being navigated this method will return traffic for the entire route
 * regardless of the current position along the route.
 *
 * @param route NMARoute to query for a traffic notification.
 * @return NMATrafficNotification for the route or nil if [[NMARoute routingMode] transportMode] is not
 * NMATransportModeCar.
 *
 * @note To ensure the traffic notification contains all traffic for the route you must explicitly
 * download traffic data using NMATrafficManager for the NMARoute in question.
 */
- (nullable NMATrafficNotification *)trafficNotificationOnRoute:(nonnull NMARoute *)route
NS_SWIFT_NAME(trafficNotification(onRoute:));

/**
 * Determines whether or not an NMATrafficNotification is ahead of the current GPS position (as reported
 * by NMAPositioningManager).
 *
 * @return YES if trafficNotification is ahead of the current GPS position.
 */
- (BOOL)isTrafficNotificationAhead:(nonnull NMATrafficNotification *)trafficNotification;

/**
 * Determines whether or not an NMATrafficNotification is on a given NMARoute
 *
 * @param trafficNotification NMATrafficNotification to check
 * @param route NMARoute to check
 * @return YES if the notification is on the given route, NO otherwise.
 */
- (BOOL)isTrafficNotification:(nonnull NMATrafficNotification *)trafficNotification onRoute:(nonnull NMARoute *)route
NS_SWIFT_NAME(isTrafficNotification(_:onRoute:));

@end

