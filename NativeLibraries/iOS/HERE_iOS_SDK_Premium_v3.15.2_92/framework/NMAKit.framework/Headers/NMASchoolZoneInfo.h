/*
* Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
* All rights reserved.
* The use of this software is conditional upon having a separate agreement
* with a HERE company for the use or utilization of this software. In the
* absence of such agreement, the use of the software is not allowed.
*/

#import <Foundation/Foundation.h>


/**
 * Represents info about school zone. Can be obtained from `NMASchoolZoneNotification` or
 * `NMASchoolZoneWarner::schoolZoneInfoForRoadElement`
 */
@interface NMASchoolZoneInfo : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The start time for school zone speed restriction.
 * Returns nil if the restriction does not have an expiration time.
 */
@property (nonatomic, readonly, nullable) NSDate *timeBegin;

/**
 * The end time for school zone speed restriction.
 * Returns nil if the restriction does not have an expiration time.
 */
@property (nonatomic, readonly, nullable) NSDate *timeEnd;

/**
 * The speed limit is valid in this school zone in m/s.
 */
@property (nonatomic, readonly) float speedLimit;

@end
