/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATransitRouteStop;



/**
 * Represents the leg of a transit journey from one stop to the next along a
 * NMATransitManeuver.
 *
 * A NMATransitManeuver is composed of one or more NMATransitRouteElement.
 */
@interface NMATransitRouteElement : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The duration, in seconds, for the NMATransitRouteElement.
 *
 * It is the estimated travel time from the departure stop to the arrival stop of
 * the NMATransitRouteElement.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * The departure stop for the NMATransitRouteElement.
 */
@property (nonatomic, readonly, nullable) NMATransitRouteStop *departureStop;

/**
 * The arrival stop for the NMATransitRouteElement.
 */
@property (nonatomic, readonly, nullable) NMATransitRouteStop *arrivalStop;

@end
