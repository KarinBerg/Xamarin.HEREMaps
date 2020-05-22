/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"

@class NMAGeoCoordinates;
@class NMAUrbanMobilityAccessPoint;
@class NMAUrbanMobilityAddress;
@class NMAUrbanMobilityDepartureFrequency;
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityPlace;
@class NMAUrbanMobilityStation;
@class NMAUrbanMobilityTransport;
@class NMAUrbanMobilityRealTimeInfo;
@class NMAUrbanMobilityAlternativeDeparture;



/**
 * Defines a departure from a transit station.
 *
 * See also `NMAUrbanMobilityStation`
 *
 * IMPORTANT: Urban Mobility is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityDeparture : NSObject

/**
 * Instances of this class should not be initialized directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 * Instances of this class should not be initialized directly
 */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
 * Transport which serves the departure.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityTransport *transport;

/**
 * Departure time.
 */
@property (nonatomic, readonly, nullable) NSDate *time;

/**
 * Departure platform.
 */
@property (nonatomic, readonly, nullable) NSString *platform;

/**
 * Real-time data (time, platform).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityRealTimeInfo *realTimeInfo;

/**
 * Frequency of the departure (nil if not available).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityDepartureFrequency *frequency;

/**
 * `NMAUrbanMobilityStation` information from which this departure occurs.
 * NOTE: This property is available only if `NMAUrbanMobilityPlace` of the departure is also a `NMAUrbanMobilityStation`.
 *
 * @return  `NMAUrbanMobilityStation` information or nil if not available.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityStation *station;

/**
 * `NMAUrbanMobilityPlace` information from which this departure occurs.
 *
 * @return `NMAUrbanMobilityPlace` from which this departure occurs or nil if not available.
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityPlace *place;

/**
 * Access point which can be used to access the transit station which hosts this departure.
 * Information about a station access point (entrance/exit).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityAccessPoint *accessPoint;

/**
 * Array of `NMAUrbanMobilityAlternativeDeparture` alternative departures.
 */
@property (nonatomic, readonly, nullable) NSArray<NMAUrbanMobilityAlternativeDeparture *> *alternativeDepartures;

@end
