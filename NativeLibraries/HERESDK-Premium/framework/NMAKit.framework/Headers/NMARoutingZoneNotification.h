/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMARoadElement;
@class NMARoutingZonesInfo;


/**
 * Represents routing zone notification object.
 */
@interface NMARoutingZoneNotification : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Array of `NMARoutingZonesInfo` objects associated with the routing zone notification.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMARoutingZonesInfo *> *routingZonesInfos;

/**
 * Indicates if routing zones are on route.
*/
@property (nonatomic, readonly) BOOL isOnRoute;

@end
