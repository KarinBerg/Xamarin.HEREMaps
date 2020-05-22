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
 * Represents a single segment of a road `NMAFTCRRoute`.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 */
@interface NMAFTCRRouteLink : NSObject

/**
 * Instances of this class should not be initialized directly.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;
/**
 * The `NSArray` of `NMAGeoCoordinates` represents the geometry of the `NMAFTCRRouteLink`.
 * The geometry is a returned as an array of `NMAGeoCoordinates` that can be used to create a
 * polyline.
 */
@property (nonatomic, readonly, strong, nullable) NSArray<NMAGeoCoordinates *> *geometry;

/**
 * Length of this link, in meters.
 */
@property (nonatomic, readonly, assign) NSUInteger length;

/**
 * Remaining distance to the final destination, in meters.
 */
@property (nonatomic, readonly, assign) NSInteger remainDistance;

/**
 * Remaining time to the final destination, in seconds.
 */
@property (nonatomic, readonly, assign) NSUInteger remainTime;

@end
