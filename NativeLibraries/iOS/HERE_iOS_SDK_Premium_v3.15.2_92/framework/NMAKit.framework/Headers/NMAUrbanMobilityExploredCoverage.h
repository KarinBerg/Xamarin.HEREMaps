/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStation;
@class NMAUrbanMobilityTransport;



/**
 * Represents coverage information about a location that is further away.
 * This coverage includes information about the closest station (if there is one
 * inside of radius) and information of lines going through five closest stations
 * (if available inside of the radius).
 *
 * IMPORTANT: Urban Mobility Coverage Search is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityExploredCoverage : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Radius (in meters) for which the coverage information is provided.
 */
@property (nonatomic, readonly) NSInteger radius;

/**
 * Number of stops returned within specified radius.
 */
@property (nonatomic, readonly) NSInteger stopsCount;

/**
 * Number of transports returned within specified radius.
 */
@property (nonatomic, readonly) NSInteger transportsCount;

/**
 * Maximum five (5) closest stations (an array of `NMAUrbanMobilityStation`) outside related radius from `NMAUrbanMobilityNearbyCoverageResult`.
 *
 * See also `NMAUrbanMobilityStation`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityStation *> *stations;

/**
 * Array of `NMAUrbanMobilityTransport` transports taken from the closest five (5) stops within the specified radius,
 * sorted by feature type.
 *
 * See also `NMAUrbanMobilityTransport`
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityTransport *> *transports;

@end
