/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMAGeoCoordinates;
@class NMAGeoPolyline;
@class NMAImage;



/**
 * Represents a NMAMapObject in the shape of a polyline.
 *
 * A `NMAMapPolyline` has multiple points that combine to create its path and
 * which are traversed in order. The line between
 * two consecutive points is always straight and is defined by the shortest
 * navigable way to move between them.
 *
 * @note The NMAViewObject location property for an NMAMapPolyline returns the
 * coordinates of the first vertex (if available).
 */
@interface NMAMapPolyline : NMAMapObject

/**
 * A convenience method for constructing an NMAMapPolyline.
 *
 * @param vertices An array of NMAGeoCoordinates which define the polyline
 */
+ (nonnull instancetype)mapPolylineWithVertices:(nonnull NSArray<NMAGeoCoordinates *> *)vertices
NS_SWIFT_UNAVAILABLE("Use corresponding instance initializer");

/**
 * The `NSArray` of NMAGeoCoordinates that comprise the path of the
 * `NMAMapPolyline`.
 */
@property (nonatomic, readonly, nonnull) NSArray<NMAGeoCoordinates *> *vertices;

/**
 * The color for the `NMAMapPolyline`.
 *
 * @note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong, nonnull) UIColor *lineColor;

/**
 * The width, in pixels, for the `NMAMapPolyline`.
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
 * The outline color for the `NMAMapPolyline`.
 *
 * @note Attempts to set this property to nil are ignored. The default outline color is transparent.
 */
@property (nonatomic, strong, nonnull) UIColor *outlineColor;

/**
 * The outline width, in pixels, for the `NMAMapPolyline`.
 *
 * The outline width must be in the range [0, 100]. The default width is 0 pixel.
 */
@property (nonatomic) NSUInteger outlineWidth;

/**
 * Indicates whether to render the `NMAMapPolyline` with depth test.
 *
 * @note Rendering with depth test should be used if map object altitude
 * is relevant in your application. Rendering objects with different
 * heights while disabling depth test may cause object occlusion.
 */
@property (nonatomic) BOOL depthTestEnabled;

/**
 * Enables shadow with provided width and shear factor. Shear factor
 * is a coefficient of changing shifting the shadow from the polyline by X
 * axis depending of tilt.
 *
 * The shadow width and shear factor must not be less than 0.
 */
-(void)enableShadow:(NSUInteger)width shearFactor:(float)shearFactor;

/**
 * Indicates whether shadow is enabled for this `NMAMapPolyline`.
 */
@property (nonatomic, getter = isShadowEnabled) BOOL shadowEnabled;

/**
 * The shadow width, in pixels, for the `NMAMapPolyline`.
 *
 * The shadow width must not be less than 0. The default value is 0 pixel.
 */
@property (nonatomic) NSUInteger shadowWidth;

/**
 * The shadow color for the `NMAMapPolyline`. Default shadow color is black.
 *
 * @note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong, nonnull) UIColor* shadowColor;

/**
 * The shadow shear factor, coefficient of changing shifting the shadow from
 * the polyline by X axis depending of tilt.
 *
 * The shadow shear factor must not be less than 0. The default value is 0 pixel.
 */
@property (nonatomic) float shadowShearFactor;

/**
 * The shadow offest x, shifting the shadow from the polyline by X axis in pixels.
 *
 * The shadow offest x must not be less than 0. The default value is 0 pixel.
 */
@property (nonatomic) float shadowOffsetX;

/**
 * The shadow offest y, shifting the shadow from the polyline by Y axis in pixels.
 *
 * The shadow offest y must not be less than 0. The default value is 0 pixel.
 */
@property (nonatomic) float shadowOffsetY;

/**
 * The shadow size increment, coefficient of the polyline`s shadow width changing in pixels.
 *
 * The shadow size increment must not be less than 0. The default value is 0 pixel.
 */
@property (nonatomic) float shadowSizeIncrement;

/**
 * Initializes a `NMAMapPolyline` instance with the specified `NMAGeoPolyline`
 *
 * @param geoPolyline The `NMAGeoPolyline` defining the polyline.
 * @return The `NMAMapPolyline`
 */
-(nonnull instancetype)initWithPolyline:(nonnull NMAGeoPolyline *)geoPolyline;

/**
 * Gets copy of the `NMAGeoPolyline` rendered by this `NMAMapPolyline`.
 */
@property (nonatomic, readonly, nonnull) NMAGeoPolyline *geoPolyline;

/**
 * Initializes a `NMAMapPolyline` instance with the specified `NSArray` of
 * NMAGeoCoordinates objects.
 *
 * @param vertices A `NSArray` of `NMAGeoCoordinates` points defining the
 *                    `NMAMapPolyline`
 * @return The `NMAMapPolyline`
 */
- (nonnull instancetype)initWithVertices:(nonnull NSArray<NMAGeoCoordinates *> *)vertices NS_DESIGNATED_INITIALIZER;

/**
 * Determines the `NMAGeoCoordinates` along the `NMAMapPolyline` path that
 * is closest to the specified `NMAGeoCoordinates` object.
 *
 * @param coordinates A `NMAGeoCoordinates` to test for nearness to the
 *                    `NMAMapPolyline`
 * @return The `NMAGeoCoordinates` vertex along the `NMAMapPolyline` path
 */
- (nonnull NMAGeoCoordinates *)nearestVertexToGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Determines the index of the `NMAMapPolyline` path array that is closest
 * to the specified `NMAGeoCoordinates` object.
 *
 * @param coordinates A `NMAGeoCoordinates` to test for nearness to the
 *                    `NMAMapPolyline`
 * @return The index of the `NMAGeoCoordinates` vertex
 */
- (NSInteger)indexOfNearestVertexToGeoCoordinates:(nonnull NMAGeoCoordinates *)coordinates;

/**
 * Removes all vertices from the NMAMapPolyline's path.
 */
- (void)clearVertices;

/**
 * Append a `NMAGeoCoordinates` point to the end of the `NMAMapPolyline` path.
 *
 * @param vertex A `NMAGeoCoordinates` path point to append
 */
- (void)appendVertex:(nonnull NMAGeoCoordinates *)vertex
NS_SWIFT_NAME(appendVertex(_:));

/**
 * Insert a `NMAGeoCoordinates` point at the specified index of the `NMAMapPolyline` path.
 *
 * @param vertex A `NMAGeoCoordinates` path point to add.
 * @param index Position to insert. Index starts with 0.
 *
 * @note If index is equal or greater than the total number of vertices, the vertex will be
 * appended to the end of the polyline path.
 */
- (void)addVertex:(nonnull NMAGeoCoordinates *)vertex atIndex:(NSUInteger)index
NS_SWIFT_NAME(addVertex(_:at:));

/**
 * Remove the last `NMAGeoCoordinates` point of the `NMAMapPolyline` path.
 */
- (void)removeLastVertex;

/**
 * Remove a `NMAGeoCoordinates` point at the specified index of the `NMAMapPolyline` path.
 *
 * @param index Position to remove. Index starts with 0 and must be smaller than the total number
 * of vertices.
 */
- (void)removeVertexAtIndex:(NSUInteger)index
NS_SWIFT_NAME(removeVertex(at:));

/**
 * Indicates whether the `NMAMapPolyline` is thinner further away when the map is tilted.
 * This property defaults to NO.
 */
@property (nonatomic, getter = isPerspective) BOOL perspective;

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
