/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@class UIImage;


/**
 * Encapsulates an image file.
 *
 * Notes on `NMAImage` objects:
 *
 * - BMP, JPEG and PNG data formats are supported.
 *
 * - BMP data format support is limited to either standard BMP v3 with 24/32
 * bits per pixel (without compression) or BMP v4/v5 (newer BMP formats) with
 * 24/32 bits per pixel plus bitfields compression and A8R8G8B8 pixel formatting.
 *
 * - Only basic parsing of the BMP header is done, while gamma correction and
 * color profile information is ignored.
 *
 * @note PNG compression may be enabled by default in Xcode; files compressed this
 * way cannot be loaded into an NMAImage through raw data or URL. These files may
 * be first loaded into a UIImage and then used to create an NMAImage.
 */
@interface NMAImage : NSObject

/**
 * Constructs an NMAImage from an UIImage.
 *
 * When converting a UIImage to an NMAImage, the scale of the original image is compared
 * against the scale of the device. If they are different, the image is resized so that
 * the scale of the final image is the same as the device scale.
 *
 * For example, if a 100x100 pixel UIImage with a scale of 2x is converted to an NMAImage
 * on a 3x scale device, the NMAImage will have dimensions of 150x150 (and an implicit
 * scale of 3x to match the device).
 *
 * SVG format is not supported
 */
+ (nullable instancetype)imageWithUIImage:(nonnull UIImage *)image
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs an NMAImage from raw data; see the class description for supported
 * file types.
 *
 * SVG format files are not supported
 */
+ (nullable instancetype)imageWithData:(nonnull NSData *)data
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Constructs an NMAImage from a local image file URL; the path may be absolute
 * or relative to the main bundle.
 *
 * SVG format files are not supported
 */
+ (nullable instancetype)imageWithURL:(nonnull NSString *)url
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * Initializes an NMAImage.
 */
- (nonnull instancetype)init;

/**
 * Initializes an NMAImage from an UIImage.
 *
 * When converting a UIImage to an NMAImage, the scale of the original image is compared
 * against the scale of the device. If they are different, the image is resized so that
 * the scale of the final image is the same as the device scale.
 *
 * For example, if a 100x100 pixel UIImage with a scale of 2x is converted to an NMAImage
 * on a 3x scale device, the NMAImage will have dimensions of 150x150 (and an implicit
 * scale of 3x to match the device).
 *
 * SVG format is not supported
 */
- (nullable instancetype)initWithUIImage:(nonnull UIImage *)image;

/**
 * Initializes an NMAImage from raw data; see the class description for supported
 * file types.
 *
 * SVG format files are not supported
 */
- (nullable instancetype)initWithData:(nonnull NSData *)data;

/**
 * Initializes an NMAImage from a local image file URL; the path may be absolute
 * or relative to the main bundle.
 *
 * SVG format files are not supported
 */
- (nullable instancetype)initWithURL:(nonnull NSString *)url;

/**
 * The BOOL indicating whether the `NMAImage` contains a valid image.
 */
@property (nonatomic, readonly, getter = isValid) BOOL valid;

/**
 * The size of the NMAImage in points.
 */
@property (nonatomic, readonly) CGSize size;

/**
 * Provides a UIImage representation of the NMAImage.
 *
 * @note Will return nil if the image could not be converted.
 */
- (nullable UIImage *)UIImageRepresentation
NS_SWIFT_NAME(uiImage());

@end
