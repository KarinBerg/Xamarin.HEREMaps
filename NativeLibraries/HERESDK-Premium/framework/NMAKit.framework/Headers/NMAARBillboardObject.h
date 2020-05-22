/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAARModelObject.h"
#import "NMAVector3d.h"
#import "NMAGeoCoordinates.h"


/**
 * Defines the orientation mode of `NMAARBillboardObject` object.
 */
typedef NS_ENUM(NSUInteger, NMAARBillboardObjectOrientation) {
    /**
     * The orientation is fixed, set explicitly using the billboard's
     * normal and up vectors.
     */
    NMAARBillboardObjectOrientationFixed = 0,

    /**
     * The billboard is oriented toward the camera.
     */
    NMAARBillboardObjectOrientationBillboard = 1
};


/**
 * 3D LiveSight billboard object that users can add to a `NMAARController`.
 *
 * @note There are two type types of billboard objects supported:
 *
 *  - Locally positioned billboard.
 *  - Geo positioned billboard.
 *
 *  In a locally positioned billboard, the object has a fixed relative distance to the camera
 *  In a geo positioned billboard, the object is fixed at the specified geo coordinates.
 */
@interface NMAARBillboardObject : NMAARModelObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Creates a billboard object with a local position and texture.
 *
 * @param localPosition The center of the billboard, represented as a distance vector
 *                 in meters relative to the camera origin.
 * @param texture An optional texture image to display on the billboard.
 *
 */
- (nonnull instancetype)initWithLocalPosition:(NMAVector3d)localPosition
                                      texture:(nullable NMAImage *)texture;

/**
 * Creates a billboard object with a geo position and texture.
 *
 * @param geoCoordinates The center of the billboard, represented as geo coordinates.
 * @param texture An optional texture image to display on the billboard.
 *
 */
- (nonnull instancetype)initWithGeoCoordinates:(nonnull NMAGeoCoordinates *)geoCoordinates
                                       texture:(nullable NMAImage *)texture;

/**
 * The local position of the billboard center relative to the camera, in meters.
 *
 * @note Returns invalid vector if the object is initialized with a geo position.
 */
@property (nonatomic, readwrite) NMAVector3d localPosition;

/**
 * The geo coordinates of the billboard center.
 *
 * @note Returns nil if the object is initialized with a local position.
 */
@property (nonatomic, readwrite, nullable) NMAGeoCoordinates *geoPosition;

/**
 * The orientation mode of the billboard.
 *
 * @note The default value is NMAARBillboardObjectOrientationBillboard.
 *
 * See also `NMAARBillboardObjectOrientation`
 */
@property (nonatomic, readwrite) NMAARBillboardObjectOrientation orientation;

/**
 * The surface normal vector of the billboard.
 *
 * The normal vector defines the direction that the billboard is facing.
 *
 * @note Valid only with NMAARBillboardObjectOrientationFixed orientation mode.
 */
@property (nonatomic, readwrite) NMAVector3d surfaceNormal;

/**
 * The up direction vector of the billboard.
 *
 * The up vector defines the direction of the top of the billboard.
 *
 * @note Valid only with NMAARBillboardObjectOrientationFixed orientation mode.
 */
@property (nonatomic, readwrite) NMAVector3d upDirection;

/**
 * The spatial size of the billboard in meters.
 *
 * @note The default value is (1.0, 1.0).
 */
@property (nonatomic, readwrite) CGSize size;

@end
