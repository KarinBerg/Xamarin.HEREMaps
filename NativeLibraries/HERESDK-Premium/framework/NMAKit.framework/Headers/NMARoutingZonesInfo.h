/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMARoadElement;
@class NMARoutingZone;


/**
 * Represents information about routing zones on a road.
 */
@interface NMARoutingZonesInfo : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Road element corresponding to these routing zones.
 */
@property (nonatomic, readonly, nonnull) NMARoadElement *roadElement;

/**
 * The distance to these routing zones, in meters.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * Array of `NMARoutingZone` objects.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMARoutingZone *> *routingZones;

@end
