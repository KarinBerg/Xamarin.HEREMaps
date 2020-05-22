/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapObject.h"

@class NMAImage;
@class NMALight;
@class NMAMaterial;



/**
 * Base class for NMAMapLocalModel and NMAMapGeoModel. This class provides
 * lighting and material properties for a custom 3D model.
 *
 */
@interface NMAMapModelObject : NMAMapObject

/**
 * The material of the model.
 *
 * @note nil values will be ignored.
 */
@property (nonatomic, strong, nullable) NMAMaterial *material;

/**
 * The lights currently attached to the model.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMALight *> *lights;

/**
 * The maximum number of supported light sources for a NMAMapModelObject.
 */
@property (nonatomic, readonly) NSUInteger maximumNumberOfLights;

/**
 * Sets the texture to use for rendering the mesh.
 *
 * @note nil values will be ignored.
 */
- (void)setTexture:(nullable NMAImage *)texture;

/**
 * Adds a light to the model object.
 *
 * @note This method will fail if the model already contains the maximum number of
 * lights, given by maximumNumberOfLights.
 *
 * @note nil values will be ignored.
 *
 * @param light The NMALight object to add to the model.
 *
 * @return YES if the light was added successfully, NO otherwise.
 */
- (BOOL)addLight:(nullable NMALight *)light;

/**
 * Removes all the lights attached to the model.
 */
- (void)removeAllLights;

@end
