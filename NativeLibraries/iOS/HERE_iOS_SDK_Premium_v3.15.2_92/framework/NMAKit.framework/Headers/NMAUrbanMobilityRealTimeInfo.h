/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

 /**
 * DEPRECATED As of SDK 3.8.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityRealTimeInfoStatus) {
    /** Is scheduled at the original arrival/departure time and at the given platform. */
    NMAUrbanMobilityRealTimeInfoStatusOk,

    /** The line is not following the normal stops sequence. */
    NMAUrbanMobilityRealTimeInfoStatusRedirected,

    /** User should take a replacement transport for this departure/arrival. */
    NMAUrbanMobilityRealTimeInfoStatusReplaced,

    /** The service has a permanent failure and will not arrive and depart. */
    NMAUrbanMobilityRealTimeInfoStatusCancelled,

    /** This is an additional not planned service. */
    NMAUrbanMobilityRealTimeInfoStatusAdditional
} DEPRECATED_ATTRIBUTE;


/**
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityRealTimeInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Gets the real-time departure time if available, nil otherwise.
 *
 * @return real-time departure time or nil if not available
 */
@property (nonatomic, readonly, nullable) NSDate *departureTime;

/**
 * Gets the real-time arrival time if available, nil otherwise.
 *
 * @return real-time arrival time or nil if not available.
 */
@property (nonatomic, readonly, nullable) NSDate *arrivalTime;

/**
 * Gets the real-time departure/arrival platform if available, nil otherwise.
 *
 * @return real-time departure/arrival platform or nil if not available.
 */
@property (nonatomic, readonly, nullable) NSString *platform;

/**
 * An indicator for some exceptional event happened to this departure/arrival.
 * Possible values are members of `NMAUrbanMobilityRealTimeInfoStatus`.
 *
 * @return Exception event, default is `NMAUrbanMobilityRealTimeInfoStatusOk`.
 */
@property (nonatomic, readonly) NMAUrbanMobilityRealTimeInfoStatus status;

@end
