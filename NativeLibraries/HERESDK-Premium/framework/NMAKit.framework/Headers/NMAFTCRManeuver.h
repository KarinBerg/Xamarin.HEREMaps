/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;


/**
 * Represents information about maneuver on the `NMAFTCRRoute`.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 */
@interface NMAFTCRManeuver : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The `NMAGeoCoordinates` of the maneuver.
 */
@property (nonatomic, readonly, strong, nullable) NMAGeoCoordinates *position;

/**
 * The instruction of the maneuver.
 */
@property (nonatomic, readonly, strong, nullable) NSString *instruction;

/**
 * The time to the next maneuver in seconds.
 */
@property (nonatomic, readonly, assign) NSUInteger travelTime;

/**
 * The length to the next maneuver in meters.
 */
@property (nonatomic, readonly, assign) NSUInteger length;

@end
