/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAPositionDataSource.h"

/**
 * The interface used to create a automotive position source for NMAPositioningManager.
 *
 * IMPORTANT: This is a Beta API, and is subject to change without notice.
 *
 * This interface extends NMAPositionDataSource and adds methods to provide sensor data from
 * automotive Dead Reckoning (DR) units.
 *
 * @note Setting a source derived from this class will force NMAPositioningManager to use a
 * map matching algorithm designed for automotive use cases which expects a constant stream of
 * position and sensor data from a DR unit at a frequency of 10Hz. The automotive map matcher
 * algorithm does not support any form of extrapolation so if a constant stream of position and
 * sensor data is not provided in tunnels or areas of traditionally poor GPS coverage the map
 * matching performance will be poor.
 *
 * @note Attempts to set [NMAPositioningManager dataSource] to an object derived from
 * NMAPositionDataSourceAutomotive will be ignored if access to this operation is denied.
 * Contact your HERE representative for more information.
 */
@protocol NMAPositionDataSourceAutomotive <NMAPositionDataSource>

@optional

/**
 * Horizontal radial error (large component) as a standard deviation in meters.
 */
- (float)horizontalLargeStandardDeviation;

/**
 * Horizontal radial error (small component) as a standard deviation in meters.
 */
- (float)horizontalSmallStandardDeviation;

/**
 * Standard deviation of the course in degrees.
 */
- (float)courseStandardDeviation;

/**
 * Standard deviation of the speed meters per second.
 */
- (float)speedStandardDeviation;

/**
 * Standard deviation of the elevation in meters.
 */
- (float)elevationStandardDeviation;

@end
