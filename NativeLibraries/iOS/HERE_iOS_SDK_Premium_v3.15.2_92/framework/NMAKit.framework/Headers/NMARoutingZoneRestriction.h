/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARoutingMode.h"


/**
 * Represents represents routing zone restriction object.
 */
@interface NMARoutingZoneRestriction : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The start time for routing zone restriction.
 * Returns nil if the restriction does not have time period.
 */
@property (nonatomic, readonly, nullable) NSDate *timeBegin;
/**
 * The end time for routing zone restriction.
 * Returns nil if the restriction does not have time period.
 */
@property (nonatomic, readonly, nullable) NSDate *timeEnd;

/**
 * The string with last digits of license plate that are restricted to travel through the route.
 * Returns nil if current restriction does not have license plate constraint.
 */
@property (nonatomic, readonly, nullable) NSString *licensePlateLastDigits;

/**
 * The transport types for this restriction.
 */
@property (nonatomic, readonly, nonnull) NSSet<NSNumber *> *transportTypes;

@end
