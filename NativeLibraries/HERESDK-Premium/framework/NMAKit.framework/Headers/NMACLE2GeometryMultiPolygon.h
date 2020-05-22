/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMACLE2Geometry.h"

@class NMACLE2GeometryPolygon;


/**
 * Represents a multipolygon custom geometry created and accessed through the
 * Custom Location Extension 2.
 *
 * This class aligns with the concept of a MULTIPOLYGON in WKT (Well Known Text) format,
 * which contains one or more POLYGON objects (serving as a container of `NMACLE2GeometryPolygon`).
 * Please refer to `NMACLE2GeometryPolygon` for more information on the contained objects.
 */
@interface NMACLE2GeometryMultiPolygon : NMACLE2Geometry

/**
 * Array of `NMACLE2GeometryPolygon` in this geometry.
 */
@property (nonnull, nonatomic) NSMutableArray<NMACLE2GeometryPolygon *> * multiPolygonArray NS_SWIFT_NAME(polygons);

@end
