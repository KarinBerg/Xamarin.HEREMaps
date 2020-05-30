/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAWaypoint.h"
#import "NMARoutingMode.h"


/**
 * Represents parameters that will be used for route calculation.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 */
@interface NMAFTCRRequestParameters : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Initializes an `NMAFTCRRequestParameters` instance with specified waypoints, routing mode
 * and overlay. By default `trafficEnabled` is set to `NO`.
 *
 * @param waypoints Should contain at least two waypoins.
 * @param mode `NMARoutingMode` mode.
 * @param overlay The overlay name that was used to upload custom routes on the server.
 *
 * @return The `NMAFTCRRequestParameters` instance.
 */
- (nonnull instancetype)initWithWaypoints:(nonnull NSArray<NMAWaypoint *> *)waypoints
                                     mode:(nonnull NMARoutingMode *)mode
                                  overlay:(nonnull NSString *)overlay;
/**
 * Overlay name for `NMAFTCRRouter` request.
 */
@property (nonnull, nonatomic, copy) NSString *overlay;

/**
 * Waypoints for `NMAFTCRRouter` request, must contain at least two waypoins.
 */
@property (nonnull, nonatomic, strong) NSArray<NMAWaypoint *> *waypoints;

/**
 * Routing mode for `NMAFTCRRouter` request.
 */
@property (nonnull, nonatomic, strong) NMARoutingMode *mode;

/**
 * Defines whether to consider traffic information for route calculation.
 */
@property (nonatomic) BOOL trafficEnabled;

@end
