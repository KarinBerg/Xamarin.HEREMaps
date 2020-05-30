/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMAGeoCoordinates;
@class NMAGeoPolygon;
@class NMAImage;


/**
 * Represents a NMAMapObject in the shape of a polygon. In comparison to a
 * NMAMapPolyline, it is assumed that the last coordinates within the path is
 * connected with the first coordinates, thereby constructing an enclosed geometry.
 *
 * @note The NMAViewObject location property for an NMAMapPolygon returns the
 * coordinates of the first vertex (if available).
 */
@interface NMAMapPolygon : NMAMapObject

/**
 * A convenience method for constructing an NMAMapPolygon.
 *
 * @param vertices An array of NMAGeoCoordinates which define the polygon
 */
+ (nonnull instancetype)mapPolygonWithVertices:(nonnull NSArray<NMAGeoCoordinates *> *)vertices
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * The fill color for the `NMAMapPolygon`.
 */
@property (nonatomic, strong, nonnull)  UIColor *fillColor;

/**
 * The `NSArray` of `NMAGeoCoordinates` objects comprising the path that
 * defines the `NMAMapPolygon` shape.
 */
@property (nonatomic, readonly, weak, nullable) NSArray<NMAGeoCoordinates *> *vertices;

/**
 * The color for the `NMAMapPolygon` border line.
 *
 * @note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong, nonnull) UIColor *lineColor;

/**
 * The line width, in pixels, for the `NMAMapPolygon` border.
 *
 * The line width must be in the range [0, 100]. The default width is 1 pixel.
 */
@property (nonatomic) NSUInteger lineWidth;

/**
 * Indicates whether the `NMAMapPolyline` is dashed.
 *
 * @note The getter is `isDashed`.
 */
@property (nonatomic, getter = isDashed) BOOL dashed;

/**
 * The length, in pixels, for the primary dash of the `NMAMapPolyline`.
 */
@property (nonatomic) NSUInteger dashPrimaryLength;

/**
 * The length, in pixels, for the secondary dash of the `NMAMapPolyline`.
 */
@property (nonatomic) NSUInteger dashSecondaryLength;

/**
 * Indicates whether to render the `NMAMapPolygon` with depth test.
 *
 * @note Rendering with depth test should be used if map object altitude
 * is relevant in your application. Rendering objects with different
 * heights while disabling depth test may cause object occlusion.
 */
@property (nonatomic) BOOL depthTestEnabled;

/**
 * Initializes a `NMAMapPolygon` instance with the specified `NMAGeoPolygon`
 *
 * @param geoPolygon The `NMAGeoPolygon` defining the polygon.
 * @return The `NMAMapPolygon`
 */
-(nonnull instancetype)initWithPolygon:(nonnull NMAGeoPolygon*)geoPolygon
NS_SWIFT_NAME(init(polygon:));

/**
 * Gets copy of the `NMAGeoPolygon` rendered by this `NMAMapPolygon`.
 */
@property (nonatomic, readonly, nonnull) NMAGeoPolygon *geoPolygon;

/**
 * Initializes a `NMAMapPolygon` instance with the specified `NSArray` of
 * NMAGeoCoordinates objects.
 *
 * @param vertices A `NSArray` of `NMAGeoCoordinates` points defining the
 *                    `NMAMapPolygon` shape
 * @return The `NMAMapPolygon`
 */
- (nonnull instancetype)initWithVertices:(nonnull NSArray<NMAGeoCoordinates *> *)vertices NS_DESIGNATED_INITIALIZER
NS_SWIFT_NAME(init(vertices:));

/**
 * Removes all vertices from the NMAMapPolygon's path.
 */
- (void)clearVertices;

/**
 * Insert a `NMAGeoCoordinates` point at the specified index of the `NMAMapPolygon` path.
 *
 * @param vertex A `NMAGeoCoordinates` path point to add.
 * @param index Position to insert. Index starts with 0.
 *
 * @note If index is equal or greater than the total number of vertices, the vertex will be
 * appended to the end of the polygon path.
 */
- (void)addVertex:(nonnull NMAGeoCoordinates *)vertex atIndex:(NSUInteger)index
NS_SWIFT_NAME(addVertex(_:at:));

/**
 * Append a `NMAGeoCoordinates` path point to the end of the `NMAMapPolygon`.
 *
 * @param vertex A `NMAGeoCoordinates` path point to append
 */
- (void)appendVertex:(nonnull NMAGeoCoordinates *)vertex
NS_SWIFT_NAME(appendVertex(_:));

/**
 * Remove the last `NMAGeoCoordinates` point of the `NMAMapPolygon`
 */
- (void)removeLastVertex;

/**
 * Remove a `NMAGeoCoordinates` point at the specified index of the `NMAMapPolygon` path.
 *
 * @param index Position to remove. Index starts with 0 and must be smaller than the total number
 * of vertices.
 */
- (void)removeVertexAtIndex:(NSUInteger)index
NS_SWIFT_NAME(removeVertex(at:));

/**
 * Determines whether the `NMAMapPolygon` object is valid. A polygon is valid as long
 * as it does not self-intersect and all vertices have the same altitude.
 *
 * @return YES if the `NMAMapPolygon` is valid, NO otherwise
 */
- (BOOL)isValid;

/**
 * Determines if the `NMAMapPolygon` contains the input `NMAGeoCoordinates`.
 *  Points at the peaks or corners of the polygon are considered outside the polygon.
 *
 *  @param coordinates `NMAGeoCoordinates` to test. The altitude is ignored.
 *
 * @return YES if the `NMAGeoCoordinates` is inside the `NMAMapPolygon`, NO otherwise
 */
- (BOOL)containsGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
* Pattern style for line/border
*
* IMPORTANT: This is a Beta API, and is subject to change without notice
*/
@property (nonatomic, assign) NMAPatternStyle patternStyle;

/**
* Custom pattern image.
*
* IMPORTANT: This is a Beta API, and is subject to change without notice
*
* @note Currently, only UIImages with POT(power of two) dimensions supported.
*/
@property (nonatomic, readwrite, nullable) NMAImage *customPattern;

@end
