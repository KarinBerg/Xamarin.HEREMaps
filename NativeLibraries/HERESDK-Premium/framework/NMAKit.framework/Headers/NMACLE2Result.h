/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMACLE2Request.h"

@class NMACLE2Geometry;


/**
 * Contains the all the geometries (`NMACLE2Geometry`) returned from an
 * `NMACLE2Request`.
 */
@interface NMACLE2Result : NSObject

/**
 * Returns an `NSArray` containing all the geometries of this `NMACLE2Result`.
 */
@property (nullable, nonatomic, readonly) NSArray<NMACLE2Geometry *> *geometriesArray;

/**
 * Returns the mode in which the originating request operated. Specially useful
 * to determine which search type was performed for an `NMACLE2Request` configured in
 * default mode (this property can only be NMACLE2ConnectivityModeOffline or NMACLE2ConnectivityModeOnline).
 */
@property (nonatomic, readonly) NMACLE2ConnectivityMode connectivityModeUsed;

@end
