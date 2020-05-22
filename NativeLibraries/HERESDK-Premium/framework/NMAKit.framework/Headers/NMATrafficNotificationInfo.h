/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMATrafficEvent;
@class NMAGeoBoundingBox;

/**
 * Traffic Severity
 */
typedef NS_ENUM(NSUInteger, NMATrafficSeverity) {
    NMATrafficSeverityUndefined = 0,
    NMATrafficSeverityNormal,
    NMATrafficSeverityHigh,
    NMATrafficSeverityVeryHigh,
    NMATrafficSeverityBlocking
};

/**
 * Traffic notification type
 */
typedef NS_ENUM(NSUInteger, NMATrafficNotificationType) {
    NMATrafficNotificationUndefined = 0,
    NMATrafficNotificationOnRoute,
    NMATrafficNotificationOnHighway,
    NMATrafficNotificationNearStart,
    NMATrafficNotificationNearStopover,
    NMATrafficNotificationNearDestination
};


/**
 * Traffic notification information object that gives detailed information about a specific
 * instance of traffic within a NMATrafficNotification.
 *
 * @note This class should not be initialized directly.
 */
@interface NMATrafficNotificationInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Traffic Notification type.
 */
@property (nonatomic, readonly) NMATrafficNotificationType type;

/**
 * Traffic Severity.
 */
@property (nonatomic, readonly) NMATrafficSeverity severity;

/**
 * The distance, in meters, from the current GPS position (as reported by NMAPositioningManager)
 * to the start of the traffic instance
 */
@property (nonatomic, readonly) double distance;

/**
 * The geographical area represented by this NMATrafficNotificationInfo object.
 */
@property (nonatomic, readonly, nonnull) NMAGeoBoundingBox *affectedArea;

/**
 * The length, in meters, of the traffic instance.
 *
 * When this NMATrafficNotificationInfo object is obtained via NMATrafficWarner during
 * navigation of a route (([NMANavigationManager navigationMode] == NMANavigationModeTurnByTurn)
 * or in repsonse to querying the traffic on a route this method returns the portion of the
 * current route affected by the traffic instance.
 *
 * Otherwise this method returns the full length of the traffic instance.
 */
@property (nonatomic, readonly) double affectedLength;

/**
 * The free flow travel time (i.e. average time with no traffic) to travel the road segment
 * represented by this NMATrafficNotificationInfo object for a distance of affectedLength.
 */
@property (nonatomic, readonly) NSTimeInterval travelTime;

/**
 * The travel time, adjusted to account for traffic, to travel the road segment represented by this
 * NMATrafficNotificationInfo object for a distance of affectedLength.
 */
@property (nonatomic, readonly) NSTimeInterval travelTimeWithTraffic;

@end
