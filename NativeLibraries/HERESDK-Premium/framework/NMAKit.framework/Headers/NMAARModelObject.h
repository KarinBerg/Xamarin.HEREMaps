/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "NMAVector3d.h"

@class NMAImage;


/**
 * The shading modes available for 3D model objects.
 */
typedef NS_ENUM(NSUInteger, NMAARModelObjectShadingMode) {
    /**
     * Textured without lighting.
     */
    NMAARModelObjectShadingModeFlatTextured = 0,

    /**
     * Textured with diffuse lighting.
     */
    NMAARModelObjectShadingModeDiffuseTextured = 1
};


/**
 * The base class for all LiveSight 3D objects that users can add to an
 * `NMAARController`.
 *
 * This class serves as the abstract base for more specific 3D object classes.
 * It contains a set of common properties including the object's transformation
 * and appearance in 3D space.
 */
@interface NMAARModelObject : NSObject

/**
 * The opacity level of the object.
 *
 * A value of 1.0 (the default) renders the object fully opaque. A value of 0.0
 * renders the object fully transparent (invisible).
 */
@property (nonatomic, readwrite) CGFloat opacity;

/**
 * The range of distances in meters from the camera inside which the object is
 * visible.
 *
 * The x and y values of the CGPoint represent the minimum and maximum visible
 * distances, respectively.
 *
 * The default range is [0,1000], meaning that the object will be visible at any
 * distance closer than 1000 meters.
 */
@property (nonatomic, readwrite) CGPoint visibilityRange;

/**
 * The shading mode of the object.
 *
 * The default value is NMAARModelObjectShadingModeDiffuseTextured.
 */
@property (nonatomic, readwrite) NMAARModelObjectShadingMode shadingMode;

/**
 * The texture of the object.
 */
@property (nonatomic, readwrite, nullable) NMAImage *texture;

/**
 * The range of distances in meters over which the object's scaling is linearly
 * interpolated.
 *
 * The dynamic scale range may be used to change the apparent size of the object
 * based on its distance from the camera. When dynamic scaling is used, the object
 * is scaled as a linear function of its distance to the camera. The scaling is
 * applied after the model transformation of the object.
 *
 * The scaling is defined as follows:
 *
 * scaling(distance) = s_min if distance < d_min
 *                   = s_max if distance > d_max
 *                   = s_min + (distance - d_min) / (d_max - d_min) * (s_max - s_min), otherwise
 *
 * where [d_min, d_max] is the dynamicScaleRange and {s_min, s_max} are the
 * dynamicScaleFactors. For both properties, x and y of the points represent the
 * min and max values, respectively.
 *
 * The defauly dynamic scale range is [0, 1000].
 */
@property (nonatomic, readwrite) CGPoint dynamicScaleRange;

/**
 * The minimum and maximum scale factors used for dynamic scaling.
 *
 * The default values are {1.0, 1.0}, meaning that no scaling is applied at any
 * distance.
 *
 * See also `NMAARModelObject::dynamicScaleRange`
 */
@property (nonatomic, readwrite) CGPoint dynamicScaleFactors;

/**
 * Sets the model transform matrix for the object.
 *
 * @param transformation An array of 16 float values defining the new 4x4 model
 * transformation matrix in column major order.
 *
 */
- (void)setTransformation:(nonnull const float[])transformation;

/**
 * Gets the current model transform matrix for the object.
 *
 * The default value is the identity matrix.
 *
 * @param transformation A pre-allocated float array of size 16 in which the model
 * transformation matrix will be stored in column major order.
 */
- (void)getTransformation:(nonnull float[])transformation;

/**
 * Resets the model transformation to the identity matrix.
 */
- (void)clearTransformation;

/**
 * Scales the object in three dimensions (the model matrix is post-multiplied).
 *
 * @param scaleFactors The scaling factors applied along the object's x-axis,
 * y-axis, and z-axis.
 *
 */
- (void)scale:(NMAVector3d)scaleFactors;

/**
 * Rotates the object an arbitrary amount around an arbitrary axis (the model
 * matrix is post-multiplied).
 *
 * @param rotationAxis The axis of rotation.
 * @param rotationAngleDeg The rotation angle in degrees conforming to the
 * right-hand convention.
 *
 */
- (void)rotateWithAxis:(NMAVector3d)rotationAxis
                 angle:(CGFloat)rotationAngleDeg;

/**
 * Rotates the object around the Cartesian axes (the model matrix is
 * post-multiplied).
 *
 * @param rotationAngles The rotation angles in degrees around the x, y, and z axes,
 * conforming to the right-hand convention.
 */
- (void)rotate:(NMAVector3d)rotationAngles;

/**
 * Translates the object (the model matrix is post-multiplied).
 *
 * @param translation The translation amounts in meters along the x, y, and z axes.
 *
 */
- (void)translate:(NMAVector3d)translation;

@end
