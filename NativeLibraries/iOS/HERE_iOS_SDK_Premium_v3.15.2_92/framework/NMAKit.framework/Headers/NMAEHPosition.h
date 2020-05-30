/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAEHPathTree;



/**
 * `NMAEHPosition` is created every time after electronic horizon is updated.
 * It contains the information about current position.
 */
@interface NMAEHPosition : NSObject

/**
 * Returns the distance from the logical beginning of the main `NMAEHPathTree` to the current
 * position of the vehicle. The logical beginning is the position of the update call that
 * resulted in a path tree reset, thus an entire new `NMAEHPathTree` was created.
 */
@property (nonatomic, readonly) NSUInteger offsetCentimeters;

/**
 * Represents the speed of the vehicle's movement at timestamp.
 */
@property (nonatomic, readonly) double speedMetersPerSecond;

/**
 * Represents the time when the gps signal was received after electronic horizon was updated.
 */
@property (nonatomic, readonly, nonnull) NSDate *timestamp;

/**
 * Represents the entire path in the tree.
 *
 * @note if current position is off-road then the pathTree will be nil.
 */
@property (nonatomic, readonly, nullable) NMAEHPathTree *pathTree;

/**
 * Instances of this class should not be initialized. Call class methods only.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
