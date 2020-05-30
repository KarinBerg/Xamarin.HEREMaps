/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMapModelObject.h"

@class NMAGeoCoordinates;
@class NMAGeoMesh;



/**
 * A 3D model defined as an array of geographical coordinates that can be
 * displayed on an `NMAMapView`.
 *
 * The NMAMapGeoModel is used to display custom 3D content on an instance of
 * NMAMapView. The 3D model is defined using an instance of NMAGeoMesh, which
 * containing an array of NMAGeoCoordinates, triangles and texture coordinates.
 *
 * The NMAMapGeoModel could includes textures, which is an NMAImage
 * applied to the mesh. 2D plane objects will respect the texture's transparency,
 * while the alpha transparency for a texture being applied to a 3D object is undefined.
 *
 * As a subclass of `NMAMapObject`, instances of `NMAMapGeoModel` may be selected,
 * hidden, placed inside an `NMAMapContainer`, or any other operation that can
 * be applied to map objects.
 */
@interface NMAMapGeoModel : NMAMapModelObject

/**
 * Initializes an instance of NMAMapGeoModel with the specified NMAGeoMesh.
 *
 * @note The mesh parameter cannot be nil.
 */
- (nonnull instancetype)initWithMesh:(nonnull NMAGeoMesh *)mesh
NS_SWIFT_NAME(init(mesh:));

@end
