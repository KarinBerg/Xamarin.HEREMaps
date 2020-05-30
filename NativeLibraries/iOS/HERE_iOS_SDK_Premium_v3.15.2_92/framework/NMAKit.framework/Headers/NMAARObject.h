/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMAARController.h"

@class NMAGeoCoordinates;
@class NMAImage;


/**
 * Base class for all LiveSight objects that can be added to an NMAARController.
 *
 * This class serves as a generalization (or abstract base) for more specific
 * object types (such as `NMAARIconObject`), bundling their common properties.
 * Do not attempt to create an NMAARObject instance directly.
 *
 * By default objects have a projection type of NMAARProjectionTypeNearFar which
 * means NMAARObjects are rendered in the Camera view using front plane or back
 * plane icons.
 *
 * Objects appearing in the back plane are rendered with reduced opacity.
 *
 * Objects appearing in the front plane render their info image to the right of
 * the front icon.
 *
 * The front/back plane concept is only relevant to the NMAARProjectionTypeNearFar
 * projection type.
 */
@interface NMAARObject : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

#pragma mark - General Properties

/**
 * The unique ID of the NMAARObject.
 *
 * @note This value will be consistent for the lifetime of the object.
 */
@property (nonatomic, readonly) NSUInteger uniqueId;

/**
 * The geo coordinates of the NMAARObject.
 */
@property (nonatomic, nonnull) NMAGeoCoordinates *coordinates;

/**
 * The frame of the object relative to the NMACompositeView in which it is rendered.
 */
@property (nonatomic, readonly) CGRect frame;

/**
 * The projection type used to display the `NMAARObject` in a camera view.
 *
 * The default value is NMAARProjectionTypeGlobal.
 */
@property (nonatomic) NMAARProjectionType projectionType;

/**
 * The opacity of the object.
 *
 * By default the opacity has a negative value, which means LiveSight adjusts the
 * opacity based on a number of factors including the proximity of the object to
 * the user and the presence of buildings between the camera and the object.
 *
 * If this value is overridden, the object will be displayed with a fixed opacity.
 * Valid values range from 0 (fully transparent) to 1 (fully opaque).
 */
@property (nonatomic) CGFloat opacity;


#pragma mark - Icons

/**
 * The front plane icon of the object.
 *
 * Rendered when the object appears in the front plane of the camera view.
 *
 * @note Attempts to replace an existing NMAImage with nil will be ignored.
 */
@property (nonatomic, readwrite, nonnull) NMAImage *frontPlaneIcon;

/**
 * The back plane icon of the object.
 *
 * Rendered when the object appears in the back plane of the camera view
 *
 * @note Attempts to replace an existing NMAImage with nil will be ignored.
 */
@property (nonatomic, readwrite, nonnull) NMAImage *backPlaneIcon;


#pragma mark - Info Image

/**
 * The info image of the object.
 *
 * By default the info image is displayed when the object appears in the front
 * plane of the camera view.
 *
 * @note Attempts to replace an existing NMAImage with nil will be ignored.
 */
@property (strong, nonatomic, nonnull) NMAImage *infoImage;

/**
 * The maximum width, in points, of the info image.
 *
 * If a maximum width is set LiveSight will not scale the info image larger than
 * this width.
 *
 * By default this property has a negative value which means no maximum width.
 */
@property (nonatomic) CGFloat infoImageMaximumWidth;

/**
 * The maximum height, in points, of the info image.
 *
 * If a maximum height is set LiveSight will not scale the info image larger than
 * this height.
 *
 * By default this property has a negative value which means no maximum height.
 */
@property (nonatomic) CGFloat infoImageMaximumHeight;

/**
 * Controls the visibility of the info image.
 */
@property (nonatomic, readonly, getter = isInfoImageVisible) BOOL infoImageVisible;

@end
