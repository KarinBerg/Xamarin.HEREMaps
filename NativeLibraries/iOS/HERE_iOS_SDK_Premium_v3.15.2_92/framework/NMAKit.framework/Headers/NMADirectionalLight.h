/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVector3d.h"

#import "NMALight.h"


/**
 * Represents a simple directional light source for use with 3D models.
 */
@interface NMADirectionalLight : NMALight

/**
 * Creates a directional light with the specified direction.
 *
 * @param direction The light source direction.
 */
+ (nonnull instancetype)lightWithDirection:(NMAVector3d)direction
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");


/**
 * Creates a directional light with the specified direction.
 *
 * @param direction The light source direction.
 */
- (nonnull instancetype)initWithDirection:(NMAVector3d)direction
NS_SWIFT_NAME(init(direction:)) NS_DESIGNATED_INITIALIZER;

/**
 * The direction of the light.
 */
@property (nonatomic) NMAVector3d direction;

@end
