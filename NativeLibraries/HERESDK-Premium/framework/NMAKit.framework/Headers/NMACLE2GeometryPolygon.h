/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMACLE2Geometry;
@class NMAGeoPolygon;



/**
 * Represents a Polygon custom geometry created and accessed through the
 * Custom Location Extension 2.
 *
 * @note The concept of polygon in WKT (Well Known Text) format consists of
 * one outer ring/polygon, plus zero or more inner rings/polygons. We map the
 * WKT concept here with one `NMAGeoPolygon` property 'outerRing' and an
 * `NSArray%` of `NMAGeoPolygons` containing the inner rings/polygons, if any.
 *
 */
@interface NMACLE2GeometryPolygon : NMACLE2Geometry

/**
 * Retrieve the outer ring (`NMAGeoPolygon`) of this geometry.
 */
@property (nullable, nonatomic) NMAGeoPolygon *outerRing;

/**
 * Retrieve all the inner rings (`NMAGeoPolygon`) of this geometry.
 */
@property (nullable, nonatomic) NSMutableArray<NMAGeoPolygon *> *innerRings;

@end
