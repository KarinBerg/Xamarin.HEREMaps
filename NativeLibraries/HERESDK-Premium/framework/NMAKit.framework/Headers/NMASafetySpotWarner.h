/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMASafetySpotNotification;
@class NMASafetySpotNotificationInfo;
@class NMASafetySpotWarner;

/**
 * NMASafetySpotWarner delegate providing safety spot warnings relevant to the current navigation
 * session.
 */
@protocol NMASafetySpotWarnerDelegate<NSObject>
@optional

/**
 * Safety spot warning notification for the current navigation session.
 *
 * @param safetySpotWarner NMASafetySpotWarner singleton instance.
 * @param safetySpotNotification NMASafetySpotNotification representing safety spot.
 */
- (void)safetySpotWarner:(nonnull NMASafetySpotWarner *)safetySpotWarner didDetectSafetySpot:(nonnull NMASafetySpotNotification *)safetySpotNotification;

@end

#pragma mark -


/**
 * Provides safety spot warning notifications for the current navigation session.
 *
 * An example of a safety spot is a speed camera or a red light camera.
 *
 * Notifications are only generated when NMANavigationManager is navigating a route
 * (navigationMode NMANavigationModeTurnByTurn) using an appropriate transport mode
 * (e.g. neither `NMATransportModePedestrian` nor `NMATransportModeBike`).
 *
 * @note This class should not be initialized directly. An instance should be obtained via
 * [NMANavigationManager safetySpotWarner].
 */
@interface NMASafetySpotWarner : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Delegate for notification of safety spots relevant to the current navigation session
 */
@property (nonatomic, weak, nullable) id<NMASafetySpotWarnerDelegate> delegate;

/**
 * Start the safety spot warner delegate callbacks.
 *
 * It will be started by default if there is an active navigation session
 * (`[NMANavigationManager navigationState]` is `NMANavigationStateRunning`).
 */
- (void)start;

/**
 * Stop the safety spot warner delegate callbacks.
 */
- (void)stop;

/**
 * Determines whether or not an NMASafetySpotNotificationInfo is ahead of the current GPS position (as reported
 * by NMAPositioningManager).
 *
 * @return YES if safetySpotNotificationInfo is ahead of the current GPS position.
 */
- (BOOL)isSafetySpotNotificationInfoAhead:(nonnull NMASafetySpotNotificationInfo *)safetySpotNotificationInfo;

@end
