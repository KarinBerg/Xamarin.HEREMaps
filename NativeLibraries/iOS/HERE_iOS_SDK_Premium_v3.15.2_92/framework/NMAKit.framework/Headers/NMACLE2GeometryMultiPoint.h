/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMACLE2Geometry.h"


/**
 * Represents a multipoint custom geometry created and accessed through the
 * Custom Location Extension 2.
 *
 */
@interface NMACLE2GeometryMultiPoint : NMACLE2Geometry

/**
 * Array of `NMAGeoCoordinates` of this geometry.
 */
@property (nonnull, nonatomic, readwrite) NSMutableArray<NMAGeoCoordinates *> * coordinatesArray NS_SWIFT_NAME(coordinates);

@end
