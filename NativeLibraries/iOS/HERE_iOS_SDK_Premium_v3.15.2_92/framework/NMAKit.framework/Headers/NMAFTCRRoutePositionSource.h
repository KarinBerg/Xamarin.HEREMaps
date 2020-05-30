/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAPositionDataSource.h"
@class NMAFTCRRoute;


/**
 * A position data source which generates updates by simulating traversal of a `NMAFTCRRoute`.
 */
@interface NMAFTCRRoutePositionSource : NSObject<NMAPositionDataSource>

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Initialize an `NMAFTCRSimulatedPositionSource` instance.
 *
 * @param route The route used for position simulation.
 * @param speed The speed used for position simulation.
 */
- (nonnull instancetype)initWithRoute:(nonnull NMAFTCRRoute*)route
                        movementSpeed:(double)speed
NS_SWIFT_NAME(init(route:movementSpeed:));

/**
 * The interval to set the frequency of position updates.
 */
@property( nonatomic ) NSTimeInterval updatesInterval;


@end
