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
 * Object representing a Polyline geometry, which consists of two or more points.
 * This class can be used to manipulate a polyline geometry along with `NMAMapPolyline` for map
 * rendering.
 */
@interface NMAGeoPolyline : NSObject

/**
 * Initialize an NMAGeoPolyline instance.
 */
- (nonnull instancetype)init;

/**
 * Initializes an `NMAGeoPolyline` instance with the specified `NMAGeoCoordinates`.
 *
 * @param coordinates An NSArray containing two or more `NMAGeoCoordinates`.
 * @return The `NMAGeoPolyline` instance, or nil if initialization failed
 */
- (nonnull instancetype)initWithCoordinates:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates;

/**
 * Add a new point to the polyline.
 *
 * @param coordinate point to be added given as `NMAGeoCoordinates`
 */
- (void)addPoint:(nonnull NMAGeoCoordinates *)coordinate;

/**
 * Adds a list of points to the polyline.
 *
 * @param coordinates NSArray containing the list of `NMAGeoCoordinates`
 */
- (void)addPoints:(nonnull NSArray<NMAGeoCoordinates *> *)coordinates;

/**
 * Insert a point to the polyline at the specified index
 *
 * @param coordinate point to be added given as `NMAGeoCoordinates`
 * @param index position of the point along the polyline
 */
- (void)insertPoint:(nonnull NMAGeoCoordinates *)coordinate atIndex:(int)index;

/**
 * Remove a point from the polyline with the specified index
 *
 * @param index position of the point along the polyline
 */
- (void)removePointAtIndex:(int)index;

/**
 * Remove all points from the polyline
 */
- (void)clear;

/**
 * Get the total number of points that currently exists in the polyline
 */
- (int)getNumberOfPoints
NS_SWIFT_NAME(numberOfPoints());

/**
 * Get the point from the specified index of this polyline.
 * @param index position of the point along the polyline
 * @return The `NMAGeoCoordinates` instance, or nil if failed
 */
- (nullable NMAGeoCoordinates *)getPointAtIndex:(int)index
NS_SWIFT_NAME(point(at:));

/**
 * Get an NSArray with all points of the polyline.
 */
- (nonnull NSArray<NMAGeoCoordinates *> *)getAllPoints
NS_SWIFT_NAME(points());

/**
 * Return the geographical length of the polyline
 */
- (double)getLength
NS_SWIFT_NAME(length());

/**
 * Gets the `NMAGeoCoordinates` (point) along the path of the polyline that is closest to the specified point.
 *
 * @param coordinate the origin point to search from given in `NMAGeoCoordinates`.
 */
- (nullable NMAGeoCoordinates *)getNearestCoordinateFrom:(nonnull NMAGeoCoordinates *)coordinate
NS_SWIFT_NAME(nearestCoordinate(from:));


/**
 * Gets the point index along the path of the polyline that is closest to the specified point.
 *
 * @param coordinate the origin point to search from given in `NMAGeoCoordinates`.
 */
- (NSUInteger)getNearestIndexFromCoordinate:(nonnull NMAGeoCoordinates *)coordinate
NS_SWIFT_NAME(nearestIndex(from:));

/**
 * Gets the geographic bounding box that contains this `NMAGeoPolyline`.
 * @return the `NMAGeoBoundingBox` instance, or nil if the line has fewer than 2 points.
 */
- (nullable NMAGeoBoundingBox *)geoBoundingBox;

@end
