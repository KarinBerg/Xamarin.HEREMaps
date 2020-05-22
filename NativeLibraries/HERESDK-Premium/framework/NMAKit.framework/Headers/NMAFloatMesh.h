/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>



/**
 * Represents a 3D model.
 *
 * The NMAFloatMesh class encapsulates all the geometric information
 * needed to render a 3D model. This information includes the vertices,
 * texture coordinates, and triangles of the model.
 */
@interface NMAFloatMesh : NSObject

/**
 * Convenient initializer for creating a NMAFloatMesh with required geometry data
 *
 * @param vertices A pointer to an array of floats representing the mesh vertices
 * @param vertexCount The number of vertices in the array
 * @param textureCoordinates A pointer to an array of floats representing the texture coordinates.
 * @param coorCount The number of texture coordinates in the array
 * @param triangles A pointer to an array of shorts representing the triangles of the mesh
 * @param triangleCount The number of triangles in the array
 * @return an object instance of NMAFloatMesh
 */
- (nonnull instancetype)initWithVertices:(nonnull const float *)vertices
                             vertexCount:(NSUInteger)vertexCount
                      textureCoordinates:(nonnull  const float *)textureCoordinates
                               coorCount:(NSUInteger)coorCount
                               triangles:(nonnull  const short *)triangles
                           triangleCount:(NSUInteger)triangleCount
NS_SWIFT_NAME(init(vertices:vertexCount:textureCoordinates:textureCoordinatesCount:triangles:triangleCount:));

/**
 * Sets the vertices of the mesh.
 *
 * Each mesh vertex is represented by three float values representing its x, y, and z
 * positions. Three values are always required for each vertex, so the length of the
 * vertices array should always be a multiple of 3.
 *
 * @note The mesh is limited to 65536 vertices.
 *
 * @param vertices A pointer to an array of floats representing the mesh vertices.
 * @param count The number of vertices in the array. The length of the vertices array
 * should be 3 * count.
 */
- (void)setVertices:(nonnull const float *)vertices withCount:(NSUInteger)count
NS_SWIFT_NAME(setVertices(_:count:));

/**
 * Sets the texture coordinates of the mesh.
 *
 * Every mesh vertex must also have a texture coordinate defined, which identifies the
 * location on the mesh texture corresponding to that vertex. Texture coordinates are
 * defined by two float values in the range [0, 1], with a value of (0, 0) corresponding
 * to the upper left corner of the texture and (1, 1) the lower right corner.
 *
 * @param textureCoordinates A pointer to an array of floats representing the texture
 * coordinates.
 * @param count The number of texture coordinates in the array. The length of the
 * textureCoordinates array should be 2 * count.
 */
- (void)setTextureCoordinates:(nonnull const float *)textureCoordinates withCount:(NSUInteger)count
NS_SWIFT_NAME(setTextureCoordinates(_:count:));

/**
 * Sets the triangles of the mesh.
 *
 * A mesh is rendered as a collection of triangles. Each triangle is defined by specifying
 * the indices of the three vertices which make up its corners. The indices may be specified
 * in any order.
 *
 * @param triangles A pointer to an array of shorts representing the triangles of the mesh.
 * @param count The number of triangles in the array. The length of the triangles array should be
 * 3 * count.
 */
- (void)setTriangles:(nonnull const short *)triangles withCount:(NSUInteger)count
NS_SWIFT_NAME(setTriangles(_:count:));

/**
 * Checks if the current mesh data is valid.
 *
 * A mesh is considered valid if it has equal numbers of vertices and texture coordinates
 * and the indices of the triangle array are all less than the number of vertices.
 */
- (BOOL)isValid;

@end
