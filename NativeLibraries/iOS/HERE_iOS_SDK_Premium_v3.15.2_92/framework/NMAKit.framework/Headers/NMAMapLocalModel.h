/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapModelObject.h"

@class NMAGeoCoordinates;
@class NMAFloatMesh;



/**
 * Displays a custom 3D model at a fixed geographical location on a map.
 *
 * The NMAMapLocalModel is used to display custom 3D content on an instance of
 * NMAMapView. The 3D model is defined using an instance of NMAFloatMesh, with the
 * unit mesh unit representing one meter in world space. The mesh origin is
 * located on a map using NMAMapLocalModel's coordinates property.
 *
 * The orientation of the mesh may be controlled by modifying its pitch, yaw,
 * and roll. These values may range from 0 to 360 degrees. The size of the mesh
 * can be adjusted manually using the scale property, or automatically adjusted
 * by setting the autoscaled property to YES.
 *
 * As a subclass of NMAMapObject, instances of NMAMapLocalModel may be selected,
 * hidden, placed inside an NMAMapContainer, or any other operation that can
 * be applied to map objects.
 */
@interface NMAMapLocalModel : NMAMapModelObject

/**
 * The geographical location of the mesh origin.
 */
@property (nonatomic, nullable) NMAGeoCoordinates *coordinates;

/**
 * The east-west axis rotation of the mesh.
 */
@property (nonatomic) float pitch;

/**
 * The up-down axis rotation of the mesh.
 */
@property (nonatomic) float yaw;

/**
 * The north-south axis rotation of the mesh.
 */
@property (nonatomic) float roll;

/**
 * A factor controlling the size of the mesh; a value of 0 will
 * render the mesh at its true size.
 *
 * @note The effect of scale on the model size varies significantly depending on whether
 * or not autoscaling is enabled and the magnitude of the model vertices. Therefore,
 * depending on these factors you may have to tweak the scale (by orders of magnitude perhaps)
 * to get a model of the same relative size as another.
 */
@property (nonatomic) float scale;

/**
 * Enables autoscaling, which causes the mesh to be rendered at
 * roughly the same size regardless of map zoom level.
 */
@property (nonatomic) BOOL autoscaled;

/**
 * Initializes an instance of NMAMapLocalModel with the specified NMAFloatMesh.
 *
 * @note The mesh parameter cannot be nil.
 */
- (nonnull instancetype)initWithMesh:(nonnull NMAFloatMesh *)mesh
NS_SWIFT_NAME(init(mesh:));

@end
