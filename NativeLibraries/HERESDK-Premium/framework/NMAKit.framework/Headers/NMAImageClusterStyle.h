/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAClusterStyle.h"

@class NMAImage;
@class UIImage;



/**
 * Implementation of `NMAClusterStyle` that uses `NMAImage` for specific cluster density.
 * Density represents the number of markers inside a cluster.
 */
@interface NMAImageClusterStyle : NMAClusterStyle

/**
 * Instances of this class must initialized with an NMAImage.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class must initialized with an NMAImage.
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Constructs a `NMAImageClusterStyle` with the given image.
 *
 * @param image `NMAImage` instance to be used for this style.
 */
+ (nullable instancetype)styleWithImage:(nullable NMAImage *)image
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs a `NMAImageClusterStyle` with the given image.
 *
 * @param image `UIImage` instance to be used for this style.
 */
+ (nullable instancetype)styleWithUIImage:(nullable UIImage *)image
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes a `NMAImageClusterStyle` instance with the given image.
 *
 * @param image `NMAImage` instance to be used for this style.
 */
- (nullable instancetype)initWithImage:(nullable NMAImage *)image
NS_SWIFT_NAME(init(nmaImage:));

/**
 * Initializes a `NMAImageClusterStyle` instance with the given image.
 *
 * @param image `UIImage` instance to be used for this style.
 */
- (nullable instancetype)initWithUIImage:(nullable UIImage *)image
NS_SWIFT_NAME(init(uiImage:));

@end
