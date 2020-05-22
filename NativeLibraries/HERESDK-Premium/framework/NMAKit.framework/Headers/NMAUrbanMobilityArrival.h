/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStation;
@class NMAUrbanMobilityAddress;
@class NMAUrbanMobilityAccessPoint;
@class NMAGeoCoordinates;
@class NMAUrbanMobilityPlace;
@class NMAUrbanMobilityRealTimeInfo;



/**
 * Defines an arrival place.
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to
 * change without notice.
 *
 * See also `NMAUrbanMobilityStation`
 *
 * See also `NMAUrbanMobilityPlace`
 *
 * See also `NMAUrbanMobilityAccessPoint`
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityArrival : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Arrival time.
 */
@property (nonatomic, readonly, nullable) NSDate *time;

/**
 * Arrival platform.
 */
@property (nonatomic, readonly, nullable) NSString *platform;

/**
 * Real-time data (time, platform).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityRealTimeInfo *realTimeInfo;

/**
 * Arrival `NMAUrbanMobilityStation` information.
 * NOTE: This property is available only if arrival `NMAUrbanMobilityPlace` is also a `NMAUrbanMobilityStation`.
 *
 * @return  `NMAUrbanMobilityStation` information or nil if not available.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityStation *station;

/**
 * Arrival `NMAUrbanMobilityPlace` information.
 *
 * @return arrival `NMAUrbanMobilityPlace` information or nil if not available.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityPlace *place;

/**
 * Access point which can be used to access the transit station which hosts this arrival.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityAccessPoint *accessPoint;

@end
