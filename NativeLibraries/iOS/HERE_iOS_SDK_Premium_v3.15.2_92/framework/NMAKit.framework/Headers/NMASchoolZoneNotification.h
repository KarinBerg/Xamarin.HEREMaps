/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@class NMARoadElement;
@class NMASchoolZoneInfo;


/**
 * Represents school zone notification object.
 */
@interface NMASchoolZoneNotification : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The road element corresponding to this school zone.
 */
@property (nonatomic, readonly, nonnull) NMARoadElement *roadElement;

/**
 * The distance to `NMASchoolZoneInfo`, in meters.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 *  Info about school zone such as time and speed.
 */
@property (nonatomic, readonly, nonnull) NMASchoolZoneInfo *schoolZoneInfo;

/**
 * Indicates if school zone is on route.
 */
@property (nonatomic, readonly) BOOL isOnRoute;

/**
 * The start time for school zone speed restriction.
 * Returns nil if the restriction does not have an expiration time.
 *
 * DEPRECATED As of SDK 3.15. Use `NMASchoolZoneInfo::timeBegin` instead.
 */
@property (nonatomic, readonly, nullable) NSDate *timeBegin DEPRECATED_ATTRIBUTE;

/**
 * The end time for school zone speed restriction.
 * Returns nil if the restriction does not have an expiration time.
 *
 * DEPRECATED As of SDK 3.15. Use `NMASchoolZoneInfo::timeEnd` instead.
 */
@property (nonatomic, readonly, nullable) NSDate *timeEnd DEPRECATED_ATTRIBUTE;

/**
 * The speed limit is valid in this school zone in m/s.
 *
 * DEPRECATED As of SDK 3.15. Use `NMASchoolZoneInfo::speedLimit` instead.
 */
@property (nonatomic, readonly) float speedLimit DEPRECATED_ATTRIBUTE;

@end
