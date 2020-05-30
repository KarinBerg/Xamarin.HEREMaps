/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAClusterStyle.h"
#import <UIKit/UIColor.h>



/**
 * Basic implementation of `NMAClusterStyle`. Use it if some customization needs be applied to
 * this style. Please see the API of this class for the list of customizable properties.
 */
@interface NMABasicClusterStyle : NMAClusterStyle

/**
 * Color of the font used for rendering cluster marker.
 */
@property (nonatomic, nonnull) UIColor *fontColor;

/**
 * Fill color of cluster marker.
 */
@property (nonatomic, nonnull) UIColor *fillColor;

/**
 * Stroke color of cluster marker.
 */
@property (nonatomic, nonnull) UIColor *strokeColor;

/**
 * Initialize a `NMABasicClusterStyle` instance
 */
- (nonnull instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Constructs a `NMABasicClusterStyle` with default values.
 */
+ (nonnull instancetype)style
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMABasicClusterStyle` with the specified colors.
 *
 * @param stroke Stroke color of cluster marker.
 * @param fill Fill color of cluster marker.
 * @param font Color of the font used for rendering cluster marker.
 */
+ (nonnull instancetype)styleWithStrokeColor:(nonnull UIColor *)stroke fillColor:(nonnull UIColor *)fill fontColor:(nonnull UIColor *)font
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes a `NMABasicClusterStyle` instance with the specified colors.
 *
 * @param stroke Stroke color of cluster marker.
 * @param fill Fill color of cluster marker.
 * @param font Color of the font used for rendering cluster marker.
 */
- (nonnull instancetype)initWithStrokeColor:(nonnull UIColor *)stroke
                                  fillColor:(nonnull UIColor *)fill
                                  fontColor:(nonnull UIColor *)font
NS_SWIFT_NAME(init(strokeColor:fillColor:fontColor:));

@end
