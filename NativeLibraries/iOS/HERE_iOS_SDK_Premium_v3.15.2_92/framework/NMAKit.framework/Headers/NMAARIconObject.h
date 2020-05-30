/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAARObject.h"



/**
 *
 * A concrete `NMAARObject` for displaying icons in a LiveSight
 * camera view.
 *
 * The NMAARIconObject may display separate images for the front plane, back
 * plane, map, and info icons.
 */
@interface NMAARIconObject : NMAARObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates an NMAARIconObject with a common image for front plane, back plane and
 * map icons.
 *
 * @param icon The image to use for the NMAARObject::frontPlaneIcon,
 *             NMAARObject::backPlaneIcon, and NMAARObject::mapIcon.
 * @param coordinates The location of the object.
 *
 * @note Icon images cannot be nil.
 */
+ (nonnull instancetype)iconObjectWithIcon:(nonnull NMAImage *)icon
                               coordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Creates an NMAARIconObject with a common image for the front plane, back plane,
 * and map icons and a separate info image.
 *
 * @param icon The image to use for the NMAARObject::frontPlaneIcon,
 *             NMAARObject::backPlaneIcon, and NMAARObject::mapIcon.
 * @param infoImage The info image for the icon.
 * @param coordinates The location of the object.
 *
 * @note Icon images cannot be nil.
 */
+ (nonnull instancetype)iconObjectWithIcon:(nonnull NMAImage *)icon
                                 infoImage:(nonnull NMAImage *)infoImage
                               coordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Creates an NMAARIconObject with specific images for the front plane, back plane,
 * and map icons and the info image.
 *
 * @param frontPlaneIcon The image to use for the NMAARObject::frontPlaneIcon.
 * @param backPlaneIcon The image to use for the NMAARObject::backPlaneIcon.
 * @param mapIcon The image to use for the NMAARObject::mapIcon. Currently unused.
 * @param infoImage The image to be use for the NMAARObject::infoImage.
 * @param coordinates The location of the object.
 *
 * @note Icon images cannot be nil.
 */
+ (nonnull instancetype)iconObjectWithFrontPlaneIcon:(nonnull NMAImage *)frontPlaneIcon
                                       backPlaneIcon:(nonnull NMAImage *)backPlaneIcon
                                             mapIcon:(nonnull NMAImage *)mapIcon
                                           infoImage:(nonnull NMAImage *)infoImage
                                         coordinates:(nonnull NMAGeoCoordinates *)coordinates;

@end
