/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */



/**
 * Represents a Zoom Range. Used to specify at which zoom level(s) a property customization
 * is to be applied.
 */
@interface NMAZoomRange : NSObject

/**
 * Minimum value of a zoom range.
 *
 * @note This value must be in the range [NMAMapViewMinimumZoomLevel, NMAMapViewMaximumZoomLevel].
 * Invalid values will be clamped to this range.
 */
@property (nonatomic) float min;

/**
 * Maximum value of a zoom range.
 *
 * @note This value must be in the range [NMAMapViewMinimumZoomLevel, NMAMapViewMaximumZoomLevel].
 * Invalid values will be clamped to this range.
 */
@property (nonatomic) float max;

/**
 * Initialize an `NMAZoomRange` instance
 *
 * @note The new instance will have the default range
 *  [NMAMapViewMinimumZoomLevel, NMAMapViewMaximumZoomLevel]
 */
- (nonnull instancetype)init;

/**
 * Helper initializer for a `NMAZoomRange`.
 *
 * @note The min and max values must be in the [NMAMapViewMinimumZoomLevel, NMAMapViewMaximumZoomLevel].
 * Invalid values will be clamped to this range.
 */
- (nonnull instancetype)initWithMinZoomLevel:(float)minimum maxZoomLevel:(float)maximum
NS_SWIFT_NAME(init(minimum:maximum:));

@end
