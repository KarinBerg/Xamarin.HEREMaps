/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;


/**
 * Object representing a Polygon, which consists of three or more points.
 * This class can be used to manipulate a polygon geometry along with `NMAMapPolygon` for map
 * rendering. The minimum number of points in an NMAGeoPolygon must be three.
 */
@interface NMAGeoPolygon : NSObject

/**
 * Initialize an NMAGeoPolygon instance.
 */
- (nonnull instancetype)init;

/**
 * Initializes an `NMAGeoPolygon` instance with the specified `NMAGeoCoordinates`.
 *
 * @param coordinates An NSArray containing two or more `NMAGeoCoordinates`.
 * @return The `NMAGeoPolygon` instance, or nil if initialization failed
 */
- (nonnull instancetype)initWithCoordinates:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates;

/**
 * Add a new point to the polygon.
 *
 * @param coordinate point to be added given as `NMAGeoCoordinates`
 */
- (void)addPoint:(nonnull NMAGeoCoordinates *)coordinate;

/**
 * Adds a list of points to the polygon.
 *
 * @param coordinates NSArray containing the list of `NMAGeoCoordinates`
 */
- (void)addPoints:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates;

/**
 * Insert a point to the polygon at the specified index
 *
 * @param coordinate point to be added given as `NMAGeoCoordinates`
 * @param index position of the point along the polygon
 */
- (void)insertPoint:(nonnull NMAGeoCoordinates *)coordinate atIndex:(int)index;

/**
 * Remove a point from the polygon with the specified index
 *
 * @param index position of the point along the polygon
 */
- (void)removePointAtIndex:(int)index;

/**
 * Remove all points from the polygon
 */
- (void)clear;

/**
 * Get the total number of points that currently exists in the polygon
 */
- (int)numberOfPoints;

/**
 * Get the point coordinates from the specified index of this polygon.
 * @param index position of the point along the polygon
 * @return The `NMAGeoCoordinates` instance, or nil if failed
 */
- (nullable NMAGeoCoordinates *)pointAtIndex:(int)index;

/**
 * Get an NSArray with all points of the polygon.
 */
- (nonnull NSArray<NMAGeoCoordinates *> *)allPoints
NS_SWIFT_NAME(points());

/**
 * Return the geographical length of the polygon in meters.
 */
- (double)length;

/**
 * Gets the `NMAGeoCoordinates` along the path of the polygon that is closest to the specified point.
 *
 * @param coordinate the origin point to search from given in `NMAGeoCoordinates`.
 */
- (nullable NMAGeoCoordinates *)nearestCoordinateFrom:(nonnull NMAGeoCoordinates *)coordinate;

/**
 * Gets the point index along the path of the polygon that is closest to the specified point.
 *
 * @param coordinate the origin point to search from given in `NMAGeoCoordinates`.
 */
- (NSUInteger)nearestIndexFromCoordinate:(nonnull NMAGeoCoordinates *)coordinate
NS_SWIFT_NAME(nearestIndex(from:));

/**
 * Sorts polygon points clockwise to make well formed polygon without self intersections.
 * @return The `NMAGeoPolygon` instance with sorted points.
 */
- (nonnull NMAGeoPolygon *)sortedPolygon;

/**
 * Gets the geographic bounding box that contains this `NMAGeoPolygon`.
 * @return the `NMAGeoBoundingBox` instance, or nil if the polygon has fewer than 2 points.
 */
- (nullable NMAGeoBoundingBox *)geoBoundingBox;

@end
