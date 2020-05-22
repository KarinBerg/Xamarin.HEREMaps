/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


@class NMASafetySpot;


/**
 * Safety spot notification information object that gives detailed information about a specific
 * instance of safety spot within a NMASafetySpotNotification.
 *
 * @note This class should not be initialized directly.
 */
@interface NMASafetySpotNotificationInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The distance, in meters, from the current GPS position (as reported by NMAPositioningManager)
 * to the safety spot.
 */
@property (nonatomic, readonly) double distance;

/**
 * The associated NMASafetySpot which provides more detail about the safety spot instance.
 */
@property (nonatomic, readonly, nullable) NMASafetySpot *safetySpot;

@end
