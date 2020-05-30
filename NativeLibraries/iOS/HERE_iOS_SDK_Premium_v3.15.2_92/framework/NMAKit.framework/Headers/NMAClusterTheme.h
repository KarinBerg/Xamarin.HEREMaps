/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAClusterStyle;



/**
 * This class contains information about styles for given density ranges.
 * Density represents the number of markers inside a cluster.
 */
@interface NMAClusterTheme : NSObject

/**
 * Initialize a `NMAClusterTheme` instance
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Constructs an empty `NMAClusterTheme`.
 */
+ (nonnull instancetype)clusterTheme
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Groups a number of markers inside a cluster.
 *
 * @param style Style that should be used for given range.
 * @param range Density range, minimum allowed start location is 2.
 * The sum of the location and length of the range should not exceed `NSIntegerMax` value.
 *
 * @return YES if valid range and style was provided, NO otherwise.
 */
- (BOOL)setStyle:(nonnull NMAClusterStyle *)style forDensityRange:(NSRange)range
NS_SWIFT_NAME(setStyle(_:range:));

@end
