/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityTransport;
@class NMAUrbanMobilityRealTimeInfo;



/**
 * Defines an alternative departure.
 *
 * IMPORTANT: Urban Mobility routing is a Beta feature. The related classes are subject to change
 * without notice.
 *
 * DEPRECATED As of SDK 3.8.
 */
DEPRECATED_ATTRIBUTE
@interface NMAUrbanMobilityAlternativeDeparture : NSObject

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
 * Real-time data (time, platform).
 */
@property (nonatomic, readonly, nullable) NMAUrbanMobilityRealTimeInfo *realTimeInfo;

@end
