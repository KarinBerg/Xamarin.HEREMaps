/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>



/**
 * Encapsulates parameters which affect the device camera.
 */
@interface NMAARCameraParameters : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * The resolution used by the camera view.
 *
 * Resolutions of 640x480 and greater are supported. Supported resolutions differ
 * across devices. To get a list of supported resolutions, call supportedSizes.
 * Arbitary sizes will always be matched to the closest resolution reported by
 * supportedSizes.
 *
 * The default resolution depends on the device and is chosen to provide the best
 * balance of performance and image quality. Depending on the device, higher
 * resolutions can have a significant performance impact.
 *
 * @note Changes made to the camera size while LiveSight is running will not be
 * reflected until livesight has been stopped and started again.
 */
@property (nonatomic, readwrite) CGSize size;

/**
 * A list of supported camera resolutions.
 *
 * @note The array contains NSValue objects; size values can be obtained by
 * calling e.g. [supportedSizes[0] CGSizeValue].
 */
@property (nonatomic, readonly, nonnull) NSArray<NSValue *> *supportedSizes;

@end
